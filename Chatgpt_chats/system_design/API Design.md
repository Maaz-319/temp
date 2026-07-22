This is one of the most important topics in software architecture because **APIs are how components communicate**.

Think of your system as a company.

* Database = Warehouse
* Backend Services = Employees
* Frontend = Customer
* API = Reception Desk

The customer never walks into the warehouse. They always talk to the reception desk.

Good API design makes your software easy to build, maintain and scale. Bad API design makes every new feature painful. Industry guidance from Microsoft and Google consistently emphasizes designing APIs around business resources, keeping them stable over time, documenting them well, and treating the API as a long-term contract rather than an implementation detail. ([Microsoft Learn][1])

---

# API Design

## Big Picture

Imagine you're building **Uber**.

```
Mobile App
      │
      ▼
-------------------------
         API
-------------------------
│ User Service          │
│ Ride Service          │
│ Payment Service       │
│ Driver Service        │
-------------------------
```

The API decides

* what requests clients can make
* what data clients receive
* who is allowed to access data
* how errors are reported
* how future versions remain compatible

A backend engineer spends a huge amount of time designing APIs.

---

# 1. REST

This is the most common API style on the Internet.

## Problem it solves

Suppose your frontend wants to

* create users
* fetch users
* delete users
* update users

How should it communicate with the backend?

REST provides a standard way.

Instead of inventing commands, REST uses HTTP.

Microsoft recommends modeling APIs around **resources (nouns)** rather than actions (verbs), using standard HTTP methods like GET, POST, PUT, PATCH, and DELETE. ([Microsoft Learn][1])

---

## How REST solves it

Everything becomes a resource.

```
User
Product
Order
Invoice
Comment
Ride
Driver
```

Each resource gets a URL.

Example

```
GET /users
```

Return all users.

```
GET /users/15
```

Return one user.

```
POST /users
```

Create user.

```
PUT /users/15
```

Replace user.

```
PATCH /users/15
```

Update some fields.

```
DELETE /users/15
```

Delete.

Very simple.

---

## Real-world example

Instagram

```
GET /posts
```

gets feed.

```
POST /posts
```

creates post.

```
DELETE /posts/81
```

deletes post.

GitHub

```
GET /repos
```

Stripe

```
GET /customers
```

Almost every public API uses REST.

---

## Advantages

✅ Easy to understand

✅ Works everywhere

✅ HTTP already supports it

✅ Easy caching

✅ Huge ecosystem

---

## Disadvantages

Sometimes client receives too much data.

Sometimes too little.

This is called

* Over-fetching
* Under-fetching

We'll solve that using GraphQL.

---

## Tools

* OpenAPI / Swagger
* Postman
* Bruno
* Insomnia
* Hoppscotch

---

## Practice

Build

```
Library API

Books

Authors

Borrowers
```

Implement CRUD using REST.

---

# 2. GraphQL

Created because REST isn't always flexible enough.

---

## Problem it solves

Imagine YouTube homepage.

Need

* user
* subscriptions
* recommended videos
* notifications
* comments count

With REST

```
GET /user

GET /subscriptions

GET /videos

GET /notifications
```

Many requests.

Or

```
GET /dashboard
```

Returns way too much data.

Neither is ideal.

---

## How GraphQL solves it

Client asks exactly what it wants.

```
query {

  user {

     name

     avatar

  }

}
```

Server returns

```
{
  "name":"Maaz",
  "avatar":"..."
}
```

Nothing extra.

Need email too?

```
query {

user {

name

avatar

email

}

}
```

Done.

Client controls response shape.

---

## Real-world example

GitHub GraphQL API.

Instead of 6 REST calls, frontend makes one GraphQL query.

Facebook also popularized GraphQL for reducing mobile network traffic.

---

## Advantages

Only required data

One endpoint

Flexible

Perfect for frontend-heavy applications

---

## Disadvantages

Caching harder

More backend complexity

Authorization can become trickier

---

## Tools

Apollo

Relay

GraphQL Playground

GraphiQL

Mercurius

Yoga

---

## Practice

Take your Library API.

Allow frontend to fetch

```
Book

Author

Publisher

Reviews

```

