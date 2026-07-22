# Design Patterns — Part 1: Creational Patterns

Before learning the individual patterns, understand **why Creational Patterns exist.**

Imagine you're building a large application.

At first, creating objects is easy.

```python
user = User()
db = MySQLDatabase()
payment = StripePayment()
```

Life is good.

But after a few months...

* Some objects need 20 configuration values.
* Some objects depend on environment (Dev/Prod).
* Some objects should only exist once.
* Some objects should change based on user choice.
* Some objects require many initialization steps.

Now object creation itself becomes a problem.

**Creational Design Patterns solve problems around object creation.**

Instead of scattering `new` or constructors everywhere, they centralize and control how objects are created, reducing coupling and making software easier to extend and maintain. ([Baeldung on Kotlin][1])

---

# 1. Factory Pattern (Factory Method)

## What problem does it solve?

Imagine you're making an e-commerce website.

Users can pay using

* Stripe
* PayPal
* JazzCash
* Easypaisa
* Bank Transfer

Without Factory:

```python
if payment == "stripe":
    processor = StripePayment()

elif payment == "paypal":
    processor = PaypalPayment()

elif payment == "jazzcash":
    processor = JazzCashPayment()

...
```

Now imagine this logic exists in 30 files.

Next week your boss says:

> "We're removing PayPal and adding Apple Pay."

Congratulations.

Now you're searching through your whole codebase.

That's exactly the problem Factory solves.

Factory centralizes object creation so the rest of your code doesn't need to know which concrete class to instantiate. ([Baeldung on Kotlin][1])

---

## Easy analogy

Imagine ordering coffee.

You don't tell the kitchen

> Grind beans

> Heat milk

> Steam milk

> Pour espresso

You simply say

> "One Latte please."

The cashier decides how to make it.

The cashier is the **Factory**.

---

## How it solves the problem

Instead of creating objects yourself,

you ask the Factory.

```
Me
 │
 │ "Give me payment processor"
 ▼
Factory
 │
 ├── Stripe
 ├── Paypal
 └── JazzCash
```

Your code doesn't care which one it gets.

---

## Real-world examples

Factory is literally everywhere.

### Django

Depending on configuration,

Django creates

* PostgreSQL connection
* SQLite connection
* MySQL connection

Your code doesn't instantiate those classes directly.

---

### Logging libraries

```python
logger = getLogger("App")
```

You don't create

```python
ConsoleLogger()

FileLogger()

CloudLogger()
```

The factory returns the right logger.

---

### Cloud SDKs

AWS SDK

Azure SDK

Google Cloud SDK

They internally create service clients through factories.

---

## Tools/frameworks using it

* Django ORM
* SQLAlchemy
* FastAPI dependency creation
* Java Spring Beans
* .NET DI Container
* AWS SDK
* Azure SDK

---

## Practice Idea

Build a Notification System.

```text
NotificationFactory

↓

Email

SMS

WhatsApp

Discord
```

Main program should only do

```python
notification = factory.create("email")
notification.send()
```

---

## When should you think about Factory?

Whenever you write code like

```python
if type == ...
```

or

```python
switch(type)
```

to create objects,

ask yourself

> Should this become a Factory?

---

## Pros

✅ Removes duplicate object creation code

✅ Easy to add new object types

✅ Follows the Open/Closed Principle

✅ Client code becomes cleaner

---

## Cons

❌ Adds extra classes

❌ Overkill for very small projects

---

---

# 2. Abstract Factory

This one confuses almost everyone at first.

Here's the trick:

> **Factory creates one object.**
>
> **Abstract Factory creates a family of related objects.** ([EECS Department][2])

---

## What problem does it solve?

Imagine you're making a cross-platform GUI application.

For Windows you need

* Windows Button
* Windows Checkbox
* Windows TextBox

For macOS you need

* Mac Button
* Mac Checkbox
* Mac TextBox

Without Abstract Factory

```python
if os == "windows":
    button = WindowsButton()

if os == "mac":
    button = MacButton()

...
```

Now repeat this for every UI component.

Mess.

---

## Easy analogy

You're furnishing a bedroom.

Option A

Buy IKEA furniture.

Option B

Buy Interwood furniture.

You don't mix

* IKEA bed
* Interwood wardrobe
* Local sofa

You usually buy a matching set.

That's what Abstract Factory returns.

A matching family.

---

## How it solves the problem

