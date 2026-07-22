Awesome. This is probably the most misunderstood topic in software engineering.

Most people learn Design Patterns like Pokémon cards.

> Factory ✔️
>
> Singleton ✔️
>
> Observer ✔️

They memorize definitions.

Then never know **when** to use them.

I don't want that to happen to you.

Instead, we're going to learn **why these patterns were invented.**

Once you understand the problems, you'll naturally recognize when a pattern fits.

---

# Module 3 — Design Patterns

## Let's start with a story...

Imagine you're a carpenter.

Every day someone asks for furniture.

One customer wants a chair.

Another wants a table.

Another wants a cupboard.

After years of building furniture, you notice something.

You keep solving the same problems.

* How do I make the legs strong?
* How do I attach drawers?
* How do I build doors?

Eventually you stop inventing new solutions every time.

You develop **standard techniques**.

Now whenever someone asks for a cupboard...

You don't start from zero.

You already know what works.

Software developers did exactly the same thing.

---

# What are Design Patterns?

The official definition is something like:

> A reusable solution to a recurring software design problem.

Let's make that much simpler.

> **A design pattern is a proven way of solving a problem that software developers have encountered thousands of times before.**

Notice something important.

It is **not code**.

It is **not a library**.

It is **not a framework**.

It's an **idea**.

Think of it as a blueprint.

Just like an architect has a blueprint for stairs.

The blueprint isn't the stairs.

It just tells you **how** to build them.

This idea became popular through the famous *Design Patterns: Elements of Reusable Object-Oriented Software* book by the "Gang of Four," which documented 23 recurring design solutions that engineers kept rediscovering across projects. ([Coursera][1])

---

# Why do Design Patterns exist?

Let's go back in time.

Imagine software development in the early days.

Developer A solves a problem.

Developer B solves the same problem differently.

Developer C invents another solution.

Developer D spends three weeks solving something that hundreds of people already solved.

Everyone keeps reinventing the wheel.

Eventually experienced engineers realized:

> "Wait... these problems keep repeating."

Not the applications.

The **design problems**.

So instead of writing books about code...

They documented the **solutions**.

That's where Design Patterns came from. They aren't language-specific tricks—they're shared solutions and a common vocabulary for discussing software design. ([DigitalOcean][2])

---

# The Real Problem Design Patterns Solve

Imagine every city invented its own traffic lights.

One city:

Red means Go.

Another:

Green means Stop.

Another:

Blue means Slow Down.

Driving would be chaos.

Instead...

The whole world agreed on common patterns.

Software is the same.

Instead of every team inventing a new way to solve common design problems...

We reuse solutions that have already proven themselves.

---

# So... should I always use a Design Pattern?

No.

And this is one of the biggest mistakes beginners make.

Patterns solve **recurring** problems.

If the problem doesn't exist...

Don't use the pattern.

Imagine buying a crane just to hang one picture frame.

Technically it works.

Practically...

It's ridiculous.

Patterns add structure.

Structure adds complexity.

Only add complexity when it solves a real problem.

Many experienced developers point out that overusing patterns makes code harder to maintain than the original problem. ([Reddit][3])

---

# Design Patterns are NOT Recipes

This is important.

Patterns don't say:

> Write these exact classes.

Instead they say:

> If you're facing **this kind of problem**, here's one proven way to solve it.

Think of cooking.

The recipe says

> Add salt.

It doesn't tell you

> Buy Himalayan pink salt from Store X.

Patterns work the same way.

They describe relationships and responsibilities, not exact implementations.

---

# A Real-World Example

Imagine Netflix.

Suppose they need to notify users when:

* A new episode is released
* Someone logs into your account
* Your payment fails
* Your subscription renews

They could write separate notification logic everywhere.

Instead, they use a common notification mechanism.

Whenever something important happens...

Interested components are informed.

Congratulations.

You've just seen the idea behind the **Observer Pattern**.

You didn't need to know the name first.

You understood the problem.

---

# Project Example

Let's use your AI Lab Evaluation System again.

Imagine you support multiple AI models.

Today:

* GPT
* Claude

Tomorrow:

* Gemini

Next month:

* Local Llama

A beginner writes:

```python
if model == "gpt":
    ...

elif model == "claude":
    ...

elif model == "gemini":
    ...
```

Every new model means changing the same code.

Eventually someone asks:

> "Can users choose their preferred grading model?"

Now the code becomes a giant `if-else` maze.

An experienced engineer recognizes:

> "I've seen this before."

There are multiple interchangeable algorithms.

That's exactly the kind of problem the **Strategy Pattern** was designed to solve.

Notice what happened.

You discovered the need for the pattern **before** learning its name.

That's how good software architects think.

---

# The Three Families of Design Patterns

The Gang of Four grouped the 23 classic patterns into three categories based on the kind of problem they solve. ([GeeksforGeeks][4])

---

## 1. Creational Patterns

Question they answer:

