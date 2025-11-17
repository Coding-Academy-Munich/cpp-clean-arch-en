// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Adventure: Command Pattern</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 10 Adventure Command Pattern.cpp -->
// <!-- slides/module_500_solid_grasp/topic_380_adventure_commands.cpp -->


// %% [markdown]
//
// ## Previous Version: Pawns with enumeration
//
// <img src="img/adventure-v4b-overview.svg" alt="Adventure Version 4b"
//      style="display:block;margin:auto;height:80%"/>


// %% [markdown]
//
// ### Problems
//
// - Open-Closed Principle violated
//   - New actions require changes to `Pawn` and `Action`
// - Signature of `Pawn::Perform` is not clear
//   - Different actions require different parameters
//   - Option: parameter of type `std::variant`, but that has many problems

// %% [markdown]
//
// - Actions are moved into their own classes
// - `Pawn::Perform()` takes a pointer to an `Action` object
// - The data needed to perform the action is stored in the `Action` object
// - `Action` objects can provide additional features, e.g. to provide text for
//   the UI


// %% [markdown]
//
// ## Version 4c: Command Pattern
//
// <img src="img/adventure-v4c-overview.svg" alt="Adventure Version 4b"
//      style="display:block;margin:auto;height:80%"/>

// %% [markdown]
//
// - Open-Closed Principle is respected
// - `Pawn::Perform` has a clear signature
// - `Action` classes can provide additional features
