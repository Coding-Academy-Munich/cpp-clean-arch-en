// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GRASP: Information Expert</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 06 GRASP Information Expert.cpp -->
// <!-- slides/module_500_solid_grasp/topic_170_grasp_info_expert.cpp -->


// %% [markdown]
//
// - Use Case "Initialize Game"
// - So far:
//   - `World` and `Location` classes
//   - `World` creates all `Location` objects
// - Next step:
//   - Store information about the connection between the `Location` objects
//   - Helpful for this: Finding locations by their name
// - Question:
//   - Who finds `Location` objects by their name?

// %% [markdown]
//
// ## Candidates

// %% [markdown]
// <div style="float:left;margin:auto;padding:80px 0;width:25%">
// <ul>
// <li> <code>Player</code></li>
// <li> <code>Game</code></li>
// <li> <code>Pawn</code></li>
// <li> <code>World</code></li>
// </ul>
// </div>
// <img src="img/adv-domain-03-small.svg"
//      style="float:right;margin:auto;width:70%"/>

// %% [markdown]
//
// ## Information Expert (GRASP)
//
// ### Question
//
// To which class should we delegate a responsibility?
//
// ### Answer
//
// To the class that has the most information necessary to fulfill the
// responsibility.

// %% [markdown]
//
// ## Who is the Information Expert?

// %% [markdown]
// <div style="float:left;margin:auto;padding:80px 0;width:25%">
// <ul>
// <li> <strike><code>Player</code></strike></li>
// <li> <strike><code>Game</code></strike></li>
// <li> <strike><code>Pawn</code></strike></li>
// <li> <b><code>World</code></b></li>
// </ul>
// </div>
// <img src="img/adv-domain-03-small.svg"
//      style="float:right;margin:auto;width:70%"/>

// %% [markdown]
//
// - See `code/completed/adventure/v2/` for the project structure with tests
//   that corresponds to our current progress
// - `code/starter_kits/adventure_sk2/` contains a new starter kit that
//   represents the same development state in case you want to continue working
//   on the implementation of the adventure game yourself