```
GUI Factory

        ↓

Windows Factory

↓

Button
Checkbox
Textbox



Mac Factory

↓

Button
Checkbox
Textbox
```

Switch one factory

Entire UI changes.

---

## Real-world example

Flutter

Android widgets

iOS widgets

Same Flutter code

Different underlying components.

---

### Database drivers

Need

* Connection
* Transaction
* Command

Each database provides matching implementations.

---

## Frameworks using it

* Java Swing Look & Feel
* Qt
* Flutter engine
* JDBC Drivers
* Spring Bean Factories

---

## Practice Idea

Build a game.

Themes

```
Medieval

Sword

Shield

Helmet



Sci-Fi

Laser

Force Field

Nano Helmet
```

Changing the factory changes the entire equipment set.

---

## Pros

✅ Easy platform switching

✅ Objects stay compatible

✅ Great for plugin systems

---

## Cons

❌ More classes

❌ Harder to understand initially

---

---

# 3. Builder Pattern

Builder is one of the most useful patterns you'll actually use.

---

## What problem does it solve?

Suppose you have

```python
Pizza(
    size,
    cheese,
    onions,
    olives,
    mushrooms,
    chicken,
    sauce,
    crust,
    spicy,
    extra_cheese,
    ...
)
```

Imagine 25 parameters.

Good luck remembering the order.

---

## Easy analogy

Subway.

You don't order

```
Sub(
True,
False,
True,
False,
True,
False,
...)
```

Instead

```
Footlong

↓

Italian Bread

↓

Chicken

↓

Cheese

↓

Sauce
```

Step by step.

That's Builder.

---

## How it solves the problem

Instead of

```python
Pizza(...)
```

you write

```python
builder

.add_cheese()

.add_olives()

.add_chicken()

.build()
```

Much easier to read.

Builder separates the construction process from the final object, making complex objects easier to create with optional configuration. ([EECS Department][2])

---

## Real-world examples

### SQL Query Builder

```python
query.select()

.where()

.order_by()

.limit()

.build()
```

---

### Docker

```
Dockerfile

↓

Build Image
```

Step-by-step construction.

---

### HTTP Request Builders

Many SDKs let you do

```python
request

.set_header()

.set_token()

.set_body()

.build()
```

---

## Frameworks

* SQLAlchemy Query Builder
* OkHttp Builder
* Lombok Builder
* Java StringBuilder
* Requests builders
* AWS SDK builders

---

## Practice Idea

Build a Resume Builder.

```
ResumeBuilder()

.set_name()

.set_email()

.add_skill()

.add_project()

.build()
```

---

## Pros

✅ Readable

✅ Handles optional parameters well

✅ Prevents huge constructors

---

## Cons

❌ More code

❌ Unnecessary for simple objects

---

---

# 4. Singleton Pattern

Probably the most famous pattern.

Also one of the most misused.

---

## What problem does it solve?

Some objects should only exist once.

Examples

* App Configuration
* Logger
* Cache Manager
* Database Connection Pool
* Settings Manager

Creating multiple instances can waste resources or lead to inconsistent state. Singleton ensures there is only one instance with a global access point. ([EECS Department][2])

---

## Easy analogy

Imagine the principal's office.

There's only one principal.

Everyone visits the same office.

Not five principals.

---

## How it solves the problem

```
Any part of app

↓

getInstance()

↓

Same object
```

Every caller receives the same instance.

---

## Real-world examples

### Logger

Every module writes to

```
AppLogger
```

Not

```
Logger1

Logger2

Logger3
```

---

### Configuration

```
config.get("DATABASE_URL")
```

Everyone reads the same configuration.

---

### Cache

Redis Client

One shared connection manager.

---

## Where you'll see it

* Spring singleton beans (default scope)
* Application configuration objects
* Logging frameworks
* Caching systems
* Connection pools (often managed as shared resources)

---

## Practice Idea

Build a Config Manager.

```
config = ConfigManager.instance()

config.get("API_KEY")
```

Every module uses the same configuration object.

---

## Pros

✅ Saves memory

✅ One source of truth

✅ Easy global access

---

## Cons

❌ Harder to unit test

❌ Introduces global state, which can create hidden dependencies

❌ Can make code more tightly coupled if overused

Many modern applications prefer **Dependency Injection (DI)** over manually implemented Singletons because DI provides shared instances without the downsides of hard-coded global access. ([Baeldung on Kotlin][1])

