Excellent. We've now reached one of the most important components of modern Internet architecture.

Many beginners think:

> **CDN = Faster Images**

That's true...

But that's only a tiny part of the story.

A software architect thinks:

> **"My users are spread across the world. How do I deliver content quickly without making every request travel thousands of kilometers?"**

A CDN solves **latency**, **origin server load**, **availability**, and often **security** by moving content closer to users. In large-scale systems, it becomes part of the overall architecture—not just a performance optimization. ([System Internals][1])

---

# Topic 5 — Content Delivery Network (CDN)

## Imagine you're the architect...

You've built a website.

Your infrastructure looks like this:

```text
Users

↓

Server (Germany)
```

Everything works.

---

Now your application becomes global.

Users are from:

```text
Pakistan

India

Japan

Australia

USA

Brazil
```

But...

The server is still in Germany.

---

## The Real Problem

Imagine a user in Pakistan requests:

```text
logo.png
```

The request travels:

```text
Pakistan

↓

Germany

↓

Pakistan
```

Maybe 200–300 ms just because of geography.

Now imagine the homepage contains:

```text
100 Images

20 JavaScript Files

10 CSS Files

Fonts

Videos
```

Every one of those files travels across continents.

Your server works harder.

Users wait longer.

---

# The Architect's Question

Instead of asking

> "How can I make my server faster?"

Ask

> **"Why is every user, regardless of where they live, talking to the same server?"**

That's the real architectural problem.

---

# The Solution

Instead of one server...

Create copies around the world.

```text
Pakistan

↓

CDN Edge

India

↓

CDN Edge

USA

↓

CDN Edge

Germany

↓

Origin Server
```

Now Pakistani users download from Pakistan (or the nearest available edge).

Americans download from America.

Japanese users download from Japan.

Nobody needs to cross the world for every request.

This dramatically reduces network latency because data travels a much shorter distance. ([System Internals][1])

---

# What is a CDN?

A **Content Delivery Network** is

> **A globally distributed network of servers that stores copies of your content and serves users from the nearest location.**

Notice something important.

A CDN is **not your main storage**.

Your original files still exist somewhere.

That location is called the **Origin**.

---

# Real World Analogy

Imagine Netflix had one DVD store.

Located only in Germany.

Everyone worldwide orders from that store.

Terrible.

Instead...

Netflix builds thousands of local distribution centers.

```text
Germany

Pakistan

Japan

USA

Australia
```

Customers receive movies from the nearest warehouse.

Exactly what a CDN does.

---

# The Basic Architecture

Without CDN:

```text
User

↓

Origin Server
```

With CDN:

```text
User

↓

Nearest CDN Server

↓

Origin Server
```

Notice:

The user almost never talks directly to the origin.

---

# Origin Server

The **Origin** is the source of truth.

Example:

```text
Origin

↓

logo.png
```

When content changes...

The origin is updated.

Everything else eventually gets updated from it.

Think of the origin as the master copy.

---

# Edge Server

Every CDN location contains **Edge Servers**.

These are the machines close to users.

Example:

```text
Pakistan

↓

Edge

Japan

↓

Edge

USA

↓

Edge
```

These edge servers store cached copies of your files.

They're designed to respond quickly because they're geographically close to users. ([pranaybathini.com][2])

---

# Point of Presence (PoP)

You'll hear this term constantly.

A **PoP (Point of Presence)** is simply:

> **A physical CDN location (data center) in a city or region.**

Example:

```text
Cloudflare

↓

Lahore PoP

↓

Dubai PoP

↓

Tokyo PoP

↓

London PoP
```

Each PoP contains multiple edge servers.

Think:

```text
CDN

↓

PoP

↓

Edge Servers
```

---

# Request Flow

Let's follow one request.

User:

```text
Pakistan
```

Requests:

```text
logo.png
```

Step 1

```text
User

↓

Nearest Edge
```

Does the edge already have it?

---

## Cache Hit

If yes:

```text
Edge

↓

Return logo.png
```

Done.

The origin isn't contacted.

Very fast.

---

## Cache Miss

Suppose it's the first request.

```text
Edge

↓

Origin Server

↓

Download logo.png

↓

Store Locally

↓

Return User
```

Next request?

Cache Hit.

This "pull" model is how most modern CDNs work by default. ([System Internals][1])

---

# Why Does a CDN Exist?

