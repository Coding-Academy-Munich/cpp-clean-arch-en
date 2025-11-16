// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Final Workshop</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 13 Final Workshop.cpp -->
// <!-- slides/module_500_solid_grasp/ws_200_library.cpp -->
//
// <!--
// clang-format on
// -->

// %% [markdown]
//
// # Library Management System
//
// - In week 1 we looked at the domain model of a library management system
// - In this workshop we want to apply the GRASP and SOLID principles, as well
//   as GoF design patterns, to create an implementation
// - Starter code is in `cpp_private/code/starter_kits/library_sk`

// %% [markdown]
//
// ## Books and Members
//
// - Implement the classes `Book` and `Member` with the attributes from the
//   domain model (see the slides from week 1)
// - Note:
//   - The library can have multiple copies of a book. Design the system so that
//     the information about title, authors, etc. is only stored once for all
//     copies
//   - How do you treat ownership of books?
//   - Later there will be different types of members. Design the system so that
//     it is open to extension with new types of members
//   - At the moment all members should be regular members

// %% [markdown]
//
// ## Adding Books
//
// - Implement the ability to add books to the system
// - This action should be possible from an external system and is part of the
//   external API of the library system
// - Who gets the responsibility for this functionality?
// - Which patterns help you with the decision?

// %% [markdown]
//
// ## Finding Books
//
// - Implement the ability to find books
// - This ability should also be part of the external API
// - Who gets the responsibility for this functionality?
// - Which patterns help you with the decision?

// %% [markdown]
//
// ## Registering and finding members
//
// - Implement the ability to register and find members
// - The same considerations apply as for books
// - Does the implementation of members create a duplication of code?
// - If so, what options do you have to eliminate it?

// %% [markdown]
//
// ## Borrowing books
//
// - Implement the ability to borrow books
// - This action should be possible from an external system and is part of the
//   external API of the library system
// - The type of user is decisive for the number of books that can be borrowed
//   and the loan period
//   - Regular members can borrow 3 books for 4 weeks
//   - Premium members can borrow 5 books for 6 weeks
//   - Students can borrow 5 books for 2 weeks

// %% [markdown]
//
// ## Returning books
//
// - Implement the ability to return books
// - This action should be possible from an external system and is part of the
//   external API of the library system
// - A fee should be charged for late return of books
//   - Regular members pay 1€ per day
//   - Premium members pay 0.5€ per day
//   - Students pay 0.5€ per day

// %% [markdown]
//
// ## Notification of borrowed books
//
// - Extend the system to periodically send messages to members who have borrowed
//   books
// - A reminder should be sent one week before the loan period expires
// - Another reminder should be sent the day before the loan period expires
// - A reminder should be sent the day after the loan period expires
// - It should be possible to send different types of messages (SMS, email, ...)

