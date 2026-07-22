Excellent. This is probably **the most misunderstood topic in System Design**.

Most beginners think:

> "Cache makes things faster."

That's true, but it's only **10% of the story**.

A software architect thinks differently:

> **"Which part of my system is becoming a bottleneck? Can I avoid doing that expensive work repeatedly?"**

Caching is fundamentally about **avoiding unnecessary work**, which improves latency, reduces database load, lowers infrastructure cost, and increases scalability. Modern architectures rely heavily on caching because databases are optimized for durability, not for serving the same popular data millions of times. ([Redis][1])

---

# Topic 2 — Caching

## Imagine you're the architect...

You're building an E-commerce website.

A user opens:

```
Homepage
```

Your backend does:

```
Browser

↓

Backend

↓

Database

↓

Return Products
```

Works perfectly.

---

Ten seconds later...

Another user opens the homepage.

Again:

```
Backend

↓

Database

↓

Return Products
```

---

Another user.

Again.

```
Database

Database

Database

Database

Database
```

Eventually...

One million users open the homepage.

Your database now receives **one million identical queries.**

---

# The Real Problem

Notice something.

The database is doing the **same work repeatedly.**

Imagine asking someone:

> What's 2 + 2?

They answer:

```
4
```

Five seconds later...

You ask again.

```
What's 2 + 2?
```

Again.

Again.

Again.

Eventually they'd say:

> **"I already told you!"**

Your database feels exactly the same.

---

# The Architect's Question

Instead of asking

> "How do I make the database faster?"

Ask

> **"Why am I asking the database the same question over and over?"**

That's architectural thinking.

---

# The Solution

Store the answer somewhere much faster.

```
Browser

↓

Backend

↓

Cache

↓

Database
```

Now the flow becomes:

```
Need Product?

↓

Check Cache

↓

Found?

↓

Yes

↓

Return immediately
```

No database.

---

# What is a Cache?

A cache is simply:

> **A temporary, very fast storage that keeps frequently used data in memory.**

Memory (RAM) is much faster than disk.

Approximate access times:

| Storage      | Speed        |
| ------------ | ------------ |
| CPU Cache    | Nanoseconds  |
| RAM (Redis)  | Microseconds |
| SSD Database | Milliseconds |

Milliseconds sound fast...

Until you're serving **100 million requests/day**.

Those milliseconds become expensive.

---

# Real World Analogy

Imagine a librarian.

Without cache:

```
Student asks

↓

Walk to storage room

↓

Find book

↓

Return
```

Every single time.

---

With cache:

```
Popular books

↓

Kept on desk

↓

Return instantly
```

Same information.

Much less work.

---

# Where Does Cache Sit?

A common architecture looks like:

```
Users

↓

Load Balancer

↓

Application Servers

↓

Redis Cache

↓

Database
```

Notice:

The database still exists.

Cache **does not replace it.**

It simply answers repeated questions.

---

# Cache Hit vs Cache Miss

These two words appear everywhere.

## Cache Hit

```
Need User #15

↓

Cache has it

↓

Return immediately
```

Database isn't touched.

Fast.

---

## Cache Miss

```
Need User #15

↓

Cache doesn't have it

↓

Ask Database

↓

Store in Cache

↓

Return User
```

Next request becomes a hit.

---

# The Golden Rule

A cache is **not the source of truth.**

The database is.

Always.

Think of the cache as a photocopy.

The original document is still in the filing cabinet.

---

# What Should Be Cached?

Architects don't cache everything.

They ask:

> **"Will this data be requested repeatedly?"**

Great candidates:

✅ Product catalog

✅ User profiles

✅ Categories

✅ Blog posts

✅ Country list

✅ Currency rates

✅ Frequently viewed videos

Because many users request the same data repeatedly.

---

# What Should NOT Be Cached?

Imagine:

```
Current Bank Balance

Live Auction Price

OTP Code

Stock Price
```

These change constantly.

Serving stale data could cause incorrect behavior or security issues.

Caching these requires extra care—or sometimes shouldn't be done at all.

---

# Read Heavy vs Write Heavy Systems

This is one of the biggest architectural decisions.

---

## Read Heavy

Example:

YouTube

For every upload:

Millions of video views.

```
Reads

Reads

Reads

Reads

1 Write
```

Perfect for caching.

---

## Write Heavy

Example:

Trading platform.

Prices update constantly.

```
Write

Write

Write

Write

Read
```

Caching becomes much harder because data changes so often.

Architects always consider the **read-to-write ratio** before introducing a cache. Cache-aside is especially effective for read-heavy workloads because only frequently requested data is stored. ([Redis][1])

---

# Where Can We Cache?

Many people think:

```
Redis
```

That's only one layer.

Modern systems often have **multiple caches**.

```
Browser Cache

↓

CDN Cache

↓

Application Cache

↓

Redis

↓

Database
```

Every layer removes work from the next one.

We'll revisit these layers again when we discuss CDNs.

---

# Local Cache vs Distributed Cache

This is an important architectural decision.

## Local Cache

```
Server A

Memory

↓

Cache
```

Each server keeps its own cache.

Advantages:

* Very fast
* No network call
* Easy to implement

Problems:

```
Server A

Product = $50

Server B

Product = $45
```

Oops.

Data is inconsistent.

Each server cached different values.

---

## Distributed Cache

Instead:

```
Server A

↓

Redis

↑

Server B
```

Everyone uses the same cache.

Advantages:

* Consistent
* Shared
* Easy to invalidate

Trade-off:

Slightly slower than local memory because it requires a network call.

Distributed caches are the standard choice for horizontally scaled applications. ([Redis][1])

---

# Redis

Redis is the most common distributed cache.

Architecturally:

```
App

↓

Redis

↓

Database
```

Redis stores data in RAM.

Which means:

* Extremely fast
* Key-Value storage
* Supports TTL
* Supports replication
* Can also act as a message broker (we'll discuss that in Queues)

---

# Cache-Aside (Lazy Loading)

This is the **most common caching strategy** you'll encounter.

Flow:

```
Need User

↓

Check Cache

↓

Found?

↓

Yes → Return

↓

No

↓

Read Database

↓

Store in Cache

↓

Return
```

Notice:

The application controls both the cache and the database.

The cache only fills **when someone asks for data**.

That's why it's called **Lazy Loading**.

Most production systems using Redis follow this pattern because it caches only the data that's actually requested. ([Redis][1])

---

# Write Through

Suppose someone updates a product.

Instead of:

```
Database Only
```

We update:

```
Database

AND

Cache
```

at the same time.

Advantages:

* Cache stays fresh.
* Reads are almost always cache hits.

Disadvantage:

You also cache data that might never be read, increasing memory usage. ([AWS Documentation][2])

---

# Write Back (Write Behind)

Different idea.

Instead of:

```
User

↓

Database

↓

Done
```

We do:

```
User

↓

Cache

↓

Return Immediately

↓

Database Updated Later
```

Very fast writes.

But risky.

If the cache crashes before writing to the database...

Data may be lost.

Used only in specialized workloads.

---

# TTL (Time To Live)

Caches cannot keep data forever.

Each item gets an expiration time.

Example:

```
Product #15

TTL = 10 Minutes
```

After 10 minutes:

```
Deleted
```

Next request goes back to the database.

TTL prevents caches from serving stale data forever and helps manage memory automatically. ([Redis][1])

---

# Cache Invalidation

There's a famous saying:

> **"There are only two hard things in Computer Science: cache invalidation and naming things."**

Imagine:

```
Database

Price = $200
```

Cache:

```
Price = $180
```

Oops.

Customer sees the wrong price.

So when data changes, architects must decide:

* Delete the cache entry?
* Update it immediately?
* Let TTL expire?
* Publish an event to invalidate caches across services?

Keeping cache and database synchronized is one of the hardest parts of distributed systems. ([Microsoft Learn][3])

---

# Cache Eviction

Memory isn't infinite.

Eventually Redis becomes full.

What should it remove?

Common policies:

### LRU (Least Recently Used)

Remove data nobody has used recently.

Example:

```
Viewed:

A

B

C

A

A

D
```

B gets removed before A.

Very common.

---

### LFU (Least Frequently Used)

Instead of recency:

Count usage.

```
A → 500 times

B → 2 times
```

Remove B.

Useful when some items stay popular over long periods.

---

### FIFO

Remove the oldest cached item first.

Simple, but less common for general-purpose caching.

---

# Cache Stampede

Imagine:

One million users request:

```
Homepage
```

The cache entry expires at exactly the same moment.

Now:

```
1,000,000 requests

↓

Database
```

Your database gets overwhelmed—the very thing the cache was meant to prevent.

Architects solve this with techniques like request coalescing (only one request repopulates the cache), distributed locks, staggered expirations (TTL jitter), or refreshing data before it expires. ([Redis][1])

---

# Software Architect's Thinking

Suppose you're building **DevEvent**.

Current requirements:

* 300 users
* One VPS
* PostgreSQL

Would you add Redis?

Probably not.

The database can easily handle the load.

Now imagine:

* 5 million users
* Homepage requested every second
* Trending events
* Popular organizers
* Event categories

Suddenly your architecture becomes:

```
Users

↓

Load Balancer

↓

Application Servers

↓

Redis Cache

↓

PostgreSQL
```

Notice the pattern?

We didn't add Redis because "Redis is cool."

We added it because the **requirements changed**.

This is how architects think:

> **Requirements → Bottleneck → Architectural Solution**

Never:

> Trend → Technology → Hope it helps.

---

# Real-World Examples

### YouTube

* Video metadata (title, views, channel)
* Popular recommendations
* Trending videos

These are read millions of times but updated relatively infrequently, making them excellent caching candidates.

---

### Amazon

* Product details
* Categories
* Search suggestions
* Frequently viewed items

Cached to reduce pressure on databases during heavy shopping periods.

---

### Instagram

* User profiles
* Public posts
* Feed fragments
* Follower counts (often cached briefly)

Serving these from memory dramatically reduces latency for repeated reads.

---

# Tools You'll Encounter

| Tool                | Purpose                                                      |
| ------------------- | ------------------------------------------------------------ |
| Redis               | Distributed in-memory cache (most common)                    |
| Memcached           | Simple distributed cache for key-value data                  |
| Caffeine            | High-performance local cache for Java applications           |
| Guava Cache         | Local in-process caching for Java                            |
| Spring Cache        | Abstraction for integrating caching into Spring applications |
| NestJS Cache Module | Built-in caching support (often backed by Redis)             |

---

# Practice (Architect Mindset)

Imagine you're designing **DevEvent**.

### Scenario 1

Requirements:

* 500 daily users
* Event details change rarely
* PostgreSQL on a single server

Ask yourself:

* Would you add a cache?
* If yes, what would you cache?
* If no, why not?

---

### Scenario 2

Requirements:

* 10 million users
* Homepage requested every second
* Trending events update every minute
* User profiles are viewed constantly

Design a high-level architecture and answer:

1. Which data would you cache?
2. Which data would you never cache?
3. Would you choose local cache or Redis?
4. What TTL would you assign to:

   * Event categories
   * Trending events
   * User profiles
   * Live attendee count
5. How would you keep the cache fresh when an event organizer edits an event?

Those are the kinds of questions senior engineers ask during architecture reviews.

---

### Next Topic

The next major building block is **Queues**, where we'll answer questions like:

* Why not do everything immediately?
* When should work happen asynchronously?
* Message Queue vs Event Bus
* RabbitMQ vs Kafka vs Redis Streams vs AWS SQS
* Producers, Consumers, Topics, Exchanges, Dead Letter Queues
* At-least-once vs At-most-once vs Exactly-once delivery
* Idempotency and retry strategies
* Designing background processing for systems like YouTube, Uber, and WhatsApp.

[1]: https://redis.io/docs/latest/develop/use-cases/cache-aside/?utm_source=chatgpt.com "Redis cache-aside | Docs"
[2]: https://docs.aws.amazon.com/whitepapers/latest/database-caching-strategies-using-redis/caching-patterns.html?utm_source=chatgpt.com "Caching patterns - Database Caching Strategies Using Redis"
[3]: https://learn.microsoft.com/en-us/azure/architecture/patterns/cache-aside?utm_source=chatgpt.com "Cache-Aside Pattern - Azure Architecture Center | Microsoft Learn"