Architecturally, it solves multiple problems.

| Problem          | Without CDN     | With CDN             |
| ---------------- | --------------- | -------------------- |
| Global latency   | High            | Low                  |
| Origin bandwidth | High            | Much lower           |
| Server overload  | Possible        | Greatly reduced      |
| Availability     | Single location | Distributed globally |
| Scalability      | Limited         | Much easier          |

Notice...

It's **not only about speed**.

It's also about reducing work for your infrastructure.

---

# What Should Be Cached?

Architects ask:

> "Is this content the same for every user?"

If yes...

Great CDN candidate.

Examples:

```text
Images

CSS

JavaScript

Fonts

Videos

PDFs

Downloads

Company Logo
```

These files rarely change and are requested by many users.

Perfect.

---

# What Should NOT Be Cached?

Usually:

```text
Shopping Cart

Bank Balance

OTP

Payment Response

Private Dashboard
```

These are user-specific.

Caching them incorrectly could expose private information.

Modern CDNs can cache dynamic content safely in some cases, but architects must design cache keys and authorization rules carefully. ([SystemForces][3])

---

# CDN vs Cache

Students often ask:

> Isn't a CDN just another cache?

Kind of...

But not exactly.

Think of it this way.

Redis:

```text
Application

↓

Redis

↓

Database
```

Purpose:

Reduce database work.

---

CDN:

```text
User

↓

Edge Server

↓

Origin
```

Purpose:

Reduce network distance.

Different bottlenecks.

Different solutions.

---

# CDN + Object Storage

Remember our Storage lesson?

We said:

Videos go into Object Storage.

Now combine that with a CDN.

```text
User

↓

CDN

↓

Object Storage

↓

Origin
```

Example:

```text
Video.mp4

↓

Amazon S3

↓

CloudFront

↓

Users
```

Notice:

The object storage is still the source.

The CDN simply distributes copies.

This is one of the most common production architectures.

---

# Static vs Dynamic Content

Architects classify content.

---

## Static

Same for everyone.

```text
Logo

CSS

Images

Fonts

JS Bundle
```

Excellent CDN candidates.

Often cached for months.

---

## Semi-Dynamic

Changes occasionally.

Examples:

```text
News Homepage

Trending Products

Blog Posts
```

Can still use CDN.

Just shorter cache durations.

---

## Dynamic

Changes every request.

```text
Dashboard

Shopping Cart

Live Scores

Bank Balance
```

Usually goes directly to the origin or uses carefully designed edge caching policies. ([pranaybathini.com][2])

---

# Cache-Control & TTL

How does the CDN know **how long** to keep a file?

The origin sends HTTP headers.

Example:

```http
Cache-Control: public, max-age=86400
```

Meaning:

```text
Cache for 1 day.
```

After the TTL expires:

The CDN checks the origin again.

Architects choose TTL based on how frequently content changes.

---

# Cache Invalidation

Suppose:

```text
logo.png
```

was replaced.

But...

The CDN still has the old logo.

Oops.

Solutions:

* Wait for TTL to expire.
* Purge the cache manually.
* Use versioned filenames.

Large systems often use **content hashing**:

```text
logo.a8d32.png
```

Update the file?

```text
logo.f91bc.png
```

New filename.

Problem solved.

Versioned assets are one of the most reliable cache invalidation strategies. ([SystemForces][3])

---

# Push vs Pull CDN

There are two main ways content reaches the CDN.

## Pull CDN (Most Common)

```text
User

↓

CDN

↓

Origin
```

The CDN fetches the file only when someone requests it.

Advantages:

* Simple
* Automatic
* Only popular files get cached

---

## Push CDN

Instead:

```text
Origin

↓

CDN
```

Whenever content changes...

You explicitly upload it to the CDN.

Useful for:

* Large media libraries
* Controlled deployments
* Predictable updates

Most websites use **pull CDNs** because they're easier to operate. ([System Internals][1])

---

# Anycast Routing

This sounds complicated.

The idea isn't.

Imagine Cloudflare owns:

```text
Lahore

Dubai

Singapore

Tokyo
```

All advertise the **same public IP address**.

When you connect...

The Internet automatically routes you to the nearest healthy location using network routing (BGP).

You don't choose.

The network chooses.

That's one reason CDNs can scale globally without users knowing which data center they're reaching. ([System Internals][1])

---

# Origin Shield

Imagine:

100 CDN locations all miss the cache simultaneously.

Without protection:

```text
100 Edge Servers

↓

Origin
```

The origin suddenly gets flooded.

Instead:

```text
Edge

↓

Regional Shield

↓

Origin
```

The shield fetches the file once.

Other edges reuse it.

Origin load drops dramatically.

This extra caching layer is called **Origin Shield**. ([System Internals][1])

---

# Software Architect's Thinking

Imagine you're designing **DevEvent**.

Current requirements:

* 500 users
* Pakistan only
* Small VPS
* Banner images

Would you add a CDN?

Probably not.

The complexity may not be worth it.

---

Now imagine:

* 50 million users
* Global audience
* Large banner images
* PDFs
* Event recordings
* Mobile app

Architecture changes:

```text
Users

↓

CDN

↓

Load Balancer

↓

Application Servers

↓

Redis

↓

PostgreSQL

↓

Object Storage
```

Notice something.

We didn't add a CDN because it's trendy.

We added it because:

* Users are global.
* Static content is large.
* Origin bandwidth becomes expensive.
* Latency matters.

Again:

> **Requirements → Bottleneck → Architectural Solution**

That's how architects think.

---

# Real-World Examples

### YouTube

* Video files stored in object storage.
* CDN delivers video chunks from edge locations.
* The origin is contacted mainly on cache misses or when content isn't yet distributed.

---

### Netflix

Netflix places popular content close to ISPs and users so that streams come from nearby caches instead of distant data centers, reducing latency and origin traffic. ([System Internals][1])

---

### Instagram

* Profile pictures
* Story images
* Static JavaScript bundles
* CSS

These are excellent CDN candidates because millions of users request the same assets repeatedly.

---

# Common CDN Providers

| Provider          | Typical Use                                  |
| ----------------- | -------------------------------------------- |
| Cloudflare        | CDN + DNS + DDoS protection + edge features  |
| Amazon CloudFront | AWS-native CDN                               |
| Google Cloud CDN  | Google Cloud workloads                       |
| Fastly            | Low-latency edge delivery and compute        |
| Akamai            | Enterprise-grade global CDN                  |
| Bunny.net         | Cost-effective CDN for many web applications |

Again, remember the role—not the product.

---

# Practice (Architect Mindset)

You're designing a platform similar to **Coursera**.

Requirements:

* Course videos
* PDF notes
* Instructor profile images
* JavaScript bundles
* Student dashboard
* Quiz submissions
* Live exam timer

For each item, answer:

| Resource           | Should it use a CDN? | Why? |
| ------------------ | -------------------- | ---- |
| Course videos      | ?                    | ?    |
| PDF notes          | ?                    | ?    |
| Profile images     | ?                    | ?    |
| JavaScript bundles | ?                    | ?    |
| Student dashboard  | ?                    | ?    |
| Quiz submissions   | ?                    | ?    |
| Live exam timer    | ?                    | ?    |

As an architect, your decisions should be based on:

* Is the content public or user-specific?
* Does it change frequently?
* Is it accessed globally?
* Is latency more important than freshness?
* Can stale content be tolerated?

If you can justify each decision with those questions, you're thinking like a software architect rather than simply "using a CDN because everyone else does."

---

# High-Level Design Milestone

You've now covered five of the most important infrastructure building blocks:

1. **Load Balancing** → Distributes traffic across servers.
2. **Caching** → Eliminates repeated expensive work.
3. **Queues** → Moves non-urgent work out of the user request path.
4. **Storage** → Chooses the right persistence technology for each type of data.
5. **CDN** → Brings content physically closer to users.

Notice that each one addresses a **different bottleneck**. A key skill for a software architect is recognizing **which bottleneck exists first**, then selecting the appropriate architectural pattern to solve it.

[1]: https://systeminternals.dev/system-design-interview/cdn/?utm_source=chatgpt.com "Design a Content Delivery Network (CDN) | Systems Explained"
[2]: https://pranaybathini.com/learn/system-design-fundamentals/14-cdn-edge-computing?utm_source=chatgpt.com "CDN and Edge Computing | System Design Fundamentals | Pranay Bathini"
[3]: https://www.systemforces.com/blog/cdn-system-design-when-and-how-to-use-a-cdn?utm_source=chatgpt.com "CDN in System Design: When and How to Use a Content Delivery Network | SystemForces"
