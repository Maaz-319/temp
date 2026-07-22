Excellent. **This is exactly the right time to slow down.**

From now on, we're no longer just learning definitions. We're going to think like a **Software Architect**.

Our goal is **not** "learn Redis" or "learn RabbitMQ."

Our goal is:

> "Given a project's requirements, how do I decide whether I need a Cache? A Queue? A CDN? Which one? Where should it sit in my architecture? What trade-offs am I making?"

That's how senior engineers approach system design. These components are architectural building blocks used to satisfy non-functional requirements such as scalability, availability, latency, reliability, and cost. ([Grokking System Design][1])

---

# The Learning Roadmap

We'll go deep into each topic in this order:

1. **Load Balancing**
2. Caching
3. Queues
4. Storage
5. CDN

Today, let's cover **Load Balancing** in depth.

---

# Topic 1 — Load Balancing

## Imagine you're the architect...

Your company launches a new app.

On Day 1:

```
          Users

            |

         Server
```

100 users.

Everything works.

---

One year later...

```
          1 Million Users

                 |

              Server
```

Now what happens?

The CPU becomes overloaded.

Memory fills up.

Too many network connections.

Requests start timing out.

Eventually...

💥 Server crashes.

---

## The Real Problem

Notice something important.

The problem isn't that your code is bad.

The problem is:

> **One machine has physical limits.**

No matter how powerful it is:

* CPU has limits
* RAM has limits
* Disk has limits
* Network bandwidth has limits

Eventually every server reaches its maximum capacity. At that point, adding more users causes slower responses or failures. ([Wasil Zafar][2])

As a software architect, you immediately think:

> "How can I make multiple servers work together?"

---

# First Solution Most Beginners Think Of

"Let's buy a bigger server."

```
Server

16 GB RAM

↓

64 GB RAM

↓

256 GB RAM
```

This is called **Vertical Scaling**.

It works...

until it doesn't.

Eventually there is no bigger server to buy, and bigger machines become increasingly expensive with a single point of failure. ([Khushal Agrawal][3])

---

# Better Solution

Instead of one huge server...

```
Server A

Server B

Server C

Server D
```

Now we have four servers.

Great!

But...

another problem appears.

---

# New Problem

A user sends a request.

Which server should receive it?

```
          User

            |

      ?

A     B     C     D
```

How does the user know?

Should they randomly guess?

Obviously not.

We need something in the middle.

---

# Meet the Load Balancer

```
                Users

                  |

          +----------------+
          | Load Balancer  |
          +----------------+

          /      |      \

     Server1 Server2 Server3
```

The Load Balancer is like a **traffic police officer**.

It receives every request.

Then decides

> "This request goes to Server 2."

The client doesn't need to know how many servers exist or which one is healthy. The load balancer hides that complexity. ([Design Gurus][4])

---

# What Problem Does It Solve?

As an architect, you should think in terms of requirements.

| Requirement        | Without Load Balancer        | With Load Balancer                |
| ------------------ | ---------------------------- | --------------------------------- |
| More users         | ❌ One server overloaded      | ✅ Traffic spread across servers   |
| High availability  | ❌ Server failure = downtime  | ✅ Send traffic to healthy servers |
| Easier scaling     | ❌ Hard                       | ✅ Add more servers                |
| Better performance | ❌ Queues grow on one machine | ✅ Work is shared                  |

Notice that **Load Balancing isn't about making one server faster.**

It's about making **the whole system** handle more work.

---

# Real World Analogy

Imagine a supermarket.

Without load balancing:

```
10 Cashiers

Only Cashier #1 is open

500 Customers
```

Chaos.

Now imagine:

```
Manager

↓

Customer → Cashier 1

Customer → Cashier 4

Customer → Cashier 8
```

The manager is acting as the load balancer.

---

# Where Does It Sit?

Almost always near the front of your backend.

```
Browser

↓

DNS

↓

Load Balancer

↓

Backend Servers

↓

Database
```

This is one of the most common high-level architecture patterns you'll see.

---

# What Does a Load Balancer Actually Do?

Many beginners think:

> "It just sends requests."

It actually does much more.

A modern load balancer can:

* distribute traffic
* check server health
* stop sending traffic to failed servers
* route based on URL or hostname
* terminate HTTPS (SSL/TLS)
* support sticky sessions when needed
* perform rate limiting (depending on the product)

In many production systems, it's one of the smartest components in the architecture. ([Wasil Zafar][2])

---

# Health Checks

Suppose you have:

```
LB

↓

Server A

Server B

Server C
```

Suddenly...

```
Server B dies.
```

Should users still be sent there?

No.

The load balancer periodically asks each server something like:

```
GET /health
```

Healthy response?

```
200 OK
```

Then the server stays in rotation.

No response?

```
Timeout
```

The load balancer removes it until it recovers.

This is one of the biggest reasons load balancers improve reliability.

---

# Load Balancing Algorithms

This is where architects make design decisions.

Different systems need different strategies.

---

## 1. Round Robin

```
Request 1 → A

Request 2 → B

Request 3 → C

Request 4 → A
```

