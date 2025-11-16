// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>SRP: Solutions</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 13 SRP Solutions.cpp -->
// <!-- slides/module_500_solid_grasp/topic_280_srp_resolutions.cpp -->
//
//

// %% [markdown]
//
// ## Single Reason to Change?
//
// <img src="img/book_01.svg"
//      style="display:block;margin:auto;width:35%"/>

// %% [markdown]
//
// ## Violation of SRP
//
// <img src="img/book_02.svg"
//      style="display:block;margin:auto;width:60%"/>

// %%
#include <string>
#include <iostream>

// %%
class Book
{
public:
    Book(const std::string& title, const std::string& author, int pages)
        : title{title}, author{author}, pages{pages}
    {}

    void print() {
        // Lots of code that handles the printer
        std::cout << "Printing " << title << " to printer." << std::endl;
    }

    void save() {
        // Lots of code that handles the database
        std::cout << "Saving " << title << " to database." << std::endl;
    }

private:
    std::string title;
    std::string author;
    int pages;
}

// %%

// %%

// %%

// %% [markdown]
//
// ## Towards a resolution of the SRP violation (version 1a)
//
// Proposal by Robert C. Martin in Clean Architecture:
//
// <img src="img/book_resolution_1a_srp.svg"
//      style="display:block;margin:auto;width:40%"/>

// %%
class BookV1
{
public:
    BookV1(const std::string& title, const std::string& author, int pages)
        : title{title}, author{author}, pages{pages}
    {}

    std::string get_title() const { return title; }
    std::string get_author() const { return author; }
    int get_pages() const { return pages; }

private:
    std::string title;
    std::string author;
    int pages;
}

// %%
class BookPrinterV1a
{
public:
    BookPrinterV1a(const BookV1& book)
        : book{&book}
    {}

    void print() {
        // Lots of code that handles the printer
        std::cout << "Printing " << book->get_title() << " to printer." << std::endl;
    }

private:
    const BookV1* book;
}

// %%
class BookDatabaseV1a
{
public:
    BookDatabaseV1a(const BookV1& book)
        : book{&book}
    {}

    void save() {
        // Lots of code that handles the database
        std::cout << "Saving " << book->get_title() << " to database." << std::endl;
    }

private:
    const BookV1* book;
}

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Resolution of the SRP violation (version 1a with facade)
//
// <img src="img/book_resolution_1a_srp_facade.svg"
//      style="display:block;margin:auto;width:50%"/>

// %%
class BookPrinterFacadeV1a
{
public:
    BookPrinterFacadeV1a(const BookV1& book)
        : book_printer{book}, book_database{book}
    {}

    void print() {
        book_printer.print();
    }

    void save() {
        book_database.save();
    }

private:
    BookPrinterV1a book_printer;
    BookDatabaseV1a book_database;
}

// %%

// %%

// %%

// %% [markdown]
//
// ## Resolution of the SRP violation (version 1b)
//
// <img src="img/book_resolution_1_srp.svg"
//      style="display:block;margin:auto;width:50%"/>

// %%
class BookPrinterV1b
{
public:
    void print(const BookV1& book) {
        // Lots of code that handles the printer
        std::cout << "Printing " << book.get_title() << " to printer.\n";
    }
}

// %%
class BookDatabaseV1b
{
public:
    void save(const BookV1& book) {
        // Lots of code that handles the database
        std::cout << "Saving " << book.get_title() << " to database.\n";
    }
}

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Resolution of the SRP violation (version 1b with facade)
//
// <img src="img/book_resolution_1_srp_facade.svg"
//      style="display:block;margin:auto;width:50%"/>

// %%
class BookFacadeV1b {
public:
    BookFacadeV1b(const BookV1& book) : book{&book} {}

    void print() {
        book_printer.print(*book);
    }

    void save() {
        book_database.save(*book);
    }

private:
    const BookV1* book;
    BookPrinterV1b book_printer;
    BookDatabaseV1b book_database;
}

// %%

// %%

// %%

// %% [markdown]
//
// ## Resolution of the SRP violation (version 2)
//
// <img src="img/book_resolution_2_srp.svg"
//      style="display:block;margin:auto;width:60%"/>

// %%
#include <iostream>
#include <string>

// %%
template <typename T>
class BookPrinterV2
{
public:
    void print(const T& book)
    {
        // Lots of code that handles the printer
        std::cout << "Printing " << book.get_title() << " to printer.\n";
    }
};

// %%
template <typename T>
class BookDatabaseV2
{
public:
    void save(const T& book)
    {
        // Lots of code that handles the database
        std::cout << "Saving " << book.get_title() << " to database.\n";
    }
};

// %%
class BookV2a
{
public:
    BookV2a(const std::string& title, const std::string& author, int pages)
        : title{title}, author{author}, pages{pages}
    {}

