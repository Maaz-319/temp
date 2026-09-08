# General OAuth Guide

## 1. What is OAuth?

OAuth is a standardized way for one application to obtain permission to access another service on behalf of a user.

For example, imagine you are building:

```text
myapp.com
```

and you want users to log in with GitHub.

Instead of asking the user for their GitHub password:

```text
Your application
    ↓
"Give me your GitHub password"
```

you redirect them to GitHub:

```text
Your application
    ↓
GitHub
    ↓
User logs in
    ↓
User approves your application
    ↓
GitHub sends your application a temporary authorization code
```

Your server exchanges that code with GitHub and receives a token.

The important idea is:

> Your application never needs to know the user's GitHub password.

OAuth was originally designed primarily for delegated authorization — "let this application access something on my behalf." It is also widely used as the foundation for "Login with X" experiences.

For actual user authentication and identity information, OpenID Connect (OIDC) is the standardized identity layer built on top of OAuth 2.0. OAuth itself is about authorization; OIDC adds standardized identity information such as an ID token.

---

# 2. The main actors

There are four important parties in an OAuth flow.

```text
                 ┌──────────────────────┐
                 │       User           │
                 │     / Browser        │
                 └──────────┬───────────┘
                            │
                            │
              ┌─────────────┴─────────────┐
              │                           │
              ▼                           ▼
       Your Application             OAuth Provider
       "OAuth Client"               "Authorization Server"
              │                           │
              │                           │
              ▼                           ▼
       Your application             Provider API
       database/session             "Resource Server"
```

Let's give them their proper OAuth names.

### Resource Owner

Usually the human user.

Example:

```text
Alice
```

Alice owns her GitHub account and its data.

### Client

Your application.

Example:

```text
myapp.com
```

OAuth calls this the **client**.

### Authorization Server

The service that authenticates the user and issues authorization credentials.

Example:

```text
GitHub
Google
Microsoft
```

### Resource Server

The API containing the protected resources.

For GitHub, this could be the GitHub API containing information about the user's account, repositories, organizations, etc.

Sometimes the authorization server and resource server are operated by the same company, but conceptually they are different roles.

---

# 3. OAuth is not the same thing as your application session

This distinction is extremely important.

Suppose Alice logs into your application with GitHub.

There are actually two authentication/authorization worlds:

```text
                 OAuth world
────────────────────────────────

Alice
  ↓
GitHub
  ↓
authorization
  ↓
authorization code
  ↓
GitHub access token
  ↓
GitHub identity


                 Your application
────────────────────────────────

GitHub identity
  ↓
local user
  ↓
your session
  ↓
browser cookie
```

OAuth establishes a relationship between your application and the provider.

Your application still needs to decide:

> "What does this GitHub user mean inside my application?"

And:

> "How will this browser remain logged in?"

That is your application's responsibility.

---

# 4. The standard web OAuth flow

For a normal web application, the most important flow to understand is:

```text
Authorization Code Flow
```

Modern implementations should generally use **PKCE** with the authorization-code flow.

The overall process looks like this:

```text
Browser
   |
   | 1. Start login
   v
Your Application
   |
   | 2. Create OAuth transaction
   |    - PKCE verifier/challenge
   |    - state if used
   |
   | 3. Redirect browser
   v
OAuth Provider
   |
   | 4. User authenticates
   | 5. User approves
   |
   | 6. Redirect browser back
   v
Your Application
   |
   | 7. Validate callback
   | 8. Exchange authorization code
   v
OAuth Provider
   |
   | 9. Access token
   v
Your Application
   |
   | 10. Get user identity
   | 11. Find/create local user
   | 12. Create application session
   v
Browser
```

Let's go through every step.

---

# 5. Step 1 — The user clicks "Login with GitHub"

The browser might request:

```text
GET /auth/github/start
```

Your application might know that the user originally wanted:

```text
/s/dashboard
```

So internally you may have:

```text
next = "/s/dashboard"
```

At this point, `next` is application-specific. OAuth does not define what `next` means.

---

# 6. Step 2 — Validate the destination

This is easy to overlook.

Suppose your application accepts:

```text
/auth/github/start?next=/dashboard
```

