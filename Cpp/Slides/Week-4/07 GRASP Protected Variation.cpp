// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GRASP: Protected Variation</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 07 GRASP Protected Variation.cpp -->
// <!-- slides/module_500_solid_grasp/topic_540_grasp_protected_variations.cpp -->
//
//

// %% [markdown]
//
// Problem: How do we design components so that variation or evolution points don’t
// have an undesirable impact on other components?

// %% [markdown]
//
// ## Protected Variation
//
// Solution:
// - Identify the points where variation or evolution may occur
// - Introduce a stable interface protecting these points
// - These interfaces are frequently pure fabrications
// - Often these interfaces introduce an indirection

// %% [markdown]
//
// ## Protected Variations
//
// - Very frequently applied:
//   - Private attributes with getters/setters
//   - Interfaces, polymorphism
//   - Virtual Machines
//   - Standards
// - Testing:
//   - Protected Variations are often entry points for tests
//   - But often additional tests have to be written to ensure that the system
//     still works when the variability is actually used

// %% [markdown]
//
// - Protected Variation is a very general principle
// - Almost all other software development principles and patterns are special
//   cases of Protected Variation

// %% [markdown]
//
// ## Beware of excessive use
//
// - Protected Variation can support two different kinds of change:
//   - Variation points: Variants that exist in the existing system
//   - Evolution points: Speculative abstractions that are supposed to support
//     the future development of the system
// - Often the cost of speculative abstractions is higher than the cost of
//   introducing them later

// %% [markdown]
//
// ## Example: Strategy Pattern
//
// <img src="img/pat_strategy.svg"
//      style="display:block;margin:auto;width:80%"/>

// %% [markdown]
//
// ## Example: Template Method Pattern
//
// <img src="img/pat_template_method.svg"
//      style="display:block;margin:auto;width:40%"/>

// %% [markdown]
//
// ## Example: Adapter Pattern
//
// <img src="img/pat_adapter.svg"
//      style="display: block; margin: auto; width: 80%;"/>

// %% [markdown]
//
// ### Example: Command Pattern
//
// <img src="img/pat_command.svg"
//      style="display:block;margin:auto;width:70%"/>


// %% [markdown]
//
// ### Example: Pull Observer
//
// <img src="img/pat_observer_pull.svg"
//      style="display:block;margin:auto;width:100%"/>

// %% [markdown]
//
// ### Example: Push Observer
//
// <img src="img/pat_observer_push.svg"
//      style="display:block;margin:auto;width:100%"/>
