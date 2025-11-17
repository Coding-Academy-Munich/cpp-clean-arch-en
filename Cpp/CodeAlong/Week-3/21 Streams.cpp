// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Streams</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 21 Streams.cpp -->
// <!-- slides/module_160_raii/topic_100_streams.cpp -->
//
//

// %% [markdown]
//
// ### Input and output streams
//
// - `std::ostream` converts data to characters
//   - `operator<<()`
// - `std::istream` converts characters to data
//   - `operator>>()`
//   - `std::getline()`
// - `std::iostream` converts in both directions

// %% [markdown]
//
// ### Classes for output streams
//
// - [`std::ostream`](https://en.cppreference.com/w/cpp/io/basic_ostream) is the
//   base class for all output streams
// - [`std::ofstream`](https://en.cppreference.com/w/cpp/io/basic_ofstream) is
//   an output stream for files
// - [`std::ostringstream`](https://en.cppreference.com/w/cpp/io/basic_ostringstream)
//   is an output stream for strings


// %% [markdown]
//
// ### Classes for input streams
//
// - [`std::istream`](https://en.cppreference.com/w/cpp/io/basic_istream) is the
//   base class for all input streams
// - [`std::ifstream`](https://en.cppreference.com/w/cpp/io/basic_ifstream) is
//   an input stream for files
// - [`std::istringstream`](https://en.cppreference.com/w/cpp/io/basic_istringstream)
//   is an input stream for strings

// %% [markdown]
//
// ### Predefined streams
//
// - `std::cin` is a global input stream
// - `std::cout` is a global output stream
// - `std::cerr` is a global output stream for error messages
// - `std::clog` is a global output stream for log messages

// %%
#include <iostream>

// %%
std::cout << "Hello World!\n";

// %% [markdown]
//
// - Streams have state
// - With manipulators you can e.g. change the output format or force a write of
//   the buffer

// %%
#include <iomanip>

// %%
std::cout << std::hex << 42 << std::endl;

// %% [markdown]
//
// ### States of streams
//
// Streams have methods that can be used to query their state:
//
// - `good()`: `true` if no error occurred, I/O possible
// - `eof()`: `true` if the end of the stream has been reached
// - `fail()`, `bad()`: `true` if an error occurred
// - `operator bool()`: `true` if no error occurred
//
// The linked
// [table](https://en.cppreference.com/w/cpp/io/ios_base/iostate) shows the
// exact meaning of the states

// %%
void print_stream_state(const std::istream& is)
{
    std::cout << std::boolalpha
              << "good: " << is.good() << "\n"
              << "eof:  " << is.eof() << "\n"
              << "fail: " << is.fail() << "\n"
              << "bad:  " << is.bad() << "\n";
}

// %%
#include <sstream>

// %%
std::istringstream iss("Hello World!\n");
std::string line;

// %%
print_stream_state(iss);

// %%
std::getline(iss, line);

// %%
print_stream_state(iss);

// %%
std::getline(iss, line);

// %%
print_stream_state(iss);

// %% [markdown]
//
// - With `clear()` you can reset the state
// - With `setstate()` you can set individual bits in the state

// %%
iss.clear();

// %%
print_stream_state(iss);

// %% [markdown]
//
// ## Guidelines for streams
//
// - [CG: SL.io.3: Prefer `iostreams` for
//   I/O](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slio3-prefer-iostreams-for-io)
// - [CG: SL.io.10: Unless you use printf-family functions call
//   ios_base::sync_with_stdio(false)](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slio10-unless-you-use-printf-family-functions-call-ios_basesync_with_stdiofalse)
// - [CG: SL.io.50: Avoid
//   endl](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slio50-avoid-endl)
