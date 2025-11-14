// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Adventure: Connection Graph</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 10 Adventure Connection Graph.cpp -->
// <!-- slides/module_500_solid_grasp/topic_250_adventure_connections.cpp -->


// %% [markdown]
//
// - We now want to implement the connections between the rooms

// %% [markdown]
//
// - `code/completed/adventure/v3b/`
// - How would you rate this implementation?
//   - What is good?
//   - What should we improve?

// %% [markdown]
//
// - Generally, the structure is good
// - A potential problem is that we are moving a lot of work into the
//   `World` class
// - This is typical when we apply "Information Expert"
// - We need an "antagonist" for this pattern

// %% [markdown]
//
// ## Workshop: Library Management
//
// - Implement the first two Activities of the Library case study using the
//   patterns we've heard about so far, i.e., implement "Registering a New
//   Member" and "Searching for Members" by applying Creator and Information
//   Expert (and taking into account the principle of low representational gap).
//
// - Do the same for the "Adding a Book" and "Searching for Books" activities.
//
// You can focus on the core functionality of the activities, i.e., the objects
// in the Domain Model that are affected by the activities, and ignore aspects
// such as access control or user interface.