    std::string get_title() const { return title; }
    std::string get_author() const { return author; }
    int get_pages() const { return pages; }
    void print() { book_printer.print(*this); }
    void save() { book_database.save(*this); };

private:
    std::string title;
    std::string author;
    int pages;
    BookPrinterV2<BookV2a> book_printer;
    BookDatabaseV2<BookV2a> book_database;
}

// %%

// %%

// %%

// %%
#include <memory>

// %%
class BookV2
{
public:
    BookV2(const std::string& title, const std::string& author, int pages,
           std::shared_ptr<BookPrinterV2<BookV2>> book_printer,
           std::shared_ptr<BookDatabaseV2<BookV2>> book_database);

    std::string get_title() const { return title_; }
    std::string get_author() const { return author_; }
    int get_pages() const { return pages_; }
    void print() { book_printer_->print(*this); }
    void save() { book_database_->save(*this); }

private:
    std::string title_;
    std::string author_;
    int pages_;
    std::shared_ptr<BookPrinterV2<BookV2>> book_printer_;
    std::shared_ptr<BookDatabaseV2<BookV2>> book_database_;
}

// %%
BookV2::BookV2(const std::string& title, const std::string& author, int pages,
       std::shared_ptr<BookPrinterV2<BookV2>> book_printer,
       std::shared_ptr<BookDatabaseV2<BookV2>> book_database)
    : title_(title), author_(author), pages_(pages)
    , book_printer_(std::move(book_printer)), book_database_(std::move(book_database))
{}

// %%

// %%

// %%

// %% [markdown]
//
// ## Comparison
//
// <div>
// <img src="img/book_resolution_1a_srp.svg"
//      style="float:left;padding:5px;width:40%"/>
// <img src="img/book_resolution_2_srp.svg"
//      style="float:right;padding:5px;width:50%"/>
// </div>

// %% [markdown]
//
// ## Workshop: Weather App
//
// Imagine a versatile weather application called WeatherWise. WeatherWise
// provides its users with up-to-date weather information sourced from various
// online platforms. Beyond just showing current conditions, the app allows
// users to view the forecast in different visual formats, and it logs errors
// for any issues during data fetch or parsing.
//
// While WeatherWise is well-received for its features, the development team
// faces challenges maintaining and extending the application. Developers have
// noticed that the core class, `Weather`, is becoming increasingly complex. It
// handles everything from data fetching to data display. This complexity makes
// it challenging to introduce new features without risking the introduction of
// bugs.
//
// Your task: Refactor the `Weather` class, ensuring that each class in the
// system adheres to the Single Responsibility Principle. By doing so, you'll
// set the foundation for a more maintainable and scalable application.

// %% [markdown]
//
// ### Weather App Class Diagram
//
// <img src="img/weather_app_class.svg"
//      style="display:block;margin:auto;width:40%"/>

// %% [markdown]
//
// ### RunWeatherApp() Sequence Diagram
//
// <img src="img/weather_app_sequence.svg"
//      style="display:block;margin:auto;width:30%"/>

// %%
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// %%
class Weather
{
public:
    void FetchDataFromSource();
    void ParseData();
    void DisplayInFormatA();
    void DisplayInFormatB();
    void LogError(const std::string& errorMsg);
    std::string FormatData() const;

private:
    std::string rawData_;
    std::vector<double> data_;
};

// %%
void Weather::FetchDataFromSource()
{
    // Simulating fetching data from some source
    rawData_ = "Sunny, 25°C";
    std::cout << "Data fetched from source.\n";
}

// %%
void Weather::ParseData()
{
    // Simulate data parsing
    if (rawData_.empty()) {
        LogError("No data available");
        return;
    }
    data_ = {10.0, 12.0, 8.0, 15.0, 20.0, 22.0, 25.0};
    std::cout << "Data parsed: " << FormatData() << "\n";
}

// %%
void Weather::DisplayInFormatA()
{
    // Simulating one display format
    if (data_.empty()) {
        LogError("No data available");
        return;
    }
    std::cout << "Format A: " << FormatData() << "\n";
}

// %%
void Weather::DisplayInFormatB()
{
    // Simulating another display format
    if (data_.empty()) {
        LogError("No data available");
        return;
    }
    std::cout << "Format B: === " << FormatData() << " ===\n";
}

// %%
void Weather::LogError(const std::string& errorMsg)
{
    // Simulating error logging
    std::cout << "Error: " << errorMsg << "\n";
}

// %%
std::string Weather::FormatData() const
{
    std::ostringstream stream;
    std::copy(
        data_.begin(), data_.end(), std::ostream_iterator<double>(stream, ", "));
    return stream.str();
}

// %%
void RunWeatherApp(bool introduceError = false)
{
    Weather w;
    w.FetchDataFromSource();
    if (!introduceError) {
        w.ParseData();
    }
    w.DisplayInFormatA();
    w.DisplayInFormatB();
}

// %%
RunWeatherApp();

// %%
RunWeatherApp(true);