> **"How should I create objects?"**

Sometimes creating an object isn't as simple as writing:

```python
user = User()
```

Maybe the object:

* needs configuration,
* depends on the operating system,
* has optional settings,
* is expensive to create,
* belongs to a family of related objects.

That's where Creational Patterns help.

Patterns:

* Factory
* Abstract Factory
* Builder
* Singleton

Think of them as different ways of **manufacturing** objects.

---

## 2. Structural Patterns

Question they answer:

> **"How should these objects fit together?"**

Imagine Lego.

The bricks already exist.

Now you need to connect them.

That's structural design.

Patterns:

* Adapter
* Facade
* Decorator
* Composite
* Proxy

They focus on organizing relationships between existing components.

---

## 3. Behavioral Patterns

Question they answer:

> **"How should objects communicate?"**

Software isn't just objects.

Objects need to:

* notify each other,
* delegate work,
* change behavior,
* send requests,
* collaborate.

Behavioral patterns organize those interactions.

Patterns:

* Observer
* Strategy
* Command
* State
* Chain of Responsibility
* Mediator
* Template Method

---

# A Different Way to Remember Them

Don't memorize the names.

Remember the questions.

| Category   | Question                           |
| ---------- | ---------------------------------- |
| Creational | How do I create this object?       |
| Structural | How do these objects fit together? |
| Behavioral | How do these objects communicate?  |

If you remember those three questions...

You'll naturally know where each pattern belongs.

---

# Where You'll See Them

Once you start looking, you'll realize design patterns are everywhere:

* **Spring** uses Factory, Proxy, Dependency Injection, and Template Method.
* **React** uses ideas similar to Observer through state updates and event-driven rendering.
* **Java Collections** use the Strategy pattern for sorting with custom comparators.
* **Java's** `ExecutorService` is an example of the Command pattern.
* **Python's** logging module uses ideas similar to Singleton and Factory.
* Many ORMs and web frameworks rely on Facade and Proxy internally.

You often use these patterns **without realizing it** because frameworks hide much of the implementation.

---

# Tools Worth Exploring

You don't need special software to *use* design patterns, but these resources are fantastic for learning and visualizing them:

* **PlantUML** – Draw class diagrams for each pattern.
* **Mermaid** – Create UML diagrams in Markdown.
* **Refactoring.Guru** – One of the best interactive explanations of design patterns with examples.
* **Head First Design Patterns** – A beginner-friendly book that focuses on understanding rather than memorization.
* **Draw.io (diagrams.net)** – Sketch relationships between classes before writing code.

---

# Practice Idea

Imagine you're building an e-commerce website.

List 10 situations where you think you'll face a design problem.

For example:

* Multiple payment methods
* Multiple shipping providers
* Email and SMS notifications
* Discount calculation
* Authentication providers
* Different report formats

Don't worry about the pattern names.

Just write down the problems.

Later, as we learn each pattern, you'll come back to this list and say:

> "Ah... this is a Strategy."

or

> "This is definitely a Factory."

That's exactly how experienced developers think.

---

# Mini Challenge

Take one application you use every day—Spotify, YouTube, GitHub, or WhatsApp.

Ask yourself:

1. Where might it need different interchangeable algorithms?
2. Where does it notify users about events?
3. Where does it hide a complex subsystem behind a simple interface?
4. Where might object creation be more complicated than calling a constructor?

Don't try to identify the exact pattern yet.

Train yourself to recognize **the problem first**.

---

# The Most Important Lesson

Here's something I wish every beginner learned earlier.

> **Senior engineers don't memorize patterns. They recognize problems.**

When they hear:

> "We need multiple payment providers."

They think:

> "I've seen this kind of problem before."

When they hear:

> "Users can switch between AI models."

They think:

> "This sounds familiar."

The pattern becomes obvious because they've learned to identify recurring design problems.

That's the skill we're building.

---

## What's next?

We'll start with the **Factory Pattern**—not by saying *"it's a creational pattern."*

Instead, we'll begin with a simple question:

> **"Why would creating an object ever be complicated?"**

Once that question makes sense, the Factory Pattern will feel like an obvious solution instead of another definition to memorize.

[1]: https://www.coursera.org/articles/gang-of-four-design-patterns?utm_source=chatgpt.com "Gang of Four Design Patterns - A Guide to Object-Oriented Design | Coursera"
[2]: https://www.digitalocean.com/community/tutorials/gangs-of-four-gof-design-patterns?utm_source=chatgpt.com "Gang of 4 Design Patterns Explained: Creational, Structural, and Behavioral | DigitalOcean"
[3]: https://www.reddit.com/r/learnprogramming/comments/vm69ba?utm_source=chatgpt.com "Design Patterns?"
[4]: https://www.geeksforgeeks.org/system-design/gang-of-four-gof-design-patterns/?utm_source=chatgpt.com "Gang of Four (GOF) Design Patterns - GeeksforGeeks"