and after login redirects the user to `/dashboard`.

That is fine.

But this is dangerous:

```text
/auth/github/start?next=https://evil.example
```

If you blindly redirect there after authentication, your application becomes an **open redirector**.

An attacker could potentially use your trusted domain to send users to a malicious site.

Therefore, validate destinations:

```text
Allowed:

/
/dashboard
/settings
/s/abc


Rejected:

https://evil.example
//evil.example
javascript:...
```

A simple and robust strategy is to allow only the URL forms your application actually needs.

OAuth does not automatically solve this problem. Your application must handle it.

Modern OAuth security guidance specifically warns about open redirectors because they can contribute to authorization-code or token exfiltration attacks.

---

# 7. Step 3 — Create a PKCE transaction

Modern OAuth should generally use PKCE.

PKCE stands for:

```text
Proof Key for Code Exchange
```

The basic idea is that your application generates a secret random value:

```text
code_verifier
```

For example:

```text
r8X...random...K2
```

Then it calculates:

```text
code_challenge = BASE64URL(
    SHA256(code_verifier)
)
```

The application sends the challenge to the OAuth provider:

```text
code_challenge=...
code_challenge_method=S256
```

But it keeps the verifier secret.

So the provider sees:

```text
code_challenge = ABC...
```

while your application remembers:

```text
code_verifier = XYZ...
```

The verifier should be transaction-specific and generated with a cryptographically secure random generator.

---

# 8. Why does PKCE exist?

Imagine an attacker somehow obtains the authorization code.

Without PKCE:

```text
Attacker
   |
   | stolen authorization code
   v
OAuth provider
   |
   v
access token
```

The attacker might be able to redeem it.

With PKCE:

```text
authorization code
        +
correct code_verifier
        ↓
    access token
```

The attacker has:

```text
authorization code
```

but not:

```text
code_verifier
```

Therefore the token exchange fails.

PKCE was originally designed to protect public clients such as native applications, but modern OAuth security guidance recommends it for web applications as well. The current OAuth security best-practice document recommends PKCE for confidential clients and requires it for public clients.

---

# 9. PKCE and GitHub

GitHub added PKCE support for OAuth and GitHub App authentication in July 2025.

GitHub currently recommends PKCE for the authorization-code flow and supports the `S256` challenge method.

So a modern GitHub authorization request conceptually looks like:

```text
https://github.com/login/oauth/authorize
    ?client_id=YOUR_CLIENT_ID
    &redirect_uri=https://myapp.com/auth/callback
    &scope=read:user
    &state=RANDOM_STATE
    &code_challenge=HASH_OF_VERIFIER
    &code_challenge_method=S256
```

The exact parameters depend on the provider.

---

# 10. What is `state`?

`state` is another security mechanism used in OAuth.

It answers:

> "Does this callback belong to an OAuth login transaction that this browser/application actually started?"

For example:

```text
Login starts:

Browser
   |
   | state = ABC123
   v
GitHub
```

Your application remembers:

```text
state = ABC123
```

GitHub later redirects:

```text
/auth/callback?code=XYZ&state=ABC123
```

Your application checks:

```text
expected state == returned state
```

If:

```text
ABC123 == ABC123
```

continue.

If:

```text
ABC123 != EVIL999
```

reject the request.

OAuth 2.0 defines `state` specifically as an opaque value that allows the client to maintain state between the authorization request and callback, and recommends it for CSRF protection.

---

# 11. Do I need both `state` and PKCE?

This is an important modern OAuth question.

The answer is:

> Not necessarily for CSRF protection, if you are using PKCE correctly and the authorization server supports and enforces it.

Current OAuth security best practice says clients that have ensured PKCE support may rely on PKCE for CSRF protection. If PKCE is not available, a transaction-specific `state` value securely bound to the user agent should be used.

So these are possible designs:

```text
Option A

state
```

Older/common approach.

```text
Option B

PKCE
```

Modern approach when the provider supports it.

```text
Option C

state + PKCE
```

Defense-in-depth and sometimes useful when `state` also carries application state.

Using both is not inherently wrong.

But don't implement both blindly just because "OAuth security requires both."

Understand what each mechanism is protecting.

