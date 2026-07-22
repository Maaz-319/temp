Perfect. This is actually the point where software engineering starts becoming **architecture**.

Many people make the mistake of learning System Design first because YouTube says it's important. In reality, if you don't understand software architecture, components, DDD, patterns, and communication first, System Design feels like memorizing random boxes.

You've already covered the right prerequisites. Now System Design will actually make sense.

---

# Module 6 — System Design

## What is System Design?

Imagine someone tells you:

> "Build YouTube."

A junior developer immediately starts thinking:

* Which framework?
* React or Vue?
* PostgreSQL or MongoDB?

A software architect asks different questions:

* How many users?
* How much traffic?
* How will videos be stored?
* What happens if one server dies?
* How do videos stream smoothly?
* How do we support millions of uploads?

System Design is the process of deciding **how all major parts of a software system fit together** so it works reliably today and can still work when it grows. ([Grokking System Design][1])

Think of it as designing a **city**, not a house.

---

# Two Types of Design

```
System Design

├── High-Level Design (HLD)
│      Big Picture
│
└── Low-Level Design (LLD)
       Code Structure
```

---

# High-Level Design (HLD)

HLD answers:

> "What major components exist, and how do they communicate?"

Example:

```
Browser

↓

Load Balancer

↓

API Server

↓

Database

↓

Redis Cache

↓

Message Queue

↓

Email Service
```

You don't care about classes yet.

You care about:

* services
* databases
* APIs
* communication
* scaling
* deployment

It is the **blueprint** of the whole application. ([showoffer.io][2])

---

# Low-Level Design (LLD)

LLD answers:

> "Inside one service, how should I write the code?"

Example:

```
UserController

↓

UserService

↓

UserRepository

↓

Database
```

Now you're thinking about:

* classes
* interfaces
* design patterns
* dependency injection
* object relationships

Basically everything you've learned before.

---

# Relationship between HLD and LLD

Imagine building a hospital.

High Level:

```
Reception

Emergency

ICU

Pharmacy

Parking
```

Low Level:

Inside Pharmacy:

```
MedicineManager

Inventory

Supplier

Billing

Prescription Validator
```

Both are necessary.

---

# The High-Level Design Topics

We'll study each one separately.

```
Client

↓

API

↓

Load Balancer

↓

Application Servers

↓

Cache

↓

Database

↓

Queue

↓

Storage

↓

CDN
```

This is almost every modern internet application.

---

# 1. Services

## What problem does it solve?

Imagine putting everything inside one huge application.

```
Authentication

Payments

Orders

Notifications

Analytics

Search

Chat
```

After a year:

```
500,000 lines

Nobody understands anything.
```

Changing one feature accidentally breaks five others.

---

## Solution

Split the application into logical services.

Example:

```
User Service

Payment Service

Notification Service

Inventory Service
```

Each has one responsibility.

Instead of one giant restaurant kitchen, imagine separate stations:

* Grill
* Desserts
* Drinks
* Pizza

Everyone specializes.

This improves maintainability, independent deployment, and team ownership as systems grow. ([Grokking System Design][1])

---

## Real-world example

Netflix

```
Authentication

Recommendations

Streaming

Payments

Profiles

Search
```

Each is an independent service.

---

## Tools

* Docker
* Kubernetes
* NestJS
* Spring Boot
* FastAPI
* ASP.NET Core

---

## Practice

Split your Chat Application into services.

---

# 2. APIs

## Problem

How do services communicate?

Suppose:

```
Frontend

Backend

Payment

Inventory
```

How does one ask another for information?

---

## Solution

APIs.

API = Contract.

Example:

```
GET /users/15
```

Response

```
{
 name: "Ali"
}
```

Everybody follows the contract.

No guessing.

APIs define clear communication between software components. ([HatfLabs - Where Ideas Meet Innovation][3])

---

## Real-world example

Foodpanda

```
Restaurant API

↓

Order API

↓

Payment API

↓

Delivery API
```

---

## Tools

* REST
* GraphQL
* gRPC
* OpenAPI / Swagger
* Postman
* Bruno
* Insomnia

---

## Practice

Design APIs for:

Library System

```
GET /books

POST /borrow

POST /return

GET /history
```

---

# 3. Load Balancer

## Problem

Imagine:

```
100,000 users

↓

1 server
```

Server crashes.

Game over.

Or CPU reaches 100%.

Nobody can log in.

---

## Solution

Instead:

```
Users

↓

Load Balancer

↓

Server 1

Server 2

Server 3
```

Load Balancer distributes traffic.

Like a traffic police officer.

Instead of sending every car to one road, it spreads cars across many roads.

This improves availability and lets applications scale horizontally. ([Design Gurus][4])

---

## Real-world example

Google Search

Millions of users hit Google every second.

Traffic is distributed among thousands of servers.

---

## Tools

* Nginx
* HAProxy
* AWS ELB
* Azure Load Balancer
* Cloudflare

---

## Practice

Draw a diagram for an e-commerce website with:

```
Users

↓

Load Balancer

↓

3 Backend Servers

↓

Database
```

---

# 4. Scaling

## Problem

Your app becomes popular.

One server isn't enough anymore.

---

## Two solutions

### Vertical Scaling

```
Old Server

8GB RAM

↓

64GB RAM
```

Upgrade the machine.

Simple.

But there is a limit.

---

### Horizontal Scaling

Instead of a bigger server:

```
Server 1

Server 2

Server 3

Server 4
```

Add more machines.

This is how large internet companies usually grow because it avoids the limits of a single server. ([Ajit Singh - Software Engineering Blog][5])

---

## Real-world

Instagram

When traffic grows:

More servers.

Not just one giant computer.

---

## Practice

Your university portal suddenly has 5 million users.

Would you:

* buy one supercomputer?
* add 50 servers?

Why?

---

# 5. Caching

## Problem

Imagine:

```
Homepage

↓

Database

↓

Return posts
```

One million users.

One million database queries.

Database dies.

---

## Solution

Cache.

```
User

↓

Cache

↓

Database
```

If data already exists in cache:

Return instantly.

Database isn't touched.

Caching stores frequently accessed data in fast memory, reducing latency and database load. ([Amazon Web Services, Inc.][6])

---

## Real-world

Instagram

Opening your profile again?

Usually comes from Redis cache.

---

## Tools

* Redis
* Memcached

---

## Practice

Which should be cached?

* User profile
* Product categories
* Weather
* Live stock prices

Discuss why each choice makes sense.

---

# 6. Queues

## Problem

User uploads a video.

Immediately after upload:

* Generate thumbnails
* Compress video
* Scan virus
* Notify followers

If everything happens instantly:

User waits 3 minutes.

Bad experience.

---

## Solution

Queue.

```
Upload

↓

Queue

↓

Background Workers
```

User immediately sees:

```
Upload successful.
```

Workers finish heavy jobs later.

Queues decouple slow work from user requests and improve responsiveness. ([Chaos and Order][7])

---

## Real-world

YouTube

Video processing starts after upload.

Not before.

---

## Tools

* RabbitMQ
* Kafka
* BullMQ
* AWS SQS
* Google Pub/Sub

---

## Practice

List tasks in a social media app that should happen asynchronously instead of immediately.

---

# 7. Storage

## Problem

Should everything go into one database?

No.

Videos.

Images.

Documents.

User data.

Logs.

Backups.

They all have different storage needs.

---

## Solution

Choose storage based on the data.

Examples:

```
User Accounts

↓

PostgreSQL

Images

↓

Object Storage

Logs

↓

Log Storage

Videos

↓

Blob Storage
```

Different storage systems are optimized for different data types and access patterns. ([THN Interview Prep][8])

---

## Real-world

YouTube

Videos aren't stored inside PostgreSQL.

They're stored in object storage.

---

## Tools

* Amazon S3
* Google Cloud Storage
* Azure Blob Storage
* MinIO

---

## Practice

For an online learning platform, decide where to store:

* User accounts
* Videos
* PDFs
* Quiz results
* Logs

---

# 8. CDN (Content Delivery Network)

## Problem

Your server is in Germany.

A user opens your website from Pakistan.

Every image travels thousands of kilometers.

Slow.

