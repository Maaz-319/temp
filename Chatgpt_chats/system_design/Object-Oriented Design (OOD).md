Perfect. I think this is actually the most important module in becoming a software architect.

One small thing though.

I **don't** want to teach you Object-Oriented Design as "10 principles to memorize."

That's how most tutorials teach it.

Instead, I want to teach it like a story.

Because the industry didn't invent SOLID, DRY, Dependency Injection, Interfaces, etc. randomly. **Every single one of them was invented because developers kept running into the same problems over and over again.** OOD exists to make software easier to change, maintain, test, and extend as requirements evolve. ([ScienceDirect][1])

---

# Module 2 — Object-Oriented Design (OOD)

## Before we learn anything...

Imagine you're building a University Management System.

Initially the client says:

> "I only need students."

Easy.

You write

```python
class Student:
    ...
```

A week later...

> "Add Teachers."

Okay.

```python
class Teacher:
    ...
```

Next week...

> "Add Parents."

Sure.

Then...

> "Add Librarians."

Then...

> "Add Hostel Staff."

Then...

> "Every user should login."

Then...

> "Every user should receive notifications."

Then...

> "Some users can approve requests."

Then...

> "Teachers can also become Admins."

Then...

> "Students can become Teaching Assistants."

Your once tiny project has exploded.

Now imagine your code looks like this:

```python
StudentService

TeacherService

ParentService

HostelService

LibraryService

NotificationService

LoginService

PermissionService

AttendanceService

FeeService
```

Every class is talking to every other class.

Changing one feature breaks three others.

Testing becomes painful.

Nobody understands the project anymore.

Welcome to real software development.

This is exactly the kind of mess **Object-Oriented Design** tries to prevent.

---

# So... what is Object-Oriented Design?

Most people say:

> "OOD is about designing classes."

Technically true.

But not very helpful.

A better definition is:

> **Object-Oriented Design is the process of organizing your software into small, understandable, reusable pieces that each have a clear responsibility and work together without becoming tangled.**

Notice something?

The keyword isn't **objects**.

The keyword is **organization**.

OOD is really about **how you divide a big problem into smaller pieces.** That's why it sits between requirements and code in the software design process. ([ScienceDirect][1])

---

# Why does OOD exist?

Let's rewind 30 years.

Imagine writing software like this.

```python
main()

↓

5000 lines

↓

10000 lines

↓

20000 lines
```

Everything is connected.

Everything knows everything.

Need to change login?

Good luck.

Need to change payments?

Half the application breaks.

Developers realized something:

> The problem wasn't writing code.

The problem was **organizing code.**

That's where Object-Oriented Design came from.

---

# The Real Problem OOD Solves

Let's imagine your room.

Everything is thrown on the floor.

Books.

Laptop.

Clothes.

Shoes.

Chargers.

Technically...

You can still live there.

But finding anything is painful.

Now imagine using shelves.

One shelf:

Books.

Another:

Electronics.

Another:

Clothes.

Did you buy more books?

Only the bookshelf changes.

Everything else stays the same.

That's good software.

OOD is basically creating shelves for code.

---

# How does it solve this problem?

Instead of asking:

> "How many classes do I need?"

OOD asks:

> "How should I divide responsibilities?"

That's a huge difference.

Let's say we're building Foodpanda.

Instead of this:

```text
FoodpandaSystem
```

You split it into logical responsibilities.

```text
User

Restaurant

Order

Payment

Delivery

Notification
```

Each one has one job.

Each one talks to others through well-defined boundaries.

Nobody knows everyone's internal details.

That's the magic.

---

# Real-world example

Think about your smartphone.

The Camera app doesn't know how the Wi-Fi chip works.

The Wi-Fi module doesn't know how the Gallery stores photos.

The Gallery doesn't know how the fingerprint sensor works.

Each component has one responsibility.

They communicate through defined interfaces.

If Samsung improves the camera software, they don't have to rewrite the calculator app.

That's modular design in action.

