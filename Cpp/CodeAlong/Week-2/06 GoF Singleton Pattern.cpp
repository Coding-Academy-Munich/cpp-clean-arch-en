// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GoF: Singleton Pattern</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 06 GoF Singleton Pattern.cpp -->
// <!-- slides/module_450_design_patterns/topic_250_singleton.cpp -->


// %% [markdown]
//
// ## Design problem: One instance of the game
//
// - The game needs multiple resources that should be accessible from different
//   subsystems
//   - System resources (screen/renderer)
//   - Game elements (characters, levels)
// - It should be ensured that each resource is created only once
//   and all subsystems access the same resource
// - Global variables?
// - Static attributes?
// - More flexible: A class that manages its single instance itself.

// %% [markdown]
//
// ### Intent
//
// Ensure a class has only one instance; provide a global point of access
// to it.

// %% [markdown]
//
// ### Motivation
//
// Some classes should have exactly one instance, e.g., classes that
// correspond to unique physical resources. This instance should be easily
// accessible. Singleton makes the class itself responsible for keeping
// track of its single instance.

// %% [markdown]
//
// ### Applicability
//
// Use the Singleton pattern when
// - there must be exactly one instance of a class, and it must be accessible to
//   clients from a well-known access point
// - the sole instance should be extensible by subclassing, and clients should
//   be able to use an extended instance without modifying their code.

// %% [markdown]
//
// ### Structure
//
// <img src="img/pat_singleton_trad.svg"
//      style="display:block;margin:auto;width:70%"/>

// %% [markdown]
//
// ### Implementation
//
// See `code/completed/singleton`.

// %%
#include <iostream>

// %%
namespace singleton
{
class SingletonNonThreadSafe
{
private:
    SingletonNonThreadSafe() = default;

    static SingletonNonThreadSafe* instance_;

public:
    static SingletonNonThreadSafe& instance();

    void some_business_logic()
    {
        // ...
    }
};
} // namespace singleton

// %%
namespace singleton
{
SingletonNonThreadSafe* SingletonNonThreadSafe::instance_{};
}

// %%
namespace singleton
{
SingletonNonThreadSafe& SingletonNonThreadSafe::instance()
{
    if (!instance_)
    {
        instance_ = new SingletonNonThreadSafe();
    }
    return *instance_;
}
} // namespace singleton

// %%
template <typename T>
void check_singleton(const T& s1, const T& s2)
{
    if (&s1 == &s2)
    {
        std::cout << "Singleton works, both variables contain the same instance."
                  << std::endl;
    }
    else
    {
        std::cout << "Singleton failed, variables contain different instances."
                  << std::endl;
    }
}

// %%
using namespace singleton;

// %%
SingletonNonThreadSafe& s1{SingletonNonThreadSafe::instance()};
SingletonNonThreadSafe& s2{SingletonNonThreadSafe::instance()};

// %%
check_singleton(s1, s2);

// %%
#include <mutex>

// %%
namespace singleton
{
class SingletonWithMutex
{
private:
    SingletonWithMutex() {}

    static SingletonWithMutex* instance_;
    static std::mutex mutex_; // <----

public:
    static SingletonWithMutex& instance();

    void some_business_logic()
    {
        // ...
    }
};
} // namespace singleton

// %%
namespace singleton
{
SingletonWithMutex* SingletonWithMutex::instance_{};
std::mutex SingletonWithMutex::mutex_{};
} // namespace singleton

// %%
namespace singleton
{
SingletonWithMutex& SingletonWithMutex::instance()
{
    std::lock_guard<std::mutex> lock{SingletonWithMutex::mutex_}; // <----
    if (!instance_)
    {
        instance_ = new SingletonWithMutex();
    }
    return *instance_;
}
} // namespace singleton

// %%
SingletonWithMutex& s3{SingletonWithMutex::instance()};
SingletonWithMutex& s4{SingletonWithMutex::instance()};

// %%
check_singleton(s3, s4);

// %% [markdown]
//
// ```cpp
// #include <mutex>
// #include <thread>
// ```

// %% [markdown]
//
// ```cpp
// class SingletonWithCallOnce
// {
// private:
//     SingletonWithCallOnce() {}
//     static SingletonWithCallOnce* instance_;
//     static std::once_flag flag_; // <----
//
// public:
//     static SingletonWithCallOnce& instance();
//     void some_business_logic() { /* ... */ }
// };
// ```