---

# 12. What should `state` contain?

A common mistake is putting lots of information into `state`.

For example:

```text
state=userId=123&role=admin&next=/dashboard
```

This is usually unnecessary.

A simpler design is:

```text
state = random opaque value
```

Then keep your application state separately.

For example:

```text
state
   ↓
random transaction ID
   ↓
server-side temporary record

transaction:
{
    next: "/dashboard",
    codeVerifier: "...",
    createdAt: ...
}
```

Alternatively, you can store carefully validated state in a secure cookie.

If the contents of `state` matter, its integrity must be protected against tampering or swapping. Modern OAuth security guidance explicitly calls this out.

---

# 13. Cookies used for OAuth transactions

A web application can store temporary OAuth transaction information in an HttpOnly cookie.

For example:

```text
oauth_transaction = ...
```

Useful cookie properties include:

```text
HttpOnly
Secure
SameSite=Lax
Path=/
short expiration
```

### HttpOnly

JavaScript cannot read the cookie.

### Secure

The browser only sends it over HTTPS.

### SameSite=Lax

Useful for browser-based OAuth redirects while providing protection against many cross-site requests.

### Short expiration

An OAuth transaction should not remain valid forever.

For example:

```text
5–10 minutes
```

is a reasonable type of lifetime for a temporary login transaction, depending on your application.

---

# 14. Step 4 — Redirect the browser to the provider

Your server responds:

```text
HTTP/1.1 302 Found
Location: https://provider.example/authorize?...
```

The browser goes to the provider.

Your server isn't usually directly logging the user into the provider.

Instead:

```text
Browser
   ↓
Provider
```

The provider now handles its own authentication.

---

# 15. Step 5 — The provider authenticates the user

For GitHub:

```text
GitHub
   ↓
User logs in
   ↓
User authorizes your application
```

Your application does not see:

```text
GitHub password
GitHub MFA secret
```

The provider handles those credentials.

This is one of the biggest benefits of OAuth.

---

# 16. Step 6 — Provider redirects back to your callback

After authorization, the provider redirects the browser back:

```text
GET /auth/callback?code=TEMPORARY_CODE&state=ABC123
```

Now your server has:

```text
code
state
```

The authorization code is temporary.

It is not your application's session.

It is not your user's password.

It is a short-lived credential that is meant to be exchanged at the token endpoint.

OAuth specifies that authorization codes should expire shortly after issuance and must not be reused.

---

# 17. Step 7 — Validate the OAuth transaction

Before creating a session, your application should validate the callback.

Depending on your design, that can include:

```text
state
PKCE transaction
redirect URI
provider
authorization code
```

For example:

```text
callback state
      ↓
does it belong to this transaction?
      ↓
yes
      ↓
continue
```

If the callback is invalid:

```text
400 Bad Request
```

and importantly:

```text
DO NOT create a session
DO NOT create a user
DO NOT treat the request as authenticated
```

---

# 18. Step 8 — Exchange the authorization code

Your backend now communicates directly with the provider.

Conceptually:

```text
Your Server
    |
    | code
    | client credentials if required
    | code_verifier
    |
    v
OAuth Provider
```

The provider validates the authorization code and PKCE verifier.

If everything is correct:

```text
Provider
    ↓
access_token
```

For a confidential server-side application, the client secret is also kept on the server and never sent to the browser.

---

# 19. What is the access token?

An access token represents authorization to access protected resources.

For example:

```text
access_token = ABC123...
```

Your server might use it to call:

```text
GitHub API
```

and ask:

```text
Who is this user?
```

or:

```text
What repositories can this user access?
```

The token belongs to the OAuth relationship with the provider.

It is not necessarily the same thing as your application's session.

---

# 20. Access token vs application session

This distinction is worth memorizing.

### OAuth access token

```text
Purpose:
Talk to the OAuth provider's APIs.
```

Example:

```text
GitHub access token
```

### Application session

```text
Purpose:
Tell YOUR application that this browser is logged in.
```

Example:

```text
hsid=random-session-id
```

Therefore:

```text
GitHub access token
       ≠
Your application session
```

You can authenticate a user with GitHub and then discard the GitHub access token if you don't need to call GitHub APIs afterward.

