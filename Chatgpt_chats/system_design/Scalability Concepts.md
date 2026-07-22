# 17. Scalability

Imagine you built a food delivery app. Initially, you have **100 users**, then suddenly one day **100,000 users** arrive because someone famous shared your app.

**Question:** Will your app survive?

If yes, your app is **scalable**.

> **Scalability = The ability of a software system to handle increasing (or decreasing) workload without becoming slow or crashing.** ([Microsoft Learn][1])

Think of scalability as planning a city.

* More people → More roads
* More houses
* Better traffic control
* More electricity

Software is exactly the same.

---

# When do we need Scalability?

Without scalability:

```
10 Users
   │
Server 😊

100 Users
   │
Server 😅

1000 Users
   │
Server 🥵

10000 Users
   │
Server 💀
```

With scalability

```
10000 Users

      │
Load Balancer
  /    |    \
App1 App2 App3
  │     │    │
 Redis Cache
      │
 Database
```

Each new component solves one bottleneck.

---

# The Biggest Bottlenecks

Most applications become slow because of one of these:

* CPU becomes busy
* RAM becomes full
* Database becomes overloaded
* Network bandwidth becomes saturated
* Disk becomes slow
* Too many users hitting the same server

Scalability techniques solve these one by one.

---

# 1. Vertical Scaling (Scaling Up)

⭐⭐⭐⭐⭐ Must Know

## What problem does it solve?

Your server is simply too weak.

Example

Current Server

```
2 CPU
4GB RAM
```

Your app becomes slow.

Instead of changing your architecture...

You buy a stronger server.

```
16 CPU
64GB RAM
```

Done.

---

## How does it solve the problem?

Instead of adding more machines...

You make **one machine more powerful.**

```
Before

Users
   │
Small Server

After

Users
   │
Very Powerful Server
```

---

## Real World Example

A startup launches an MVP.

Initially

```
1 VPS
```

After 6 months

They upgrade to

```
More RAM
More CPU
NVMe SSD
```

No architecture changes required.

---

## Advantages

✅ Very easy

✅ No code changes

✅ Fast upgrade

---

## Disadvantages

❌ Hardware has limits

You cannot keep buying bigger servers forever.

Eventually you'll reach:

```
Largest AWS Instance
```

Then?

Nothing bigger exists.

---

## Related Tools

* AWS EC2
* Azure Virtual Machines
* Google Compute Engine
* DigitalOcean Droplets

---

## Practice Idea

Deploy a small Express/FastAPI app.

Run load tests.

Increase server RAM.

Observe performance changes.

---

# 2. Horizontal Scaling (Scaling Out)

⭐⭐⭐⭐⭐ Must Know

## Problem

One server isn't enough anymore.

Instead of buying a monster server...

Buy many normal servers.

---

## How does it solve the problem?

Instead of

```
Users
  │
Server
```

You get

```
Users

    │
Load Balancer
  /   |    \
App1 App2 App3
```

Now requests are shared.

Each server works less.

Horizontal scaling lets capacity grow by adding more machines rather than relying on one bigger machine. ([Microsoft Learn][1])

---

## Real World Example

Netflix doesn't run on one server.

Thousands of servers work together.

Same for:

* Google
* Facebook
* YouTube
* Amazon

---

## Advantages

✅ Nearly unlimited growth

✅ Fault tolerant

✅ High availability

---

## Disadvantages

More complex

Need:

* Load balancer
* Shared database
* Distributed cache
* Monitoring

---

## Related Tools

* Docker
* Kubernetes
* AWS ECS
* Azure AKS
* Google GKE

---

## Practice

Run

```
3 Express servers
```

Place

```
NGINX
```

in front.

Watch traffic distribute.

---

# Vertical vs Horizontal

| Vertical             | Horizontal        |
| -------------------- | ----------------- |
| Bigger server        | More servers      |
| Easy                 | More complex      |
| Limited              | Highly scalable   |
| Cheap initially      | Better long-term  |
| Single failure point | Better redundancy |

A common path is **scale up first**, then **scale out** when one machine becomes the bottleneck. ([Redis][2])

---

# 3. Caching

⭐⭐⭐⭐⭐ Must Know

## Problem

Your database keeps receiving the same query.

Example

