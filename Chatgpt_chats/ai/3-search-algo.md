
The syllabus specifically expects you to practice tracing these search algorithms by hand, and AIMA/MIT cover these same families of search methods. [AIMA](https://aima.cs.berkeley.edu/global-figures.pdf?utm_source=chatgpt.com)

We'll use **one tiny graph** for most algorithms:

```text
        A
       / \
      B   C
     / \   \
    D   E   F
         \ /
          G
```

Goal: `G`

---

# 1. Breadth-First Search — BFS

### Idea

BFS explores **level by level**.

```text
A
↓
B C
↓
D E F
↓
G
```

It uses a **queue**: first in → first out.

### Simplest Python

```python
from collections import deque

graph = {
    "A": ["B", "C"],
    "B": ["D", "E"],
    "C": ["F"],
    "D": [],
    "E": ["G"],
    "F": ["G"],
    "G": []
}

def bfs(start, goal):
    queue = deque([start])
    visited = set()

    while queue:
        node = queue.popleft()

        if node in visited:
            continue

        visited.add(node)
        print("Visiting:", node)

        if node == goal:
            return True

        for neighbor in graph[node]:
            queue.append(neighbor)

    return False


bfs("A", "G")
```

### Output

```text
Visiting: A
Visiting: B
Visiting: C
Visiting: D
Visiting: E
Visiting: F
Visiting: G
```

### Remember

> **BFS = Queue = level by level**

---

# 2. Uniform-Cost Search — UCS

BFS cares about **number of steps**.

UCS cares about **total cost**.

Example:

```text
A --1--> B --10--> G
 \
  4
   \
    C --2--> G
```

B → G has 10 cost, while A → C → G costs only 6.

UCS should choose the **cheapest total path**.

AIMA describes UCS as expanding the node with the lowest path cost. [AIMA](https://aima.cs.berkeley.edu/4th-ed/pdfs/newchap03.pdf?utm_source=chatgpt.com)

### Python

```python
import heapq

graph = {
    "A": [("B", 1), ("C", 4)],
    "B": [("G", 10)],
    "C": [("G", 2)],
    "G": []
}

def ucs(start, goal):
    queue = [(0, start)]
    visited = set()

    while queue:
        cost, node = heapq.heappop(queue)

        if node in visited:
            continue

        visited.add(node)

        print("Visiting:", node, "Cost:", cost)

        if node == goal:
            return cost

        for neighbor, edge_cost in graph[node]:
            heapq.heappush(
                queue,
                (cost + edge_cost, neighbor)
            )


print("Answer:", ucs("A", "G"))
```

### Output

```text
Visiting: A Cost: 0
Visiting: B Cost: 1
Visiting: C Cost: 4
Visiting: G Cost: 6

Answer: 6
```

### Remember

> **UCS = cheapest path so far**

---

# 3. Depth-First Search — DFS

DFS goes **as deep as possible** before coming back.

It uses a **stack**.

```text
A
↓
B
↓
D
↓
back
E
↓
G
```

### Python

```python
def dfs(node, goal, visited=None):

    if visited is None:
        visited = set()

    if node in visited:
        return False

    visited.add(node)

    print("Visiting:", node)

    if node == goal:
        return True

    for neighbor in graph[node]:
        if dfs(neighbor, goal, visited):
            return True

    return False


dfs("A", "G")
```

### Remember

> **DFS = Stack/recursion = go deep first**

DFS generally isn't complete or optimal, unlike BFS under its applicable conditions. [AIMA](https://aima.cs.berkeley.edu/global-figures.pdf?utm_source=chatgpt.com)

---

# 4. Depth-Limited Search — DLS

DLS is basically:

> **DFS + maximum depth**

For example:

```text
A       depth 0
|
B       depth 1
|
D       depth 2
```

If limit = `2`, don't go deeper.

### Python

```python
def dls(node, goal, limit):

    print("Visiting:", node, "Depth:", limit)

    if node == goal:
        return True

    if limit == 0:
        return False

    for neighbor in graph[node]:
        if dls(neighbor, goal, limit - 1):
            return True

    return False


dls("A", "G", 2)
```

### Remember

> **DLS = DFS with a depth limit**

---

# 5. Iterative Deepening DFS — IDDFS

This one combines the ideas of BFS and DFS.

It repeatedly runs DLS:

```text
Limit = 0
Limit = 1
Limit = 2
Limit = 3
...
```

### Python

```python
def dls(node, goal, limit):

    if node == goal:
        return True

    if limit == 0:
        return False

    for neighbor in graph[node]:
        if dls(neighbor, goal, limit - 1):
            return True

    return False


def iddfs(start, goal):

    depth = 0

    while True:
        print("Searching depth:", depth)

        if dls(start, goal, depth):
            return True

        depth += 1


iddfs("A", "G")
```

### Remember

> **IDDFS = DFS repeatedly with increasing depth limit**

AIMA lists IDDFS as complete under the usual finite-branching conditions and cost-optimal for equal step costs. [AIMA](https://aima.cs.berkeley.edu/global-figures.pdf?utm_source=chatgpt.com)

---

# 7. Greedy Best-First Search

Now we start using **heuristics**.

Suppose:

```text
A → B → G
```

`h(n)` means:

> "How far do I THINK this node is from the goal?"

Greedy says:

> "I'll visit the node that looks closest to the goal."

So:

```text
f(n) = h(n)
```

### Python

```python
import heapq

graph = {
    "A": ["B", "C"],
    "B": ["G"],
    "C": ["G"],
    "G": []
}

heuristic = {
    "A": 5,
    "B": 2,
    "C": 4,
    "G": 0
}

def greedy(start, goal):

    queue = [(heuristic[start], start)]
    visited = set()

    while queue:

        h, node = heapq.heappop(queue)

        if node in visited:
            continue

        visited.add(node)

        print("Visiting:", node, "h =", h)

        if node == goal:
            return True

        for neighbor in graph[node]:
            heapq.heappush(
                queue,
                (heuristic[neighbor], neighbor)
            )


greedy("A", "G")
```

### Remember

> **Greedy = "Which node looks closest?"**

---

# 8. A* Search ⭐

This is one of the **most important algorithms in your syllabus**.

A* combines:

```text
g(n) = actual cost so far

h(n) = estimated cost remaining
```

and:

```text
f(n) = g(n) + h(n)
```

### Python

```python
import heapq

graph = {
    "A": [("B", 2), ("C", 5)],
    "B": [("G", 5)],
    "C": [("G", 1)],
    "G": []
}

heuristic = {
    "A": 5,
    "B": 4,
    "C": 1,
    "G": 0
}

def astar(start, goal):

    queue = [(heuristic[start], 0, start)]
    visited = set()

    while queue:

        f, g, node = heapq.heappop(queue)

        if node in visited:
            continue

        visited.add(node)

        print(
            "Node:", node,
            "g =", g,
            "h =", heuristic[node],
            "f =", f
        )

        if node == goal:
            return g

        for neighbor, cost in graph[node]:

            new_g = g + cost
            new_f = new_g + heuristic[neighbor]

            heapq.heappush(
                queue,
                (new_f, new_g, neighbor)
            )


print("Cost:", astar("A", "G"))
```

### Remember

> **A* = actual cost + estimated cost**

```text
             A*
              |
        ┌─────┴─────┐
        ↓           ↓
     g(n)          h(n)
   actual       estimated
    cost           cost
```

MIT's search material specifically covers A* as an extension of optimal search using admissible heuristics. [MIT OpenCourseWare](https://ocw.mit.edu/courses/6-034-artificial-intelligence-fall-2010/resources/lecture-5-search-optimal-branch-and-bound-a/?utm_source=chatgpt.com)

---

# Your Practice Map

Here's how I'd practice these for your exam:

| Algorithm | Simplest practice |
|---|---|
| **BFS** | Find `G` in a small graph |
| **UCS** | Find cheapest path with different edge costs |
| **DFS** | Find `G` using recursion |
| **DLS** | DFS with depth limit = 2 |
| **IDDFS** | Find `G` by trying depth 0,1,2,3 |
| **Bidirectional** | Search A → G from both sides |
| **Greedy** | Find goal using only `h(n)` |
| **A\*** ⭐ | Find cheapest path using `g+h` | 

### The big picture

Don't memorize 14 completely unrelated algorithms. Think of them as a few families:

```text
SEARCH
│
├── Uninformed
│   ├── BFS
│   ├── UCS
│   ├── DFS
│   ├── DLS
│   ├── IDDFS
│   └── Bidirectional
│
├── Informed
    ├── Greedy
    └── A*
```

MIT's course organizes its search material similarly: depth-first/hill-climbing/beam, optimal search/A*, then games/minimax/alpha-beta. [MIT OpenCourseWare](https://ocw.mit.edu/courses/6-034-artificial-intelligence-fall-2010/pages/readings/?utm_source=chatgpt.com)

**For actual learning, I'd go one by one rather than trying to memorize this whole page.** Start with **BFS**, run the code, then manually trace the queue. After that, DFS → UCS → A* is a very good progression.