# 🧪 DSA Practice Question Bank
### 4 Types × All Topics — With Full Answers

> **Legend:**
> - 🔵 Dry Run — Trace through operations, give final state
> - 🟠 Complete the Code — Fill in the missing core logic
> - 🔴 LeetCode Style — Write the full solution
> - 🟢 Function on Input → Output — Apply and answer

---

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 📦 SECTION 1: QUEUES
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

---

## 🔵 QUEUE DRY RUNS

---

### Q1 — Shifted Queue Dry Run

**MAX SIZE = 5**
Perform the following operations on a **Shifted Queue** and show the array state after EACH step.

```
Operations:
1. enqueue(10)
2. enqueue(20)
3. enqueue(30)
4. dequeue()
5. enqueue(40)
6. enqueue(50)
7. dequeue()
8. dequeue()
```

<details>
<summary>✅ ANSWER</summary>

```
Initial:  [__][__][__][__][__]   front=-1, rear=-1

1. enqueue(10): [10][__][__][__][__]   front=0, rear=0
2. enqueue(20): [10][20][__][__][__]   front=0, rear=1
3. enqueue(30): [10][20][30][__][__]   front=0, rear=2
4. dequeue():   Remove 10, then SHIFT LEFT
                [20][30][__][__][__]   front=0, rear=1
5. enqueue(40): [20][30][40][__][__]   front=0, rear=2
6. enqueue(50): [20][30][40][50][__]   front=0, rear=3
7. dequeue():   Remove 20, SHIFT LEFT
                [30][40][50][__][__]   front=0, rear=2
8. dequeue():   Remove 30, SHIFT LEFT
                [40][50][__][__][__]   front=0, rear=1

Final State: [40][50][__][__][__]   front=0, rear=1
```
</details>

---

### Q2 — Circular Queue Dry Run

**MAX SIZE = 4**
Trace the following operations and show **front, rear, count** after each step.

```
Operations:
1. enqueue(5)
2. enqueue(10)
3. enqueue(15)
4. enqueue(20)
5. dequeue()
6. dequeue()
7. enqueue(25)
8. enqueue(30)
9. enqueue(35)    ← what happens here?
```

<details>
<summary>✅ ANSWER</summary>

```
Array indices: [0] [1] [2] [3]    MAX=4

Initial:  front=0, rear=-1, count=0

1. enqueue(5):  rear=(−1+1)%4=0  → arr[0]=5   front=0,rear=0,count=1
   [5 ][__][__][__]

2. enqueue(10): rear=(0+1)%4=1   → arr[1]=10  front=0,rear=1,count=2
   [5 ][10][__][__]

3. enqueue(15): rear=(1+1)%4=2   → arr[2]=15  front=0,rear=2,count=3
   [5 ][10][15][__]

4. enqueue(20): rear=(2+1)%4=3   → arr[3]=20  front=0,rear=3,count=4
   [5 ][10][15][20]   ← FULL

5. dequeue():   remove arr[0]=5, front=(0+1)%4=1, count=3
   [__][10][15][20]   front=1,rear=3

6. dequeue():   remove arr[1]=10, front=(1+1)%4=2, count=2
   [__][__][15][20]   front=2,rear=3

7. enqueue(25): rear=(3+1)%4=0   → arr[0]=25  front=2,rear=0,count=3
   [25][__][15][20]   ← WRAPPED AROUND!

8. enqueue(30): rear=(0+1)%4=1   → arr[1]=30  front=2,rear=1,count=4
   [25][30][15][20]   ← FULL

9. enqueue(35): count==MAX → "Queue is FULL!" — REJECTED
```

**Key insight:** After step 7, rear (=0) < front (=2). That's the wrap-around! The queue is still valid.
</details>

---

### Q3 — Deque Dry Run

**MAX SIZE = 5**
Trace each operation, showing the logical contents (front → rear):

```
Operations:
1. addRear(10)
2. addRear(20)
3. addFront(5)
4. addFront(1)
5. removeRear()
6. removeFront()
7. addRear(99)
8. removeFront()
```

<details>
<summary>✅ ANSWER</summary>

```
1. addRear(10):   [10]             → content: 10
2. addRear(20):   [10][20]         → content: 10 20
3. addFront(5):   [5][10][20]      → content: 5 10 20
4. addFront(1):   [1][5][10][20]   → content: 1 5 10 20
5. removeRear():  remove 20        → content: 1 5 10
6. removeFront(): remove 1         → content: 5 10
7. addRear(99):   [5][10][99]      → content: 5 10 99
8. removeFront(): remove 5         → content: 10 99

Final: [10][99]  (front=10, rear=99)
```
</details>

---

### Q4 — Priority Queue Dry Run (Min-Heap)

Insert the following into a **Min-Heap Priority Queue** one by one. Draw the heap array after **each insertion**, showing how bubble-up works.

```
Insert order: 30, 10, 20, 5, 15
```

<details>
<summary>✅ ANSWER</summary>

```
Heap array (0-indexed), parent of i = (i-1)/2

Insert 30:
  arr = [30]
  i=0, no parent → done
  Heap: [30]

Insert 10:
  arr = [30, 10]
  i=1, parent=(1-1)/2=0 → arr[0]=30 > arr[1]=10 → SWAP
  arr = [10, 30]
  i=0 → done
  Heap: [10, 30]

Insert 20:
  arr = [10, 30, 20]
  i=2, parent=(2-1)/2=0 → arr[0]=10 < arr[2]=20 → NO SWAP
  Heap: [10, 30, 20]

Insert 5:
  arr = [10, 30, 20, 5]
  i=3, parent=(3-1)/2=1 → arr[1]=30 > arr[3]=5 → SWAP
  arr = [10, 5, 20, 30]
  i=1, parent=(1-1)/2=0 → arr[0]=10 > arr[1]=5 → SWAP
  arr = [5, 10, 20, 30]
  i=0 → done
  Heap: [5, 10, 20, 30]

Insert 15:
  arr = [5, 10, 20, 30, 15]
  i=4, parent=(4-1)/2=1 → arr[1]=10 < arr[4]=15 → NO SWAP
  Heap: [5, 10, 20, 30, 15]

Final heap array: [5, 10, 20, 30, 15]
Minimum (highest priority): 5
```
</details>

---

## 🟠 QUEUE — COMPLETE THE CODE

---

### Q5 — Complete the Circular Queue `isFull()` and `dequeue()`

```cpp
class CircularQueue {
    int arr[MAX];
    int front, rear, count;
public:
    CircularQueue() { front = 0; rear = -1; count = 0; }

    bool isFull() {
        // ❓ YOUR CODE HERE
    }

    bool isEmpty() { return count == 0; }

    void enqueue(int val) {
        if (isFull()) { cout << "Full!\n"; return; }
        rear = (rear + 1) % MAX;
        arr[rear] = val;
        count++;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Empty!\n"; return; }
        // ❓ YOUR CODE HERE (print removed val, advance front, decrement count)
    }
};
```

<details>
<summary>✅ ANSWER</summary>

```cpp
bool isFull() {
    return count == MAX;
}

void dequeue() {
    if (isEmpty()) { cout << "Empty!\n"; return; }
    cout << arr[front] << " dequeued.\n";
    front = (front + 1) % MAX;
    count--;
}
```