---

# Quick Comparison

| Pattern          | Main Idea                                   | Think Of It As          |
| ---------------- | ------------------------------------------- | ----------------------- |
| Factory          | Create **one** appropriate object           | Coffee shop cashier     |
| Abstract Factory | Create a **family** of matching objects     | IKEA bedroom set        |
| Builder          | Construct a complex object **step by step** | Subway sandwich builder |
| Singleton        | Ensure only **one shared instance** exists  | Principal's office      |

---

# How to Remember Them Forever

Whenever you're designing software, ask yourself these four questions:

1. **Do I need to choose between different object types?** → **Factory**
2. **Do I need a whole family of compatible objects?** → **Abstract Factory**
3. **Is my object complicated to build with many optional parts?** → **Builder**
4. **Should there only ever be one instance of this object?** → **Singleton**

These four patterns form the foundation of **Creational Design Patterns**. Once you recognize the *object creation problem*, choosing the right pattern becomes much easier. ([Baeldung on Kotlin][1])

[1]: https://www.baeldung.com/creational-design-patterns?utm_source=chatgpt.com "Introduction to Creational Design Patterns | Baeldung"
[2]: https://web.eecs.umich.edu/~movaghar/Gang%20of%20Four%20Book.pdf?utm_source=chatgpt.com "Creational Patterns"


# Design Patterns — Part 2: Structural Patterns

In the first part, we learned:

> **Creational Patterns = "How do I create objects?"**

Now comes the next category.

> **Structural Patterns = "How do I organize and connect objects together?"**

As projects grow, you rarely have just a few classes. You might have hundreds or even thousands of classes interacting with each other.

Without a good structure, your code becomes:

* Difficult to understand
* Tightly coupled
* Hard to change
* Full of duplicate logic

Structural patterns solve these problems by defining better ways for classes and objects to work together through composition instead of complex inheritance. This aligns with one of the core principles emphasized by the original Gang of Four patterns: **favor object composition over class inheritance.**

---

# 1. Adapter Pattern

> **Keyword:** Compatibility

---

## What problem does it solve?

Imagine you've built a weather application.

Your code expects this interface:

```python
weather.get_temperature()
```

Later, you decide to use another weather API.

But its SDK provides:

```python
weather.fetchTemp()
```

Oops.

Your entire application expects

```python
get_temperature()
```

but the new library gives

```python
fetchTemp()
```

Do you rewrite your entire project?

No.

That's where Adapter comes in.

The Adapter lets classes with incompatible interfaces work together by translating one interface into another without changing either class.

---

## Easy analogy

Suppose you buy a laptop from the US.

It has

```
Type A Plug
```

Pakistan uses another socket.

You don't modify your laptop.

You don't modify your house.

You buy a power adapter.

```
Laptop
     ↓
Adapter
     ↓
Pakistani Socket
```

The adapter translates between both sides.

---

## How it solves the problem

Instead of changing existing code:

```
Application

↓

Adapter

↓

Third-party Library
```

The application still calls

```python
weather.get_temperature()
```

The Adapter internally converts that into

```python
weather.fetchTemp()
```

Nobody else knows.

---

## Real-world software examples

### Payment gateways

Your application expects

```python
pay(amount)
```

Stripe SDK

```python
charge()
```

PayPal SDK

```python
makePayment()
```

Adapter converts both into

```python
pay()
```

---

### Database Drivers

Different databases expose different APIs.

ORMs adapt them into one common interface.

---

### Legacy systems

Companies often connect new software with decades-old legacy software using adapters.

---

## Tools & frameworks

You'll see Adapter in:

* Java JDBC Drivers
* Python DB-API adapters
* SQLAlchemy dialects
* Requests wrappers
* Cloud SDK wrappers

---

## Practice Idea

Create

```
VideoPlayer Interface

↓

YouTube Adapter

VLC Adapter

Local File Adapter
```

Your media player should play videos regardless of source.

---

## Pros

✅ Reuse old code

✅ Easy integration

✅ Decouples client from implementation

---

## Cons

❌ Adds another layer

❌ Too many adapters can make architecture harder to follow

---

# 2. Facade Pattern

> **Keyword:** Simplicity

---

## What problem does it solve?

Imagine starting a computer.

Internally it performs:

```
Power Supply

↓

CPU

↓

RAM

↓

GPU

↓

Storage

↓

Operating System
```

