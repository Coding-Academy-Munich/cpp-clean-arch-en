// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Workshop: Introduction</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 07 Workshop Introduction.cpp -->
// <!-- slides/module_500_solid_grasp/topic_200_library_workshop_intro.cpp -->


// %% [markdown]
//
// # Library Management System
//
// - System for managing users and media inventory in libraries
// - For both librarians and users
// - Activities: Registration, search, borrowing, returning, fine payments
// - Searching for media in other libraries and online repositories
// - Recommendations for users
// - Different interfaces (web, app, terminal)

// %% [markdown]
//
// - What could the domain model for such a system look like?
// - What concepts are there?
// - What use cases are there?

// %% [markdown]
//
// ## Domain Model: Concepts
//
// - Media
//   - Books, videos, music, ...
//   - Different metadata for different media
// - Users
//   - Members, visitors, possibly different types of members
//   - Different types of memberships: children, students, seniors, ...
//   - Different privileges
//   - Activities: borrowing media, returning, fine payments
// - Librarians
//   - Managing users and media
//   - Activities: registration, search, borrowing, returning, fine payments

// %% [markdown]
//
// ## Activities (Librarian)
//
// - Managing members (registration, deletion, search, modification, ...)
// - Managing media (adding, deleting, searching, modification ...)
// - Borrowing and returning media (library side)
// - Triggering reminders, fine payments
// - Displaying previous activities (adding, borrowing, ...) for all users

// %% [markdown]
//
// ## Activities (User)
//
// - Registration, deregistration, notification of address changes
// - Searching for media
// - Borrowing and returning media (user side)
// - Displaying previous activities (borrowing, returns, fine payments) for the user

// %% [markdown]
//
// ## The Starter Kit
//
// - `code/starter_kits/library_sk`
// - CMake project with library, main program, and applications

// %% [markdown]
//
// ## Mini-Workshop: Library Management System
//
// - Try to compile and run the starter kit.
// - Add a class `Book` that has an attribute `title`.
// - Add a Getter for the `title` attribute.
// - Write a test that checks that the getter works.
// - Create a book in the main program and print its title.
// - Remove the dummy class `DeleteMe` and its tests. Ensure that you can still
//   build the project and run the main program and tests.
//
// **Note**: Of course this is not a meaningful test, it is just to get you
// familiar with the infrastructure we use in this course.