**Why `count == MAX` for isFull?**
Because after wrapping around, front and rear could be adjacent again, so checking indices alone is ambiguous. The count variable is the cleanest solution.
</details>

---

### Q6 — Complete the Priority Queue `removeMin()` bubble-down

```cpp
void removeMin() {
    if (isEmpty()) return;
    cout << "Removed: " << arr[0] << "\n";
    arr[0] = arr[--size];  // move last element to root

    int i = 0;
    while (true) {
        int left    = 2 * i + 1;
        int right   = 2 * i + 2;
        int smallest = i;

        // ❓ YOUR CODE HERE:
        // Check if left child exists and is smaller than current smallest
        // Check if right child exists and is smaller than current smallest
        // If smallest changed, swap and continue. Else break.
    }
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
        if (left < size && arr[left] < arr[smallest])
            smallest = left;
        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest == i) break;   // already in the right place

        swap(arr[i], arr[smallest]);
        i = smallest;               // move down
```
</details>

---

## 🟢 QUEUE — FUNCTION ON INPUT → OUTPUT

---

### Q7 — What is the output?

```cpp
CircularQueue cq;  // MAX = 4
cq.enqueue(100);
cq.enqueue(200);
cq.dequeue();
cq.enqueue(300);
cq.enqueue(400);
cq.enqueue(500);
cq.dequeue();
cq.display();
```

<details>
<summary>✅ ANSWER</summary>

```
Step by step:
enqueue(100): [100, ___, ___, ___]  front=0, rear=0, count=1
enqueue(200): [100, 200, ___, ___]  front=0, rear=1, count=2
dequeue():    remove 100 → [___, 200, ___, ___]  front=1, rear=1, count=1
enqueue(300): [___, 200, 300, ___]  front=1, rear=2, count=2
enqueue(400): [___, 200, 300, 400]  front=1, rear=3, count=3
enqueue(500): rear wraps → [500, 200, 300, 400]  front=1, rear=0, count=4
dequeue():    remove arr[1]=200 → front=2, count=3

display() shows: 300 400 500
Output: Circular Queue: [300] [400] [500]
```
</details>

---

### Q8 — Priority Queue Output

```cpp
PriorityQueue pq;
pq.insert(50);
pq.insert(30);
pq.insert(40);
pq.insert(10);
pq.insert(20);

cout << pq.peekMin() << "\n";
pq.removeMin();
cout << pq.peekMin() << "\n";
pq.removeMin();
cout << pq.peekMin() << "\n";
```

<details>
<summary>✅ ANSWER</summary>

```
After inserting all: Min-heap = [10, 20, 40, 50, 30]

peekMin() → 10
removeMin() → removes 10, heap becomes [20, 30, 40, 50]
peekMin() → 20
removeMin() → removes 20, heap becomes [30, 50, 40]
peekMin() → 30

OUTPUT:
10
20
30
```
</details>

---

## 🔴 QUEUE — LEETCODE STYLE

---

### Q9 — Implement Stack using Two Queues

**Problem:** Implement a Stack (LIFO) using **only queues**. Implement: `push(x)`, `pop()`, `top()`, `empty()`.

**Constraint:** You may only use standard queue operations (enqueue, dequeue, front, size, empty).

```
Example:
push(1), push(2), push(3)
top()  → 3
pop()  → 3
top()  → 2
empty() → false
```

<details>
<summary>✅ ANSWER</summary>

```cpp
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;

public:
    // Push: add to q2, then move everything from q1 to q2,
    // then swap so newest element is always at front of q1
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);  // q1 now has newest at front
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "top: "   << st.top()   << "\n";  // 3
    cout << "pop: "   << st.pop()   << "\n";  // 3
    cout << "top: "   << st.top()   << "\n";  // 2
    cout << "empty: " << st.empty() << "\n";  // 0 (false)
    return 0;
}
```

**Trace of push(1), push(2), push(3):**
```
push(1): q1=[1]
push(2): q2=[2], move q1→q2: q2=[2,1], swap → q1=[2,1]
push(3): q2=[3], move q1→q2: q2=[3,2,1], swap → q1=[3,2,1]
top → q1.front() = 3 ✓
```
</details>

---

### Q10 — Sliding Window Maximum (Deque application)

**Problem:** Given an array of integers and a window size `k`, find the **maximum** in each sliding window.

```
Input:  arr = [1, 3, -1, -3, 5, 3, 6, 7],  k = 3
Output: [3, 3, 5, 5, 6, 7]

Explanation:
Window [1,3,-1] → max=3
Window [3,-1,-3] → max=3
Window [-1,-3,5] → max=5
...
```

<details>
<summary>✅ ANSWER</summary>

```cpp
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMax(vector<int>& arr, int k) {
    deque<int> dq;   // stores INDICES, front = index of max element
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        // Remove indices outside the window
        while (!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();

        // Remove smaller elements from back (they'll never be max)
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        // Window is fully formed
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = slidingWindowMax(arr, k);
    cout << "Maximums: ";
    for (int x : res) cout << x << " ";
    cout << "\n";  // Output: 3 3 5 5 6 7
    return 0;
}
```
</details>

---

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 🔗 SECTION 2: LINKED LISTS
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

---

## 🔵 LINKED LIST DRY RUNS

---

### Q11 — Singly Linked List Operations Trace

Start with an **empty** Singly Linked List. Trace each operation and draw the list:

```
1. insertTail(10)
2. insertTail(20)
3. insertTail(30)
4. insertHead(5)
5. deleteHead()
6. deleteTail()
7. insertTail(40)
8. deleteByValue(20)
9. deleteAtPosition(1)
10. reverse()
```

<details>
<summary>✅ ANSWER</summary>

```
1. insertTail(10): [10] → NULL
2. insertTail(20): [10] → [20] → NULL
3. insertTail(30): [10] → [20] → [30] → NULL
4. insertHead(5):  [5] → [10] → [20] → [30] → NULL
5. deleteHead():   [10] → [20] → [30] → NULL   (5 removed)
6. deleteTail():   [10] → [20] → NULL           (30 removed)
7. insertTail(40): [10] → [20] → [40] → NULL
8. deleteByValue(20): [10] → [40] → NULL        (20 removed)
9. deleteAtPosition(1): position 0=10, 1=40
   Remove node at index 1 (value=40): [10] → NULL
10. reverse(): [10] → NULL   (only one node, no change)

Final list: [10] → NULL
```

**Trace of reverse() on a longer example — [10] → [20] → [30]:**
```
Start: prev=NULL, curr=[10], next=?

Step 1: next=[20], curr→prev=NULL, prev=[10], curr=[20]
   NULL ← [10]  [20] → [30]

Step 2: next=[30], curr→prev=[10], prev=[20], curr=[30]
   NULL ← [10] ← [20]  [30] → NULL

Step 3: next=NULL, curr→prev=[20], prev=[30], curr=NULL
   NULL ← [10] ← [20] ← [30]

head = [30]
Result: [30] → [20] → [10] → NULL ✓
```
</details>

---

### Q12 — Doubly Linked List Reverse Dry Run

Given this doubly linked list:
```
NULL ⇄ [1] ⇄ [2] ⇄ [3] ⇄ [4] ⇄ NULL
```