---

## Solution

CDN.

```
Original Server

↓

CDN

↓

Pakistan

India

Japan

USA

Brazil
```

Images are copied to servers around the world.

The user downloads from the nearest location.

This reduces latency and speeds up delivery of static content. ([Design Gurus][4])

---

## Real-world

Netflix

Movies are served from edge locations close to users rather than a single central server.

---

## Tools

* Cloudflare
* Amazon CloudFront
* Fastly
* Bunny.net
* Akamai

---

## Practice

If your users are mostly in:

* Pakistan
* India
* UAE
* Saudi Arabia

Would a CDN help? Explain your reasoning.

---

# 9. Databases

## Problem

Every application needs persistent data.

But one database doesn't fit every use case.

---

## Solution

Choose the database based on your requirements.

Common choices:

* **SQL (PostgreSQL, MySQL):** Strong consistency, relationships, transactions (e.g., banking, e-commerce orders).
* **NoSQL (MongoDB, DynamoDB):** Flexible schema, easy horizontal scaling (e.g., social media, event logs). ([THN Interview Prep][8])

---

## Real-world

Amazon might use:

* SQL for orders and payments.
* NoSQL for product catalogs or session data.

Different parts of a system can use different databases.

---

## Tools

* PostgreSQL
* MySQL
* MongoDB
* Cassandra
* DynamoDB
* Redis (as a cache)

---

## Practice

For a food delivery app, choose databases for:

* Users
* Restaurants
* Orders
* Delivery tracking
* Reviews

Explain why you picked each one.

---

# Low-Level Design Topics

Everything you've already been learning fits here:

* Classes
* Interfaces
* SOLID Principles
* Design Patterns
* Dependency Injection
* Modules
* Relationships (Association, Aggregation, Composition, Inheritance)

LLD is about designing **clean code inside a service**, while HLD is about designing **how services work together**.

---

# Suggested Learning Order

Don't learn these randomly. Follow this sequence:

1. High-Level Design mindset
2. Services
3. APIs
4. Databases
5. Storage
6. Caching
7. Queues
8. Load Balancing
9. Scaling
10. CDN
11. Low-Level Design (connecting everything back to classes, modules, and patterns)
12. End-to-end design of real systems (Chat app, YouTube, Uber, WhatsApp, Library, E-commerce)

By the end of this module, you'll be able to take a product idea and answer questions like:

* What services should this system have?
* How will they communicate?
* Where should the data live?
* Which data should be cached?
* What tasks should run asynchronously?
* How will the system handle 10 users? 10,000 users? 10 million users?
* How do the high-level architecture and low-level code fit together?

That's the foundation of practical system design used in real software engineering.

[1]: https://www.grokkingsystemdesign.com/system-design-fundamentals?utm_source=chatgpt.com "System Design Fundamentals: The Complete Reference Guide (2026)"
[2]: https://www.showoffer.io/learn/system-design/key-concepts/high-level-design?utm_source=chatgpt.com "High Level Design - System Design | ShowOffer"
[3]: https://yasir.com.pk/blog/system-design/complete-system-design-guide?utm_source=chatgpt.com "The Complete Guide to 30 Essential System Design Concepts (Explained for Developers) | HatfLabs - Where Ideas Meet Innovation"
[4]: https://www.designgurus.io/blog/system-design-interview-fundamentals?utm_source=chatgpt.com "25 Fundamental System Design Concepts You Must Know Before Your Interview"
[5]: https://singhajit.com/system-design-cheat-sheet/?utm_source=chatgpt.com "System Design Cheat Sheet: Concepts Every Developer Should Know - Ajit Singh"
[6]: https://aws.amazon.com/caching/?utm_source=chatgpt.com "What is Caching and How it Works | AWS"
[7]: https://www.youngju.dev/blog/architecture/2026-04-12-system-design-fundamentals.en?utm_source=chatgpt.com "System Design Fundamentals — Scalability, Availability, Caching, and Message Queues | Chaos and Order"
[8]: https://technohubnetwork.com/dsa/system-design/core-concepts?utm_source=chatgpt.com "Core Concepts (System Components) | THN Interview Prep"
