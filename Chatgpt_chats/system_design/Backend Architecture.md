Awesome choice. Middleware is one of those concepts that feels simple at first ("just some code before the controller"), but once you understand it deeply, you'll start recognizing it in almost every backend framework (Express, FastAPI, NestJS, ASP.NET Core, Spring Boot, Django, Laravel, etc.).

---

# Middleware

## What problem does Middleware solve?

Imagine you're building an E-Commerce website.

You have 100 API endpoints.

```text
GET /products

POST /orders

GET /cart

POST /login

POST /checkout

GET /profile

...
```

Now suppose **every endpoint** needs to do these things:

* Check if user is logged in
* Log request information
* Record analytics
* Check rate limits
* Enable CORS
* Measure execution time
* Handle errors

If you write this code inside every controller...

```python
def create_order():
    check_auth()

    log_request()

    rate_limit()

    ...

    # actual order logic
```

...and repeat it for 100 endpoints, you've created a maintenance nightmare.

If you later change authentication, you'll have to modify dozens or hundreds of controllers.

This violates **DRY (Don't Repeat Yourself)** and mixes business logic with technical concerns. Frameworks solve this by introducing a **request pipeline** where middleware handles common tasks before or after controllers. ([Microsoft Learn][1])

---

# The Core Idea

Middleware is simply **a function (or class) that sits between the incoming request and your controller**.

Instead of

```text
Client
   │
Controller
```

you get

```text
Client

↓

Middleware

↓

Controller
```

But in reality there are usually many middleware components.

```text
Client

↓

Logger

↓

Authentication

↓

Rate Limiter

↓

Validation

↓

Controller

↓

Response
```

Each middleware gets a chance to inspect or modify the request, stop it completely, or pass it to the next step in the pipeline. ([Microsoft Learn][1])

---

# Real World Analogy

Imagine you're entering an airport.

```
You

↓

Security Check

↓

Passport Verification

↓

Immigration

↓

Boarding Gate

↓

Plane
```

Notice something?

The pilot doesn't check your passport.

The pilot doesn't scan your luggage.

The pilot only flies the plane.

Exactly the same idea.

Controllers shouldn't verify JWTs.

Controllers shouldn't log requests.

Controllers shouldn't check CORS.

Middleware handles these jobs before the controller is reached.

---

# What exactly is inside Middleware?

A middleware can do three things.

## 1. Read the request

Example

```http
Authorization: Bearer eyJ...

Content-Type: application/json

IP Address

Headers

Cookies
```

It can inspect anything.

---

## 2. Modify the request

Example

Incoming request

```text
GET /profile
```

Authentication middleware verifies the JWT.

Then it adds

```python
request.user = {
    id: 52,
    name: "Ali"
}
```

Now every controller can simply use

```python
request.user
```

without decoding the token again.

---

## 3. Stop the request

Suppose authentication fails.

Middleware returns

```http
401 Unauthorized
```

Controller never executes.

```text
Client

↓

Authentication

↓

401

×

Controller never runs
```

This is called **short-circuiting** the request pipeline. ([Microsoft Learn][1])

---

# The Request Pipeline

One of the most important concepts in backend development.

Think of the request as traveling through checkpoints.

```text
Client

↓

Logging

↓

CORS

↓

Authentication

↓

Authorization

↓

Rate Limiting

↓

Controller

↓

Database

↓

Response
```

Every request follows this path.

The response then travels back through the middleware chain, allowing middleware to perform work after the controller too (for example logging response time or adding headers). This bidirectional flow is a defining feature of many middleware pipelines. ([Microsoft Learn][1])

---

# Why not put everything inside Controllers?

Imagine

```python
def login():

    log()

    check_ip()

    check_rate_limit()

    parse_json()

    verify_token()

    measure_time()

    business_logic()

    compress_response()

    analytics()
```

Now imagine this repeated 300 times.

Controllers become unreadable.

Instead

```text
Controller

↓

login()

↓

authenticate()

↓

create_token()

↓

return
```

Much cleaner.

---

# Middleware vs Controller

| Middleware                   | Controller                        |
| ---------------------------- | --------------------------------- |
| Works for many routes        | Works for one endpoint            |
| Handles technical concerns   | Handles business logic            |
| Runs before/after controller | Runs only when reached            |
| Can stop request             | Usually returns business response |
| Reusable                     | Endpoint specific                 |

---

# Common Types of Middleware

Let's go through the middleware you'll encounter in almost every backend.

---

## 1. Logging Middleware

### Problem

You want to know

* Who called your API?
* Which endpoint?
* How long did it take?
* Was it successful?

Without logs, debugging production issues becomes very difficult.

---

### Flow

```text
Request

↓

Logger

↓

Controller

↓

Logger

↓

Response
```

Logger records

```
GET /products

200 OK

123 ms

User: 42
```

---

### Real World

GitHub

Stripe

Google Cloud

AWS

Almost every production backend logs every request.

---

# 2. Authentication Middleware

Probably the most common.

### Problem

Only logged-in users should access

```
/profile

/orders

/cart
```

Without middleware

Every controller would repeat

```python
verifyJWT()
```

---

### Middleware

```text
Request

↓

JWT Middleware

↓

Controller
```

If token is invalid

```
401 Unauthorized
```

Controller never executes.

---

# 3. Authorization Middleware

People often confuse Authentication and Authorization.

Authentication

> Who are you?

Authorization

> What are you allowed to do?

Example

```
DELETE /users
```

Only admins.

Middleware checks

```python
user.role == "admin"
```

Otherwise

```
403 Forbidden
```

---

# 4. CORS Middleware

Browsers restrict requests from different origins for security.

Suppose

Frontend

```
https://shop.com
```

Backend

```
https://api.shop.com
```

Browser asks

> Is this request allowed?

CORS middleware answers

```
Yes.

Allow-Origin: shop.com
```

Without it

Browser blocks the request.

---

# 5. Error Handling Middleware

Instead of every controller doing

```python
try:

...

except:
```

you let errors bubble up.

```text
Controller

↓

Exception

↓

Error Middleware

↓

500 JSON Response
```

Benefits

* One place for error formatting
* Consistent responses
* Centralized logging

---

# 6. Request Parsing Middleware

Incoming request

```http
{
    "name":"Ali"
}
```

Middleware converts it into

```python
request.body
```

Without it

Controllers would have to manually parse raw HTTP data.

---

# 7. Rate Limiting Middleware

Problem

One attacker sends

```
100000 requests
```

Server crashes.

Middleware tracks requests per client.

```
100 requests/minute

Allowed

101st

429 Too Many Requests
```

---

# 8. Compression Middleware

Large response

```
5 MB JSON
```

Middleware compresses it.

```
500 KB
```

Benefits

* Faster responses
* Less bandwidth
* Better performance

---

# 9. Request Timing Middleware

Measures

```
Request Started

↓

Controller

↓

Request Finished

↓

152 ms
```

Useful for finding slow endpoints.

---

# Middleware Order Matters

This is one of the biggest beginner mistakes.

Imagine

```text
Client

↓

Authorization

↓

Authentication

↓

Controller
```

Problem

Authorization needs to know who the user is.

But authentication hasn't run yet.

Wrong.

Correct

```text
Client

↓

Authentication

↓

Authorization

↓

Controller
```

Another example:

```
Compression

↓

Response
```

Compression should happen after the controller generates the response, not before.

The order of middleware directly affects correctness, and frameworks typically execute middleware in the order you register them. ([Microsoft Learn][1])

---

# Middleware Should NOT Contain

Middleware is **not** the place for business logic.

❌ Bad

```python
Authentication

↓

Calculate Order Total

↓

Apply Coupon

↓

Update Inventory
```

These belong in services or use cases.

Good middleware handles **cross-cutting concerns**:

* Authentication
* Authorization
* Logging
* Error handling
* Metrics
* Tracing
* Rate limiting
* CORS
* Compression

---

# Middleware vs Filters vs Interceptors

Different frameworks use different names.

| Framework    | Similar Concept                         |
| ------------ | --------------------------------------- |
| Express      | Middleware                              |
| FastAPI      | Middleware                              |
| NestJS       | Middleware, Guards, Interceptors, Pipes |
| ASP.NET Core | Middleware, Filters                     |
| Spring Boot  | Filters, Interceptors                   |
| Django       | Middleware                              |

Some frameworks split responsibilities further (for example, NestJS uses **Guards** for authorization and **Pipes** for validation), but the underlying idea is still "process the request before or after the controller."

---

# Real-World Example: Online Banking

Imagine a user requests:

```http
POST /transfer
```

The request might travel like this:

```text
Client

↓

Request Logger
(Log request started)

↓

HTTPS Enforcement
(Reject insecure HTTP)

↓

CORS Check
(Allow trusted frontend)

↓

Rate Limiter
(Prevent abuse)

↓

Authentication
(Verify JWT)

↓

Authorization
(Check transfer permission)

↓

Validation
(Check amount > 0)

↓

Fraud Detection Middleware
(Check suspicious activity)

↓

TransferController

↓

TransferService

↓

Database

↓

Response

↓

Logger
(Log success and duration)
```

Notice that **TransferController** only worries about transferring money. Every technical concern has already been handled.

---

# Practice Ideas

### Beginner

Create these middleware:

* Logger
* Request Timer
* Authentication
* Error Handler

---

### Intermediate

Build a Notes API with:

* JWT Authentication Middleware
* Rate Limiter
* Request Logger
* CORS Middleware
* Global Error Handler

---

### Advanced

Build an E-commerce backend where every request goes through:

```text
Request

↓

Logger

↓

Request ID Generator

↓

Authentication

↓

Authorization

↓

Rate Limiter

↓

Validation

↓

Controller

↓

Service

↓

Repository

↓

Database

↓

Response

↓

Metrics Logger
```

By implementing this full pipeline, you'll gain the same mental model used in professional backend frameworks and understand **why middleware exists—not just how to use it.**

[1]: https://learn.microsoft.com/hr-hr/aspnet/core/fundamentals/middleware/?view=aspnetcore-10.0&utm_source=chatgpt.com "ASP.NET Core Middleware | Microsoft Learn"
