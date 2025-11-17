// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GRASP: Pure Fabrication</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 16 GRASP Pure Fabrication.cpp -->
// <!-- slides/module_500_solid_grasp/topic_520_grasp_pure_fabrication.cpp -->


// %% [markdown]
//
// Which object do we give the responsibility for a task if e.g. Information
// Expert or Creator lead to solutions that are not good because they have low
// cohesion or high coupling?


// %% [markdown]
//
// # GRASP: Pure Fabrication
//
// - A class that does not appear in the domain model
// - Typically a counterweight to the Information Expert that wants to concentrate
//   functionality in a single class
// - Example:
//   - Database-functionality in domain classes
//   - Consistent with Information Expert
//   - But: low cohesion, high coupling
//   - Introduction of Data Access Objects (a pure fabrication)

// %% [markdown]
//
// ## Beware of excessive use
//
// - If pure fabrications are used too often, this can lead to a loss of the low
//   representational gap
// - Often this also reduces the cohesion of the domain classes
// - Especially developers with a background in procedural languages tend to
//   introduce a lot of "behavior objects" where responsibilities are *not*
//   co-located with the information needed for their fulfillment

// %% [markdown]
//
// ### Related Principles
//
// - Low Coupling, High Cohesion
// - Information Expert
//   - Pure Fabrication removes responsibilities assigned by Information Expert
// - Almost all Design Patterns are Pure Fabrications

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
