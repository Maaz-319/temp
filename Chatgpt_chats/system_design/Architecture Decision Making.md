This is one of the most important skills that separates a **developer** from a **software architect**.

Many beginners think architecture is about knowing technologies.

It isn't.

Architecture is mostly about **making good decisions and being able to explain them.**

Senior engineers spend far more time answering:

> "Why did we choose this?"

than

> "How do we code this?"

In interviews, architecture reviews, and design documents, people constantly ask:

* Why PostgreSQL?
* Why not MongoDB?
* Why Redis instead of caching inside Python?
* Why Kafka instead of RabbitMQ?
* Why FastAPI over Django?
* Why Next.js instead of React?
* Why TypeScript instead of JavaScript?

If your answer is

> "Because everyone uses it."

that's not architecture.

---

# What is Architecture Decision Making?

Imagine your project is like building a house.

You have to decide:

* brick or wood?
* steel roof or concrete?
* solar panels or not?
* two floors or one?

There is no universally correct answer.

Every choice has:

* benefits
* drawbacks
* cost
* future maintenance

Software architecture is exactly the same.

An architect chooses technologies according to **requirements**, **constraints**, and **trade-offs**, not popularity. This idea is emphasized across software architecture literature and modern engineering practice. ([arXiv][1])

---

# The Architect's Thinking Process

Instead of asking

> Which database is best?

Ask

> What problem am I trying to solve?

For every technology ask:

```
Problem
↓

Requirements

↓

Possible Options

↓

Compare Tradeoffs

↓

Choose One

↓

Accept its disadvantages
```

Notice the last step.

There is **no perfect technology**.

Every technology solves one problem while creating another.

That is called a **trade-off**.

---

# A Decision Framework

Whenever you choose a technology, answer these questions.

## 1. What problem am I solving?

Example

Need user accounts.

Need file uploads.

Need real-time chat.

Need analytics.

Need millions of events.

Different problems need different tools.

---

## 2. What are my requirements?

Examples

Need transactions?

Need scalability?

Need speed?

Need flexibility?

Need strong consistency?

Need low cost?

Need developer productivity?

---

## 3. What options exist?

Example

Need database?

Possible options

* PostgreSQL
* MySQL
* MongoDB
* Cassandra
* DynamoDB

---

## 4. Compare them

Not by popularity.

Compare

* Performance
* Cost
* Complexity
* Learning curve
* Community
* Ecosystem
* Hosting support
* Scalability
* Reliability

---

## 5. Choose one

Choose the one that solves **your** problem best.

Not everyone's.

---

# Let's Practice

Suppose we're building:

## Food Delivery App

Requirements

* Users
* Orders
* Payments
* Restaurants
* Reviews

Question:

Should we choose MongoDB?

Let's think.

Orders require

* transactions
* consistency
* relationships
* payment integrity

That sounds like SQL.

Therefore

PostgreSQL becomes a stronger choice than MongoDB for the core transactional data because it provides ACID transactions, relational integrity, and advanced SQL features. ([PostgreSQL][2])

See?

We didn't start from PostgreSQL.

We started from the **problem**.

---

# Example 1

## Why PostgreSQL?

### Problem it solves

You have structured data with relationships.

Example

```
Users

Orders

Payments

Products

Invoices
```

Everything connects together.

---

### How does it solve it?

PostgreSQL provides:

* ACID transactions
* Foreign keys
* JOINs
* Constraints
* Powerful indexing
* Advanced SQL
* Reliable concurrency control

These features help keep business data consistent even when many users are accessing it simultaneously. ([PostgreSQL][2])

---

### Real-world example

Think about

Amazon Orders

```
User

↓

Order

↓

Payment

↓

Shipment
```

If payment fails

everything should rollback.

SQL databases excel here.

---

### Why NOT PostgreSQL?

Bad choice when

* schema changes every day
* mostly document data
* extremely flexible JSON documents
* event logs

---

### Related Tools

* PostgreSQL
* pgAdmin
* Prisma
* SQLAlchemy
* Alembic

---

### Practice

Design database for

Netflix

Should

Movies

Actors

Genres

Users

Reviews

be relational?

Yes.

Why?

---

# Example 2

## Why MongoDB?

### Problem

Data structure changes frequently.

Example

Different products

```
Phone

Laptop

Shoes

Books
```

Each has different attributes.

Trying to force this into SQL tables becomes messy.

---

### How it solves it

MongoDB stores JSON-like documents.

Each document can have different fields.

Perfect for flexible schemas.

---

### Real-world example

E-commerce catalog

```
Phone

RAM

Storage

Battery

Camera
```

Shoes

```
Size

Color

Material
```

Book

```
Author

Pages

Language
```

Different shapes.

Same database.

---

### Why NOT MongoDB?

Bad for

* banking
* accounting
* inventory with strict consistency
* complex relational queries

---

### Related Tools

* MongoDB
* MongoDB Compass
* Mongoose
* Atlas

---

### Practice

Design Pinterest.

Would MongoDB fit?

Why?

---

# Example 3

## Why Redis?

### Problem

Database is becoming slow.

Example

Home page

Every user requests

```
Top Products
```

every second.

Database keeps doing same query.

Wasteful.

---

### How it solves it

Redis stores data in memory (RAM), making reads extremely fast.

Instead of

```
User

↓

Database
```

Use

```
User

↓

Redis

↓

Database
```

Database is only queried when the cache misses.

---

### Real-world example

Instagram

Trending posts

Don't calculate every request.

Cache them.

---

### Why NOT Redis?

Don't store permanent business data only in Redis.

RAM is expensive and caches are usually treated as temporary data.

---

### Related Tools

* Redis
* Redis Insight

