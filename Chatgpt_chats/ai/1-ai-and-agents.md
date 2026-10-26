# 1. Introduction to AI & Knowledge-Based Systems

## First: What are we actually trying to understand?

Before jumping into algorithms, let's answer the bigger question:

> **What does it actually mean for a machine to be intelligent?**

That's where AI starts.

A modern definition from NIST describes AI as a machine-based system that, given human-defined objectives, can make predictions, recommendations, or decisions that influence real or virtual environments. [NIST Computer Security Resource Center](https://csrc.nist.gov/glossary/term/artificial_intelligence?utm_source=chatgpt.com)

But that's a **modern engineering definition**.

Historically, AI researchers asked a much harder question:

> **Can a machine think?**

And that question led to several different interpretations of intelligence.

---

# 1.1 What Does "Intelligence" / AI Mean?

AIMA gives us **four different ways of looking at AI**:

| | Thinking | Acting |
|---|---|---|
| **Human** | Thinking humanly | Acting humanly |
| **Rational** | Thinking rationally | Acting rationally |

This distinction is **very important for exams**.

Let's understand each.

---

## A. Thinking Humanly

### What is it?

This approach asks:

> **Can we make a machine think the way a human thinks?**

The focus isn't simply on getting the correct answer.

It's about reproducing the **human cognitive process**.

For example:

Suppose you ask:

> "Why did you choose this university?"

A human might:

1. remember universities they considered
2. compare fees
3. consider reputation
4. remember what their parents said
5. consider distance
6. weigh emotions
7. make a decision

A "thinking humanly" AI tries to model this kind of process.

### Problem it solves

We want machines to reproduce or simulate **human cognitive behavior**.

This is useful when we're interested in:

- human decision-making
- cognitive science
- psychology
- understanding how people solve problems
- human-computer interaction

### How does it solve it?

Researchers study how humans actually perform a task and then build computational models of those processes.

So:

**Human behavior → study cognitive process → computational model**

This is different from simply saying:

> "Give me the correct answer."

### Real-world example

Cognitive models can be used to simulate:

- how humans make decisions
- how users interact with interfaces
- how people solve problems
- how memory and attention affect behavior

### Important distinction

A system can produce the same answer as a human **without thinking like a human**.

That's why this is its own category.

---

# B. Thinking Rationally

Now we move away from humans.

The question becomes:

> **Can the machine reason correctly according to formal rules of logic?**

This is the **"laws of thought"** approach in AIMA. [AIMA](https://aima.cs.berkeley.edu/contents.htm?utm_source=chatgpt.com)

For example:

```text
All humans are mortal.

Socrates is a human.

Therefore:

Socrates is mortal.
```

A machine can represent this using formal logic and derive the conclusion.

### Problem it solves

Humans aren't always logically consistent.

We make mistakes.

We forget things.

We get emotional.

Formal reasoning tries to provide a systematic way of reaching conclusions.

### How?

Represent knowledge formally and apply inference rules.

Very roughly:

```text
Knowledge
   ↓
Logical rules
   ↓
Inference
   ↓
Conclusion
```

### Real-world application

A classic example is a **rule-based expert system**.

For example:

```text
IF patient has fever
AND patient has cough
THEN possible_flu = true
```

The system uses explicit rules to derive conclusions.

This is one reason you'll later encounter:

- propositional logic
- first-order logic
- knowledge bases
- inference
- expert systems

---

# C. Acting Humanly

This is where **Alan Turing** enters.

Instead of asking:

> "Does the machine actually think?"

Turing essentially proposed a more observable question:

> **Can a machine behave in a way that is indistinguishable from a human in conversation?**

His 1950 paper *Computing Machinery and Intelligence* introduced the **Imitation Game**, which became associated with the Turing Test. [OUP Academic](https://academic.oup.com/mind/article/LIX/236/433/986238?login=false\&utm_source=chatgpt.com)

Imagine:

```text
        Human Judge
             |
       text conversation
        /            \
       /              \
    Human           Machine
```

The judge doesn't know which is which.

If the judge can't reliably distinguish the machine from the human, the machine succeeds according to the test.

### Problem it solves

It gives us an **observable test for human-like behavior** rather than trying to define mysterious things like "thinking."

### How?

Evaluate the machine's external behavior.

Not:

> "What is happening inside its brain?"

But:

> "How does it behave?"

### Real-world example

A conversational AI is an obvious modern example of a system evaluated partly through human-like interaction.

But here's an important exam point:

**Passing a Turing-style test does not prove that a machine thinks like a human.**

It only demonstrates a certain level of human-like behavior.

---

# D. Acting Rationally ⭐

This is the approach that becomes **extremely important** for the rest of your AIMA course.

Instead of asking:

> "Does it think like a human?"

or

> "Does it behave like a human?"

we ask:

> **Does it choose the best action given what it knows?**

That's a **rational agent**.

AIMA calls this the **rational-agent approach**. [AIMA](https://aima.cs.berkeley.edu/contents.htm?utm_source=chatgpt.com)

Imagine a self-driving car.

It sees:

```text
Traffic light → RED
Pedestrian → crossing
Car → approaching
```

It decides:

```text
BRAKE
```

It doesn't matter whether the internal reasoning resembles a human's reasoning.

What matters is:

> Was braking the appropriate action given the available information?

### Problem it solves

We want machines that **make good decisions in their environments**.

### How?

The agent:

```text
Perceives environment
       ↓
Processes information
       ↓
Chooses action
       ↓
Acts
       ↓
Environment changes
       ↓
Perceives again
```

This gives us the fundamental AI loop:

> **Perception → Decision → Action**

And this leads directly into **Intelligent Agents**.

---

# The Four Approaches — Memorize This

For your exam:

```text
                    AI
                     |
        ┌────────────┴────────────┐
        │                         │
     THINKING                  ACTING
        │                         │
   ┌────┴────┐               ┌────┴────┐
   │         │               │         │
 HUMAN    RATIONAL         HUMAN    RATIONAL
   │         │               │         │
Cognitive   Logic         Turing     Agent
Modeling     / Rules       Test      approach
```

The easiest way to remember:

- **Thinking humanly** → "Think like us"
- **Thinking rationally** → "Think logically"
- **Acting humanly** → "Behave like us"
- **Acting rationally** → "Do the right thing"

---

# 1.2 History of AI

This part is less about memorizing 500 dates and more about understanding **why AI changed direction repeatedly**.

AIMA itself divides its history into:

- inception: 1943–1956
- early enthusiasm: 1952–1969
- reality check: 1966–1973
- expert systems: 1969–1986
- neural networks' return
- probabilistic reasoning and ML
- big data
- deep learning [AIMA](https://aima.cs.berkeley.edu/contents.htm?utm_source=chatgpt.com)

Let's turn that into a story.

---

## Era 1 — Symbolic AI

### Basic idea

Early AI researchers thought:

> Intelligence is largely about manipulating symbols and rules.

For example:

```text
Human
  ↓
knowledge

"Ali is a student."
"Students attend university."

  ↓

Rules

  ↓

Conclusion

"Ali attends university."
```

Machines were given:

- symbols
- facts
- rules
- logic
- search procedures

This became known as **symbolic AI**.

---

# GPS — General Problem Solver

One famous example is **GPS (General Problem Solver)**, developed by Newell, Shaw and Simon.

The idea was ambitious:

> Instead of creating a program for one specific problem, can we create a general-purpose problem solver?

GPS used **means-ends analysis**: compare the current state with the desired goal, identify the difference, and choose actions/subgoals to reduce that difference. [Wikipedia](https://en.wikipedia.org/wiki/General_Problem_Solver?utm_source=chatgpt.com)

Think:

```text
Current state
     ↓
"What is different from my goal?"
     ↓
Find action that reduces difference
     ↓
New state
     ↓
Repeat
     ↓
Goal
```

### Example

You want:

```text
Current:
Kitchen → messy

Goal:
Kitchen → clean
```

Difference:

```text
messy vs clean
```

Action:

```text
clean kitchen
```

In more complicated problems, GPS decomposes the problem into subgoals.

### Why it mattered

It demonstrated the power of **general symbolic problem solving**.

### Why it didn't solve general intelligence

The real world is messy.

There are:

- huge numbers of possibilities
- uncertainty
- incomplete information
- ambiguous concepts
- common sense
- enormous search spaces

Symbolic systems could become overwhelmed by the number of possible states — what's often called **combinatorial explosion**. [Museum of AI](https://www.museumofai.org.uk/nodes/node-gps-1959?utm_source=chatgpt.com)

---

# ELIZA

Then you have **ELIZA**, created by Joseph Weizenbaum at MIT.

ELIZA simulated a psychotherapist using pattern matching and scripted responses. [Springer Nature Link](https://link.springer.com/article/10.1007/s00146-018-0825-9?utm_source=chatgpt.com)

Someone might say:

```text
"I am feeling sad."
```

ELIZA could detect a pattern and respond with something like:

```text
"Why are you feeling sad?"
```

It wasn't actually understanding the person's emotions.

It was essentially:

```text
Input
 ↓
Pattern matching
 ↓
Rule
 ↓
Response
```

Yet people sometimes reacted to ELIZA as if it genuinely understood them. [HISTORY TV Denmark](https://www.history.com/articles/ai-first-chatbot-eliza-artificial-intelligence-precursor-llms?utm_source=chatgpt.com)

### Why you study ELIZA

Because it teaches a very important AI lesson:

> **Human-like behavior does not necessarily mean human-like understanding.**

That connects directly back to the **Turing Test**.

---

# AI Winters ❄️

Then something interesting happened.

People became extremely optimistic about AI.

Predictions were ambitious.

But actual systems struggled with real-world complexity.

Funding and interest dropped.

These periods became known as **AI winters**.

Stanford's AI100 history describes the mid-1980s decline as a period where interest dropped and funding dried up. [AI100](https://ai100.stanford.edu/2016-report/appendix-i-short-history-ai?utm_source=chatgpt.com)

### The pattern

You should remember:

```text
Big promises
     ↓
Huge expectations
     ↓
Reality doesn't match
     ↓
Disappointment
     ↓
Funding decreases
     ↓
AI winter
     ↓
New approach
     ↓
AI revival
```

This happened more than once.

---

# Expert Systems Boom

Then symbolic AI became useful in a narrower form.

Instead of:

> "Let's build a machine with general intelligence."

Researchers asked:

> "Can we encode the knowledge of an expert in a specific domain?"

Enter **expert systems**.

Example:

```text
Doctor's knowledge
       ↓
Rules + facts
       ↓
Knowledge Base
       ↓
Inference Engine
       ↓
Diagnosis / Recommendation
```

This worked much better when the domain was constrained.

A famous example is **MYCIN**, which was designed to assist with medical diagnosis.

### Core idea

```text
Knowledge + Rules + Inference
```

This is the foundation behind a lot of the **Knowledge-Based Systems** material you'll study later.

---

# Statistical / Machine Learning Era

Then the philosophy shifted.

Instead of manually writing:

```text
IF this
AND that
THEN this
```

we started saying:

> **Let the machine learn patterns from data.**

For example:

Instead of manually defining what a cat looks like:

```text
IF ears pointed
AND four legs
AND whiskers
...
THEN CAT
```

give the system:

```text
10,000 cat images
10,000 non-cat images
```

and let an algorithm learn the patterns.

That is the major conceptual shift:

### Symbolic AI

```text
Human → rules → machine
```

### Machine Learning

```text
Human → data → learning algorithm → learned model
```

---

# Deep Learning Era

Neural networks had existed much earlier, but advances in:

- computational power
- GPUs
- large datasets
- improved algorithms

made deep neural networks extremely powerful.

Stanford's AI history places deep learning's major modern rise around 2011 onward. [AI100](https://ai100.stanford.edu/2016-report/appendix-i-short-history-ai?utm_source=chatgpt.com)

This produced major advances in:

- computer vision
- speech recognition
- NLP
- game playing
- generative AI

And eventually:

```text
Neural networks
       ↓
Deep learning
       ↓
Transformers
       ↓
Large language models
       ↓
Generative AI
```

---
---

# 1.4 Applications of AI

Don't memorize random application names.

Think in categories.

## Classic AI

### Games

Examples:

- chess
- checkers
- game-playing agents

These introduced:

- search
- heuristics
- minimax
- game trees

---

### Expert Systems

```text
Expert knowledge
      ↓
Rules
      ↓
Inference
      ↓
Decision
```

Used historically in:

- medicine
- chemistry
- troubleshooting
- diagnosis

---

### NLP

Early systems such as ELIZA dealt with language through symbolic rules and pattern matching. [Springer Nature Link](https://link.springer.com/article/10.1007/s00146-018-0825-9?utm_source=chatgpt.com)

---

# Modern AI

### Computer Vision

```text
Image
 ↓
Neural network
 ↓
Features
 ↓
Prediction
```

Applications:

- face recognition
- medical imaging
- autonomous vehicles
- quality inspection

---

### Recommendation Systems

Netflix/YouTube/Spotify-style systems:

```text
User behavior
     +
Item information
     ↓
Model
     ↓
Predicted preferences
     ↓
Recommendations
```

---

### Autonomous Systems

Examples:

- autonomous vehicles
- robots
- drones

And here's where your **agent** concept becomes extremely useful.

---

# 1.5 Intelligent Agents ⭐⭐⭐

This is probably the most important part of this chapter.

Forget complicated definitions for a second.

Imagine:

> **Anything that observes its environment and does something in that environment can be modeled as an agent.**

AIMA describes an agent as something that perceives its environment through sensors and acts upon that environment through actuators. [AIMA](https://aima.cs.berkeley.edu/4th-ed/pdfs/newchap02.pdf?utm_source=chatgpt.com)

Think:

```text
             ENVIRONMENT
                  ↓
               Sensors
                  ↓
               AGENT
                  ↓
              Actuators
                  ↓
             ENVIRONMENT
```

That's the fundamental loop.

---

# Example: Robot Vacuum

Environment:

```text
House
```

Sensors:

```text
Camera
Bump sensor
Dirt sensor
```

Agent:

```text
Robot vacuum software
```

Actuators:

```text
Wheels
Vacuum motor
Brushes
```

It perceives:

```text
"There is dirt here."
```

and acts:

```text
"Move here and vacuum."
```

Then it observes again.

So:

```text
PERCEIVE → DECIDE → ACT → PERCEIVE → DECIDE → ACT
```

---

# 1.6 Rational Agent

Now remember our earlier discussion.

A rational agent isn't necessarily:

> "an agent that always makes the perfect decision."

That's impossible in many real situations because the agent doesn't know everything.

Instead:

> **A rational agent chooses the action expected to maximize its performance measure, given its percept history and available knowledge.**

That's the important idea.

---

## Example

You're driving.

You see:

```text
Traffic light = red
```

A rational action is:

```text
STOP
```

But imagine the sensor is broken and incorrectly says:

```text
Traffic light = green
```

The agent might drive.

Was the agent necessarily irrational?

Not necessarily.

It made the decision using the information it had.

That's why **rationality ≠ omniscience**.

AIMA explicitly distinguishes rationality from omniscience and discusses how learning and autonomy affect agents. [AIMA](https://aima.cs.berkeley.edu/contents.htm?utm_source=chatgpt.com)

---

# 1.7 PEAS Framework ⭐⭐⭐

This is an **exam favorite**.

PEAS stands for:

> **P**erformance  
> **E**nvironment  
> **A**ctuators  
> **S**ensors

AIMA says that specifying the task environment is the first step in designing an agent and groups these four elements into the PEAS description. [AIMA](https://aima.cs.berkeley.edu/4th-ed/pdfs/newchap02.pdf?utm_source=chatgpt.com)

Let's use a self-driving taxi.

### P — Performance

How do we determine whether the agent is doing a good job?

For example:

```text
Safety
Passenger satisfaction
Travel time
Fuel efficiency
Legal driving
Profit
```

### E — Environment

Where does it operate?

```text
Roads
Cars
Pedestrians
Traffic lights
Weather
Passengers
```

### A — Actuators

How does it affect the environment?

```text
Steering
Accelerator
Brakes
Horn
Indicators
```

### S — Sensors

How does it perceive the environment?

```text
Camera
GPS
Radar
LiDAR
Speedometer
Microphones
```

So:

```text
Self-driving taxi

P → Safe + fast + comfortable journey
E → Roads + traffic + pedestrians
A → Steering + brakes + accelerator
S → Cameras + GPS + radar + LiDAR
```

### Exam trick

If they ask:

> "Give PEAS for a chess-playing agent"

Don't start writing paragraphs.

Think:

```text
P → win / score / avoid illegal moves
E → chess board + opponent
A → move pieces
S → board state
```

That's it.

---

# 1.8 Types of Environments

This is another section you should **understand rather than memorize**.

AIMA identifies several properties of task environments. [AIMA](https://aima.cs.berkeley.edu/contents.htm?utm_source=chatgpt.com)

---

## 1. Fully Observable vs Partially Observable

### Fully observable

Agent can access all relevant information.

Example:

```text
Chess
```

The entire board is visible.

### Partially observable

Some information is hidden.

Example:

```text
Poker
```

You don't know the opponent's cards.

### Easy memory trick

> **Can I see everything important?**

Yes → fully observable.

No → partially observable.

---

# 2. Deterministic vs Stochastic

### Deterministic

Same action → predictable result.

```text
2 + 2 → 4
```

Chess is approximately deterministic in its rules.

### Stochastic

Outcomes involve uncertainty.

```text
Action → possible outcomes
```

Driving has:

- unpredictable pedestrians
- other drivers
- weather
- mechanical uncertainty

### Memory trick

> **Can I predict exactly what happens after my action?**

Yes → deterministic.

No → stochastic.

---

# 3. Episodic vs Sequential

### Episodic

Each decision is relatively independent.

Example:

```text
Image classification
```

Classify image #1.

Then image #2.

The first decision doesn't fundamentally determine the second.

### Sequential

Current action affects future decisions.

Example:

```text
Chess
```

Your current move changes everything that can happen later.

### Memory trick

> **Does what I do now affect what happens later?**

Yes → sequential.

---

# 4. Static vs Dynamic

### Static

Environment doesn't change while you're deciding.

Example:

```text
Crossword puzzle
```

### Dynamic

Environment can change while you're thinking.

Example:

```text
Driving
```

Traffic keeps moving while the agent makes decisions.

---

# 5. Discrete vs Continuous

### Discrete

Finite/countable states or actions.

```text
Chess moves
```

### Continuous

Values vary continuously.

```text
Car speed
Steering angle
Robot arm position
```

---

# 6. Single-Agent vs Multi-Agent

### Single-agent

Only one agent is making decisions.

Example:

```text
Sudoku solver
```

### Multi-agent

Other agents also act.

Example:

```text
Chess
```

There are two decision-makers.

Or:

```text
Autonomous driving
```

because other drivers are also making decisions.

---

# Environment Cheat Sheet

| Property | Ask yourself |
|---|---|
| Fully observable | Can I see everything important? |
| Partially observable | Is some important information hidden? |
| Deterministic | Does my action have a predictable outcome? |
| Stochastic | Is there uncertainty? |
| Episodic | Is each decision mostly independent? |
| Sequential | Does today's action affect tomorrow? |
| Static | Does the environment wait for me? |
| Dynamic | Can it change while I'm thinking? |
| Discrete | Are states/actions countable? |
| Continuous | Do values vary continuously? |
| Single-agent | Am I the only decision-maker? |
| Multi-agent | Are other agents making decisions too? |

---

# 1.9 Agent Architectures

Now we're at the really interesting part.

We've established:

```text
Environment
     ↓
   Sensors
     ↓
   Agent
     ↓
 Actuators
     ↓
Environment
```

But **how does the agent decide what to do?**

AIMA introduces five major architectures. [AIMA](https://aima.cs.berkeley.edu/contents.htm?utm_source=chatgpt.com)

---

# 1. Simple Reflex Agent

The simplest one.

It says:

> **If I perceive X, do Y.**

Basically:

```text
IF condition
THEN action
```

Example robot vacuum:

```text
IF dirt detected
THEN vacuum
```

Or:

```text
IF obstacle detected
THEN turn
```

### Architecture

```text
Environment
    ↓
 Sensors
    ↓
Current percept
    ↓
Condition → Action rule
    ↓
 Actuators
    ↓
Environment
```

### Problem it solves

Simple situations where the current observation is enough to decide what to do.

### Major limitation

It doesn't remember the past.

Suppose:

```text
Room A → Room B → Room A
```

It might not know:

> "I've already been here."

It just reacts to what it currently sees.

---

# 2. Model-Based Reflex Agent

Now we give the agent **memory / internal state**.

Instead of only asking:

> "What do I see?"

it also asks:

> "What do I know about the world based on what I've seen before?"

Architecture:

```text
             ┌──────────────┐
             │ Internal     │
             │ State/Model  │
             └──────┬───────┘
                    ↑
Environment → Sensors → Agent → Actuators
```

### Problem it solves

**Partial observability.**

If you can't see everything, memory becomes useful.

Example:

A robot enters a room.

It sees:

```text
Door
```

Then moves away.

Later it sees another wall.

Its internal model can remember:

> "There was a door behind me."

### Difference

Simple reflex:

```text
Current percept → action
```

Model-based:

```text
Current percept
      +
Internal state
      ↓
Action
```

---

# 3. Goal-Based Agent

Now we add **goals**.

Instead of simply reacting:

> "Obstacle → turn."

the agent thinks:

> "What action helps me reach my goal?"

Example:

```text
Goal:
Reach Lahore
```

Current position:

```text
Islamabad
```

The agent evaluates possible routes.

```text
Islamabad
    ↓
Possible routes
    ↓
Search / planning
    ↓
Route
    ↓
Lahore
```

### Problem it solves

When there are multiple possible actions and we need to determine **which sequence gets us toward a goal**.

This is where you'll later encounter:

- search
- planning
- state spaces
- BFS
- DFS
- A*
- heuristics

---

# 4. Utility-Based Agent

Goal-based agents ask:

> **Can I reach the goal?**

Utility-based agents ask:

> **Which outcome is better?**

This is a huge upgrade.

Suppose your goal is:

```text
Reach university
```

You have:

```text
Route A → 20 min, expensive
Route B → 30 min, cheap
Route C → 25 min, comfortable
```

All three achieve the goal.

But which one is **better**?

That's where utility comes in.

```text
Goal
 ↓
Possible outcomes
 ↓
Utility evaluation
 ↓
Best expected outcome
```

### Problem it solves

Situations where:

- multiple outcomes satisfy the goal
- outcomes have different quality
- uncertainty exists
- trade-offs exist

### Example

Autonomous car:

```text
Option A:
Fast but dangerous

Option B:
Safe but slow

Option C:
Safe + moderately fast
```

A utility function can balance:

```text
Safety
+
Time
+
Comfort
+
Cost
```

---

# 5. Learning Agent ⭐

Finally:

> **The agent learns from experience.**

Instead of humans having to specify everything beforehand:

```text
Human → rules → agent
```

the agent can improve:

```text
Experience
    ↓
Learning
    ↓
Improved behavior
    ↓
More experience
    ↓
Better learning
```

AIMA treats learning agents as the fifth major agent architecture. [AIMA](https://aima.cs.berkeley.edu/contents.htm?utm_source=chatgpt.com)

A classic architecture contains:

```text
             ┌─────────────────┐
             │ Learning Element│
             └────────┬────────┘
                      ↓
Environment → Agent → Action
      ↑                ↓
      └──── Feedback ──┘
```

### Problem it solves

We can't manually program every possible situation.

The world changes.

The agent may encounter situations its programmer never anticipated.

### Example

Recommendation system:

```text
User watches videos
       ↓
System observes behavior
       ↓
Learns preferences
       ↓
Better recommendations
       ↓
More user behavior
       ↓
More learning
```

---

# The Five Agents — The Progression

This is **the mental model I want you to keep**:

```text
Simple Reflex
      ↓
"If X, do Y"

Model-Based
      ↓
"I remember what I've seen."

Goal-Based
      ↓
"What gets me to my goal?"

Utility-Based
      ↓
"Which possible outcome is best?"

Learning Agent
      ↓
"I can improve from experience."
```

Or even shorter:

```text
React
 ↓
Remember
 ↓
Plan
 ↓
Compare
 ↓
Learn
```

That's a beautiful way to remember the progression.

---

# One Example Across All Five

Let's use a **robot delivery agent**.

### Simple Reflex

```text
IF obstacle
THEN turn
```

### Model-Based

```text
IF obstacle
THEN turn

AND remember:
"Obstacle exists here."
```

### Goal-Based

```text
Goal = deliver package

Find route
from warehouse → customer
```

### Utility-Based

```text
Goal = delivery

Compare:
Route A → fast but expensive
Route B → slow but cheap
Route C → balanced

Choose highest utility.
```

### Learning

```text
Try routes
 ↓
Observe results
 ↓
Learn traffic patterns
 ↓
Improve future decisions
```

Now you can see why each architecture exists.

---

# The Big Picture of This Chapter

Everything we've discussed fits together:

```text
                     AI
                      │
          ┌───────────┴───────────┐
          │                       │
     What is AI?             How do we build it?
          │                       │
    ┌─────┴─────┐             AGENTS
    │           │                │
 Human       Rational            │
 approaches                    PEAS
                                │
                          Environment
                                │
                         Agent Architecture
                                │
              ┌─────────┬───────┼─────────┬──────────┐
              ↓         ↓       ↓         ↓          ↓
           Reflex    Model    Goal     Utility    Learning
```

And historically:

```text
Symbolic AI
    ↓
GPS / Logic / Rules
    ↓
Expert Systems
    ↓
AI Winters
    ↓
Statistical ML
    ↓
Neural Networks
    ↓
Deep Learning
    ↓
Transformers / Modern Generative AI
```

The important thing is **not** that modern AI completely replaced symbolic AI.

A lot of modern systems combine ideas:

```text
Neural models
     +
Search
     +
Planning
     +
Knowledge
     +
Tools
     +
Reasoning
     ↓
Modern intelligent systems
```

That's also why learning these "old" concepts is absolutely worthwhile.

---

# 🎯 What I Want You to Be Able to Answer After This

If your professor suddenly asks:

### "What is AI?"

You should be able to say:

> AI is the field of building systems capable of performing tasks involving intelligent behavior, with different approaches defining intelligence as thinking humanly, thinking rationally, acting humanly, or acting rationally.

### "What is a rational agent?"

> An agent that chooses actions expected to maximize its performance measure given its percept history and available information.

### "What is PEAS?"

> A framework for specifying an agent's task environment: Performance, Environment, Actuators, and Sensors.

### "Difference between simple reflex and model-based?"

> A simple reflex agent acts only from the current percept, while a model-based reflex agent maintains internal state to account for aspects of the world that aren't directly observable.

### "Goal vs utility?"

> A goal tells the agent which states are acceptable; utility lets the agent compare desirable states and choose the better one.

### "Why did symbolic AI struggle?"

> Because real-world problems involve huge search spaces, uncertainty, incomplete information, and knowledge that's difficult to encode manually.

### "Why is PSSH important?"

> It captures the central idea behind classical symbolic AI: intelligent behavior can be produced through physical systems that manipulate symbolic representations according to formal rules.

---

## One final mental model

If you remember **only one thing** from today's lesson, remember this:

```text
                 INTELLIGENCE
                      │
        ┌─────────────┴─────────────┐
        │                           │
     HUMAN                        RATIONAL
        │                           │
   ┌────┴────┐                 ┌────┴────┐
   │         │                 │         │
 THINK     ACT              THINK       ACT
   │         │                 │         │
Cognitive  Turing           Logic     Rational
modeling    Test                      agents
                                      │
                                      ↓
                                ENVIRONMENT
                                      ↕
                                   AGENT
                                      │
                        ┌─────────────┼─────────────┐
                        ↓             ↓             ↓
                     Sensors      Reasoning      Actions
                                      │
                         ┌────────────┼────────────┐
                         ↓            ↓            ↓
                      Goals       Utility       Learning
```

And **that** is why Chapter 1–2 comes first: before learning search, logic, knowledge representation, planning, ML, or reinforcement learning, you need to understand **what an intelligent system is supposed to do**.

### Sources worth keeping

- [AIMA — Chapter 1 & 2 contents](https://aima.cs.berkeley.edu/contents.htm?utm_source=chatgpt.com) — your primary textbook structure.
- [AIMA Chapter 2 — Intelligent Agents](https://aima.cs.berkeley.edu/4th-ed/pdfs/newchap02.pdf?utm_source=chatgpt.com) — particularly useful for PEAS, rationality, and agent architecture.
- [Turing's “Computing Machinery and Intelligence” — Oxford Academic](https://academic.oup.com/mind/article/LIX/236/433/986238?login=false&utm_source=chatgpt.com) — primary source for the imitation game.
- [Stanford AI100 — Short History of AI](https://ai100.stanford.edu/2016-report/appendix-i-short-history-ai?utm_source=chatgpt.com) — excellent historical overview.
- [AIMA Python](https://github.com/aimacode/aima-python?utm_source=chatgpt.com) — practical implementation companion.
- [SWI-Prolog](https://www.swi-prolog.org/Documentation.html?utm_source=chatgpt.com) — for symbolic/logic programming.
- [Gymnasium](https://gymnasium.farama.org/index.html?utm_source=chatgpt.com) — for hands-on agent/environment experimentation.

**Next, the natural move is Chapter 2 practice:** I'll take **PEAS + environment classification + agent architecture** and give you scenarios where *you* have to identify them, then we'll check your reasoning rather than just memorizing answers.
