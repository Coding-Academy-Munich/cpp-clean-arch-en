// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GRASP: Controller</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 03 GRASP Controller.cpp -->
// <!-- slides/module_500_solid_grasp/topic_500_grasp_controller.cpp -->


// %% [markdown]
//
// # GRASP: Controller
//
// - For each module/subsystem: external messages are handled by Controller
//   objects that
//   - are not part of the UI
//   - cover one subsystem or use case each
// - The controller is the first object after the UI to handle events/messages.
//   It coordinates the system.
// - The controller is frequently a Façade, i.e., it delegates its work to other
//   objects.
// - A use-case controller always processes a complete use case (but controllers
//   can process more than one use case).

// %% [markdown]
//
// ## Controller
//
// - Related: Façade pattern (Domain Façade), Domain Controller
// - See Hexagonal Architecture: Controllers are the ports in the hexagonal architecture
// - Tests: Controller provide a central interface for single subsystems or use cases
