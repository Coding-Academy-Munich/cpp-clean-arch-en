// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Adventure: Pawn</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 09 Adventure Pawn.cpp -->
// <!-- slides/module_500_solid_grasp/topic_320_adventure_pawn.cpp -->


// %% [markdown]
// <img src="img/adv-domain-03.svg"
//      style="display:block;margin:auto;width:50%"/>

// %% [markdown]
//
// ## Version 4a: Pawns
//
// <img src="img/adventure-v4a-overview.svg" alt="Adventure Version 4a"
//      style="display:block;margin:auto;height:80%"/>

// %% [markdown]
//
// See `code/completed/adventure/v4a` for the complete code.

// %% [markdown]
//
// ## Version 4b: Enumeration of actions
//
// - Enumeration `Action` with all possible actions
// - `Pawn` class only has a `Perform()` method
// - `Perform()` method gets an `action` as a parameter

// %% [markdown]
//
// ## Version 4b: Pawns with enumeration
//
// <img src="img/adventure-v4b-overview.svg" alt="Adventure Version 4b"
//      style="display:block;margin:auto;height:80%"/>

// %% [markdown]
//
// ```cpp
// enum class Action { Move, SkipTurn };
// ```
//
// ```cpp
// void Pawn::Perform(Action action, const std::string& direction)
// {
//     switch (action) {
//     case Action::Move:
//         location = &location->GetConnectedLocation(direction);
//         break;
//     case Action::SkipTurn:
//         break;
//     }
// }
// ```

// %% [markdown]
//
// ## GRASP and SOLID principles
//
// - GRASP:
//   - Protected Variation
//   - Polymorphism
//   - Indirection
// - SOLID:
//   - Open-Closed Principle