Thousands of operations happen.

But you only press

```
Power Button
```

That's a Facade.

A Facade provides one simple interface to a complex subsystem, hiding unnecessary complexity from the client.

---

## Easy analogy

Imagine checking into a hotel.

Without a facade:

* Reception
* Room Service
* Housekeeping
* Billing
* Security

You'd have to contact each department yourself.

Instead...

You call reception.

Reception handles everything.

Reception is the Facade.

---

## How it solves the problem

Instead of

```
OrderService

↓

Inventory

↓

Payment

↓

Shipping

↓

Email

↓

Invoice
```

You simply call

```python
place_order()
```

Internally

```
Facade

↓

Inventory

Payment

Shipping

Email
```

Everything happens automatically.

---

## Real-world examples

### Online shopping

```
checkout()
```

Internally

* Validate cart
* Charge payment
* Update inventory
* Create shipment
* Send email

One method.

Many operations.

---

### Cloud SDKs

AWS SDK

```
upload_file()
```

Internally performs authentication, retries, request signing, and networking.

---

## Tools & frameworks

* Spring Boot
* AWS SDK
* Azure SDK
* Google Cloud SDK
* Laravel services

---

## Practice Idea

Build a Movie Streaming App.

One method

```python
watch_movie()
```

Internally

* Login
* Subscription check
* Load subtitles
* Buffer video
* Start streaming

---

## Pros

✅ Very easy API

✅ Reduces coupling

✅ Hides complexity

---

## Cons

❌ Can become a "God class" if it grows too much

---

# 3. Decorator Pattern

> **Keyword:** Add features without modifying the original object

---

## What problem does it solve?

Suppose you have

```
Coffee
```

Customer wants

* Milk
* Sugar
* Cream
* Chocolate
* Caramel

Should you create classes like

```
CoffeeWithMilk

CoffeeWithSugar

CoffeeWithMilkAndSugar

CoffeeWithMilkSugarChocolate

CoffeeWithEverything
```

Imagine how many combinations you'll end up with!

Decorator solves this by attaching new behavior to an object dynamically, without changing the original class.

---

## Easy analogy

Buying a burger.

Base burger:

```
Burger
```

Want cheese?

Add it.

Want bacon?

Add it.

Want extra sauce?

Add it.

You're decorating the burger.

---

## How it solves the problem

```
Coffee

↓

Milk Decorator

↓

Sugar Decorator

↓

Chocolate Decorator
```

Each decorator wraps the previous object.

---

## Real-world examples

### Java I/O

```
FileInputStream

↓

BufferedInputStream

↓

DataInputStream
```

Each wrapper adds functionality.

---

### Web frameworks

Authentication

↓

Logging

↓

Caching

↓

Compression

Each layer decorates the request handler.

---

## Tools & frameworks

* Java I/O streams
* Python decorators (conceptually similar, though language decorators are a separate feature)
* Middleware in Django, FastAPI, Express, ASP.NET Core

---

## Practice Idea

Pizza ordering.

Base pizza.

Decorators:

* Cheese
* Mushrooms
* Chicken
* Olives

Each topping changes the price and description.

---

## Pros

✅ Flexible

✅ No subclass explosion

✅ Add features at runtime

---

## Cons

❌ Many decorators can make debugging harder

---

# 4. Composite Pattern

> **Keyword:** Tree structures

---

## What problem does it solve?

Imagine a file system.

```
Folder

↓

Folder

↓

Folder

↓

File
```

Folders can contain

* Files
* Other folders

Both should be treated similarly.

Composite lets you treat individual objects and groups of objects uniformly.

---

## Easy analogy

Think about your university.

```
University

↓

Department

↓

Teacher

↓

Student
```

Every level is part of one larger hierarchy.

---

## How it solves the problem

```
Component

↓

Leaf

(File)

↓

Composite

(Folder)
```

Folder contains many Components.

Each Component can be either

* File
* Folder

The client doesn't need to care.

---

## Real-world examples

### File Explorer

Folders contain

* Files
* Other folders

---

### HTML DOM

```
<body>

↓

<div>

↓

<section>

↓

<p>
```

Every HTML element is part of a tree.

---

### Organization charts

CEO

↓

Managers

↓

Employees

---

## Tools & frameworks

* HTML DOM
* XML parsers
* Java Swing component trees
* File systems

---

