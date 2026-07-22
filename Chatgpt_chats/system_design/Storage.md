Perfect. This topic is one of the biggest upgrades in your architecture thinking.

Most developers think:

> "Storage means Database."

A software architect thinks:

> **"What kind of data am I storing? How will it be accessed? How large will it become? How fast must it be? How much can I spend?"**

That's a completely different mindset.

Storage is **not one technology**. It's a collection of technologies, each optimized for different requirements like latency, durability, scalability, sharing, and cost. Modern systems almost always combine multiple storage types rather than relying on one. ([SystemDesign][1])

---

# Topic 4 — Storage

## Imagine you're the architect...

A startup founder says:

> "We're building an online learning platform."

What data do you need to store?

```text
Users

Videos

PDF Notes

Assignments

Profile Pictures

Certificates

Chat Messages

Logs

Backups
```

A junior developer says:

> "Let's put everything in PostgreSQL."

It works...

...until it doesn't.

---

# The Real Problem

Imagine storing a 5 GB video inside PostgreSQL.

Now another.

And another.

Soon:

```text
Database

↓

500 TB
```

Questions start appearing:

* Backups become enormous.
* Queries become slower.
* Storage becomes expensive.
* Scaling becomes difficult.

The problem isn't PostgreSQL.

The problem is:

> **You're using the wrong storage for the wrong data.**

---

# The Architect's Question

Instead of asking

> "Which database should I use?"

Ask

> **"What kind of data is this?"**

Because different kinds of data need different storage.

---

# Think Like a Warehouse

Imagine you're designing a warehouse.

Would you store:

* Frozen food
* Documents
* Cars
* Jewelry

...all on the same shelf?

Of course not.

Each needs different storage.

Software is exactly the same.

---

# Storage Categories

As architects, we can roughly divide storage into:

```text
Storage

├── Database

├── Block Storage

├── File Storage

├── Object Storage

├── Archive Storage
```

Each solves different problems.

---

# First Rule

**A database is NOT a file storage system.**

This is probably the biggest beginner mistake.

Database:

Good for

```text
User

Email

Orders

Payments
```

Not good for

```text
Movies

Images

ZIP Files

PDFs

Backups
```

Large binary objects can be stored in databases, but at scale they're usually better placed in dedicated storage systems, with only metadata (filename, URL, owner, size, etc.) stored in the database. ([systemdesignsandbox.com][2])

---

# Block Storage

Let's start with the lowest level.

Imagine buying a brand new SSD.

It looks like:

```text
Empty Disk
```

No folders.

No files.

Nothing.

That's basically block storage.

---

## What is Block Storage?

Think of block storage as:

> **A virtual hard drive.**

It stores raw blocks of bytes.

It doesn't know what a file is.

It doesn't know what a photo is.

It doesn't know what a database is.

It only knows:

```text
Block 1

Block 2

Block 3
```

The operating system creates the file system on top of it. Block storage itself is just raw storage. ([GeeksforGeeks][3])

---

## Real World Analogy

Imagine an empty notebook.

Blank pages.

You decide:

* where chapter starts
* where chapter ends

The notebook doesn't care.

That's block storage.

---

## Architecture

```text
Application

↓

Operating System

↓

File System (ext4, NTFS)

↓

Block Storage
```

Notice:

Applications never talk directly to blocks.

---

## Where is Block Storage Used?

Block storage is excellent when applications need:

* Very low latency
* Frequent reads/writes
* Random access
* High IOPS

Typical examples:

* Databases
* Virtual machine disks
* Operating systems

---

## Real World

Suppose Amazon runs PostgreSQL.

The database files are stored on block storage (for example, cloud block volumes).

Not object storage.

Why?

Because databases constantly modify small pieces of data.

They need fast random writes.

---

# File Storage

Now imagine Windows Explorer.

```text
Documents

Pictures

Downloads

Music
```

Folders.

Subfolders.

Files.

That's file storage.

---

## What is File Storage?

Instead of blocks...

You work with:

```text
/report.pdf

/images/logo.png

/music/song.mp3
```

Everything has a path.

The storage manages directories and permissions for you. ([computerweekly.com][4])

---

## Real World Analogy

Imagine a library.

```text
Floor

↓

Shelf

↓

Book
```

Everything has a location.

Easy for humans.

---

## Architecture

```text
Application

↓

File System

↓

Storage
```

Unlike block storage...

You don't manage blocks yourself.

---

## Where is File Storage Used?

Perfect for:

* Shared folders
* Office documents
* Company files
* Team collaboration
* Home directories

---

## Examples

A company shared drive.

Dropbox folders.

Office documents.

NAS (Network Attached Storage).

---

# Object Storage

This is the storage every software architect must understand.

Almost every cloud application uses it.

---

## Problem

Imagine storing

```text
5 Billion Photos

200 Million Videos

100 Billion Documents
```

Can folders handle this well?

Not really.

Managing huge directory trees becomes difficult.

---

## Solution

Object Storage.

---

## What is Object Storage?

Instead of folders...

Everything becomes an object.

Each object contains:

```text
Data

+

Metadata

+

Unique ID
```

No traditional folders are required. Objects live in a flat namespace and are usually accessed through an HTTP API using a unique key. ([AlgoMaster][5])

---

## Real World Analogy

Imagine a warehouse.

Every package gets:

```text
Tracking Number

Metadata

Package
```

Nobody cares which shelf it's on.

The tracking number finds it.

---

## Architecture

```text
Application

↓

HTTP API

↓

Object Storage
```

Notice something different.

Unlike block storage...

Applications usually communicate over HTTP.

---

## Examples

* Profile pictures
* Videos
* PDFs
* Audio
* Backups
* ML datasets
* Logs

Basically...

Large files.

---

## Real World

When you upload:

```text
Instagram Photo
```

It usually isn't stored inside PostgreSQL.

Instead:

```text
Photo

↓

Object Storage

↓

URL

↓

Database stores URL
```

Example:

```text
users

id

name

profile_picture_url
```

The database stores metadata.

The image lives elsewhere.

---

# Object vs File vs Block

This comparison is one every architect should remember.

| Block                    | File                        | Object                           |
| ------------------------ | --------------------------- | -------------------------------- |
| Looks like a disk        | Looks like folders          | Looks like an API                |
| Fast random reads/writes | Human-friendly sharing      | Massive scalability              |
| Used by databases        | Used for shared files       | Used for images, videos, backups |
| OS manages file system   | Storage manages directories | Storage manages objects          |

The right choice depends on workload, not popularity. ([AlgoMaster][6])

---

# Hot, Warm and Cold Storage

Architects also think about **how often** data is accessed.

---

## Hot Storage

Frequently used.

Examples:

```text
Current User Profile

Shopping Cart

Today's Orders
```

Requirements:

* Lowest latency
* Highest performance

Usually the most expensive.

---

## Warm Storage

Sometimes accessed.

Examples:

```text
Last Year's Photos

Completed Projects

Old Chat History
```

Balanced performance and cost.

---

## Cold Storage

Rarely accessed.

Examples:

```text
Backups

Legal Records

Archives

10-year-old Logs
```

Very cheap.

Much slower.

Cloud providers offer archive tiers specifically for this purpose because long-term storage has very different access requirements than active application data. ([SystemDesign][1])

---

# Storage Architecture Example

Let's design YouTube.

What should go where?

```text
User Accounts

↓

PostgreSQL

--------------

Videos

↓

Object Storage

--------------

Thumbnails

↓

Object Storage

--------------

Comments

↓

PostgreSQL

--------------

Analytics Logs

↓

Data Warehouse / Object Storage

--------------

Search Index

↓

Search Engine
```

Notice something.

One application.

Many storage systems.

That's how real systems are built.

---

# Storage and Databases Work Together

Many beginners imagine:

```text
Application

↓

Database
```

Reality is closer to:

```text
Application

↓

PostgreSQL

↓

Object Storage

↓

Redis

↓

Search Engine

↓

Backups
```

Storage is an ecosystem.

Not one technology.

---

# Software Architect's Thinking

Imagine you're designing **DevEvent**.

You ask:

"What kinds of data do we have?"

```text
Users

Events

Tickets

Invoices

Banner Images

Certificates

Logs
```

Then map each one:

| Data                | Storage                      |
| ------------------- | ---------------------------- |
| Users               | PostgreSQL                   |
| Events              | PostgreSQL                   |
| Banner Images       | Object Storage               |
| Certificates (PDFs) | Object Storage               |
| Logs                | Log storage / Object Storage |
| Database Backups    | Object Storage / Archive     |

Notice:

You aren't choosing technologies first.

You're classifying data first.

Then choosing storage.

That's architectural thinking.

---

# Real-World Examples

### YouTube

* **Metadata (title, channel, views)** → Relational database
* **Video files** → Object storage
* **Thumbnails** → Object storage
* **Search index** → Dedicated search engine

---

### Google Drive

* File metadata → Database
* Actual documents, images, videos → Object storage
* User permissions → Database

---

### Netflix

* Content catalog → Database
* Movie files → Object storage feeding CDN
* Viewing history → Database
* Playback logs → Analytics storage

---

# Tools You'll Encounter

| Category            | Common Tools                                               |
| ------------------- | ---------------------------------------------------------- |
| Relational Database | PostgreSQL, MySQL                                          |
| NoSQL Database      | MongoDB, Cassandra                                         |
| Block Storage       | AWS EBS, Google Persistent Disk, Azure Managed Disks       |
| File Storage        | NFS, SMB, AWS EFS, Azure Files                             |
| Object Storage      | Amazon S3, Google Cloud Storage, Azure Blob Storage, MinIO |
| Archive Storage     | Amazon S3 Glacier, Azure Archive Storage                   |

Don't memorize the products.

Remember the **role** they play.

---

# Practice (Architect Mindset)

You're building a platform similar to **Google Classroom**.

You need to store:

* Student accounts
* Assignment PDFs
* Lecture videos
* Student submissions
* Profile pictures
* Chat messages
* Server logs
* Database backups

For each item, answer:

1. Which storage type would you choose?
2. Why?
3. Does it need hot, warm, or cold storage?
4. If the platform grows to **100 million users**, does your storage decision still make sense?

If you can justify each choice based on **workload, access pattern, scalability, and cost**, you're starting to think like a software architect instead of simply selecting technologies.

---

## Next Topic

Next we'll cover **Content Delivery Networks (CDNs)** from the same architectural perspective, including:

* Why object storage alone isn't enough for global applications
* How CDNs reduce latency
* Edge locations and Points of Presence (PoPs)
* Cache hierarchy and cache invalidation
* Static vs dynamic content
* Signed URLs and private content
* CDN architecture for YouTube, Netflix, and Instagram
* How CDNs work together with object storage and caching to deliver content worldwide.

[1]: https://systemdesign.ops4life.com/guides/storage/?utm_source=chatgpt.com "Storage — SystemDesign"
[2]: https://www.systemdesignsandbox.com/learn/storage-types?utm_source=chatgpt.com "Block Storage vs Object Storage | System Design Sandbox"
[3]: https://www.geeksforgeeks.org/system-design/block-object-and-file-storage-in-cloud-with-difference/?utm_source=chatgpt.com "Block, Object, and File Storage in System Design - GeeksforGeeks"
[4]: https://www.computerweekly.com/feature/Storage-technology-explained-File-block-and-object-storage?utm_source=chatgpt.com "Storage technology explained: File, block and object storage | Computer Weekly"
[5]: https://algomaster.io/learn/system-design/object-storage?utm_source=chatgpt.com "Object Storage | System Design"
[6]: https://algomaster.io/learn/system-design/block-vs-file-vs-object-storage?utm_source=chatgpt.com "Block vs File vs Object Storage | System Design"
