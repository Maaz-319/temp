
# 2. Knowledge Representation — Introductory Pass
Let's first get the *intuition* right. Don't memorize definitions yet.

## 1. First: What is Knowledge Representation?

In simple words:

> **Knowledge Representation (KR) is the way we organize information so an AI system can understand relationships between things and reason with them.**

That's the important part: **reason with them**.

A normal database can store:

```text
Ali
20
CS Student
Lahore
```

But an AI knowledge representation might capture:

```text
Ali is a CS student.
CS students study programming.
Programming requires practice.
Therefore, Ali needs programming practice.
```

Now the system isn't merely storing facts.

It has **relationships + rules** that allow it to derive something new.

That distinction is basically why KR exists. Knowledge representation is concerned with both the **representational** and **reasoning** challenges of making knowledge usable by AI. [Stanford Encyclopedia of Philosophy](https://plato.stanford.edu/archives/fall2020/entries/logic-ai/?utm_source=chatgpt.com)

---

# 2. Data vs Knowledge vs Code

This is probably the most important thing to understand from this section.

Think of an AI system as having three different ingredients:

```text
DATA
  ↓
"What exists?"

KNOWLEDGE
  ↓
"What does it mean, and how is it related?"

CODE
  ↓
"What should I do with it?"
```

Let's use a simple example.

Suppose we're building an AI system for a university.

### Data

We have:

```text
Ali
CS
20
3.4
Programming
3
```

These are pieces of data.

Your syllabus describes data as essentially **raw facts without the relationships/context that make them useful for inference**. Syllabus

Real systems obviously use more structured data than this, and technically data can already have structure and meaning—NIST, for example, defines data as information in a specific representation. So don't interpret "data = meaningless" too literally. [NIST Computer Security Resource Center](https://csrc.nist.gov/glossary/term/data?utm_source=chatgpt.com)

For your **exam**, though, remember the course framing:

> **Data = raw facts/values.**

---

# 3. Then What Makes It Knowledge?

Now we add relationships.

```text
Ali is a CS student.

CS students study programming.

Ali has completed Programming 1.

Programming 2 requires Programming 1.

Therefore:

Ali is eligible for Programming 2.
```

Notice what happened.

We didn't necessarily get a new piece of data from somewhere.

We **inferred** something from existing facts and relationships.

That's the key idea:

> **Knowledge = facts + relationships + context that allow reasoning/inference.**

This matches the conceptual distinction in your syllabus. Syllabus

NIST also describes knowledge as a retrievable set of concepts, while its information terminology emphasizes meaning and context. [NIST Computer Security Resource Center](https://csrc.nist.gov/glossary/term/knowledge?utm_source=chatgpt.com)

---

# 4. And What Is Code?

Now imagine we have:

```python
if student.has_completed("Programming 1"):
    student.can_take("Programming 2")
```

That's **code**.

Code tells the computer **how to perform an operation**.

So:

| Thing | Main question |
|---|---|
| **Data** | What values/facts do we have? |
| **Knowledge** | What do these facts mean and how are they related? |
| **Code** | What procedure should the computer execute? |

A nice way to remember it:

```text
Data     → facts
Knowledge → facts + meaning + relationships
Code     → procedures
```

---

# 5. Why Can't We Just Put Everything in Code?

This is where Knowledge Representation becomes useful.

Imagine you're making a medical expert system.

Bad design:

```python
if fever and cough and fatigue:
    diagnose_flu()

if fever and rash:
    diagnose_measles()

if fever and ...
    ...
```

You've basically buried the **medical knowledge inside the program code**.

Now imagine a doctor tells you:

> "Add a new rule about a recently discovered symptom."

You have to modify the program.

With a knowledge-based approach, you could separate the knowledge:

```text
Knowledge Base

Disease: Flu
Symptoms:
    fever
    cough
    fatigue

Rule:
    IF fever AND cough AND fatigue
    THEN possible flu
```

And have a separate reasoning mechanism operate on it.

This separation between **domain knowledge** and **inference procedures** is a major idea in traditional knowledge-based AI. It makes it possible to add or modify domain knowledge without rebuilding the whole reasoning program. [ScienceDirect](https://www.sciencedirect.com/topics/social-sciences/knowledge-representation?utm_source=chatgpt.com)

Think:

```text
                 ┌─────────────────┐
                 │  Knowledge Base  │
                 │                 │
                 │ Facts           │
                 │ Relationships   │
                 │ Rules           │
                 └────────┬────────┘
                          │
                          ↓
                 ┌─────────────────┐
                 │ Inference Engine│
                 │                 │
                 │ "What follows?" │
                 └────────┬────────┘
                          │
                          ↓
                       Answer
```

**Knowledge = what the system knows**

**Inference = how it derives conclusions**

We'll go much deeper into this later when you reach **Logic Programming, Knowledge Representation Schemas, and Expert Systems** in Sections 7–9 of your syllabus. Syllabus

---

# 6. So What Problem Does Knowledge Representation Solve?

Here's the exam-friendly version:

> **Problem:** Computers need knowledge in a structured form that allows them to reason about a domain rather than merely store information.

Suppose you give a computer:

```text
Ali
Ahmed
CS
Programming
Prerequisite
```

It doesn't automatically know:

```text
Ali studies CS.

Programming is a CS subject.

Programming 2 requires Programming 1.

Ali completed Programming 1.

Therefore Ali can take Programming 2.
```

We need a representation that makes these relationships explicit.

So KR solves:

### Problem 1 — Representing complex knowledge

How do we represent:

- objects
- properties
- relationships
- rules
- events
- concepts
- exceptions

?

### Problem 2 — Reasoning

How can the AI derive:

> "Ali can take Programming 2"

from existing knowledge?

### Problem 3 — Updating knowledge

What happens when:

```text
Programming 2 prerequisite
```

changes?

We want to update the **knowledge**, rather than rewrite an entire program.

These are exactly the kinds of representational and reasoning challenges that motivated knowledge representation as an AI field. [Stanford Encyclopedia of Philosophy](https://plato.stanford.edu/archives/fall2020/entries/logic-ai/?utm_source=chatgpt.com)

---

# 7. How Does Knowledge Representation Solve It?

By choosing a **representation scheme**.

Basically:

> "What structure should we use to describe the world?"

For example, we could represent:

### As simple facts

```text
Student(Ali)
Studies(Ali, CS)
```

### As rules

```text
IF Student(x) AND Studies(x, CS)
THEN CS_Student(x)
```

### As a graph

```text
Ali ──studies──> CS
CS  ──contains──> Programming
```

### As a frame

```text
Student:
    name: Ali
    age: 20
    major: CS
```

These aren't random formats.

Each representation gives the AI different capabilities for **storing, querying and reasoning about knowledge**.

Your later syllabus section explicitly covers several of these:

- Logic
- Semantic Networks
- Frames
- Scripts

Syllabus

We'll study each properly later.

---

# 8. Why Does Representation Matter?

This is the second major exam point from your syllabus.

Your syllabus says a representation scheme should be:

> **Expressive + efficient for inference + easy to acquire/update.** Syllabus

Let's unpack that.

## A. Expressiveness

**Can I represent the knowledge I actually need?**

Suppose I want to represent:

```text
Ali owns a Tesla.

Tesla is a vehicle.

Vehicles require energy.

Electric vehicles use electricity.

Tesla is electric.
```

My representation needs to be capable of representing:

```text
Ali → owns → Tesla

Tesla → is_a → Vehicle

Tesla → is_a → ElectricVehicle
```

If the representation can't express these relationships, it's not useful.

So:

> **Expressiveness = How much and what kinds of knowledge can I represent?**

---

# 9. Efficient Inference

Imagine I have:

```text
10 facts
```

and finding a conclusion takes:

```text
0.001 seconds
```

Cool.

But imagine:

```text
10 million facts
```

and the system has to check every possible relationship every time.

Now inference becomes painfully slow.

So we care about:

> **How efficiently can the system derive conclusions from its knowledge?**

This is one of the established criteria for evaluating knowledge representation systems: not just whether knowledge can be represented, but whether conclusions can be generated efficiently. [ScienceDirect](https://www.sciencedirect.com/topics/social-sciences/knowledge-representation?utm_source=chatgpt.com)

---

# 10. Easy to Acquire and Update

This one is underrated.

Suppose your knowledge base contains:

```text
100,000 rules
```

and adding one new rule requires rewriting half the system.

That's terrible.

Instead, we want something like:

```text
Knowledge Base
       │
       ├── Add knowledge
       ├── Remove knowledge
       ├── Update knowledge
       └── Query knowledge
```

This matters because real-world knowledge changes.

For example:

```text
University policy:

Old:
CS students need 120 credits.

New:
CS students need 130 credits.
```

Ideally:

```text
UPDATE(KnowledgeBase)
```

rather than:

```text
rewrite_entire_AI_system()
```

The ability to add and modify stored knowledge is explicitly identified as an important desirable property of KR systems. [ScienceDirect](https://www.sciencedirect.com/topics/social-sciences/knowledge-representation?utm_source=chatgpt.com)

---

# 11. Real-World Example: Google Knowledge Graph

A really good modern example is a **knowledge graph**.

Stanford describes knowledge graphs as a way of organizing structured knowledge around entities and their relationships, integrating information from multiple sources and supporting inference and applications in AI/ML/NLP. [Stanford University](https://web.stanford.edu/class/cs520/?utm_source=chatgpt.com)

Imagine:

```text
                 ┌──────────────┐
                 │   Pakistan   │
                 └──────┬───────┘
                        │
                     capital
                        │
                        ↓
                 ┌──────────────┐
                 │ Islamabad    │
                 └──────────────┘
```

and:

```text
Ali ──studies_at──> University

University ──located_in──> Islamabad

Islamabad ──capital_of──> Pakistan
```

Now the system has relationships rather than isolated values.

That's extremely useful for:

- search
- question answering
- recommendation
- information integration
- NLP
- explaining relationships between entities

Knowledge graphs have become an important abstraction for organizing structured knowledge and incorporating world knowledge into AI systems. [Stanford University](https://web.stanford.edu/class/cs520/?utm_source=chatgpt.com)

---

# 12. Another Example: Medical Expert System

This is actually closer to the **classic symbolic AI** your syllabus is teaching.

Imagine:

```text
Fact:
Patient has fever.

Fact:
Patient has cough.

Fact:
Patient has fatigue.

Rule:
IF fever AND cough AND fatigue
THEN possible influenza.
```

The system can reason:

```text
Patient
   │
   ├── fever
   ├── cough
   └── fatigue
          │
          ↓
       Rule fires
          │
          ↓
   Possible influenza
```

That's the foundation behind **rule-based expert systems**, which your syllabus covers later. Classic systems such as MYCIN used knowledge bases and inference mechanisms for medical reasoning. [ScienceDirect](https://www.sciencedirect.com/topics/social-sciences/knowledge-representation?utm_source=chatgpt.com)

---

# 14. Practice Idea 🔥

Don't make a boring CRUD project.

Build a tiny:

## "University Knowledge Reasoner"

Create a knowledge base like:

```text
Students
Courses
Teachers
Prerequisites
Departments
```

Represent facts such as:

```text
Ali studies CS.

AI is a CS course.

AI requires Python.

Ali completed Python.
```

Then implement rules:

```text
IF student completed prerequisite
THEN student is eligible for course.
```

Your system should be able to answer:

```text
> Is Ali eligible for AI?

Yes.

> Why?

Ali completed Python,
and Python is a prerequisite for AI.
```

Start with Python dictionaries/graphs.

Then **rebuild the same idea in Prolog**.

That second version will make the difference between **ordinary programming and logic-based knowledge representation** click much harder than simply reading about it.

---

# 15. The Mental Model I Want You to Keep

Forget the complicated terminology for a moment.

Think of an intelligent system like this:

```text
             WORLD
               ↓
        ┌───────────────┐
        │     DATA      │
        │ facts/values  │
        └───────┬───────┘
                ↓
        ┌───────────────┐
        │   KNOWLEDGE   │
        │ relationships │
        │ context/rules │
        └───────┬───────┘
                ↓
        ┌───────────────┐
        │   INFERENCE   │
        │  "What follows?│
        └───────┬───────┘
                ↓
             ANSWER
```

And **code** is the machinery implementing the operations that manipulate the data/knowledge and perform inference.

The central idea is:

> **Data tells you what is there. Knowledge tells you how things relate and what those facts mean. Code provides procedures for operating on them. Knowledge representation gives the knowledge a form in which a computer can reason over it.**

That's the foundation you'll need when we later reach **Propositional Logic → First-Order Logic → Prolog → Semantic Networks → Frames → Scripts → Expert Systems**. Your syllabus deliberately places these topics after this introductory distinction because they are essentially different ways of representing and reasoning about knowledge. Syllabus

### Quick exam check

If the examiner asks:

**"Why is knowledge representation important in AI?"**

A strong short answer would be:

> Knowledge representation provides a structured way to encode facts, relationships, and rules so that an AI system can reason about a domain. A good representation should be expressive enough to capture relevant knowledge, support efficient inference, and allow knowledge to be acquired, modified, and maintained easily. 

**Next concept in this section:** we can go deeper into **Knowledge vs Data vs Code** with tricky examples/exam scenarios, because that distinction is deceptively simple but has some important subtleties.