## Practice Idea

Create a Company Hierarchy.

```
Company

↓

Department

↓

Team

↓

Employee
```

Printing the company should recursively print every level.

---

## Pros

✅ Simple recursive operations

✅ Easy tree traversal

✅ Uniform interface

---

## Cons

❌ Can make it harder to enforce restrictions on what can contain what

---

# 5. Proxy Pattern

> **Keyword:** Control access

---

## What problem does it solve?

Sometimes you don't want users talking directly to an object.

Maybe because:

* It's expensive to create
* It's remote
* It needs authentication
* It should cache results
* It should log activity

A Proxy acts as a placeholder or representative for another object and controls access to it.

---

## Easy analogy

Imagine a celebrity.

You don't call them directly.

You speak to their manager.

The manager decides

* Allow
* Reject
* Schedule
* Delay

Manager = Proxy.

---

## How it solves the problem

```
Client

↓

Proxy

↓

Real Object
```

Proxy can

* Cache
* Authenticate
* Log
* Delay creation
* Limit access

before forwarding the request.

---

## Real-world examples

### Image loading

Social media apps don't load every high-resolution image immediately.

Instead

```
Placeholder

↓

Real Image

when needed
```

---

### Database Proxy

Before a query runs

* Check permissions
* Log activity
* Cache results

Then execute.

---

### Reverse proxies

Servers like **Nginx** often sit in front of application servers to handle caching, SSL termination, load balancing, and request forwarding.

---

## Tools & frameworks

* Nginx (reverse proxy)
* HAProxy
* Hibernate lazy loading proxies
* Java RMI proxies
* Python proxy objects

---

## Practice Idea

Build a Photo Gallery.

```
High Resolution Images
```

Only load an image when the user clicks it.

Until then

Display a lightweight placeholder.

---

## Pros

✅ Better security

✅ Lazy loading

✅ Caching

✅ Logging

---

## Cons

❌ Extra layer of indirection

❌ Can introduce slight performance overhead

---

# Quick Comparison

| Pattern   | Main Idea                                  | Easy Analogy               |
| --------- | ------------------------------------------ | -------------------------- |
| Adapter   | Make incompatible interfaces work together | Travel plug adapter        |
| Facade    | Hide complexity behind a simple interface  | Hotel reception desk       |
| Decorator | Add features dynamically                   | Adding toppings to a pizza |
| Composite | Treat single objects and groups the same   | Folder/File hierarchy      |
| Proxy     | Control or delay access to another object  | Celebrity's manager        |

---

# How to Recognize Them in Real Projects

When designing software, ask yourself these questions:

1. **Do I need to connect two things that speak different "languages"?** → **Adapter**
2. **Is my subsystem too complicated for users to interact with directly?** → **Facade**
3. **Do I want to add optional features without changing the original class?** → **Decorator**
4. **Am I working with tree-like data structures where parents and children should be handled the same way?** → **Composite**
5. **Do I need to control, secure, cache, or delay access to an object?** → **Proxy**

---

# Adapter vs Facade vs Decorator vs Proxy (The Most Common Confusion)

| Pattern   | Changes Interface? | Adds Behavior? | Simplifies Complexity? | Controls Access? |
| --------- | ------------------ | -------------- | ---------------------- | ---------------- |
| Adapter   | ✅ Yes              | ❌ No           | ❌ No                   | ❌ No             |
| Facade    | ❌ No               | ❌ No           | ✅ Yes                  | ❌ No             |
| Decorator | ❌ No               | ✅ Yes          | ❌ No                   | ❌ No             |
| Proxy     | ❌ Usually No       | Sometimes      | ❌ No                   | ✅ Yes            |

A simple way to remember them:

* **Adapter** = "Translate"
* **Facade** = "Simplify"
* **Decorator** = "Enhance"
* **Proxy** = "Protect or Control"

These five patterns make up the core **Structural Design Patterns** and you'll encounter them frequently in frameworks, middleware, SDKs, GUI toolkits, networking libraries, and enterprise applications. Their goal is not to create objects (that's Creational), but to organize how objects collaborate in a clean, maintainable way.



# Design Patterns — Part 3: Behavioral Patterns

We've already covered:

* ✅ Creational → *How do we create objects?*
* ✅ Structural → *How do we connect objects?*

Now comes the last category.

> **Behavioral Patterns answer one question:**
>
> **"How should objects communicate with each other?"**

