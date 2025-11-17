// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GRASP: Polymorphism</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 10 GRASP Polymorphism.cpp -->
// <!-- slides/module_500_solid_grasp/topic_510_grasp_polymorphism.cpp -->


// %% [markdown]
//
// # GRASP: Polymorphism
//
// - Polymorphic operations describe similar (but not identical) behaviors that may
//   change depending on the type of an object
// - Typically no switch between behaviors during run-time

// %% [markdown]
//
// - (Dynamic) Polymorphism: Inheritance, virtual methods
//   - Very flexible
//   - Selection of functionality at run-time (dynamic type)
//   - Overhead in run-time and memory (measure with profiler!)
//   - Heterogeneous containers possible
// - Static Polymorphism: Templates
//   - Very efficient: No overhead
//   - Selection of functionality at compile-time (static type)
//   - Template types often spread throughout the whole program
//   - Heterogeneous containers not possible
// - Function pointers
//   - Less flexible than virtual methods, same run-time overhead
//   - Sometimes syntactically simpler, less code, lambda functions

// %% [markdown]
//
// ## Related: Type-hierarchy rules
//   - Isa-rule
//   - Only leaves are concrete
//   - Enforcement of invariants for subtypes by supertype
// - See also: LSP, Open/Closed principle

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
