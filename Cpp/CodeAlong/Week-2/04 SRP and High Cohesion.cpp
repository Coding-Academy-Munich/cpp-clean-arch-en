// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>SRP and High Cohesion</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 04 SRP and High Cohesion.cpp -->
// <!-- slides/module_500_solid_grasp/topic_260_srp_and_high_cohesion_intro_short.cpp -->


// %% [markdown]
//
// - Problem: Too much functionality in one class
// - Both SOLID and GRASP have a pattern for/against this

// %% [markdown]
//
// ## SOLID: Single Responsibility Principle (SRP)
//
// Alternative formulations:
//
// - A module should have one, and only one, reason to change
// - A module should be responsible to one, and only one, actor

// %% [markdown]
//
// - Example (from Clean Architecture):
//
// ```cpp
// class Employee {
// public:
//     void calculatePay();  // <-- Finance Department (CFO)
//     void reportHours();   // <-- Human Resources (COO)
//     void save();          // <-- Database Administrator (CTO)
// };
// ```

// %% [markdown]
//
// ## GRASP: High Cohesion
//
// ### Problem
//
// - How do we define classes that are focused, understandable, and maintainable?
//
// ### Solution
//
// - Assign responsibilities so that cohesion is high
// - Use this principle to evaluate design alternatives
//
// - As a side effect, coupling is reduced

// %% [markdown]
//
// ### What is Cohesion?
//
// Cohesion is a measure of how well different parts of an artifact fit together

// %% [markdown]
//
// ### High Cohesion
//
// - Simplifies development, reuse, testing, performance
//
// ### Low Cohesion
//
// - Makes it difficult to understand the code, to find places for changes
// - Leads to large classes and/or high coupling
// - Almost always has a **large negative effect**
// - Is **difficult to fix**

// %% [markdown]
//
// ### How do we recognize low cohesion?
//
// - Difficulties finding names
// - Many reasons for change
// - Code Smells:
//   - Divergent Change
//   - Shotgun Surgery

// %% [markdown]
//
// ### Related Topics
//
// - Layers/Hexagonal Architecture
// - SRP
// - Command/Query Separation (CQS)
// - Aspects (Separation of Concerns)
