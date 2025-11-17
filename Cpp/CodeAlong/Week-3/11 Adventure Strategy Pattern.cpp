// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Adventure: Strategy Pattern</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 11 Adventure Strategy Pattern.cpp -->
// <!-- slides/module_500_solid_grasp/topic_390_adventure_strategy.cpp -->


// %% [markdown]
//
// ## Version 4c: Command Pattern
//
// <img src="img/adventure-v4c-overview.svg" alt="Adventure Version 4c"
//      style="display:block;margin:auto;height:80%"/>

// %% [markdown]
//
// - Human and computer-controlled players
// - To do:
//   - Generate all possible actions (depending on the situation)
//   - Select an action
//   - Perform the action
// - Who should get this responsibility?

// %% [markdown]
//
// - Information expert:
//   - At the moment, nobody knows all possible actions
//   - `Pawn` knows where it is
//   - For further actions:
//     - `Pawn` probably contains most of the required information
// - Should we give the responsibility to `Pawn`?

// %% [markdown]
//
// ### Counterarguments
//
// - `Pawn` potentially gets too many responsibilities
//   - Movement on the game board
//   - Display of graphics
//   - Strategy for computer-controlled players
//   - Interaction with human user
// - Low representational gap?

// %% [markdown]
//
// - Let's look at the domain model:

// %% [markdown]
// <img src="img/adv-domain-03.svg"
//      style="display:block;margin:auto;width:50%"/>

// %% [markdown]
//
// - `Player` is responsible for the strategy
// - We should introduce a `Player` class and give it the responsibility
//   for the new tasks


// %% [markdown]
//
// ## Version 5a: `Player` class
//
// <img src="img/adventure-v5a.svg" alt="Adventure Version 5a"
//      style="display:block;margin:auto;height:60%"/>

// %% [markdown]
//
// - `Player` class is responsible for the strategy
// - At the moment, only a hard-wired strategy:
//   - Player always takes the last entry in the list of actions
// - We want to support multiple strategies
// - With an "interactive" strategy, we want to involve the human player
// - Let's try an enumeration of all possible strategies

// %% [markdown]
//
// ## Version 5b: Multiple strategies
//
// <img src="img/adventure-v5b.svg" alt="Adventure Version 5b"
//      style="display:block;margin:auto;height:60%"/>

// %% [markdown]
//
// - The class diagram doesn't look too bad
// - Implementation is not well factored
// - Open-Closed principle is violated
// - Better: Strategy pattern


// %% [markdown]
//
// ## Version 5c: Multiple strategies
//
// <img src="img/adventure-v5c.svg" alt="Adventure Version 4b"
//      style="display:block;margin:auto;height:60%"/>

// %% [markdown]
//
// Next step: Improving the interactive strategy