// %% [markdown]
//
// ```cpp
// SingletonWithCallOnce* SingletonWithCallOnce::instance_{};
// std::once_flag SingletonWithCallOnce::flag_{};
// ```

// %% [markdown]
//
// ```cpp
// SingletonWithCallOnce& SingletonWithCallOnce::instance()
// {
//     std::call_once(flag_, []() {
//         instance_ = new SingletonWithCallOnce();
//     });
//     return *instance_;
// }
// ```

// %% [markdown]
//
// ```cpp
// SingletonWithCallOnce& s5{SingletonWithCallOnce::instance()};
// SingletonWithCallOnce& s6{SingletonWithCallOnce::instance()};
// ```

// %% [markdown]
//
// ```cpp
// check_singleton(s5, s6);
// ```

// %% [markdown]
//
// ### Structure (Meyer's Singleton)
//
// <img src="img/pat_singleton.svg"
//      style="display:block;margin:auto;width:70%"/>

// %%
class Singleton
{
private:
    Singleton() {}
    // Delete copy and move operations...

public:
    static Singleton& instance()
    {
        static Singleton instance_{};
        return instance_;
    }

    void some_business_logic()
    {
        // ...
    }
};

// %%
Singleton& s7{Singleton::instance()};
Singleton& s8{Singleton::instance()};

// %%
check_singleton(s7, s8);

// %% [markdown]
//
// ### Consequences
//
// The *Singleton* has several benefits:
//
// - Controlled access to sole instance.
// - Lower number of global names.
// - Permits refinement of operations and representation.
// - Permits a variable number of instances.
// - More flexible than class operations.

// %% [markdown]
//
// ### Known uses
//
// - Java: `java.lang.Runtime` or `org.eclipse.core.runtime.Plugin`.
// - Many C++ applications implement their own Singleton classes for various
//   purposes.

// %% [markdown]
//
// ### Example
//
// <img src="img/pat_game_engine.svg"
//      style="display:block;margin:auto;width:70%"/>

// %%
#include <cstdint>
#include <iostream>
#include <memory>
#include <random>

// %%
class GraphicsDevice
{
public:
    GraphicsDevice() { std::cout << "GraphicsDevice created" << std::endl; }
    ~GraphicsDevice() { std::cout << "GraphicsDevice destroyed" << std::endl; }
};

// %%
class GameEngine
{
private:
    uint32_t audio_device_handle;
    bool level_loaded;
    bool characters_loaded;

    GameEngine();
    GameEngine(const GameEngine&) = delete;
    GameEngine& operator=(const GameEngine&) = delete;

public:
    static GameEngine& instance()
    {
        static GameEngine instance{};
        return instance;
    }

    uint32_t get_audio_device_handle() const { return audio_device_handle; }
    void load_level();
    void load_characters();
    void run();
};

// %%
uint32_t current_audio_device_handle{0};

// %%
GameEngine::GameEngine()
    : audio_device_handle(++current_audio_device_handle),
      level_loaded(false),
      characters_loaded(false)
{}

// %%
void GameEngine::load_level()
{
    std::cout << "Loading level..." << std::endl;
    level_loaded = true;
}

// %%
void GameEngine::load_characters()
{
    std::cout << "Loading characters..." << std::endl;
    characters_loaded = true;
}

// %%
void GameEngine::run()
{
    if (!level_loaded)
    {
        std::cerr << "Level not loaded\n";
        return;
    }
    if (!characters_loaded)
    {
        std::cerr << "Characters not loaded\n";
        return;
    }
    std::cout << "Running the game engine\n";
    // Reset variables for the next run
    level_loaded = characters_loaded = false;
}

// %%
void set_up_level()
{
    GameEngine& engine{GameEngine::instance()};
    engine.load_level();
    std::cout << "Setting up the game level\n";
}

// %%
void set_up_characters()
{
    GameEngine& engine{GameEngine::instance()};
    engine.load_characters();
    std::cout << "Setting up the game characters\n";
}

// %% [markdown]
//
// The order of calls to `set_up_level()` and `set_up_characters()` is
// random.

// %%
set_up_level();
set_up_characters();
GameEngine::instance().run();

// %%
GameEngine::instance().run();

// %%
set_up_characters();
set_up_level();
GameEngine::instance().run();

// %%