Everybody gets turns.

### Advantages

Simple.

Fast.

Easy.

### Problem

Suppose:

```
A → Slow

B → Fast

C → Fast
```

Round Robin doesn't care.

It still sends equal traffic.

Good when servers are roughly identical.

---

## 2. Least Connections

Instead of taking turns...

```
Server A

2 users

Server B

75 users

Server C

4 users
```

Next request?

```
Server A
```

Because it currently has the fewest active connections.

Useful when requests take different amounts of time, such as long-running uploads or WebSocket connections. ([Wasil Zafar][2])

---

## 3. Weighted Round Robin

Suppose your servers aren't equal.

```
Server A

64 GB RAM

Server B

16 GB RAM

Server C

16 GB RAM
```

Should they receive equal traffic?

No.

Weights let stronger servers receive more requests.

Example:

```
A = 60%

B = 20%

C = 20%
```

Very common in production.

---

## 4. IP Hash / Sticky Sessions

Some applications need the same user to keep hitting the same server.

Example:

```
Ali logs in.

↓

Server A stores session in memory.

↓

Next request goes to Server C.

↓

Server C says:

Who are you?
```

Oops.

The session was only on Server A.

A load balancer can hash the client IP (or use a session cookie) so that the same client keeps reaching the same backend.

Today, architects often prefer **stateless services** and store session data in shared stores like Redis, reducing the need for sticky sessions. Sticky sessions are still useful in some workloads but introduce operational trade-offs. ([Khushal Agrawal][3])

---

# Software Architect's Thinking

Suppose you're designing a Chat App.

You ask:

> How many users?

Answer:

```
300 users.
```

Do you need a load balancer?

Probably not.

One server is enough.

Now imagine:

```
10 million users.
```

Immediately your architecture changes.

```
Users

↓

Load Balancer

↓

20 Chat Servers

↓

Redis

↓

Database
```

Notice something important:

The architecture evolved because **the requirements changed**.

Architecture is always driven by requirements—not by trends.

---

# Real-World Examples

### Netflix

Millions of users request movies simultaneously.

A load balancer distributes requests across many application servers before those servers fetch metadata or streaming information. ([Grokking System Design][1])

---

### Amazon

During Black Friday:

```
Millions of requests

↓

Load Balancers

↓

Thousands of servers
```

If one server fails, users are transparently routed to others.

---

### Google Search

You type:

```
google.com
```

You're not talking to one machine.

Your request is routed through layers of networking and load balancing before reaching an appropriate backend service. ([Design Gurus][4])

---

# Tools You'll Encounter

As an architect, you don't need to master all of them immediately. Just know what role they play.

| Tool                                    | Why it's used                                         |
| --------------------------------------- | ----------------------------------------------------- |
| Nginx                                   | Reverse proxy and software load balancer              |
| HAProxy                                 | High-performance TCP/HTTP load balancing              |
| Envoy                                   | Modern service proxy used with microservices          |
| Traefik                                 | Dynamic load balancer, popular with Docker/Kubernetes |
| AWS Elastic Load Balancer (ELB/ALB/NLB) | Managed cloud load balancing                          |
| Kubernetes Service + Ingress            | Distribute traffic across Pods inside Kubernetes      |

---

# Practice (Architect Mindset)

Imagine you're building **DevEvent** (one of your own projects).

Current requirements:

* 500 daily users
* 20 concurrent users
* Single VPS
* PostgreSQL database

**Question 1:** Would you introduce a load balancer? Why or why not?

Now imagine the requirements change:

* 3 million users
* Multiple backend servers
* Zero downtime during deployments
* High availability is required

**Question 2:** Sketch a high-level architecture. Where would the load balancer sit? How many backend instances would you start with? How would you handle a server failure?

Don't worry about the "correct" answer—what matters is practicing the architectural reasoning behind your decisions.

---

## Next Lesson

The next topic should be **Caching**.

We'll cover it from a software architect's perspective, including:

* Why caches exist (it's **not** just "to make things faster")
* Cache-aside vs Read-through vs Write-through vs Write-back
* Local cache vs Distributed cache
* Redis architecture
* Cache invalidation (the hardest problem)
* TTL, eviction policies, cache warming
* What should and should **not** be cached
* Designing caching for real systems like YouTube, WhatsApp, and E-commerce.

[1]: https://www.grokkingsystemdesign.com/system-design-fundamentals?utm_source=chatgpt.com "System Design Fundamentals: The Complete Reference Guide (2026)"
[2]: https://www.wasilzafar.com/pages/series/system-design/system-design-load-balancing-caching.html?utm_source=chatgpt.com "System Design Series Part 3: Load Balancing & Caching - Wasil Zafar"
[3]: https://khushal.net/blog/system-design-chapter-one-scaling-notes/?utm_source=chatgpt.com "System Design Chapter 1 Notes: How Web Systems Start Scaling - Khushal Agrawal"
[4]: https://www.designgurus.io/blog/system-design-interview-fundamentals?utm_source=chatgpt.com "25 Fundamental System Design Concepts You Must Know Before Your Interview"