```
SELECT Product WHERE id=1
```

One million users ask for it.

Database performs

```
Same query

Again

Again

Again

Again...
```

Waste of work.

---

## Solution

Store the answer somewhere faster.

```
User

↓

Cache

↓

Database
```

If cache already has it

Database isn't touched.

---

## Real World Example

Instagram profile.

Millions open Cristiano Ronaldo's profile.

Instagram doesn't query the database every time.

It caches popular data.

Caching improves scalability by serving repeated requests from memory instead of repeatedly querying slower storage. ([Google Cloud Documentation][3])

---

## Advantages

Very fast

Reduces DB load

Lower latency

Cheaper

---

## Disadvantages

Cache can become outdated.

Need expiration policies.

---

## Related Tools

* Redis
* Memcached
* Cloudflare Cache

---

## Practice

Cache API responses for

```
60 seconds
```

Measure response time before and after.

---

# 4. Redis

⭐⭐⭐⭐⭐ Must Know

Redis is the most popular cache you'll encounter.

---

## Problem

Reading database is slow.

Need something extremely fast.

---

## Solution

Redis stores data **in RAM**, so reads and writes are extremely fast—often in sub-millisecond time. It can act as a cache, database, message broker, and more. ([Redis][4])

```
Database

↓

Redis

↓

Application
```

---

## Example

Instead of

```
SELECT * FROM Products
```

every request...

Store

```
products:list
```

inside Redis.

Next request

```
Redis

↓

Done
```

---

## Common Uses

* Sessions
* Login tokens
* Shopping carts
* Leaderboards
* API cache
* Rate limiting
* Queues

---

## Tools

* Redis
* Redis Insight
* Upstash Redis

---

## Practice

Cache weather API results.

Measure:

Without Redis

With Redis

---

# 5. Load Balancing

⭐⭐⭐⭐⭐ Must Know

## Problem

One server receives every request.

```
10000 users

↓

One Server
```

Server dies.

App dies.

---

## Solution

Add a traffic manager.

```
Users

↓

Load Balancer

↓

App1

App2

App3
```

Requests are spread across healthy servers, improving throughput and availability. ([Google Cloud Documentation][3])

---

## Real World Example

Amazon

When millions shop during Black Friday

Traffic is distributed across thousands of servers.

---

## Algorithms

Round Robin

```
1→A

2→B

3→C

4→A
```

Least Connections

```
Send request to least busy server
```

IP Hash

Same user

→ Same server

---

## Related Tools

* NGINX
* HAProxy
* Traefik
* AWS Elastic Load Balancer
* Cloudflare Load Balancing

---

## Practice

Run

```
3 FastAPI servers
```

Place NGINX before them.

Refresh browser repeatedly.

Watch logs.

---

# 6. CDN (Content Delivery Network)

⭐⭐⭐⭐⭐ Must Know

## Problem

Users are worldwide.

Your server is only in Germany.

Pakistan users wait.

Australia users wait even longer.

---

## Solution

Copy static files around the world.

```
Pakistan

↓

Local CDN Server

↓

Image
```

Instead of

```
Pakistan

↓

Germany
```

CDNs cache static assets close to users, reducing latency and offloading work from your origin servers. ([Google Cloud Documentation][3])

---

## Real World Example

YouTube videos

Netflix thumbnails

GitHub CSS

Images

JS files

Fonts

---

## Benefits

Faster

Less latency

Less bandwidth

Less server load

---

## Related Tools

* Cloudflare
* AWS CloudFront
* Fastly
* Akamai

---

## Practice

Deploy a website.

Serve images via Cloudflare.

Measure page load before and after.

---

# 7. Autoscaling

⭐⭐⭐⭐⭐ Must Know

## Problem

Traffic changes every hour.

Night

```
100 users
```

Morning

```
50,000 users
```

Buying servers for the peak wastes money.

---

## Solution

Automatically add or remove servers.

```
Traffic ↑

↓

More Servers

Traffic ↓

↓

Remove Servers
```

Autoscaling automatically adjusts compute capacity based on predefined rules or metrics such as CPU, memory, or request rate. ([Microsoft Learn][1])

---

## Real World Example

Food delivery app

Lunch

Many servers

Midnight

Few servers

---

## Related Tools