Trace the **reverse()** function step by step. Show prev/next pointers at each node after the swap.

```cpp
void reverse() {
    DNode* curr = head;
    DNode* temp = nullptr;
    while (curr) {
        swap(curr->prev, curr->next);
        temp = curr->prev;
        curr = temp;
    }
    swap(head, tail);
}
```

<details>
<summary>✅ ANSWER</summary>

```
Original: NULL←[1]⇄[2]⇄[3]⇄[4]→NULL

curr = [1]:
  swap([1].prev=NULL, [1].next=[2]) → [1].prev=[2], [1].next=NULL
  temp = [1].prev = [2]
  curr = [2]

curr = [2]:
  swap([2].prev=[1], [2].next=[3]) → [2].prev=[3], [2].next=[1]
  temp = [2].prev = [3]
  curr = [3]

curr = [3]:
  swap([3].prev=[2], [3].next=[4]) → [3].prev=[4], [3].next=[2]
  temp = [3].prev = [4]
  curr = [4]

curr = [4]:
  swap([4].prev=[3], [4].next=NULL) → [4].prev=NULL, [4].next=[3]
  temp = [4].prev = NULL
  curr = NULL → LOOP ENDS

swap(head, tail): head=[4], tail=[1]

Result: NULL←[4]⇄[3]⇄[2]⇄[1]→NULL ✓
```
</details>

---

### Q13 — deleteAtPosition Trace (Singly)

List: `[10] → [20] → [30] → [40] → [50] → NULL`

Trace `deleteAtPosition(3)` step by step through this code:

```cpp
void deleteAtPosition(int pos) {
    if (pos == 0) { deleteHead(); return; }
    Node* curr = head;
    for (int i = 0; i < pos - 1 && curr->next; i++)
        curr = curr->next;
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}
```

<details>
<summary>✅ ANSWER</summary>

```
List:  [10] → [20] → [30] → [40] → [50] → NULL
index:   0       1      2      3      4

pos = 3, not 0 so no deleteHead.

curr starts at head = [10] (i=0)
Loop: i < pos-1 = 2

i=0: curr = curr->next = [20]
i=1: curr = curr->next = [30]
i=2: stop (i is not < 2)

curr = [30]
temp = curr->next = [40]
curr->next = temp->next = [50]
delete temp ([40])

Result: [10] → [20] → [30] → [50] → NULL
Node with value 40 deleted ✓
```
</details>

---

## 🟠 LINKED LIST — COMPLETE THE CODE

---

### Q14 — Complete insertTail for Singly Linked List

```cpp
void insertTail(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        // ❓ YOUR CODE HERE (what if list is empty?)
        return;
    }
    Node* curr = head;
    // ❓ YOUR CODE HERE (traverse to last node)
    curr->next = newNode;
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
void insertTail(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;   // if empty, new node IS the head
        return;
    }
    Node* curr = head;
    while (curr->next)    // stop when curr is the LAST node
        curr = curr->next;
    curr->next = newNode;
}
```
</details>

---

### Q15 — Complete the Linked List Reverse

```cpp
void reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr) {
        // ❓ Step 1: Save next node
        // ❓ Step 2: Reverse the pointer (curr->next = prev)
        // ❓ Step 3: Move prev to curr
        // ❓ Step 4: Move curr to saved next
    }
    // ❓ Update head
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
void reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr) {
        next       = curr->next;  // Step 1: Save next
        curr->next = prev;        // Step 2: Flip pointer
        prev       = curr;        // Step 3: Advance prev
        curr       = next;        // Step 4: Advance curr
    }
    head = prev;  // prev is now the new head (last node we visited)
}
```
</details>

---

### Q16 — Complete deleteByValue for Doubly Linked List

```cpp
void deleteByValue(int val) {
    DNode* curr = head;
    while (curr && curr->data != val)
        curr = curr->next;

    if (!curr) { cout << "Not found!\n"; return; }
    if (curr == head) { deleteHead(); return; }
    if (curr == tail) { deleteTail(); return; }

    // ❓ YOUR CODE HERE
    // The node is in the MIDDLE — fix both prev and next pointers
    // Then delete curr
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
    // curr is a middle node
    curr->prev->next = curr->next;   // node before curr skips over curr
    curr->next->prev = curr->prev;   // node after curr points back to curr's prev
    cout << curr->data << " deleted.\n";
    delete curr;
```

**Diagram:**
```
Before: ... → [A] ⇄ [curr] ⇄ [B] → ...
After:  ... → [A]    ⇄      [B] → ...
  A.next = B
  B.prev = A
  delete curr
```
</details>

---

## 🟢 LINKED LIST — FUNCTION ON INPUT → OUTPUT

---

### Q17 — What does this function return?

```cpp
int mystery(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* curr = head;
    while (curr) {
        if (curr->data % 2 == 0) count++;
        curr = curr->next;
    }
    return count;
}
```

**Input list:** `[3] → [6] → [9] → [12] → [15] → [18] → NULL`

<details>
<summary>✅ ANSWER</summary>

```
Visits: 3 (odd), 6 (even✓), 9 (odd), 12 (even✓), 15 (odd), 18 (even✓)
count = 3

Return value: 3
The function counts EVEN numbers in the list.
```
</details>

---

### Q18 — Trace this recursive function

```cpp
void printReverse(Node* curr) {
    if (!curr) return;
    printReverse(curr->next);
    cout << curr->data << " ";
}
```

**Input list:** `[1] → [2] → [3] → [4] → [5] → NULL`

<details>
<summary>✅ ANSWER</summary>

```
Call stack (going in):
printReverse([1]) → calls printReverse([2])
printReverse([2]) → calls printReverse([3])
printReverse([3]) → calls printReverse([4])
printReverse([4]) → calls printReverse([5])
printReverse([5]) → calls printReverse(NULL)
printReverse(NULL) → returns

Now unwinding (printing on the way OUT):
[5] prints 5
[4] prints 4
[3] prints 3
[2] prints 2
[1] prints 1

OUTPUT: 5 4 3 2 1
```

This is printing the list in reverse using the **call stack** — no reversal needed!
</details>

---

## 🔴 LINKED LIST — LEETCODE STYLE

---

### Q19 — Detect a Cycle in Linked List (Floyd's Algorithm)

**Problem:** Given a linked list, determine if it has a cycle (a node whose `next` points back to a previous node).

```
Input: 1 → 2 → 3 → 4 → 5 → (points back to 2)
Output: true (cycle exists)

Input: 1 → 2 → 3 → NULL
Output: false
```

<details>
<summary>✅ ANSWER</summary>

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Floyd's Tortoise & Hare Algorithm
// Slow pointer moves 1 step, fast pointer moves 2 steps
// If they meet → cycle exists!
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;         // move 1 step
        fast = fast->next->next;   // move 2 steps
        if (slow == fast) return true;  // they met → cycle!
    }
    return false;  // fast reached NULL → no cycle
}

