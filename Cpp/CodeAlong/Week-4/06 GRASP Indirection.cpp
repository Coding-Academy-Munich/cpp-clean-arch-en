// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GRASP: Indirection</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 06 GRASP Indirection.cpp -->
// <!-- slides/module_500_solid_grasp/topic_530_grasp_indirection.cpp -->


// %% [markdown]
//
// # GRASP: Indirection
//
// <div>
// "Any problem in computer science can be solved by adding another level of
// indirection."
// <div style="float:right;">- David Wheeler</div>
// </div>
//
// <br>
// <div> "Except too many levels of indirection."
// <div style="float:right;">– N.N.</div>
// </div>

// %% [markdown]
//
// - How can we reduce the coupling between two objects?
// - We introduce another layer that decouples the two objects

// %% [markdown]
//
// ## Indirection
//
// - Very frequent pattern on every layer
//   - Operating system
//   - Virtual machines
//   - Polymorphic method calls
// - Testing:
//   - Indirections are seams that can be used for testing purposes