using one GraphQL query.

---

# 3. gRPC

Now imagine backend talking to backend.

Not browser.

Microservices.

---

## Problem it solves

REST sends JSON.

JSON is readable.

But

* large
* slower
* text-based

When hundreds of services communicate thousands of times per second, that overhead matters.

---

## How gRPC solves it

Uses

Protocol Buffers (protobuf)

instead of JSON.

Binary data.

Much smaller.

Much faster.

Supports

```
Unary request

Streaming

Bi-directional streaming
```

Also generates client/server code automatically from `.proto` files. Google's API Design Guide strongly recommends protobuf-based contracts for many internal and cloud APIs because they provide a clear, language-neutral interface. ([Google Cloud Documentation][2])

---

## Real-world example

Netflix

Google Cloud

Kubernetes

Most large microservice systems use gRPC internally.

---

## Advantages

Very fast

Small payload

Strong typing

Auto-generated SDKs

Streaming support

---

## Disadvantages

Harder to debug manually

Browser support requires extra layers

Less human-readable

---

## Tools

Protocol Buffers

grpcurl

Evans

Buf

grpcui

---

## Practice

Create

```
Order Service

Inventory Service
```

Inventory receives

```
CheckStock(productId)
```

via gRPC.

---

# 4. WebSockets

---

## Problem it solves

Imagine WhatsApp.

Messages should appear instantly.

REST cannot do that efficiently because the client would keep asking:

```
Any new message?

Any new message?

Any new message?
```

Polling wastes resources.

---

## How WebSockets solve it

Client connects once.

```
Connect
```

Connection stays open.

Server pushes updates instantly.

```
New message

Friend typing

Online status

```

No repeated requests.

---

## Real-world example

Discord

WhatsApp Web

Slack

Trading apps

Online multiplayer games

---

## Advantages

Real-time

Very low latency

Two-way communication

---

## Disadvantages

Persistent connections consume resources

More complex scaling

Stateful connections

---

## Tools

Socket.IO

ws

SignalR

Phoenix Channels

---

## Practice

Build

Realtime chat

without refreshing page.

---

# 5. API Versioning

---

## Problem it solves

Suppose today

```
GET /users
```

returns

```
name
email
```

Tomorrow

```
email
```

becomes

```
emailAddress
```

Boom.

Every mobile app breaks.

---

## Solution

Keep old API alive.

Example

```
/v1/users

/v2/users
```

Or use version headers. The key principle is to evolve APIs without unexpectedly breaking existing clients. ([Microsoft Learn][3])

---

## Real-world example

Stripe

GitHub

Microsoft Graph

---

## Practice

Create

```
v1

name

email
```

Then

```
v2

firstName

lastName

email
```

---

# 6. Pagination

---

## Problem

Imagine

10 million products.

```
GET /products
```

Should backend send all?

Impossible.

---

## Solution

```
GET /products?page=2&limit=20
```

Only return 20.

Microsoft recommends sensible defaults and maximum limits to improve performance and reduce abuse. ([Microsoft Learn][1])

---

## Real-world

Amazon

YouTube

Instagram

GitHub

---

## Types

Offset Pagination

```
page=3
```

Cursor Pagination

```
after=abc123
```

Cursor pagination is generally preferred for rapidly changing datasets because it avoids duplicates and skipped records.

---

## Practice

Return

20 books

per request.

---

# 7. Filtering

---

## Problem

User wants

```
Books

Price < 1000

Language English

Category AI
```

Without filtering

Backend returns everything.

Frontend filters.

Wasteful.

---

## Solution

```
GET /books?

category=AI

&price_lt=1000

&language=en
```

Filtering allows the server to return only relevant data, reducing bandwidth and improving response times. ([Microsoft Learn][1])

---

## Practice

Implement

```
category

price

author

rating
```

filters.

---

# 8. Authentication

---

## Problem

How does server know

you are actually you?

---

## Solution

Client proves identity.

Methods

* Session Cookies
* JWT
* OAuth2
* API Keys
* OpenID Connect

Flow

```
Login

↓

Receive Token

↓

Send Token

↓

Access Granted
```

---

## Real-world

GitHub Token

Google Login