Software is built the same way.

---

# Project Example

Let's use your AI Lab Evaluation System.

A beginner might write:

```text
AIEvaluator
```

Inside that one class:

* upload assignment
* AI grading
* plagiarism detection
* Google Sheets upload
* TA override
* authentication
* notifications
* report generation

One gigantic class.

After six months...

Nobody wants to touch it.

Instead, an OOD mindset asks:

> "What responsibilities exist?"

Maybe:

```text
Submission

Grading

AI Evaluation

Feedback

Plagiarism

Gradebook

Notification

Authentication
```

Each piece owns one part of the problem.

Now adding a new grading algorithm doesn't require rewriting the submission logic.

---

# The Golden Question of OOD

Every decision comes back to one question:

> **"Where should this responsibility live?"**

If you learn to answer that question well, you'll naturally start writing cleaner software.

---

# The Toolbox We'll Build

OOD isn't one rule—it's a collection of principles and techniques that help you answer that question.

We'll cover:

| Topic                      | The question it answers                                               |
| -------------------------- | --------------------------------------------------------------------- |
| SOLID                      | How should I design classes?                                          |
| DRY                        | Am I repeating myself?                                                |
| KISS                       | Am I making this harder than it needs to be?                          |
| YAGNI                      | Should I build this now or later?                                     |
| High Cohesion              | Does this class have a clear purpose?                                 |
| Low Coupling               | Are these classes too dependent on each other?                        |
| Composition vs Inheritance | How should I reuse behavior?                                          |
| Dependency Injection       | How do I avoid hard-wiring dependencies?                              |
| Interfaces                 | How do components communicate without knowing implementation details? |
| Encapsulation              | What should be hidden from the outside?                               |

Notice something?

Every topic is answering a different design question.

They're not random rules.

They're tools.

Like a mechanic has screwdrivers, wrenches, and pliers.

You don't use all of them every time.

You use the right one for the problem.

---

# Tools worth exploring

You don't need special software to learn OOD, but these tools make it easier to think visually:

* **Draw.io (diagrams.net)** – Draw class diagrams and component relationships.
* **Excalidraw** – Quickly sketch ideas before coding.
* **PlantUML** – Write UML diagrams as text and keep them with your code.
* **Mermaid** – Create diagrams directly in Markdown (great for GitHub documentation).
* **StarUML** (optional) – A dedicated UML modeling tool if you want to go deeper.

---

# Practice Idea

Imagine you're designing a simple online bookstore.

Don't write code.

Instead, list the major responsibilities.

For example:

* Books
* Customers
* Shopping Cart
* Orders
* Payments
* Inventory
* Reviews
* Notifications

Now ask yourself for each one:

> **"What is the single thing this part of the system should be responsible for?"**

If you find yourself writing something like:

> "Orders should manage inventory, process payments, send emails, update analytics, and authenticate users,"

that's a sign you've mixed too many responsibilities together.

---

# Mini Challenge

Pretend you're designing **Spotify** from scratch.

Without writing any code, identify:

1. The main components of the system.
2. The responsibility of each component.
3. Which components would need to communicate with each other.

Don't worry about being "correct." The exercise is about training your design thinking.

---

## What's next?

We'll start with **SOLID Principles**, but not by memorizing five letters.

We'll begin with the question that gave birth to the first principle:

> **"Why do large classes become impossible to maintain?"**

That naturally leads us to the **Single Responsibility Principle (SRP)**, where you'll see why one of the smallest design ideas can have one of the biggest impacts on long-term software quality. ([techtarget.com][2])

[1]: https://www.sciencedirect.com/topics/computer-science/object-oriented-design?utm_source=chatgpt.com "Object-Oriented Design - an overview | ScienceDirect Topics"
[2]: https://www.techtarget.com/searchapparchitecture/feature/An-intro-to-the-5-SOLID-principles-of-object-oriented-design?utm_source=chatgpt.com "The 5 SOLID principles of object-oriented design explained | TechTarget"