* Kubernetes HPA
* AWS Auto Scaling
* Azure Autoscale
* Google Managed Instance Groups

---

## Practice

Deploy a containerized app to Kubernetes.

Configure HPA.

Generate traffic with a load-testing tool and watch pods scale.

---

# 8. Database Optimization

⭐⭐⭐⭐⭐ Must Know

## Problem

Database is slow.

Even if servers are fast.

---

## Solution

Make queries efficient.

Common techniques

* Add indexes
* Remove unnecessary joins
* Normalize or denormalize where appropriate
* Use pagination
* Avoid `SELECT *`
* Cache hot queries
* Batch operations

---

## Real World Example

E-commerce

Instead of

```
SELECT *
```

Use

```
SELECT
name,
price
```

Much less data travels.

---

## Related Tools

* PostgreSQL EXPLAIN / EXPLAIN ANALYZE
* MySQL EXPLAIN
* pgAdmin
* DBeaver

---

## Practice

Create a table with

```
1 Million rows
```

Run a query.

Add an index.

Compare execution time.

---

# 9. Read Replicas

⭐⭐⭐⭐⭐ Must Know

## Problem

Database receives

```
1000 writes

100000 reads
```

Reads overload the primary database.

---

## Solution

Copy data to replica databases.

```
          Write

            │

Primary DB

  │      │

Replica Replica

Reads   Reads
```

The primary handles writes, while replicas serve read queries, increasing read capacity and reducing pressure on the primary. Replication is asynchronous in many systems, so replicas may briefly lag behind the primary. ([Redis][5])

---

## Real World Example

An online store

Customer places order

→ Write to Primary

Thousands browse products

→ Read from Replicas

---

## Advantages

Fast reads

Primary stays healthy

Easy scaling

---

## Disadvantages

Replication lag

Newly written data might not appear on a replica immediately.

---

## Related Tools

* PostgreSQL Streaming Replication
* MySQL Replication
* Amazon Aurora Read Replicas
* Google Cloud SQL Read Replicas

---

## Practice

Run PostgreSQL with one primary and one replica using Docker.

Send:

* INSERTs → Primary
* SELECTs → Replica

Observe how reads and writes are separated.

---

# How These Pieces Fit Together

A scalable web application often evolves into something like this:

```text
                 Users
                   │
              ┌───────────┐
              │    CDN    │   ← Images, CSS, JS
              └─────┬─────┘
                    │
            ┌──────────────┐
            │ Load Balancer│
            └───┬────┬─────┘
                │    │
         ┌──────▼┐ ┌─▼─────┐
         │ App 1 │ │ App 2 │   ← Horizontally scaled
         └──┬────┘ └──┬────┘
            │          │
        ┌───▼──────────▼───┐
        │      Redis       │   ← Cache
        └────────┬─────────┘
                 │
           ┌─────▼─────┐
           │ Primary DB│   ← Writes
           └─────┬─────┘
          ┌──────▼──────┐
          │ Read Replica│   ← Reads
          └─────────────┘
```

This architecture is common because each layer removes a different bottleneck: the CDN speeds up static content, the load balancer distributes traffic, horizontal scaling increases application capacity, Redis reduces repeated database work, and read replicas let the database serve many more read requests without overwhelming the primary.

[1]: https://learn.microsoft.com/en-us/azure/well-architected/performance-efficiency/scale-partition?utm_source=chatgpt.com "Architecture strategies for optimizing scaling and partitioning - Microsoft Azure Well-Architected Framework | Microsoft Learn"
[2]: https://redis.io/tutorials/operate/redis-at-scale/scalability/?utm_source=chatgpt.com "Scaling Redis: Clustering, Sharding, and Read Replicas Guide"
[3]: https://docs.cloud.google.com/architecture/scalable-and-resilient-apps?utm_source=chatgpt.com "Patterns for scalable and resilient apps  |  Cloud Architecture Center  |  Google Cloud Documentation"
[4]: https://redis.io/tutorials/what-is-redis/?utm_source=chatgpt.com "What is Redis? In-memory database, cache, and message broker"
[5]: https://redis.io/wp-content/uploads/2021/12/caching-at-scale-with-redis-updated-2021-12-04.pdf?utm_source=chatgpt.com "Caching at Scale"
