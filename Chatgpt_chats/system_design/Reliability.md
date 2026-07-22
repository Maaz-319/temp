# 18. Reliability (Making Software Survive Failures)

Imagine you built an online shopping app.

Everything works perfectly during development.

Then production happens.

* Database suddenly becomes slow.
* Payment gateway goes offline for 2 minutes.
* One server crashes.
* Network becomes unstable.
* Thousands of users visit because of Black Friday.

If your application crashes because of one small failure...

👉 It is **not reliable.**

Reliability is about building software that **continues working even when things go wrong.**

Big companies like Netflix, Google, Amazon and Uber assume failures are normal—not rare. They design systems expecting servers, databases, APIs and networks to fail every day. That's the core idea behind modern reliability engineering. ([Microsoft Learn][1])

---

# Reliability Mindset

Instead of asking

> "What if everything works?"

Ask

> "What happens when this breaks?"

Every component should answer that question.

```
Client
   │
   ▼
API Server
   │
 ├── Database ❌ Down
 │
 ├── Redis ❌ Slow
 │
 ├── Payment API ❌ Timeout
 │
 └── Email Service ❌ Failed

Can the app still work?

↓

Reliable systems say YES.
```

---

# Reliability Toolbox

These are the major building blocks.

⭐⭐⭐⭐⭐ Must Know

* Monitoring
* Logging
* Tracing
* Metrics
* Health Checks
* Retries
* Timeouts
* Graceful Degradation

⭐⭐⭐⭐ Good to Know

* Fallbacks
* Circuit Breaker (later)
* Bulkheads
* Rate Limiting

Let's learn them one by one.

---

# 1. Monitoring

## What problem does it solve?

Imagine your website crashes at 3 AM.

Nobody knows.

Users keep complaining.

Developers wake up after 5 hours.

Business loses money.

Without monitoring:

```
Problem happened

↓

Nobody knows

↓

Customers discover it first
```

Bad.

---

## How does Monitoring solve this?

Monitoring constantly watches your system.

It keeps checking

* Is server alive?
* CPU usage?
* Memory?
* Error rate?
* Database?
* API response time?
* Number of users?

If something becomes abnormal

↓

It alerts engineers immediately.

Modern monitoring is a foundation of reliability because recovery starts with detecting problems quickly. Good monitoring includes both technical signals (CPU, latency, errors) and business signals (orders, payments, signups). ([AWS Documentation][2])

---

## Real World Example

Netflix

Thousands of servers.

If one server dies,

Monitoring instantly detects it.

Traffic is shifted elsewhere.

Users usually never notice.

---

## Popular Tools

* Prometheus
* Grafana
* Datadog
* New Relic
* Dynatrace
* Azure Monitor
* Google Cloud Monitoring
* AWS CloudWatch

---

## Practice Idea

Create a small Node/Python API.

Monitor

* Requests
* CPU
* Memory

Visualize using

Prometheus + Grafana.

---

# 2. Logging

## Problem it solves

Your app crashes.

Why?

No idea.

Without logs you're basically blind.

---

## What are logs?

Logs are simply messages your application writes.

Example

```
User logged in

Payment started

Database connected

Payment failed

Retrying...

Payment success
```

Each event gets recorded.

---

## How Logging solves the problem

Instead of guessing

You can replay what happened.

Think of logs like CCTV footage.

Monitoring tells you

> Something is wrong.

Logs tell you

> What happened.

Structured logs with timestamps, error codes and request identifiers make troubleshooting much easier than plain text logs. ([Microsoft Learn][3])

---

## Real World Example

Uber payment failed.

Developer searches logs

```
Order ID 72819

↓

Payment API returned 503

↓

Retried after 2 seconds

↓

Success
```

Problem found.

---

## Popular Tools

* ELK Stack
* Loki
* Splunk
* Graylog
* Fluentd
* Fluent Bit

---

## Practice Idea

Build a Todo API.

Log

* Every request
* Errors
* Login
* Database queries

---

# 3. Tracing

## Problem it solves

Imagine this request

```
Client

↓

Gateway

↓

User Service

↓

Order Service

↓

Inventory

↓

Payment

↓

Notification
```

Payment failed.

Where?

Which service?

Which request?

Hard to know.

---

## How Tracing solves it

Every request gets a unique ID.

Example

```
Trace ID

9df82ac
```

Every service adds information.

```
Gateway

↓

Order

↓

Payment

↓

Inventory
```

Now you can see

Exactly where the request spent time.

Distributed tracing is especially valuable in microservices because a single user request often crosses many services. ([Google Cloud][4])