---

### Practice

Where would you use Redis in YouTube?

---

# Example 4

## Why Kafka?

### Problem

Many services need to know something happened.

Example

Order placed.

Need to

* send email
* update inventory
* notify warehouse
* update analytics
* create invoice

Without Kafka

```
Order Service

↓

Email

↓

Inventory

↓

Analytics

↓

Warehouse
```

Very tightly coupled.

---

### How it solves it

Kafka acts as an event stream.

```
Order

↓

Kafka

↓

Email

Inventory

Analytics

Warehouse
```

Everyone subscribes independently, allowing systems to scale and evolve separately. Kafka was designed specifically for high-throughput, low-latency, fault-tolerant event streaming. ([Apache Kafka][3])

---

### Real-world example

Uber

Ride completed.

Many systems react independently.

---

### Why NOT Kafka?

Don't use Kafka for

* simple CRUD apps
* blog websites
* small portfolios
* apps with only one backend

It adds operational complexity.

---

### Related Tools

* Apache Kafka
* Kafka UI
* Confluent Platform
* Redpanda

---

### Practice

Design Amazon checkout.

Which events would you publish?

---

# Example 5

## Why FastAPI?

### Problem

Need to build APIs quickly while keeping good performance and clear code.

---

### How it solves it

FastAPI uses Python type hints to provide:

* automatic request validation
* automatic OpenAPI/Swagger docs
* async support
* high performance
* excellent editor support

It is designed to reduce boilerplate and speed up API development. ([FastAPI][4])

---

### Real-world example

AI startups

Machine Learning APIs

Internal tools

Backend for mobile apps

---

### Why NOT FastAPI?

Maybe avoid it if:

* your team is deeply invested in another ecosystem (e.g., Spring Boot, .NET)
* you need a batteries-included framework with built-in admin panels and ORM conventions like Django

---

### Related Tools

* FastAPI
* Uvicorn
* Pydantic
* SQLAlchemy
* Alembic

---

### Practice

Would FastAPI be a good backend for an AI chatbot?

Why?

---

# Example 6

## Why Next.js?

### Problem

React alone leaves decisions like routing, SSR, optimization, and API handling to you.

---

### How it solves it

Next.js provides:

* file-based routing
* Server Components
* server-side rendering (SSR)
* static generation (SSG)
* image optimization
* API routes / Backend-for-Frontend capabilities

This helps improve SEO, performance, and developer productivity. ([Next.js][5])

---

### Real-world example

Marketing sites

Dashboards

E-commerce

SaaS applications

---

### Why NOT Next.js?

If you're building:

* an offline desktop app
* a tiny SPA with no SEO needs
* a project where another frontend framework better fits the team

Plain React or another solution might be enough.

---

### Related Tools

* Next.js
* React
* Vercel
* Turbopack

---

### Practice

Should an online newspaper use React or Next.js?

Explain your reasoning.

---

# Example 7

## Why Python?

### Problem

Need to build features quickly with readable code.

---

### How it solves it

Python emphasizes simplicity and has one of the richest ecosystems for:

* AI/ML
* automation
* scripting
* backend APIs
* data engineering

It enables rapid development, especially for startups and data-heavy applications.

---

### Real-world example

* AI assistants
* automation pipelines
* recommendation systems
* internal tools

---

### Why NOT Python?

Maybe not the best choice when:

* every millisecond of runtime performance matters
* you're building low-level systems or game engines

---

### Related Tools

* Python
* Poetry
* uv
* pip
* FastAPI
* Django

---

### Practice

Would you choose Python for a banking backend?

What factors would influence your decision?

---

# Example 8

## Why TypeScript?

### Problem

Large JavaScript codebases become harder to maintain because type-related bugs are found only at runtime.

---

### How it solves it

TypeScript adds static typing to JavaScript.

Benefits:

* catch many errors before running
* better IDE autocomplete
* safer refactoring
* easier collaboration on large teams

---

### Real-world example

Large React applications

Enterprise dashboards

SaaS products

---

### Why NOT TypeScript?

For:

* tiny prototypes
* quick experiments
* throwaway scripts

JavaScript may be sufficient.

---

### Related Tools

* TypeScript
* ESLint
* Prettier
* ts-node

---

### Practice

Build a medium-sized e-commerce frontend.

Would you choose JavaScript or TypeScript?

Why?

---

# The Biggest Lesson

Don't memorize:

> PostgreSQL is best.

Memorize this:

```
Problem

↓

Requirements

↓

Possible Solutions

↓

Trade-offs

↓

Decision

↓

Consequences
```

That thinking process is what software architects use every day.

## Mini Exercise

Imagine you're designing a **real-time food delivery app** (similar to Uber Eats or Foodpanda). For each of these technologies, write down:

* Why would you choose it?
* What specific problem does it solve in your architecture?
* What alternative could you have used, and why did you reject it?

Doing this exercise forces you to think like an architect instead of simply remembering technology names.

[1]: https://arxiv.org/abs/2201.05825?utm_source=chatgpt.com "Decision Models for Selecting Patterns and Strategies in Microservices Systems and their Evaluation by Practitioners"
[2]: https://www.postgresql.org/docs/16/intro-whatis.html?utm_source=chatgpt.com "PostgreSQL: Documentation: 16: 1.  What Is PostgreSQL?"
[3]: https://kafka.apache.org/28/design/design/?utm_source=chatgpt.com "Design | Apache Kafka"
[4]: https://fastapi.tiangolo.com/?utm_source=chatgpt.com "FastAPI - FastAPI"
[5]: https://nextjs.org/docs/app?utm_source=chatgpt.com "Next.js Docs: App Router | Next.js"