int main() {
    // Build: 1 → 2 → 3 → 4 → 5 → (back to 2)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next; // cycle!

    cout << (hasCycle(head) ? "Cycle detected!" : "No cycle") << "\n";

    // Build: 1 → 2 → 3 → NULL
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    cout << (hasCycle(head2) ? "Cycle detected!" : "No cycle") << "\n";

    return 0;
}
```

**Output:**
```
Cycle detected!
No cycle
```

**Why it works:** If there's a cycle, the fast pointer laps the slow one inside the cycle. If no cycle, fast hits NULL first.
</details>

---

### Q20 — Find Middle of Linked List

**Problem:** Find the **middle node** of a linked list. If two middles exist, return the **second** one.

```
Input: 1 → 2 → 3 → 4 → 5     Output: node with value 3
Input: 1 → 2 → 3 → 4          Output: node with value 3
```

<details>
<summary>✅ ANSWER</summary>

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data; Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// Same tortoise & hare trick!
// When fast reaches end, slow is at middle.
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    // 1 → 2 → 3 → 4 → 5
    Node* h = new Node(1);
    h->next = new Node(2);
    h->next->next = new Node(3);
    h->next->next->next = new Node(4);
    h->next->next->next->next = new Node(5);
    cout << "Middle: " << findMiddle(h)->data << "\n"; // 3

    // 1 → 2 → 3 → 4
    Node* h2 = new Node(1);
    h2->next = new Node(2);
    h2->next->next = new Node(3);
    h2->next->next->next = new Node(4);
    cout << "Middle: " << findMiddle(h2)->data << "\n"; // 3
    return 0;
}
```
</details>

---

### Q21 — Merge Two Sorted Linked Lists

**Problem:** Given two **sorted** linked lists, merge them into one sorted list.

```
List1: 1 → 3 → 5
List2: 2 → 4 → 6
Output: 1 → 2 → 3 → 4 → 5 → 6
```

<details>
<summary>✅ ANSWER</summary>

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data; Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

Node* mergeSorted(Node* l1, Node* l2) {
    // Base cases
    if (!l1) return l2;
    if (!l2) return l1;

    // Pick smaller head, recurse for the rest
    if (l1->data <= l2->data) {
        l1->next = mergeSorted(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSorted(l1, l2->next);
        return l2;
    }
}

void print(Node* h) {
    while (h) { cout << h->data << " → "; h = h->next; }
    cout << "NULL\n";
}

int main() {
    Node* l1 = new Node(1); l1->next = new Node(3); l1->next->next = new Node(5);
    Node* l2 = new Node(2); l2->next = new Node(4); l2->next->next = new Node(6);
    Node* merged = mergeSorted(l1, l2);
    print(merged); // 1 → 2 → 3 → 4 → 5 → 6 → NULL
    return 0;
}
```
</details>

---

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 🌳 SECTION 3: BINARY TREES
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

---

## 🔵 BINARY TREE DRY RUNS

---

### Q22 — All Traversals on a Given Tree

For this tree:
```
            [1]
           /   \
         [2]   [3]
         / \   / \
       [4] [5][6] [7]
       /
     [8]
```

Write the output of:
- Pre-order (Root → Left → Right)
- In-order (Left → Root → Right)
- Post-order (Left → Right → Root)
- Level-order (BFS)

<details>
<summary>✅ ANSWER</summary>

```
Pre-order  (Root→L→R): 1  2  4  8  5  3  6  7
In-order   (L→Root→R): 8  4  2  5  1  6  3  7
Post-order (L→R→Root): 8  4  5  2  6  7  3  1
Level-order (BFS):     1  2  3  4  5  6  7  8

BFS trace using queue:
Queue: [1]
  Dequeue 1, enqueue 2,3    → output: 1
Queue: [2,3]
  Dequeue 2, enqueue 4,5    → output: 1 2
Queue: [3,4,5]
  Dequeue 3, enqueue 6,7    → output: 1 2 3
Queue: [4,5,6,7]
  Dequeue 4, enqueue 8      → output: 1 2 3 4
Queue: [5,6,7,8]
  Dequeue 5, no children    → output: 1 2 3 4 5
Queue: [6,7,8]
  Dequeue 6, no children    → output: 1 2 3 4 5 6
Queue: [7,8]
  Dequeue 7, no children    → output: 1 2 3 4 5 6 7
Queue: [8]
  Dequeue 8, no children    → output: 1 2 3 4 5 6 7 8
```
</details>

---

### Q23 — Build Expression Tree from Postfix (Dry Run)

**Postfix expression:** `4 2 - 3 1 + *`

Trace the **stack** step by step and draw the final expression tree.

<details>
<summary>✅ ANSWER</summary>

```
Token by token:

Token=4: create node [4], push → Stack: [[4]]

Token=2: create node [2], push → Stack: [[4],[2]]

Token=-: OPERATOR
  pop right = [2]
  pop left  = [4]
  create [-], left=[4], right=[2]
  push [-]  → Stack: [[-]]
       [-]
      /   \
    [4]  [2]

Token=3: create node [3], push → Stack: [[-],[3]]

Token=1: create node [1], push → Stack: [[-],[3],[1]]

Token=+: OPERATOR
  pop right = [1]
  pop left  = [3]
  create [+], left=[3], right=[1]
  push [+]  → Stack: [[-],[+]]
       [+]
      /   \
    [3]  [1]

Token=*: OPERATOR
  pop right = [+]
  pop left  = [-]
  create [*], left=[-], right=[+]
  push [*]  → Stack: [[*]]

FINAL TREE:
         [*]
        /   \
      [-]   [+]
      / \   / \
    [4][2] [3][1]

Infix: (4-2) * (3+1)
Value: 2 * 4 = 8 ✓
```
</details>

---

### Q24 — Identify Tree Properties

For this tree:
```
         [10]
        /    \
      [5]    [20]
      /        \
    [3]        [25]
```

Answer:
1. Is it a **BST**? (Left < Root < Right at every node)
2. What is the **height**?
3. What is the **in-order traversal**?
4. Is it a **complete** binary tree?
5. Is it a **full** binary tree?

<details>
<summary>✅ ANSWER</summary>

```
1. Is it a BST?
   Node 10: left=5 ✓, right=20 ✓
   Node 5: left=3 ✓, right=none ✓
   Node 20: left=none ✓, right=25 ✓
   → YES, it is a BST ✓

2. Height (longest root-to-leaf path):
   10 → 5 → 3   (length = 2)
   10 → 20 → 25 (length = 2)
   Height = 2 (counting edges) OR 3 (counting nodes) — clarify with professor

3. In-order (L→Root→R): 3  5  10  20  25
   (For BST, in-order always gives SORTED output ✓)

4. Complete binary tree? NO
   A complete tree fills all levels left to right.
   Level 1: [10]         → 1 node ✓
   Level 2: [5], [20]    → 2 nodes ✓
   Level 3: [3], [25]    → [3] is leftmost, but [25] is rightmost skipping middle → NOT complete

5. Full binary tree? NO
   A full tree means every node has 0 or 2 children.
   Node 5 has only 1 child (3) → NOT full.
```
</details>

---

## 🟠 BINARY TREE — COMPLETE THE CODE

---

### Q25 — Complete the Post-order Traversal

```cpp
void postorder(Node* root) {
    if (!root) return;
    // ❓ YOUR CODE HERE
    // Hint: Left, then Right, then Root (print)
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);    // 1. Recurse Left
    postorder(root->right);   // 2. Recurse Right
    cout << root->data << " "; // 3. Print Root LAST
}
```
</details>

---

### Q26 — Complete BFS (Level-order) using Queue

```cpp
void levelorder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        // ❓ Step 1: Get the front node from the queue
        // ❓ Step 2: Print its data
        // ❓ Step 3: If it has a left child, enqueue it
        // ❓ Step 4: If it has a right child, enqueue it
    }
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
void levelorder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();    // Step 1 & 2
        cout << curr->data << " ";          // Step 2: print
        if (curr->left)  q.push(curr->left);  // Step 3
        if (curr->right) q.push(curr->right); // Step 4
    }
}
```
</details>

---

### Q27 — Complete buildFromPostfix (Expression Tree)

```cpp
TreeNode* buildFromPostfix(const string& postfix) {
    stack<TreeNode*> st;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        TreeNode* node = new TreeNode(token);
        if (isOperator(token)) {
            // ❓ YOUR CODE HERE
            // Pop right first, then left
            // Set them as children of node
        }
        // ❓ Push node onto stack
    }
    return st.top();
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
if (isOperator(token)) {
    node->right = st.top(); st.pop();  // right child first (IMPORTANT ORDER!)
    node->left  = st.top(); st.pop();  // then left child
}
st.push(node);   // always push, whether operand or operator
```

**Why right first?** Because the stack gives you the last-pushed operand first, and in postfix `A B op`, B was pushed after A, so B is on top → B goes RIGHT, A goes LEFT.
</details>

---

## 🟢 BINARY TREE — FUNCTION ON INPUT → OUTPUT

---

### Q28 — Evaluate Expression Tree

Evaluate this expression tree using the `evaluate()` function:

```
         [+]
        /   \
      [*]   [-]
      / \   / \
    [3][4] [9][2]