---

## Real World Example

Amazon checkout.

Checkout is slow.

Trace shows

```
Gateway

10ms

↓

Order

20ms

↓

Payment

4 seconds
```

Problem found.

---

## Popular Tools

* Jaeger
* Zipkin
* OpenTelemetry
* Grafana Tempo

---

## Practice

Create

```
Frontend

↓

API

↓

Database
```

Assign Trace ID.

Print it in every log.

---

# 4. Metrics

## Problem

You need numbers.

Not text.

Example

```
How many users?

Average latency?

Errors?

Memory?

CPU?
```

Logs cannot answer quickly.

---

## What are Metrics?

Metrics are numbers collected continuously over time.

Examples:

* Requests per second
* CPU usage
* RAM usage
* Response time
* Error rate
* Active users
* Queue length

Metrics help you see trends, create dashboards and trigger alerts before users notice issues. ([Google Cloud][4])

---

## Example

```
CPU

20%

25%

30%

90%

95%

99%
```

Immediately obvious.

---

## Real World Example

YouTube monitors

* Streaming latency
* Buffer rate
* Watch time
* Errors

---

## Popular Tools

* Prometheus
* Grafana
* Datadog
* CloudWatch

---

## Practice

Collect

```
Request Count

Average Response Time

Errors

Memory
```

Plot in Grafana.

---

# 5. Health Checks

## Problem

Suppose your server is alive.

But database isn't.

Should load balancer send traffic?

No.

---

## Health Check

A small endpoint.

Example

```
GET /health
```

Returns

```
Healthy
```

or

```
Unhealthy
```

Health endpoints can check not just the app process, but also important dependencies like databases, caches, and message brokers. External systems poll these endpoints to decide whether traffic should continue flowing to that instance. ([Microsoft Learn][5])

---

## Example

```
Server

↓

Health Check

↓

Database OK

Redis OK

Storage OK

↓

Healthy
```

---

## Real World Example

Kubernetes

Every few seconds

```
GET /health
```

If unhealthy

↓

Restart Pod automatically.

---

## Practice

Create

```
/health
```

Check

* Database
* Redis
* External API

---

# 6. Retries

## Problem

Network errors happen.

Example

```
Payment API

↓

Timeout
```

Maybe just temporary.

If you fail immediately,

You lose customers.

---

## Retry

Try again.

```
Attempt 1

Failed

↓

Attempt 2

Success
```

---

## Why it works

Many failures are temporary.

Examples

* Network hiccup
* Temporary overload
* Short restart

Retry solves these.

---

## Bad Retry

```
Retry

Retry

Retry

Retry

Retry

Retry
```

Immediately.

You make the server even worse.

---

## Good Retry

```
1 sec

↓

2 sec

↓

4 sec

↓

8 sec
```

This is called **Exponential Backoff**.

Reliable retry strategies combine timeouts, delays, retry limits, and respect server hints like the `Retry-After` header. Excessive retries can make outages worse. ([Microsoft Learn][6])

---

## Real World Example

Google Drive upload.

Network disconnects.

Automatically retries.

User doesn't even notice.

---

## Tools

* Polly (.NET)
* Resilience4j
* Tenacity (Python)
* Axios Retry
* urllib3 Retry

---

## Practice

Call an API.

Make it randomly fail.

Retry 3 times with exponential backoff.

---

# 7. Fallbacks

## Problem

Weather API failed.

Should entire app stop?

No.

---

## Fallback

Use another option.

```
Primary API

↓

Failed

↓

Backup API
```

or

```
Cached data
```

or

```
Default value
```

---

## Real World Example

Google Maps

Live traffic unavailable.

Shows map without traffic.

Still useful.

---

## Common Fallbacks

* Cache
* Backup server
* Static data
* Default message
* Alternative provider

---

## Practice

Weather app

Primary API

↓

If failed

↓

Show yesterday's cached weather.

---

# 8. Timeouts

## Problem

Calling another service.

It never responds.

Your server waits forever.

Eventually everything gets stuck.

---

## Timeout

Wait only for a limited time.

Example

```
Wait

2 seconds

↓

No response

↓

Cancel
```

Timeouts prevent threads, connections, and resources from being tied up indefinitely. They should be configured before implementing retries because the two mechanisms work together. ([Microsoft Learn][6])

---

## Real World Example

Payment Gateway

Wait 3 seconds.

If no response

↓

Stop waiting.

↓

Return error or fallback.

---

## Popular Tools

Almost every HTTP client supports timeouts:

* Axios
* Fetch
* requests
* OkHttp
* gRPC