As applications grow, objects constantly interact.

Think about:

* User clicks a button
* Payment succeeds
* Notification is sent
* Order status changes
* Database updates
* Cache refreshes

Behavioral patterns organize these interactions so they're flexible, loosely coupled, and easy to extend instead of becoming a tangled mess of method calls. ([DigitalOcean][1])

---

# 1. Observer Pattern

> **Keyword:** Event Subscription

---

## What problem does it solve?

Imagine Instagram.

You post a new picture.

Now all your followers should receive a notification.

Without Observer:

```text
Instagram

↓

Notify Alice

↓

Notify Bob

↓

Notify Charlie

↓

Notify David

↓

...
```

The `Post` class now knows every follower.

If someone follows or unfollows you...

More code changes.

The objects become tightly coupled.

Observer solves exactly this problem.

It creates a **one-to-many relationship** where one object (the Subject) automatically notifies many other objects (Observers) whenever its state changes, without knowing their concrete implementations. ([Wikipedia][2])

---

## Easy analogy

Think about YouTube.

You subscribe to a channel.

When a new video is uploaded:

```
Channel

↓

Subscriber 1

Subscriber 2

Subscriber 3

Subscriber 4
```

The channel doesn't know who you are personally.

It simply says

> "New video uploaded."

Everyone subscribed receives it.

---

## How it solves the problem

Instead of

```text
Subject

↓

Calls everyone manually
```

You get

```text
Subject

↓

Observer List

↓

Notify Everyone
```

Observers can join or leave anytime.

---

## Real-world examples

### GitHub

Watch a repository.

New release?

You receive notification.

---

### Stock Market

Stock price changes.

Investors receive updates.

---

### Chat Applications

Someone sends a message.

Everyone in the room gets notified.

---

### GUI Frameworks

Button clicked.

Every registered event listener runs.

---

## Tools & Frameworks

* React Event System
* Java Swing Listeners
* JavaFX Events
* Node.js EventEmitter
* RxJS
* Qt Signals & Slots

---

## Practice Idea

Build a Weather Station.

```
Weather Station

↓

Phone App

↓

TV

↓

Website

↓

Smart Watch
```

Whenever temperature changes,

all devices update automatically.

---

## Pros

✅ Loose coupling

✅ Easy to add subscribers

✅ Great for event-driven systems

---

## Cons

❌ Too many observers can make debugging difficult

❌ Notification order isn't always guaranteed

---

# 2. Strategy Pattern

> **Keyword:** Swap algorithms

---

## What problem does it solve?

Suppose Google Maps offers

* Walking
* Driving
* Bicycle
* Bus

Without Strategy

```python
if mode == "car":
    ...

elif mode == "walk":
    ...

elif mode == "bike":
    ...
```

This keeps growing.

Strategy says:

> Put every algorithm in its own class.

Choose one at runtime.

Strategy defines a family of algorithms, encapsulates each one, and makes them interchangeable without changing the client code. ([DigitalOcean][1])

---

## Easy analogy

Imagine paying online.

You choose

* Credit Card
* PayPal
* Stripe
* JazzCash

The checkout page doesn't care.

It simply says

```
Pay()
```

Different strategy.

Same interface.

---

## How it solves the problem

```
Checkout

↓

Payment Strategy

↓

Stripe

↓

Paypal

↓

JazzCash
```

Switch strategy.

No code changes.

---

## Real-world examples

### Compression

ZIP

RAR

7z

---

### Sorting

Quick Sort

Merge Sort

Heap Sort

---

### Authentication

Google Login

GitHub Login

Microsoft Login

---

## Tools

* Java Comparator
* Python's `sorted(key=...)` (conceptually similar)
* Spring Security authentication providers

---

## Practice Idea

Build a Navigation App.

Strategies

* Fastest Route
* Cheapest Route
* Scenic Route

Switch routes while the app is running.

---

## Pros

✅ Removes huge if-else blocks

✅ Easy to add new algorithms

✅ Open/Closed Principle

---

## Cons

❌ More classes

❌ Small projects may not need it

---

# 3. Command Pattern

> **Keyword:** Turn actions into objects

---

## What problem does it solve?

Imagine a text editor.

You click

* Copy
* Paste
* Undo
* Redo

Instead of executing directly,

each action becomes an object.

This lets you queue, log, replay, or undo actions.