---

# 21. Step 9 — Get the user's identity

After obtaining an access token, your server may call the provider's API.

For example:

```text
Your Server
    |
    | Authorization: Bearer ACCESS_TOKEN
    v
GitHub API
    |
    v
{
    id: 12345,
    login: "alice",
    avatar_url: "..."
}
```

Your application should identify the external account using a **stable provider identifier**, not a mutable username.

For GitHub:

```text
externalId = GitHub user ID
```

is preferable to:

```text
externalId = GitHub username
```

because usernames can change.

Your internal representation might be:

```text
ExternalProfile

{
    provider: "github",
    externalId: "12345",
    handle: "alice",
    avatarUrl: "..."
}
```

This abstraction makes it possible to support:

```text
GitHub
Google
Microsoft
Apple
```

without forcing the rest of your application to understand each provider's API format.

---

# 22. Step 10 — Find or create your local user

Now your application has something like:

```text
GitHub user ID = 12345
```

Your database might contain:

```text
users

id | provider | external_id | handle
---+----------+-------------+-------
42 | github   | 12345       | alice
```

If the row exists:

```text
GitHub 12345
    ↓
local user 42
```

If it doesn't:

```text
GitHub 12345
    ↓
create local user
    ↓
local user 42
```

This is the bridge between the provider's identity system and your application's identity system.

---

# 23. Why you should not use the provider username as the primary identity

Suppose Alice changes:

```text
GitHub username:
alice123 → alice-dev
```

If your application identifies her by:

```text
username = "alice123"
```

you may accidentally treat her as a different person.

Instead:

```text
provider + stable external ID
```

should identify the external account.

For example:

```text
github + 12345
```

is the identity relationship.

The current username can be stored as profile information.

---

# 24. Step 11 — Create your own application session

Once you know:

```text
localUserId = 42
```

your application creates its own session.

For example:

```text
sessionId = RANDOM_256_BIT_VALUE
```

Store:

```text
session:RANDOM_256_BIT_VALUE

{
    userId: 42,
    createdAt: "...",
    lastSeenAt: "..."
}
```

Then send:

```text
Set-Cookie: hsid=RANDOM_256_BIT_VALUE
```

The browser now has an application session.

Future requests look like:

```text
Browser
   |
   | Cookie: hsid=ABC
   v
Your Application
   |
   | lookup session ABC
   v
userId = 42
```

Now your application knows who the browser represents.

---

# 25. Why use a random session ID?

Don't put the entire user object into the cookie:

```text
cookie = {
    userId: 42,
    role: "admin"
}
```

Instead, use an opaque random identifier:

```text
cookie = hsid=RANDOM_VALUE
```

and store the actual session server-side.

This gives you:

```text
Browser
   |
   | opaque session ID
   v
Server
   |
   v
session
   |
   v
user
```

It also makes revocation easier.

You can delete:

```text
session:RANDOM_VALUE
```

and the browser is immediately logged out.

---

# 26. Should the session contain roles and permissions?

Usually, keep the session minimal.

For example:

```text
{
    userId: 42,
    createdAt: "...",
    lastSeenAt: "..."
}
```

Then retrieve current user information when authorization decisions are needed.

Why?

Because permissions can change.

Imagine:

```text
Monday:
Alice = admin
```

Then:

```text
Tuesday:
Alice = normal user
```

If the session permanently contains:

```text
role = admin
```

Alice might remain an admin until the session expires.

If the session contains only:

```text
userId = 42
```

your application can check current database state.

---

# 27. The complete architecture

Putting everything together:

```text
                       BROWSER
                          |
                          |
                 /login/github
                          |
                          v
                 YOUR APPLICATION
                          |
             ┌────────────┴────────────┐
             │                         │
             │ Validate `next`         │
             │                         │
             │ Create OAuth transaction│
             │                         │
             │ Generate PKCE verifier  │
             │ Generate challenge      │
             │                         │
             │ Optional state          │
             │                         │
             └────────────┬────────────┘
                          |
                          | 302
                          v
                    GITHUB / GOOGLE
                          |
                    User authenticates
                          |
                    User authorizes
                          |
                          | 302
                          v
                /oauth/callback?code=...
                          |
                          v
                 YOUR APPLICATION
                          |
                 Validate transaction
                          |
                          v
                  Exchange code
                          |
                          v
                 OAuth Provider
                          |
                    access token
                          |
                          v
                 Provider user API
                          |
                     user identity
                          |
                          v
                   Local database
                          |
                     local user
                          |
                          v
                   Create session
                          |
                          v
                    session store
                          |
                          v
                   hsid cookie
                          |
                          v
                    APPLICATION
```

