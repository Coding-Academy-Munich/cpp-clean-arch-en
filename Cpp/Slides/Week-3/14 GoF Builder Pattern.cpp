// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GoF: Builder Pattern</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 14 GoF Builder Pattern.cpp -->
// <!-- slides/module_450_design_patterns/topic_300_builder.cpp -->


// %% [markdown]
//
// - Pattern for creating objects
// - Separates the construction of a complex object from its representation
// - Allows the same construction to produce different representations
// - In C++ sometimes also used as a replacement for
//   - overloaded constructors
//   - named arguments

// %% [markdown]
//
// ## Idea
//
// - Use a builder object to store the configuration of an object
// - Create the object from the configuration

// %% [markdown]
//
// - Document builder
// - Create Markdown and HTML documents

// %%
#include <memory>
#include <string>
#include <vector>

// %%
class DocumentElement;

// %%
class DocumentBuilder
{
public:
    DocumentBuilder& addTitle(const std::string& title);
    DocumentBuilder& addHeader(const std::string& header);
    DocumentBuilder& addParagraph(const std::string& paragraph);
    std::string getMarkdown() const;
    std::string getHtml() const;

private:
    std::vector<std::unique_ptr<DocumentElement>> elements;
};

// %%
class DocumentElement
{
public:
    DocumentElement() = default;
    DocumentElement(const DocumentElement&) = delete;
    DocumentElement& operator=(const DocumentElement&) = delete;
    DocumentElement(DocumentElement&&) = delete;
    DocumentElement& operator=(DocumentElement&&) = delete;
    virtual ~DocumentElement() = default;

    virtual std::string getMarkdown() const = 0;
    virtual std::string getHtml() const = 0;
};

// %%
class Title : public DocumentElement
{
public:
    Title(const std::string& title) : title(title) {}
    std::string getMarkdown() const override { return "# " + title + "\n"; }
    std::string getHtml() const override { return "<h1>" + title + "</h1>\n"; }

private:
    std::string title;
};

// %%
class Header : public DocumentElement
{
public:
    Header(const std::string& header) : header(header) {}
    std::string getMarkdown() const override { return "## " + header + "\n"; }
    std::string getHtml() const override { return "<h2>" + header + "</h2>\n"; }

private:
    std::string header;
};

// %%
class Paragraph : public DocumentElement
{
public:
    Paragraph(const std::string& paragraph) : paragraph(paragraph) {}
    std::string getMarkdown() const override { return paragraph + "\n"; }
    std::string getHtml() const override { return "<p>" + paragraph + "</p>\n"; }

private:
    std::string paragraph;
};

// %%
DocumentBuilder& DocumentBuilder::addTitle(const std::string& title)
{
    elements.push_back(std::make_unique<Title>(title));
    return *this;
}

// %%
DocumentBuilder& DocumentBuilder::addHeader(const std::string& header)
{
    elements.push_back(std::make_unique<Header>(header));
    return *this;
}

// %%
DocumentBuilder& DocumentBuilder::addParagraph(const std::string& paragraph)
{
    elements.push_back(std::make_unique<Paragraph>(paragraph));
    return *this;
}

// tags=["keep", "subslide"]
#include <sstream>

// %%
std::string DocumentBuilder::getMarkdown() const
{
    std::stringstream result;
    for (const auto& element : elements)
    {
        result << element->getMarkdown();
    }
    return result.str();
}

// %%
std::string DocumentBuilder::getHtml() const
{
    std::stringstream result;
    for (const auto& element : elements)
    {
        result << element->getHtml();
    }
    return result.str();
}

// %%
DocumentBuilder builder;

// %%
builder.addTitle("Builder Pattern")
    .addHeader("Introduction")
    .addParagraph("The builder pattern is a creational pattern.")
    .addParagraph("It is used to separate the construction of a complex object from "
                  "its representation.");

// %%
#include <iostream>

// %%
std::cout << builder.getMarkdown() << std::endl;