---

## Practice

Call

```
https://httpstat.us/200?sleep=10000
```

Set timeout to

```
2 seconds
```

Handle failure gracefully.

---

# 9. Graceful Degradation

## Problem

One service fails.

Should entire app crash?

No.

---

## Graceful Degradation

Instead of

```
Everything broken
```

Use

```
Some features unavailable

↓

Core features still work
```

Think of it as **"limited service is better than no service."**

---

## Example

Netflix

Recommendation service fails.

Instead of

```
Error
```

They simply show

```
Popular Movies
```

Still usable.

---

## Another Example

E-commerce

Reviews service fails.

Users can still

* Search
* Buy
* Pay

Only reviews disappear.

---

## Why it works

Users mostly care about the main task.

Don't block checkout because recommendations failed.

Cloud architecture guidance recommends treating dependency failures as normal situations and designing applications to continue delivering core business value even when some components are unavailable. ([AWS Documentation][7])

---

## Practice

Build

```
Product Page
```

Features

* Product info
* Reviews
* Recommendations

If Reviews fail

Show

```
Reviews temporarily unavailable.
```

Product page should still load.

---

# How Everything Works Together

Imagine a user places an order.

```
        User
          │
          ▼
     API Server
          │
          ▼
     Monitoring
          │
          ▼
  Metrics + Logs + Traces
          │
          ▼
 Health Check says API is Healthy
          │
          ▼
 Calls Payment Service
          │
     Timeout (3s)
          │
     Retry (2 times)
          │
    Still fails
          │
       Fallback
          │
"Payment service temporarily unavailable"
          │
          ▼
 Graceful Degradation
(Order saved, payment pending)
```

Every block has a different responsibility:

| Concept              | Main Job                                      |
| -------------------- | --------------------------------------------- |
| Monitoring           | Detect problems in real time                  |
| Logging              | Record what happened                          |
| Tracing              | Follow a request across services              |
| Metrics              | Measure system behavior with numbers          |
| Health Checks        | Report whether a service is ready and healthy |
| Retries              | Recover from temporary failures               |
| Timeouts             | Avoid waiting forever                         |
| Fallbacks            | Use an alternative when a dependency fails    |
| Graceful Degradation | Keep core features working despite failures   |

# Architecture Takeaway

When designing any backend service, ask these questions for **every important dependency** (database, cache, payment gateway, AI API, email service, etc.):

1. How will I know if it fails? → **Monitoring + Health Checks**
2. How will I investigate the failure? → **Logs + Traces**
3. How will I measure its performance? → **Metrics**
4. How long should I wait? → **Timeout**
5. Should I retry? → **Retry with backoff**
6. If retries fail, is there a backup? → **Fallback**
7. If there is no backup, can the application still provide its core functionality? → **Graceful Degradation**

Following this checklist while designing software is one of the biggest differences between a project that works only in development and one that remains dependable in production.

[1]: https://learn.microsoft.com/en-us/azure/well-architected/reliability/self-preservation?utm_source=chatgpt.com "Architecture strategies for self-healing and self-preservation - Microsoft Azure Well-Architected Framework | Microsoft Learn"
[2]: https://docs.aws.amazon.com/wellarchitected/latest/reliability-pillar/rel_withstand_component_failures_monitoring_health.html?utm_source=chatgpt.com "REL11-BP01 Monitor all components of the workload to detect failures - Reliability Pillar"
[3]: https://learn.microsoft.com/en-us/azure/architecture/best-practices/monitoring?utm_source=chatgpt.com "Monitoring and diagnostics guidance - Azure Architecture Center | Microsoft Learn"
[4]: https://cloud.google.com/architecture/framework/reliability/slo-and-alerts?utm_source=chatgpt.com "Detect potential failures by using observability  |  Cloud Architecture Center  |  Google Cloud"
[5]: https://learn.microsoft.com/en-us/azure/architecture/patterns/health-endpoint-monitoring?utm_source=chatgpt.com "Health Endpoint Monitoring pattern - Azure Architecture Center | Microsoft Learn"
[6]: https://learn.microsoft.com/en-us/azure/architecture/best-practices/transient-faults?utm_source=chatgpt.com "Transient Fault Handling - Azure Architecture Center | Microsoft Learn"
[7]: https://docs.aws.amazon.com/wellarchitected/latest/reliability-pillar/rel_mitigate_interaction_failure_graceful_degradation.html?utm_source=chatgpt.com "REL05-BP01 Implement graceful degradation to transform applicable hard dependencies into soft dependencies - Reliability Pillar"
