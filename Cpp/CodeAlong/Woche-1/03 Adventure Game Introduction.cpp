// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Adventure Game: Introduction</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 03 Adventure Game Introduction.cpp -->
// <!-- slides/module_500_solid_grasp/topic_120_adventure_intro.cpp -->


// %% [markdown]
//
// # Example: Adventure Game
//
// - The player controls a game character
// - The character can move through a world consisting of interconnected
//   locations
// - In some locations there are objects the player can interact with
// - In the world there are characters controlled by the computer (NPCs)
// - The player can interact with NPCs (e.g. talk, fight, trade)

// %% [markdown]
//
// - See Game Pitch for details (`Extras` folder)
// - Design models as UML diagrams
//   - Important: Understanding of the domain
//   - Not important: Details of modeling, UML vs. ...
//   - Not important: Development process, ...

// %% [markdown]
//
// ## Domain Model: Static Structure

// %% [markdown]
// <img src="img/adv-domain-01.svg"
//      style="display:block;margin:auto;width:50%"/>

// %% [markdown]
// <img src="img/adv-domain-02.svg"
//      style="display:block;margin:auto;width:50%"/>

// %% [markdown]
// <img src="img/adv-domain-03.svg"
//      style="display:block;margin:auto;width:50%"/>

// %% [markdown]
//
// ## Domain Model: Behavior
//
// - Understanding behavior is important
// - Many ways to describe behavior
//   - Use Cases
//   - User Stories
//   - Activity Diagrams
//   - Sequence Diagrams
//   - ...

// %% [markdown]
//
// - We want to consider the following use cases for our game:
//   - Initialize the Game
//   - Main Game Loop
//   - Player Takes a Turn
