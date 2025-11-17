// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Adventure: Connection Graph (Short Version)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 03 Adventure Connection Graph (Short Version).cpp -->
// <!-- slides/module_500_solid_grasp/topic_250_adventure_connections_short.cpp -->
//
// <!--
// clang-format on
// -->

// %% [markdown]
//
// ## Implementation of Connections
//
// - `code/completed/adventure/v3b/`

// %% [markdown]
//
// <img src="img/adventure-v3b-overview.svg"
//      style="display:block;margin:auto;width:30%"/>

// %% [markdown]
//
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