```

<details>
<summary>✅ ANSWER</summary>

```
Post-order evaluation (leaves first):

Left subtree [*]:
  evaluate([3]) = 3
  evaluate([4]) = 4
  3 * 4 = 12

Right subtree [-]:
  evaluate([9]) = 9
  evaluate([2]) = 2
  9 - 2 = 7

Root [+]:
  12 + 7 = 19

ANSWER: 19
Expression: (3*4) + (9-2) = 12 + 7 = 19 ✓
```
</details>

---

### Q29 — What does this function compute?

```cpp
int mystery(Node* root) {
    if (!root) return 0;
    return 1 + max(mystery(root->left), mystery(root->right));
}
```

Apply it to:
```
       [A]
      /   \
    [B]   [C]
    /       \
  [D]       [E]
```

<details>
<summary>✅ ANSWER</summary>

```
mystery(NULL) = 0

mystery([D]) = 1 + max(0, 0) = 1
mystery([E]) = 1 + max(0, 0) = 1
mystery([B]) = 1 + max(mystery([D]), 0) = 1 + max(1,0) = 2
mystery([C]) = 1 + max(0, mystery([E])) = 1 + max(0,1) = 2
mystery([A]) = 1 + max(mystery([B]), mystery([C])) = 1 + max(2,2) = 3

ANSWER: 3
The function computes the HEIGHT of the tree (number of nodes on longest path).
```
</details>

---

## 🔴 BINARY TREE — LEETCODE STYLE

---

### Q30 — Maximum Depth of Binary Tree

**Problem:** Find the maximum depth (height) of a binary tree.

```
Input:
      3
     / \
    9  20
       / \
      15   7

Output: 3
```

<details>
<summary>✅ ANSWER</summary>

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data; Node* left; Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

int maxDepth(Node* root) {
    if (!root) return 0;
    int leftDepth  = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    cout << "Max Depth: " << maxDepth(root) << "\n"; // 3
    return 0;
}
```
</details>

---

### Q31 — Check if Binary Tree is a BST

**Problem:** Given a binary tree, determine if it is a valid Binary Search Tree.

```
Valid BST:        Invalid BST:
    5                 5
   / \               / \
  3   7             3   7
 / \               / \
2   4             2   6    ← 6 > 5 but is in left subtree → INVALID
```

<details>
<summary>✅ ANSWER</summary>

```cpp
#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data; Node* left; Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// Key insight: each node must be within a valid (min, max) range
bool isValidBST(Node* root, long min_val = LLONG_MIN, long max_val = LLONG_MAX) {
    if (!root) return true;  // empty tree is valid

    if (root->data <= min_val || root->data >= max_val)
        return false;  // node violates the BST range

    // Left children must be < root->data (max_val = root->data)
    // Right children must be > root->data (min_val = root->data)
    return isValidBST(root->left,  min_val, root->data) &&
           isValidBST(root->right, root->data, max_val);
}

int main() {
    // Valid BST: 5, 3, 7, 2, 4
    Node* root = new Node(5);
    root->left = new Node(3); root->right = new Node(7);
    root->left->left = new Node(2); root->left->right = new Node(4);
    cout << (isValidBST(root) ? "Valid BST" : "Invalid BST") << "\n";  // Valid

    // Invalid: 5 with left child 3 having right child 6
    Node* bad = new Node(5);
    bad->left = new Node(3); bad->right = new Node(7);
    bad->left->right = new Node(6);  // 6 > 5, wrong side!
    cout << (isValidBST(bad) ? "Valid BST" : "Invalid BST") << "\n";  // Invalid

    return 0;
}
```
</details>

---

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 🌲 SECTION 4: AVL TREES
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

---

## 🔵 AVL TREE DRY RUNS

---

### Q32 — Insert Sequence and Identify Rotations

Insert the following into an empty AVL tree **one by one**. After each insertion that causes an imbalance, **identify the rotation** needed and show the tree before and after.

**Sequence:** `10, 20, 30`

<details>
<summary>✅ ANSWER</summary>

```
Insert 10:
    [10]
    h=1, BF=0   ✓ Balanced

Insert 20:
    [10]
      \
      [20]
    BF(10) = 0-1 = -1   ✓ Still balanced

Insert 30:
    [10]
      \
      [20]
        \
        [30]
    BF(10) = 0-2 = -2   ✗ IMBALANCED!

This is RR Case (inserted right of right child)
Apply LEFT ROTATION at node 10:

Before:              After:
  [10]                [20]
    \                /    \
    [20]    →      [10]  [30]
      \
      [30]

BF(10)=0, BF(30)=0, BF(20)=0   ✓ All balanced!
```
</details>

---

### Q33 — Insert Sequence: `30, 20, 10`

<details>
<summary>✅ ANSWER</summary>

```
Insert 30:
    [30]   BF=0  ✓

Insert 20:
    [30]
    /
  [20]
  BF(30) = 1-0 = 1   ✓ OK

Insert 10:
    [30]
    /
  [20]
  /
[10]
BF(30) = 2-0 = 2   ✗ IMBALANCED!

LL Case (inserted left of left child)
Apply RIGHT ROTATION at node 30:

Before:          After:
    [30]           [20]
    /             /    \
  [20]    →     [10]  [30]
  /
[10]

BF(10)=0, BF(30)=0, BF(20)=0   ✓ Balanced!
```
</details>

---

### Q34 — Insert Sequence: `30, 10, 20` (LR Case)