---

# 28. The four major security problems

When designing OAuth, think about four different problems rather than treating "OAuth security" as one thing.

## Problem 1 — "Can someone forge a callback?"

Mechanisms:

```text
PKCE
state
OIDC nonce
```

depending on the flow and provider.

Modern OAuth security guidance allows PKCE to serve as CSRF protection when the authorization server supports it and the client uses it correctly.

---

## Problem 2 — "Can someone steal/redeem an authorization code?"

Mechanism:

```text
PKCE
```

The attacker may have:

```text
authorization code
```

but doesn't have:

```text
code_verifier
```

---

## Problem 3 — "Can my application redirect users somewhere malicious?"

Mechanism:

```text
strict redirect/destination validation
```

OAuth does not solve your application's `next` parameter.

---

## Problem 4 — "How does the user stay logged into my application?"

Mechanism:

```text
your own session system
```

For example:

```text
hsid
    ↓
session store
    ↓
userId
    ↓
database
```

OAuth does not automatically provide your application's session architecture.

---

# 29. What a modern implementation should NOT do

Avoid designs like:

```text
Browser
   ↓
GitHub access token
   ↓
store directly in browser
   ↓
use as application's permanent session
```

Also avoid:

```text
next=https://evil.com
```

without validation.

Avoid:

```text
state = "123"
```

or any predictable/static state.

Avoid putting sensitive information into an unprotected `state` parameter.

Avoid storing OAuth client secrets in browser JavaScript.

Avoid using a mutable provider username as the permanent external identity.

---

# 30. What should be random?

Several values in OAuth-related systems should be unpredictable.

### PKCE verifier

```text
random
```

### State

If used:

```text
random
```

### Session ID

```text
random
```

These are different values serving different purposes.

For example:

```text
PKCE verifier
    ↓
protects authorization-code exchange

state
    ↓
binds OAuth transaction / CSRF protection

session ID
    ↓
authenticates browser to your application
```

Don't reuse one value for all three purposes.

---

# 31. What does an OAuth library replace?

A good OAuth library can take care of much of the protocol plumbing.

Instead of manually implementing:

```text
generate state
encode state
decode state
generate PKCE
calculate challenge
build authorization URL
exchange code
validate OAuth response
handle provider quirks
```

you ideally delegate these to a mature library.

Your application can then focus on:

```text
validate next
       ↓
start OAuth transaction
       ↓
OAuth library
       ↓
provider identity
       ↓
find/create local user
       ↓
create application session
       ↓
redirect
```

The exact division depends on the library.

---

# 32. What should remain your responsibility?

Even with an OAuth library, you still need application-specific logic.

Keep things such as:

```text
Routing
    ↓
Which endpoint was requested?

Destination validation
    ↓
Where can the user go?

User provisioning
    ↓
Which local user corresponds to this provider account?

Authorization
    ↓
Is this user allowed to perform this action?

Application session
    ↓
How does my application keep users logged in?

Database
    ↓
What does this identity mean in my system?
```

A library should not make those decisions for you.

---

# 33. What should a provider abstraction look like?

If your application supports multiple providers, conceptually you want:

```text
AuthProvider
    |
    ├── GitHub
    ├── Google
    ├── Microsoft
    └── Apple
```

The rest of your application should ideally interact with something like:

```text
ExternalProfile

{
    provider,
    externalId,
    handle,
    avatarUrl
}
```

rather than knowing:

```text
GitHub uses login
Google uses email
Microsoft uses ...
```

The provider-specific code translates the provider's response into your common representation.

---

# 34. Example: GitHub

For GitHub:

```text
Provider:
GitHub

Authorization endpoint:
GitHub OAuth authorization endpoint

Token endpoint:
GitHub OAuth token endpoint

User API:
GitHub API

External identity:
GitHub user ID
```

Your application can conceptually perform:

```text
Login
  ↓
GitHub authorization
  ↓
authorization code
  ↓
PKCE verification
  ↓
GitHub access token
  ↓
GitHub user profile
  ↓
github user ID
  ↓
local user
  ↓
application session
```

GitHub currently recommends PKCE for OAuth authorization-code flows and recommends minimal scopes.

---

# 35. Example: Google

The same architecture applies:

```text
Your Application
      ↓
Google authorization
      ↓
authorization code
      ↓
PKCE
      ↓
tokens
      ↓
Google identity
      ↓
local user
      ↓
application session
```

The provider-specific details change:

```text
URLs
scopes
identity fields
token behavior
OIDC support
```

but the architecture remains the same.

---

# 36. OAuth vs OpenID Connect

This distinction is very important if your goal is specifically "Login with X."

### OAuth

Primarily answers:

> "Can this application access this resource on behalf of the user?"

Example:

```text
"Allow my application to read your GitHub repositories."
```

### OpenID Connect

Adds identity:

> "Who authenticated?"

It provides standardized identity information, including an ID token.

So:

```text
OAuth
    ↓
authorization

OIDC
    ↓
authentication/identity built on OAuth
```

If you're building generic "Sign in with..." functionality, OIDC is often preferable when the provider supports it.

GitHub's traditional OAuth integration is an OAuth API authorization flow rather than a generic OIDC identity provider, so the application may obtain the user's identity by calling GitHub's user API after obtaining an access token.

---

# 37. The role of scopes

Scopes describe what access your application is requesting.

For example:

```text
scope=read:user
```

means roughly:

```text
"I need permission to read the user's profile."
```

Don't request:

```text
everything
```

if you only need:

```text
user identity
```

The principle is:

> Request the minimum permissions necessary.

This limits damage if credentials are compromised and improves user trust. GitHub explicitly recommends minimal scopes for OAuth applications.

---

# 38. What happens if the user rejects authorization?

The callback may contain something like:

```text
error=access_denied
```

Your application should treat this as:

```text
Login/authorization did not complete.
```

It should not:

```text
create a user
create an authenticated session
```

unless the application has another valid authentication mechanism.

---

# 39. What happens if the authorization code is stolen?

With modern PKCE:

```text
attacker gets:

authorization_code
```

but does not have:

```text
code_verifier
```

Therefore:

```text
code + wrong verifier
       ↓
token endpoint
       ↓
rejected
```

Authorization codes are also intended to be short-lived and single-use.

---

# 40. What happens if the OAuth state is wrong?

If you're using `state`:

```text
expected state = ABC
returned state = XYZ
```

Then:

```text
reject callback
```

Do not attempt:

```text
exchange code
create user
create session
```

The callback should be treated as invalid.

---

# 41. A good production architecture

For a normal server-side web application, a clean architecture is:

```text
                 HTTP / Router
                      |
                      v
               Auth Service
                      |
             ┌────────┴─────────┐
             │                  │
             v                  v
       OAuth Library       Application Logic
             │                  │
             v                  v
        Provider            User Database
             │                  │
             └────────┬─────────┘
                      |
                      v
                Session Manager
                      |
                      v
                Session Store
```

The OAuth library handles the complicated OAuth protocol.

Your application handles:

```text
users
permissions
sessions
redirect destinations
business rules
```

This is usually a better separation than implementing the entire OAuth protocol yourself.

---

# 42. What I would implement manually vs use a library for

### Use a mature library for:

```text
✓ OAuth authorization URL construction
✓ PKCE
✓ state handling
✓ callback processing
✓ authorization-code exchange
✓ provider protocol details
✓ token parsing/validation
✓ OIDC validation, if applicable
```

### Implement yourself:

```text
✓ local user model
✓ external-account mapping
✓ application authorization
✓ session policy
✓ session storage
✓ allowed post-login destinations
✓ application-specific redirects
✓ account linking rules
```

The exact boundary depends on the library.

---

# 43. Why not just write OAuth yourself?