Discord Login

---

## Practice

Protect

```
POST /books
```

Only logged-in users can create books.

---

# 9. Error Handling

---

## Problem

What if something goes wrong?

Need consistent responses.

---

## Solution

Use proper HTTP status codes.

```
200 OK

201 Created

400 Bad Request

401 Unauthorized

403 Forbidden

404 Not Found

500 Internal Server Error
```

Example

```json
{
  "error": {
    "code": "BOOK_NOT_FOUND",
    "message": "Book does not exist"
  }
}
```

Consistent error formats make APIs much easier for other developers to consume. ([Microsoft Learn][1])

---

## Practice

Create reusable error responses for every endpoint.

---

# 10. Rate Limiting

---

## Problem

Someone sends

```
1 million requests
```

Your server dies.

---

## Solution

Limit requests.

Example

```
100 requests

per minute
```

If exceeded

```
429 Too Many Requests
```

Rate limiting also helps protect against abuse and denial-of-service scenarios. ([Microsoft Learn][1])

---

## Real-world

GitHub

Twitter/X

Stripe

OpenAI APIs

---

## Tools

Redis

NGINX

Kong

Cloudflare

API Gateway

---

## Practice

Limit

```
Login API

5 requests/minute
```

per IP.

---

# 11. OpenAPI (Swagger)

---

## Problem

You built 80 endpoints.

How will frontend developers know:

* URLs
* request body
* response format
* authentication
* parameters

Without documentation, they'll constantly ask questions.

---

## Solution

Describe the API using the **OpenAPI Specification (OAS)**. Many teams follow a **contract-first** approach: design the API contract first, then implement it. This keeps frontend and backend aligned and allows documentation and client SDKs to be generated automatically. ([Microsoft Learn][1])

Example

```yaml
GET /books

Response

200

[
  {
    id
    title
    author
  }
]
```

Swagger UI automatically creates an interactive documentation website where developers can try requests directly in the browser.

---

## Real-world

Almost every serious public API today exposes OpenAPI documentation:

* GitHub
* Stripe
* Microsoft
* PayPal
* Internal company APIs

---

## Tools

* OpenAPI Specification
* Swagger UI
* Swagger Editor
* Redoc
* Stoplight
* Scalar

---

## Practice

Generate Swagger documentation for your Library API and ensure every endpoint is documented.

---

# Decision Cheat Sheet

| Requirement                                | Best Choice    |
| ------------------------------------------ | -------------- |
| Standard CRUD web app                      | REST           |
| Frontend needs custom data                 | GraphQL        |
| Microservice-to-microservice communication | gRPC           |
| Real-time chat, notifications, games       | WebSockets     |
| Protect existing clients during changes    | API Versioning |
| Huge datasets                              | Pagination     |
| Search-specific data                       | Filtering      |
| Secure endpoints                           | Authentication |
| Consistent failures                        | Error Handling |
| Prevent abuse                              | Rate Limiting  |
| Self-documenting APIs                      | OpenAPI        |

---

# Mini Project (Practice Everything)

Build a **BookVerse** platform (think Goodreads + Amazon Books).

Include:

* REST API for books, authors, users, reviews
* GraphQL endpoint for the frontend
* gRPC communication between Book Service and Recommendation Service
* WebSocket notifications when someone reviews your book
* JWT authentication
* Cursor pagination for books and reviews
* Filtering by genre, author, rating, and publication year
* API versioning (`v1` and `v2`)
* Rate limiting on login and review submission
* Complete OpenAPI documentation

This single project will give you hands-on experience with nearly every major API design concept used in modern backend systems.

[1]: https://learn.microsoft.com/en-us/azure/architecture/best-practices/api-design?utm_source=chatgpt.com "Web API Design Best Practices - Azure Architecture Center | Microsoft Learn"
[2]: https://docs.cloud.google.com/apis/design?utm_source=chatgpt.com "API design guide  |  Cloud API Design Guide  |  Google Cloud Documentation"
[3]: https://learn.microsoft.com/ga-ie/azure/architecture/microservices/design/api-design?utm_source=chatgpt.com "API Design - Azure Architecture Center | Microsoft Learn"