<details>
<summary>✅ ANSWER</summary>

```
Insert 30:
    [30]  BF=0  ✓

Insert 10:
    [30]
    /
  [10]
  BF(30)=1  ✓

Insert 20:
    [30]
    /
  [10]
    \
    [20]
  BF(30)=2-0=2  ✗ IMBALANCED!
  BF(10)=0-1=-1

LR Case: left child (10) is right-heavy
Step 1: Left rotate at [10]
    [30]
    /
  [20]
  /
[10]

Step 2: Right rotate at [30]
       [20]
      /    \
    [10]  [30]

BF all = 0  ✓ Balanced!
```
</details>

---

### Q35 — Insert Sequence: `10, 30, 20` (RL Case)

<details>
<summary>✅ ANSWER</summary>

```
Insert 10:   [10]  BF=0  ✓

Insert 30:
    [10]
      \
      [30]
    BF(10)=-1  ✓

Insert 20:
    [10]
      \
      [30]
      /
    [20]
  BF(10) = 0-2 = -2  ✗ IMBALANCED!
  BF(30) = 1-0 = 1

RL Case: right child (30) is left-heavy
Step 1: Right rotate at [30]
    [10]
      \
      [20]
        \
        [30]

Step 2: Left rotate at [10]
       [20]
      /    \
    [10]  [30]

BF all = 0  ✓ Balanced!
```
</details>

---

### Q36 — Insert Sequence: `50, 25, 75, 10, 30` — Full Trace

<details>
<summary>✅ ANSWER</summary>

```
Insert 50:
    [50] h=1, BF=0  ✓

Insert 25:
    [50]
    /
  [25]
  BF(50)=1  ✓

Insert 75:
    [50]
   /    \
 [25]  [75]
  BF(50)=0  ✓  (perfectly balanced)

Insert 10:
      [50]
     /    \
   [25]  [75]
   /
 [10]
  BF(50)=2-1=1  ✓ (still ok, just heavy)
  BF(25)=1  ✓

Insert 30:
      [50]
     /    \
   [25]  [75]
   /  \
 [10] [30]
  BF(50)=2-1=1  ✓
  BF(25)=1-1=0  ✓
  All balanced!

Final tree:
      [50]
     /    \
   [25]  [75]
   /  \
 [10] [30]

Heights: 10→1, 30→1, 25→2, 75→1, 50→3
Balance factors: 10=0, 30=0, 25=0, 75=0, 50=1
All BF ∈ {-1,0,1} → Valid AVL ✓
```
</details>

---

### Q37 — Is this a Valid AVL Tree? (Check all BFs)

```
           [15]
          /    \
        [9]   [20]
        / \     \
      [5] [12] [25]
      /
    [2]
```

<details>
<summary>✅ ANSWER</summary>

```
Calculate height of each node (bottom-up):
  [2]:  h=1
  [5]:  h=2 (left=[2] h=1, right=none h=0) → 1+max(1,0)=2
  [12]: h=1
  [9]:  h=3 (left=[5] h=2, right=[12] h=1) → 1+max(2,1)=3
  [25]: h=1
  [20]: h=2 (left=none h=0, right=[25] h=1) → 1+max(0,1)=2
  [15]: h=4 (left=[9] h=3, right=[20] h=2) → 1+max(3,2)=4

Balance Factors (left_height - right_height):
  [2]:  0-0 = 0  ✓
  [5]:  1-0 = 1  ✓
  [12]: 0-0 = 0  ✓
  [9]:  2-1 = 1  ✓
  [25]: 0-0 = 0  ✓
  [20]: 0-1 = -1 ✓
  [15]: 3-2 = 1  ✓

All balance factors ∈ {-1, 0, 1}

→ YES, this is a valid AVL Tree ✓
```
</details>

---

## 🟠 AVL TREE — COMPLETE THE CODE

---

### Q38 — Complete getBalance and updateHeight

```cpp
int height(AVLNode* n) {
    return n ? n->height : 0;
}

int getBalance(AVLNode* n) {
    // ❓ YOUR CODE HERE
    // Return height(left) - height(right), or 0 if n is null
}

void updateHeight(AVLNode* n) {
    // ❓ YOUR CODE HERE
    // height = 1 + max of left and right heights
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
int getBalance(AVLNode* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

void updateHeight(AVLNode* n) {
    if (n)
        n->height = 1 + max(height(n->left), height(n->right));
}
```
</details>

---

### Q39 — Complete the Right Rotation

```cpp
AVLNode* rotateRight(AVLNode* z) {
    AVLNode* y  = z->left;
    AVLNode* T3 = y->right;

    // ❓ YOUR CODE HERE:
    // Make z the right child of y
    // Move T3 to be z's left child
    // Update heights (z first, then y)
    // Return the new root (y)
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
AVLNode* rotateRight(AVLNode* z) {
    AVLNode* y  = z->left;
    AVLNode* T3 = y->right;

    y->right = z;    // z becomes right child of y
    z->left  = T3;   // T3 becomes left child of z

    updateHeight(z); // update z first (it's now lower)
    updateHeight(y); // then update y (new root)

    return y;        // y is the new root of this subtree
}
```

**Memory trick for rotations:**
```
Right Rotation (LL fix):
  y->right = z   (pull y up, push z down-right)
  z->left  = T3  (T3 was y's right, now z's left)

Left Rotation (RR fix) — mirror image:
  y->left  = z   (pull y up, push z down-left)
  z->right = T2  (T2 was y's left, now z's right)
```
</details>

---

## 🟢 AVL — FUNCTION ON INPUT → OUTPUT

---

### Q40 — What rotation is needed?

For each imbalanced configuration below, name the rotation case (LL/RR/LR/RL) and the node where rotation is applied:

```
Case A:          Case B:          Case C:         Case D:
    z                z               z               z
   /                  \             /                 \
  y                    y           y                   y
 /                      \           \                 /
x                        x           x               x
```

<details>
<summary>✅ ANSWER</summary>

```
Case A: z's left child (y) is left-heavy → LL Case
  Fix: Right Rotation at z

Case B: z's right child (y) is right-heavy → RR Case
  Fix: Left Rotation at z

Case C: z's left child (y) is right-heavy → LR Case
  Fix: Left Rotation at y, THEN Right Rotation at z

Case D: z's right child (y) is left-heavy → RL Case
  Fix: Right Rotation at y, THEN Left Rotation at z

Memory trick:
  LL → single Right
  RR → single Left
  LR → Left then Right (zigzag left-right)
  RL → Right then Left (zigzag right-left)
```
</details>

---

## 🔴 AVL — LEETCODE STYLE

---

### Q41 — Count nodes in AVL/BST within a range

**Problem:** Given a BST, count how many nodes have values between `low` and `high` (inclusive).

```
Tree:
       10
      /  \
     5    15
    / \     \
   3   7    18

low=6, high=15
Output: 3   (nodes: 7, 10, 15)
```

<details>
<summary>✅ ANSWER</summary>

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data; Node* left; Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