Command encapsulates a request—including all information needed to perform it—as an object. ([Coursera][3])

---

## Easy analogy

Restaurant.

Customer tells waiter

```
Pizza
```

Waiter doesn't cook.

Waiter carries the order.

Chef executes it.

```
Customer

↓

Waiter (Command)

↓

Chef
```

---

## How it solves the problem

```
Button

↓

Command

↓

Receiver
```

The button doesn't know how to save a file.

It just executes

```
command.execute()
```

---

## Real-world examples

### VS Code

Undo

Redo

Cut

Paste

---

### Remote Control

Each button stores a command.

TV

Fan

Lights

---

### Job Queues

Email job

SMS job

Image processing

Each job is a command object.

---

## Tools

* Celery
* RabbitMQ workers
* Quartz Scheduler

---

## Practice Idea

Build a Smart Home.

Commands

* Turn Lights On
* Turn Fan Off
* Open Door
* Close Garage

Add Undo.

---

## Pros

✅ Undo/Redo

✅ Logging

✅ Queueing

✅ Scheduling

---

## Cons

❌ Many small classes

---

# 4. State Pattern

> **Keyword:** Object changes behavior

---

## What problem does it solve?

Imagine a music player.

States:

* Playing
* Paused
* Stopped

Without State

```python
if playing:
...

elif paused:
...

elif stopped:
...
```

Eventually every method has giant conditionals.

State moves behavior into separate state objects.

Instead of asking "what state am I in?", the object delegates behavior to its current state. ([DigitalOcean][1])

---

## Easy analogy

Traffic light.

```
Red

↓

Green

↓

Yellow

↓

Red
```

Each state behaves differently.

---

## How it solves the problem

```
Player

↓

Current State

↓

Playing

Paused

Stopped
```

Switch state.

Behavior automatically changes.

---

## Real-world examples

ATM

* No Card
* Card Inserted
* PIN Entered
* Cash Dispensed

Each state allows different actions.

---

### Vending Machine

* Out of stock
* Waiting
* Dispensing
* Payment received

---

## Practice Idea

Build a Door.

States

* Locked
* Unlocked
* Open

Different actions allowed.

---

## Pros

✅ Removes conditionals

✅ Easy to add states

---

## Cons

❌ Many state classes

---

# 5. Chain of Responsibility

> **Keyword:** Pass it along

---

## What problem does it solve?

Imagine customer support.

```
Level 1

↓

Level 2

↓

Manager

↓

Director
```

If Level 1 can't solve it,

it forwards it.

Nobody knows who will finally handle it.

Chain of Responsibility passes a request along a chain of handlers until one of them handles it, reducing coupling between the sender and receiver. ([Wikipedia][4])

---

## Easy analogy

University approval.

```
Teacher

↓

HOD

↓

Dean

↓

Vice Chancellor
```

Each person decides

Handle?

Or pass along.

---

## Real-world examples

### HTTP Middleware

Authentication

↓

Authorization

↓

Validation

↓

Controller

---

### Logging

DEBUG

↓

INFO

↓

WARNING

↓

ERROR

---

## Tools

* Express.js Middleware
* ASP.NET Middleware
* Django Middleware
* Servlet Filters

---

## Practice Idea

Build an Expense Approval System.

```
Manager

↓

Director

↓

CEO
```

Each can approve based on amount.

---

## Pros

✅ Loose coupling

✅ Flexible chain

---

## Cons

❌ Harder to debug request flow

---

# 6. Mediator Pattern

> **Keyword:** Central communication

---

## What problem does it solve?

Suppose five colleagues communicate directly.

Everyone talks to everyone.

```
A ↔ B ↔ C ↔ D ↔ E
```

Connections explode.

Mediator introduces one central coordinator.

Objects talk only to the mediator instead of each other, reducing dependencies. ([DigitalOcean][1])

---

## Easy analogy

Airport.

Pilots don't talk directly.

Everything goes through

```
Air Traffic Control
```

ATC is the mediator.

---

## Real-world examples

### Chat Application

Users don't send messages directly.

Server coordinates everything.

---

### Air Traffic Control

Planes

↓

Tower

↓

Other planes

---

## Tools

* SignalR Hub
* Chat servers
* Event buses
* Message brokers (conceptually)

---

## Practice Idea

Build a Chat Room.

Users only communicate through

```
ChatRoomMediator
```

---

## Pros

✅ Loose coupling

