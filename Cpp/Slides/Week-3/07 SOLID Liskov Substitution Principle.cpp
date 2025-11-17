// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>SOLID: Liskov Substitution Principle</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 07 SOLID Liskov Substitution Principle.cpp -->
// <!-- slides/module_500_solid_grasp/topic_350_solid_lsp.cpp -->
//
// <!--
// clang-format on
// -->

// %% [markdown]
//
// # SOLID: Liskov Substitution Principle
//
// It should always be possible to substitute an object of a subclass for an
// object of its parent class.

// %% [markdown]
//
// ## LSP Violation

// %%
#include <iostream>

// %%
class Rectangle {
protected:
    float length;
    float width;

public:
    Rectangle(float l, float w) : length{l}, width{w} {}

    virtual float Area() { return length * width; }

    virtual float GetLength() const { return length; }
    virtual void SetLength(float l) { length = l; }

    virtual float GetWidth() const { return width; }
    virtual void SetWidth(float w) { width = w; }
};

// %%
class Square : public Rectangle {
public:
    Square(float l) : Rectangle{l, l} {}

    void SetLength(float l) override {
        length = l;
        width = l;
    }

    void SetWidth(float w) override {
        length = w;
        width = w;
    }
};

// %%
void ResizeRectangle(Rectangle& r) {
    r.SetLength(4);
    r.SetWidth(5);
    std::cout << "Length: " << r.GetLength() << ", Width: " << r.GetWidth()
              << ", Area: " << r.Area() << std::endl;
}

// %%
Rectangle r{3, 4};
ResizeRectangle(r);

// %%
Square s{3};
ResizeRectangle(s);
