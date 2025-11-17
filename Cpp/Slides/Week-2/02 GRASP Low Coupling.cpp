// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GRASP: Low Coupling</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 02 GRASP Low Coupling.cpp -->
// <!-- slides/module_500_solid_grasp/topic_240_grasp_low_coupling.cpp -->


// %% [markdown]
//
// ## Low Coupling (GRASP)
//
// ### Question
//
// How can we minimize the negative impact of changes?
//
// ### Answer
//
// Assign responsibilities in such a way that (unnecessary) coupling is
// minimized

// %% [markdown]
//
// - Coupling: Dependency between two artifacts
// - [Different types of
//   coupling](https://en.wikipedia.org/wiki/Coupling_(computer_programming)
// - Low coupling is a general principle

// %% [markdown]
//
// ### Impact of coupling
//
// - If **A** is tightly coupled to **B** (**A → B**), then we cannot understand
//   and change **A** independently of **B**
// - This is transitive: If **A → B → C → D**, then we potentially have to
//   change **A**, **B**, and **C** if we make a change to **D**

// %% [markdown]
//
// ### Avoiding coupling
//
// - A certain degree of coupling is **unavoidable**
//   - Whenever two components work together, coupling arises
// - High coupling to **stable** components is typically not a problem
//   - Example: `std::vector`
// - Unwanted high coupling at the local level
//   - Is not good, but often not a big problem
//   - Can typically be fixed relatively easily
// - Unwanted high coupling at the global level
//   - Is very difficult to eliminate
//   - Should always be in focus during development

// %% [markdown]
//
// ### What indicates high coupling?
//
// - Long compile times for most changes
// - Shotgun Surgery
//   - Small changes in functionality require changes in many parts of the code
// - Divergent Change
//   - Many changes in functionality require changes in the same part of the
//     codebase
// - Law of Demeter
//   - A component should only communicate with components that it knows directly
//
// Typically, high coupling is also associated with low cohesion.

// %% [markdown]
//
// ### How can we avoid coupling?
//
// - GRASP:
//   - Creator, Information Expert
//   - Pure Fabrication, Indirection, Protected Variations
// - SOLID: Single Responsibility Principle, Dependency Inversion Principle
