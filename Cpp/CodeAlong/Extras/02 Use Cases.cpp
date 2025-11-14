// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Use Cases</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 02 Use Cases.cpp -->
// <!-- slides/module_500_solid_grasp/topic_140_adventure_use_cases.cpp -->
//
//

// %% [markdown]
//
// ### Use Case 1: Initialize the Game
//
// **Scope:** Adventure Game
//
// **Actors:** Player


// %% [markdown]
//
// **Context of Use:** The player starts a new game or restarts a previous game.
//
// **Precondition:** Game software is loaded and running.
//
// **Trigger:** Player selects "New Game" or "Load Game" from the main menu.

// %% [markdown]
//
// **Main Success Scenario:**
// 1. Player chooses "New Game".
// 2. System initializes a new game world with default settings.
// 3. System places the pawn at a starting location.
// 4. Game presents the initial game state to the player.

// %% [markdown]
//
// **Success Guarantee:** Game is initialized and ready for the player to take a
// turn.
//
// **Minimal Guarantee:** Game state is stable and ready for any selectable action
// from the player.
//
// **Stakeholders and Interests:**
// - Player: Wants a smooth experience when starting or loading a game.


// %% [markdown]
//
// **Extensions:**
// 1a. Player chooses "Load Game".
// 1. System prompts the player to select a saved game.
// 2. Game loads the saved state.
//
// 2a. Error in loading saved game.
// 1. System displays an error message.
// 2. Player is taken back to the main menu.
//

// %% [markdown]
//
// ### Use Case 2: Main Game Loop
//
// **Scope:** Adventure Game
//
// **Actors:** Player, NPCs

// %% [markdown]
//
// **Context of Use:** Player interacts with the game, and NPCs act based on predefined logic.
//
// **Precondition:** Game is initialized.
//
// **Trigger:** Player begins their turn.

// %% [markdown]
//
// **Main Success Scenario:**
// 1. Player starts their turn by choosing an action (e.g., move, interact).
// 2. System processes the action.
// 3. NPCs take their respective turns based on game logic.
// 4. Game provides feedback to the player on the outcomes of all actions.
// 5. System checks for any game-over conditions.
// 6. Returns control to the player for the next turn.

// %% [markdown]
//
// **Success Guarantee:** Game loop proceeds smoothly, and the player always knows the outcome of their actions.
//
// **Minimal Guarantee:** Game state remains consistent and does not crash.
//
// **Stakeholders and Interests:**
// - Player: Expects a seamless gameplay experience without interruptions.

// %% [markdown]
//
// **Extensions:**
// 1a. Game-over condition is met (e.g., player's pawn reaches a particular objective, player's pawn loses all health).
// 1. System presents a game-over screen with relevant information (e.g., win/lose message, score).
// 2. Player is given options to restart or return to the main menu.
//
// 2a. Player chooses to save the game during their turn.
// 1. System pauses the game loop.
// 2. Player saves the game.
// 3. Game loop resumes.


// %% [markdown]
//
// ### Use Case 3: Player Takes a Turn
//
// **Scope:** Adventure Game
//
// **Actors:** Player

// %% [markdown]
//
// **Context of Use:** Player decides on an action during their turn.
//
// **Precondition:** Player's turn in the game loop.
//
// **Trigger:** System prompts the player for an action.

// %% [markdown]
//
// **Main Success Scenario:**
// 1. Player selects an action (e.g., move to a location, interact with an NPC, use an object).
// 2. System processes the action.
// 3. System provides feedback on the outcome of the action.
// 4. Player's turn ends.

// %% [markdown]
//
// **Success Guarantee:** Player's chosen action is executed, and feedback is provided.
//
// **Minimal Guarantee:** Game state remains consistent.
//
// **Stakeholders and Interests:**
// - Player: Expects their chosen actions to be executed accurately.

// %% [markdown]
//
// **Extensions:**
// 1a. Player chooses an invalid action (e.g., move to an inaccessible location).
// 1. System provides feedback indicating the invalid action.
// 2. Player is prompted to choose a valid action.
//
// 2a. Player chooses to access the game menu during their turn.
// 1. System pauses the game.
// 2. Player accesses options like saving, adjusting settings, or quitting.
// 3. Player returns to their turn after exiting the menu.