✅ Easier communication

---

## Cons

❌ Mediator can become overly complex if it takes on too many responsibilities

---

# 7. Template Method

> **Keyword:** Same algorithm, customizable steps

---

## What problem does it solve?

Suppose every report follows

```
Load Data

↓

Analyze

↓

Generate Output

↓

Save
```

Only the analysis changes.

Don't rewrite the whole algorithm.

Template Method defines the overall algorithm once and lets subclasses customize specific steps without changing the algorithm's structure. ([DigitalOcean][1])

---

## Easy analogy

Making tea.

```
Boil Water

↓

Add Tea

↓

Pour

↓

(Optional) Add Milk

↓

(Optional) Add Sugar
```

Overall process stays the same.

Some steps vary.

---

## Real-world examples

### Game Engine

```
Initialize

↓

Update

↓

Render

↓

Cleanup
```

Games override

```
Update()
```

The engine controls the flow.

---

### Data Processing

```
Read File

↓

Validate

↓

Transform

↓

Export
```

Only transformation differs.

---

## Tools

* Django Class-Based Views
* JUnit test lifecycle
* Spring `JdbcTemplate` (template-style API)

---

## Practice Idea

Build a File Importer.

Template

```
Open

↓

Read

↓

Parse

↓

Save
```

Create

* CSV Importer
* JSON Importer
* XML Importer

Only the parsing step changes.

---

# Quick Comparison

| Pattern                 | Purpose                             | Easy Analogy                        |
| ----------------------- | ----------------------------------- | ----------------------------------- |
| Observer                | Notify many listeners               | YouTube subscribers                 |
| Strategy                | Swap algorithms                     | Google Maps route selection         |
| Command                 | Wrap actions as objects             | Restaurant waiter carrying an order |
| State                   | Change behavior based on state      | Traffic light                       |
| Chain of Responsibility | Pass request until handled          | Customer support escalation         |
| Mediator                | Centralize communication            | Air Traffic Control                 |
| Template Method         | Fixed algorithm, customizable steps | Tea recipe                          |

---

# How to Recognize Them in Real Projects

Whenever you're designing software, ask yourself these questions:

1. **Do multiple objects need to react when one object changes?** → **Observer**
2. **Do I need to switch between different algorithms at runtime?** → **Strategy**
3. **Should an action be queued, logged, scheduled, or undone?** → **Command**
4. **Does an object's behavior depend on its current state?** → **State**
5. **Should a request travel through multiple handlers until one processes it?** → **Chain of Responsibility**
6. **Are too many objects talking directly to each other?** → **Mediator**
7. **Is the overall workflow fixed, but some individual steps vary?** → **Template Method**

---

# The Three Most Confused Behavioral Patterns

| Pattern             | What changes?                               | Example                                                                     |
| ------------------- | ------------------------------------------- | --------------------------------------------------------------------------- |
| **Strategy**        | **Algorithm**                               | Choose Stripe vs PayPal for payment                                         |
| **State**           | **Object behavior based on internal state** | ATM behaves differently after a card is inserted                            |
| **Template Method** | **Specific steps in a fixed workflow**      | CSV and JSON importers share the same import pipeline but parse differently |

A good mental model is:

* **Observer** → "Broadcast"
* **Strategy** → "Choose"
* **Command** → "Package"
* **State** → "Become"
* **Chain of Responsibility** → "Pass"
* **Mediator** → "Coordinate"
* **Template Method** → "Template"

Once you understand these seven patterns, you'll start recognizing them everywhere—in web frameworks, GUI libraries, game engines, messaging systems, middleware pipelines, cloud SDKs, and enterprise applications. ([DigitalOcean][1])

[1]: https://www.digitalocean.com/community/tutorials/gangs-of-four-gof-design-patterns?utm_source=chatgpt.com "Gang of 4 Design Patterns Explained: Creational, Structural, and Behavioral | DigitalOcean"
[2]: https://en.wikipedia.org/wiki/Observer_pattern?utm_source=chatgpt.com "Observer pattern"
[3]: https://www.coursera.org/articles/gang-of-four-design-patterns?utm_source=chatgpt.com "Gang of Four Design Patterns - A Guide to Object-Oriented Design | Coursera"
[4]: https://en.wikipedia.org/wiki/Chain-of-responsibility_pattern?utm_source=chatgpt.com "Chain-of-responsibility pattern"