int countInRange(Node* root, int low, int high) {
    if (!root) return 0;

    int count = 0;
    if (root->data >= low && root->data <= high)
        count = 1;  // this node is in range

    // BST property: skip entire subtrees when possible
    if (root->data > low)   // left subtree may have valid nodes
        count += countInRange(root->left, low, high);
    if (root->data < high)  // right subtree may have valid nodes
        count += countInRange(root->right, low, high);

    return count;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    cout << "Count in [6,15]: " << countInRange(root, 6, 15) << "\n"; // 3
    cout << "Count in [3,9]:  " << countInRange(root, 3, 9)  << "\n"; // 3 (3,5,7)
    return 0;
}
```
</details>

---

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 🕸️ SECTION 5: GRAPHS (Easy)
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

---

## 🔵 GRAPH DRY RUNS

---

### Q42 — BFS Trace on Undirected Graph

Given this **undirected** graph (adjacency list):
```
0 → [1, 2]
1 → [0, 3, 4]
2 → [0, 5]
3 → [1]
4 → [1]
5 → [2]
```

Trace **BFS starting from vertex 0**. Show the **queue** and **visited** array after each step.

<details>
<summary>✅ ANSWER</summary>

```
visited = [F, F, F, F, F, F]
Queue: [0]
visited[0] = T

Step 1: Dequeue 0, output: 0
  Neighbors of 0: 1, 2
  Enqueue 1, 2. visited[1]=T, visited[2]=T
  Queue: [1, 2]
  Output so far: 0

Step 2: Dequeue 1, output: 1
  Neighbors of 1: 0(visited), 3, 4
  Enqueue 3, 4. visited[3]=T, visited[4]=T
  Queue: [2, 3, 4]
  Output so far: 0 1

Step 3: Dequeue 2, output: 2
  Neighbors of 2: 0(visited), 5
  Enqueue 5. visited[5]=T
  Queue: [3, 4, 5]
  Output so far: 0 1 2

Step 4: Dequeue 3, output: 3
  Neighbors of 3: 1(visited) → nothing to enqueue
  Queue: [4, 5]
  Output so far: 0 1 2 3

Step 5: Dequeue 4, output: 4
  Neighbors of 4: 1(visited) → nothing
  Queue: [5]
  Output so far: 0 1 2 3 4

Step 6: Dequeue 5, output: 5
  Neighbors of 5: 2(visited) → nothing
  Queue: []

FINAL BFS ORDER: 0 1 2 3 4 5
```
</details>

---

### Q43 — DFS Trace on Directed Graph

Given this **directed** graph:
```
0 → [1, 2]
1 → [3]
2 → [3, 4]
3 → [5]
4 → []
5 → []
```

Trace **recursive DFS starting from vertex 0**. Show call stack and output order.

<details>
<summary>✅ ANSWER</summary>

```
DFS(0): visit 0, output: 0
  → Call DFS(1):
      visit 1, output: 0 1
      → Call DFS(3):
          visit 3, output: 0 1 3
          → Call DFS(5):
              visit 5, output: 0 1 3 5
              neighbors of 5: none → RETURN
          RETURN from DFS(3)
      RETURN from DFS(1)
  → Call DFS(2):
      visit 2, output: 0 1 3 5 2
      → Call DFS(3): already visited → skip
      → Call DFS(4):
          visit 4, output: 0 1 3 5 2 4
          neighbors of 4: none → RETURN
      RETURN from DFS(2)

FINAL DFS ORDER: 0 1 3 5 2 4

Call Stack Visualization:
DFS(0)
  DFS(1)
    DFS(3)
      DFS(5) ← deepest, returns first
    ← back to DFS(3), done
  ← back to DFS(1), done
  DFS(2)
    DFS(3) skipped (visited)
    DFS(4) ← returns
  ← back to DFS(2), done
← back to DFS(0), done
```
</details>

---

## 🟠 GRAPH — COMPLETE THE CODE

---

### Q44 — Complete addEdge for Adjacency Matrix (Undirected)

```cpp
void addEdge(int u, int v) {
    // ❓ YOUR CODE HERE
    // For undirected graph, set BOTH directions
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
void addEdge(int u, int v) {
    matrix[u][v] = 1;  // edge from u to v
    matrix[v][u] = 1;  // edge from v to u (undirected = both ways)
}

// For DIRECTED graph, only:
// matrix[u][v] = 1;
```
</details>

---

### Q45 — Complete DFS for Disconnected Graph

```cpp
void DFSHelper(int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor])
            DFSHelper(neighbor, visited);
    }
}

void DFSAll() {
    vector<bool> visited(V, false);
    // ❓ YOUR CODE HERE
    // Visit every component — loop through all vertices,
    // start a new DFS for each unvisited vertex
}
```

<details>
<summary>✅ ANSWER</summary>

```cpp
void DFSAll() {
    vector<bool> visited(V, false);
    cout << "DFS (all components):\n";
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {               // found an unvisited node
            cout << "  Component: ";
            DFSHelper(i, visited);       // explore entire component
            cout << "\n";
        }
    }
}
```

**Why this works:** Even if the graph is disconnected, we iterate over every vertex. When we find one that hasn't been visited, it must belong to a new component. We then DFS the entire component from it.
</details>

---

## 🟢 GRAPH — FUNCTION ON INPUT → OUTPUT

---

### Q46 — Build this graph and run BFS — what is the output?

```
Build the following undirected graph using adjacency list:
  0—1, 0—2, 1—2, 2—3

Then call BFS(0).
```

<details>
<summary>✅ ANSWER</summary>

```
Adjacency list after edges:
0 → [1, 2]
1 → [0, 2]
2 → [0, 1, 3]
3 → [2]

BFS from 0:
Queue: [0], visited[0]=T
Dequeue 0 → print 0, enqueue 1,2 → Queue: [1,2]
Dequeue 1 → print 1, enqueue 2(already visited) → Queue: [2]
Dequeue 2 → print 2, enqueue 3 → Queue: [3]
Dequeue 3 → print 3, no new neighbors → Queue: []

OUTPUT: 0 1 2 3
```
</details>

---

## 🔴 GRAPH — LEETCODE STYLE

---

### Q47 — Number of Connected Components

**Problem:** Given `n` nodes and a list of edges (undirected), return the **number of connected components**.

```
Input: n=5, edges=[[0,1],[1,2],[3,4]]
Output: 2
(Component 1: {0,1,2}, Component 2: {3,4})
```

<details>
<summary>✅ ANSWER</summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;
        for (int neighbor : adj[node])
            if (!visited[neighbor])
                dfs(neighbor, visited, adj);
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj);
                components++;  // each DFS call covers one component
            }
        }
        return components;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    cout << sol.countComponents(5, edges) << "\n"; // 2

    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{3,4}};
    cout << sol.countComponents(5, edges2) << "\n"; // 1 (all connected)
    return 0;
}
```
</details>

---

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 📋 MIXED CHALLENGE QUESTIONS
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

---

### Q48 — Spot the Bug 🐛

What is wrong with this `deleteByValue` for Singly Linked List?

```cpp
void deleteByValue(int val) {
    Node* curr = head;
    while (curr && curr->data != val)
        curr = curr->next;
    if (!curr) return;
    Node* temp = curr->next;
    curr->data = temp->data;    // copy next node's data here
    curr->next = temp->next;    // skip next node
    delete temp;
}
```

<details>
<summary>✅ ANSWER</summary>