// %%
std::cout << builder.getHtml() << std::endl;

// %% [markdown]
//
// ## Builder and Fluent Interface
//
// - Builder Pattern is often combined with a fluent interface
// - Each of the methods returns a reference to the builder
// - Allows chaining of method calls

// %% [markdown]
//
// ## Builder and Named Arguments
//
// - C++ does not provide direct support for named arguments
// - Builder Pattern can be used as a replacement
// - Each method of the builder takes an argument
// - The original method is called with the builder or implemented as a method
//   of the builder

// %%
#include <iostream>

// %%
void sendRequest(
    std::string url, std::string method = "GET",
    std::map<std::string, std::string> headers = {},
    std::map<std::string, std::string> params = {}, std::string data = "",
    int timeout = 30
)
{
    std::cout << "Sending " << method << " request to " << url << "\n";
    std::cout << "Headers:\n";
    for (const auto& [key, value] : headers)
    {
        std::cout << "  " << key << ": " << value << "\n";
    }
    std::cout << "Parameters:\n";
    for (const auto& [key, value] : params)
    {
        std::cout << "  " << key << ": " << value << "\n";
    }
    std::cout << "Data: " << data << "\n";
    std::cout << "Timeout: " << timeout << " seconds.\n";
}

// %% [markdown]
//
// - The function `sendRequest` has many arguments that have the same type.
// - This makes it difficult to remember the order of the arguments.
// - Also, potentially many arguments with default value have to be specified if
//   only one or two should be changed.


// %%
sendRequest(
    "https://example.com", "POST", {{"Content-Type", "application/json"}}, {},
    "My Data", 60
);

// %%
// Change only the timeout....
sendRequest("https://example.com", "GET", {}, {}, "", 10);

// %% [markdown]
//
// - We can use a builder to simplify the construction of the request.
// - The arguments are replaced by calls to named methods.
// - The builder stores the configuration and creates the request.
// - This way we only have to specify the changed values.
// - The order of the arguments no longer matters.
// - The purpose of the arguments becomes clearer.
// - Unfortunately, a lot of code is necessary to define the builder.

// %%
class RequestBuilder
{
public:
    RequestBuilder& setUrl(const std::string& url);
    RequestBuilder& setMethod(const std::string& method);
    RequestBuilder& addHeader(const std::string& key, const std::string& value);
    RequestBuilder& addParam(const std::string& key, const std::string& value);
    RequestBuilder& setData(const std::string& data);
    RequestBuilder& setTimeout(int timeout);
    void send() const;

private:
    std::string url{"https://example.com"};
    std::string method{"GET"};
    std::map<std::string, std::string> headers;
    std::map<std::string, std::string> params;
    std::string data;
    int timeout{30};
};

// %%
RequestBuilder& RequestBuilder::setUrl(const std::string& url)
{
    this->url = url;
    return *this;
}

// %%
RequestBuilder& RequestBuilder::setMethod(const std::string& method)
{
    this->method = method;
    return *this;
}

// %%
RequestBuilder& RequestBuilder::addHeader(
    const std::string& key, const std::string& value
)
{
    headers[key] = value;
    return *this;
}

// %%
RequestBuilder& RequestBuilder::addParam(
    const std::string& key, const std::string& value
)
{
    params[key] = value;
    return *this;
}

// %%
RequestBuilder& RequestBuilder::setData(const std::string& data)
{
    this->data = data;
    return *this;
}

// %%
RequestBuilder& RequestBuilder::setTimeout(int timeout)
{
    this->timeout = timeout;
    return *this;
}

// %%
void RequestBuilder::send() const
{
    sendRequest(url, method, headers, params, data, timeout);
}

// %%
RequestBuilder request;
request.setUrl("https://example.com")
    .setMethod("POST")
    .addHeader("Content-Type", "application/json")
    .setData("My Data")
    .setTimeout(60)
    .send();

// %%
// Change only the timeout....
RequestBuilder{}.setTimeout(10).send();