You technically can.

The protocol itself isn't enormous.

The problem is that OAuth security is full of details:

```text
CSRF
PKCE
code injection
redirect URI validation
token leakage
open redirects
mix-up attacks
state handling
token storage
client authentication
provider differences
OIDC nonce validation
```

A mature library has already dealt with many of these edge cases.

The goal should therefore be:

> **Write your application's authentication policy, not your own OAuth protocol implementation.**

---

# 44. Is manually implementing `state` bad?

No.

This is perfectly legitimate:

```text
random state
   ↓
secure cookie
   ↓
callback
   ↓
compare
```

It is a standard OAuth security technique.

The concern is whether you're manually implementing things that a well-tested library could safely handle for you.

For example:

```text
manual PKCE implementation
manual state encoding
manual provider-specific token exchange
manual token parsing
manual OIDC validation
```

The more protocol code you own, the more security-sensitive code you have to maintain.

---

# 45. The simplest modern mental model

If you remember only one diagram, remember this:

```text
                USER
                  |
                  v
        ┌──────────────────┐
        │ Your Application │
        └────────┬─────────┘
                 |
                 | "Authenticate/authorize"
                 v
        ┌──────────────────┐
        │ OAuth Provider   │
        │ GitHub / Google  │
        └────────┬─────────┘
                 |
                 | authorization code
                 v
        ┌──────────────────┐
        │ Your Backend     │
        └────────┬─────────┘
                 |
                 | code + PKCE verifier
                 v
        ┌──────────────────┐
        │ OAuth Provider   │
        └────────┬─────────┘
                 |
                 | access token
                 v
        ┌──────────────────┐
        │ Provider API     │
        └────────┬─────────┘
                 |
                 | external identity
                 v
        ┌──────────────────┐
        │ Your User DB     │
        └────────┬─────────┘
                 |
                 | local user
                 v
        ┌──────────────────┐
        │ Your Session     │
        └────────┬─────────┘
                 |
                 | session cookie
                 v
                USER
```

---

# 46. Final checklist

For a modern "Login with GitHub/Google/etc." web application, think about these separately:

### OAuth protocol

```text
[ ] Authorization Code Flow
[ ] PKCE with S256
[ ] Correct redirect URI
[ ] Secure client credentials
[ ] Minimal scopes
```

### Transaction security

```text
[ ] PKCE
[ ] state if needed/desired
[ ] OIDC nonce when using OIDC
[ ] Short-lived transaction data
[ ] Reject invalid callbacks
```

### Application security

```text
[ ] Validate `next`
[ ] Prevent open redirects
[ ] Use stable external provider IDs
[ ] Don't trust provider usernames as permanent IDs
[ ] Don't create a session until authentication succeeds
```

### Session security

```text
[ ] Cryptographically random session IDs
[ ] HttpOnly cookie
[ ] Secure cookie
[ ] Appropriate SameSite policy
[ ] Session expiration
[ ] Ability to revoke sessions
[ ] Keep session data minimal
```

### Architecture

```text
[ ] OAuth library handles OAuth protocol
[ ] Provider-specific code isolated
[ ] User database independent of OAuth
[ ] Application session independent of OAuth tokens
[ ] Authorization/permissions remain application-owned
```

---

# 47. The core idea

OAuth is **not**:

```text
"Use this library and authentication is solved."
```

It's better understood as:

```text
OAuth
   ↓
Securely establish authorization/identity
        +
Your application
   ↓
Decide what that identity means
        +
Your session system
   ↓
Keep the browser authenticated
```

So the clean modern design is:

```text
              OAuth / OIDC
                   │
                   │
          "Who is this user?"
                   │
                   ▼
             External ID
                   │
                   ▼
              Local User
                   │
                   ▼
          Application Session
                   │
                   ▼
          Authenticated Browser
```

And the biggest practical recommendation is:

> **Don't implement OAuth protocol/security primitives yourself unless you have a good reason. Use a mature library for OAuth + PKCE + provider interaction, and keep your own code focused on user mapping, authorization, sessions, and application-specific redirects.**

For GitHub specifically, the modern authorization-code flow should include PKCE; GitHub added support in 2025 and recommends it.