```
BUG: This only works if the node to delete is NOT the TAIL node.

If val is in the LAST node:
  curr = last node
  temp = curr->next = nullptr
  curr->data = temp->data  →  CRASH! Dereferencing nullptr!

Also — this technique works by overwriting the current node with
the next node's data, then deleting the next node. But if curr IS
the tail, there IS no next node.

FIX: Check for tail case separately, or use the standard
"track the previous pointer" approach.

CORRECT APPROACH:
void deleteByValue(int val) {
    if (!head) return;
    if (head->data == val) { deleteHead(); return; }
    Node* curr = head;
    while (curr->next && curr->next->data != val)
        curr = curr->next;
    if (!curr->next) return;  // not found
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}
```
</details>

---

### Q49 — Mixed Trace: Queue + Linked List

```cpp
SinglyLinkedList myList;
ShiftedQueue q;

myList.insertTail(5);
myList.insertTail(10);
myList.insertTail(15);
myList.insertHead(1);

// Enqueue all list values into the queue
Node* curr = myList.head;
while (curr) {
    q.enqueue(curr->data);
    curr = curr->next;
}

myList.reverse();
q.dequeue();
q.dequeue();

// What does myList and q contain now?
```

<details>
<summary>✅ ANSWER</summary>

```
After list operations:
  insertTail(5):  [5] → NULL
  insertTail(10): [5] → [10] → NULL
  insertTail(15): [5] → [10] → [15] → NULL
  insertHead(1):  [1] → [5] → [10] → [15] → NULL

Enqueue all into q (in order 1, 5, 10, 15):
  Queue: [1][5][10][15]   front=0, rear=3

myList.reverse():
  List becomes: [15] → [10] → [5] → [1] → NULL

q.dequeue() → removes 1, shifts: [5][10][15][ ]   rear=2
q.dequeue() → removes 5, shifts: [10][15][ ][ ]   rear=1

FINAL STATE:
  myList: [15] → [10] → [5] → [1] → NULL
  Queue:  [10][15]  (front=0, rear=1)
```
</details>

---

### Q50 — Postfix Expression to Result (Without Building Tree)

**Convert** this postfix and **evaluate** it manually:

`8 4 2 - / 3 *`

Show the **stack** at each step.

<details>
<summary>✅ ANSWER</summary>

```
Token=8:  push 8       → Stack: [8]
Token=4:  push 4       → Stack: [8, 4]
Token=2:  push 2       → Stack: [8, 4, 2]
Token=-:  pop 2, pop 4, compute 4-2=2, push 2
                        → Stack: [8, 2]
Token=/:  pop 2, pop 8, compute 8/2=4, push 4
                        → Stack: [4]
Token=3:  push 3       → Stack: [4, 3]
Token=*:  pop 3, pop 4, compute 4*3=12, push 12
                        → Stack: [12]

RESULT: 12

Expression in infix: (8 / (4 - 2)) * 3 = (8/2) * 3 = 4 * 3 = 12 ✓
```
</details>

---

# 📊 ANSWER QUICK REFERENCE

| Q# | Topic | Type | Key Concept |
|----|-------|------|-------------|
| 1 | Shifted Queue | 🔵 Dry Run | Shift left on dequeue |
| 2 | Circular Queue | 🔵 Dry Run | Modulo wrap, front/rear tracking |
| 3 | Deque | 🔵 Dry Run | Front/rear removal |
| 4 | Priority Queue | 🔵 Dry Run | Bubble-up on insert |
| 5 | Circular Queue | 🟠 Code | isFull uses count |
| 6 | Priority Queue | 🟠 Code | Bubble-down logic |
| 7 | Circular Queue | 🟢 Output | Wrap-around trace |
| 8 | Priority Queue | 🟢 Output | Min-heap peek/remove |
| 9 | Stack using Queue | 🔴 LC | Two-queue trick |
| 10 | Sliding Window Max | 🔴 LC | Monotone deque |
| 11 | Singly LL | 🔵 Dry Run | All 7 operations |
| 12 | Doubly LL | 🔵 Dry Run | Swap prev/next to reverse |
| 13 | Singly LL | 🔵 Dry Run | deleteAtPosition pointer trace |
| 14 | Singly LL | 🟠 Code | insertTail traversal |
| 15 | Singly LL | 🟠 Code | 3-pointer reverse |
| 16 | Doubly LL | 🟠 Code | Middle node deletion |
| 17 | Singly LL | 🟢 Output | Count evens |
| 18 | Singly LL | 🟢 Output | Recursive reverse print |
| 19 | Cycle Detection | 🔴 LC | Floyd's tortoise & hare |
| 20 | Middle Node | 🔴 LC | Fast/slow pointers |
| 21 | Merge Sorted | 🔴 LC | Recursive merge |
| 22 | All Traversals | 🔵 Dry Run | Pre/In/Post/BFS |
| 23 | Postfix Tree | 🔵 Dry Run | Stack-based build |
| 24 | Tree Properties | 🟢 Output | BST, height, complete, full |
| 25 | Post-order | 🟠 Code | L→R→Root pattern |
| 26 | BFS (Level-order) | 🟠 Code | Queue enqueue left/right |
| 27 | Build from Postfix | 🟠 Code | Right-first pop |
| 28 | Evaluate Tree | 🟢 Output | Bottom-up evaluation |
| 29 | Height function | 🟢 Output | Recursive max depth |
| 30 | Max Depth | 🔴 LC | 1 + max(left, right) |
| 31 | Valid BST | 🔴 LC | Min/max range check |
| 32 | AVL Insert 10,20,30 | 🔵 Dry Run | RR → Left Rotation |
| 33 | AVL Insert 30,20,10 | 🔵 Dry Run | LL → Right Rotation |
| 34 | AVL Insert 30,10,20 | 🔵 Dry Run | LR → Double Rotation |
| 35 | AVL Insert 10,30,20 | 🔵 Dry Run | RL → Double Rotation |
| 36 | AVL Insert 5 values | 🔵 Dry Run | Full insertion trace |
| 37 | Valid AVL check | 🟢 Output | Compute all BFs |
| 38 | getBalance, updateHeight | 🟠 Code | Height difference |
| 39 | Right Rotation | 🟠 Code | y→right=z, z→left=T3 |
| 40 | Identify Rotations | 🟢 Output | LL/RR/LR/RL patterns |
| 41 | BST Range Count | 🔴 LC | Prune subtrees |
| 42 | Graph BFS | 🔵 Dry Run | Queue + visited |
| 43 | Graph DFS | 🔵 Dry Run | Call stack trace |
| 44 | addEdge Matrix | 🟠 Code | Both directions |
| 45 | DFS Disconnected | 🟠 Code | Loop all vertices |
| 46 | Build + BFS | 🟢 Output | Standard BFS output |
| 47 | Connected Components | 🔴 LC | DFS count components |
| 48 | Spot the Bug | 🔵 Dry Run | Null tail crash |
| 49 | Queue + LL Mixed | 🟢 Output | Combined trace |
| 50 | Postfix Evaluate | 🔵 Dry Run | Operand stack |

---

*Total: 50 questions across 4 types and all 5 topics.*
*Practice tip: Do the dry runs with pen and paper first, THEN verify with code.*
