// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>RAII</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 22 RAII.cpp -->
// <!-- slides/module_160_raii/topic_110_raii.cpp -->


// %% [markdown]
//
// ## Resource Acquisition Is Initialization (RAII)
//
// Schema for resource management in C++
//
// - Resources are acquired in constructors
// - Resources are released in destructors
//
// Resource management is thus automatic

// %% [markdown]
//
// - Heap memory is allocated in the constructor
// - Heap memory is released in the destructor
// - Copy-control operations must manage the resources correctly

// %% [markdown]
//
// - [P.8: Don’t leak any
//   resources](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#p8-dont-leak-any-resources)
// - [R.1: Manage resources automatically using resource handles and RAII
//   (Resource Acquisition Is
//   Initialization)](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r1-manage-resources-automatically-using-resource-handles-and-raii-resource-acquisition-is-initialization)
// - [E.6: Use RAII to prevent
//   leaks](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#e6-use-raii-to-prevent-leaks)


// %% [markdown]
//
// ## Example: Files
//
// - [Filesystem](https://en.cppreference.com/w/cpp/filesystem) library for file
//   operations (C++17)
// - Input and output via streams

// %% [markdown]
//
// ### RAII for files
//
// - File is opened in the constructor
// - File is closed in the destructor
//
// Resource management is thus automatic

// %%
// !ls /tmp

// %%
#include <fstream>
#include <iostream>

// %%
{
    std::ifstream file{"/tmp/test.txt"};
    if (file) {
        std::cout << "File exists!\n";
    } else {
        std::cout << "Could not open file!\n";
    }
}

// %%
{
    std::ofstream file{"/tmp/test.txt"};
    file << "Hello World!\n";
}

// %%
// !ls /tmp

// %%
{
    std::ifstream file{"/tmp/test.txt"};
    if (file) {
        std::string line;
        std::getline(file, line);
        if (file) {
            std::cout << "Line is: " << line << "\n";
        } else {
            std::cout << "Could not read line!\n";
        }
    } else {
        std::cout << "Could not open file!\n";
    }
    // file is closed here
}

// %% [markdown]
//
// - Vectors can be copied, memory is duplicated
// - With other resources this is not always possible
//   - Files
//   - Mutexes
//   - Threads
//   - ...

// %%
#include <fstream>

// %%
{
    std::ofstream file1{"/tmp/test.txt"};
    // std::ofstream file2{file1};
}


// %%
{
    std::ofstream file1{"/tmp/test.txt"};
    std::ofstream file2{std::move(file1)};

    if (!file1.is_open()) {
        std::cout << "file1 is closed\n";
    }
    if (file2.is_open()) {
        std::cout << "file2 is open\n";
    }
}

// %%
#include <filesystem>

// %%
std::filesystem::exists("/tmp/test.txt");

// %%
std::filesystem::path file{"/tmp/test.txt"};

std::cout << "stem = " << file.stem() << ", ext = " << file.extension() << "\n";

// %%
std::filesystem::remove(file);

// %%
std::filesystem::exists(file);

// %%
// !ls /tmp

// %% [markdown]
//
// ## Mini Workshop: RAII Integer on the Heap
//
// - Write a class `IntOnHeap` that manages an `int` value on the heap
// - A constructor should receive an `int` value and allocate it on the heap
// - A destructor should release the value again
// - Implement copy-control operations that ensure the correct behavior
//   - Copying should not be allowed
//   - Moving should be possible
// - Implement a method `get` that returns the value
// - Implement a method `set` that changes the value

// %%
#include <iostream>
#include <string>

using namespace std::string_literals;

// %%

// %%
