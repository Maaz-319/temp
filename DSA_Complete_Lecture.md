# 📚 Complete DSA Lecture — From Zero to Hero (AI Generated DOC)
### Taught Simply. Coded Clearly. Understood Deeply.

---

## 🧠 How to Read This Guide

Think of your computer's memory like a **city**. Every house has an address (memory address). Data structures are just **different ways to organize houses** so you can find, add, or remove things **fast**.

---

# 🟦 CHAPTER 1: QUEUES

## 🎯 What is a Queue?

Imagine a **line at a McDonald's counter**. The first person who stands in line gets served first. The last person waits. This is called **FIFO — First In, First Out**.

```
FRONT → [Ali] [Sara] [Ahmed] [Zara] ← REAR
  (served first)             (joined last)
```

Four types we'll cover:
| Type | Real-Life Analogy |
|------|-------------------|
| Shifted (Linear) | Normal queue at a bank |
| Circular | Circular conveyor belt at a sushi restaurant |
| Double-Ended (Deque) | A train where doors open on both ends |
| Priority | Hospital Emergency Room (sicker = served first) |

---

## 1.1 Shifted (Linear) Queue

**Problem with Linear Queue:** When you remove from front, all elements must **shift left**. Wasteful!

```
Before dequeue:  [10][20][30][40]
                  ^front
After dequeue:   [ ][20][30][40]  → Shift → [20][30][40][ ]
```

### ✅ C++ Code — Shifted Queue

```cpp
#include <iostream>
using namespace std;

#define MAX 5

class ShiftedQueue {
    int arr[MAX];
    int front, rear;

public:
    ShiftedQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Add to rear
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is FULL!\n";
            return;
        }
        if (front == -1) front = 0; // first element
        arr[++rear] = val;
        cout << val << " added to queue.\n";
    }

    // Remove from front (then shift everything left)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << arr[front] << " removed from queue.\n";

        // Shift all elements to the left
        for (int i = front; i < rear; i++) {
            arr[i] = arr[i + 1];
        }
        rear--;

        if (rear == -1) front = -1; // queue became empty
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Queue (front → rear): ";
        for (int i = front; i <= rear; i++)
            cout << "[" << arr[i] << "] ";
        cout << "\n";
    }
};

int main() {
    ShiftedQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
```

**Output:**
```
10 added to queue.
20 added to queue.
30 added to queue.
Queue (front → rear): [10] [20] [30]
10 removed from queue.
Queue (front → rear): [20] [30]
```

---

## 1.2 Circular Queue

**Fix for the wasted space problem!**

Imagine the array as a **circle**. When rear reaches the end, it wraps around to index 0 (if that space is free).

```
Indices:  0    1    2    3    4
        [20] [30] [__] [__] [10]
               ↑rear            ↑front

front=4, rear=1 → Still has room!
```

### ✅ C++ Code — Circular Queue

```cpp
#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull()  { return count == MAX; }
    bool isEmpty() { return count == 0; }

    void enqueue(int val) {
        if (isFull()) { cout << "Queue FULL!\n"; return; }
        rear = (rear + 1) % MAX;  // wrap around using modulo
        arr[rear] = val;
        count++;
        cout << val << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue EMPTY!\n"; return; }
        cout << arr[front] << " dequeued.\n";
        front = (front + 1) % MAX; // wrap around
        count--;
    }

    void display() {
        if (isEmpty()) { cout << "Empty!\n"; return; }
        cout << "Circular Queue: ";
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << "[" << arr[idx] << "] ";
            idx = (idx + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.display();
    cq.dequeue();
    cq.dequeue();
    cq.enqueue(6); // wraps around to use freed spots!
    cq.enqueue(7);
    cq.display();
    return 0;
}
```

**Key Magic:** `(rear + 1) % MAX` — This is what makes it circular!

---

## 1.3 Double-Ended Queue (Deque)

Like a **train with doors on BOTH ends**. You can add/remove from either end.

```
addFront(10) → [10]
addFront(5)  → [5][10]
addRear(20)  → [5][10][20]
removeFront  →    [10][20]
removeRear   →    [10]
```

### ✅ C++ Code — Deque (using circular array)

```cpp
#include <iostream>
using namespace std;

#define MAX 6

class Deque {
    int arr[MAX];
    int front, rear, count;

public:
    Deque() { front = 0; rear = -1; count = 0; }

    bool isFull()  { return count == MAX; }
    bool isEmpty() { return count == 0; }

    // Add to front
    void addFront(int val) {
        if (isFull()) { cout << "Full!\n"; return; }
        front = (front - 1 + MAX) % MAX; // move front backwards (wrap)
        arr[front] = val;
        count++;
        cout << val << " added at FRONT.\n";
    }

    // Add to rear
    void addRear(int val) {
        if (isFull()) { cout << "Full!\n"; return; }
        rear = (rear + 1) % MAX;
        arr[rear] = val;
        count++;
        cout << val << " added at REAR.\n";
    }

    // Remove from front
    void removeFront() {
        if (isEmpty()) { cout << "Empty!\n"; return; }
        cout << arr[front] << " removed from FRONT.\n";
        front = (front + 1) % MAX;
        count--;
    }

    // Remove from rear
    void removeRear() {
        if (isEmpty()) { cout << "Empty!\n"; return; }
        cout << arr[rear] << " removed from REAR.\n";
        rear = (rear - 1 + MAX) % MAX;
        count--;
    }

    void display() {
        if (isEmpty()) { cout << "Empty!\n"; return; }
        cout << "Deque: ";
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << "[" << arr[idx] << "] ";
            idx = (idx + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    Deque dq;
    dq.addRear(10);
    dq.addRear(20);
    dq.addFront(5);
    dq.addFront(1);
    dq.display();
    dq.removeFront();
    dq.removeRear();
    dq.display();
    return 0;
}
```

---

## 1.4 Priority Queue

**Hospital Emergency Room**: A child with a broken leg gets treated before someone with a cold — **higher priority = served first**, regardless of arrival time.

### ✅ C++ Code — Priority Queue (Min-Heap using array)

```cpp
#include <iostream>
using namespace std;

#define MAX 10

class PriorityQueue {
    int arr[MAX];
    int size;

public:
    PriorityQueue() { size = 0; }

    bool isEmpty() { return size == 0; }

    // Insert and bubble up (min-heap: smaller = higher priority)
    void insert(int val) {
        if (size == MAX) { cout << "Full!\n"; return; }
        arr[size] = val;
        int i = size;
        size++;
        // Bubble up: if child < parent, swap
        while (i > 0 && arr[i] < arr[(i - 1) / 2]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        cout << val << " inserted.\n";
    }

    // Remove highest priority (smallest value)
    void removeMin() {
        if (isEmpty()) { cout << "Empty!\n"; return; }
        cout << "Removed: " << arr[0] << "\n";
        arr[0] = arr[--size]; // replace root with last element
        // Bubble down
        int i = 0;
        while (true) {
            int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
            if (left < size && arr[left] < arr[smallest])  smallest = left;
            if (right < size && arr[right] < arr[smallest]) smallest = right;
            if (smallest == i) break;
            swap(arr[i], arr[smallest]);
            i = smallest;
        }
    }

    int peekMin() { return isEmpty() ? -1 : arr[0]; }

    void display() {
        cout << "Priority Queue (array form): ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(40);
    pq.insert(10);
    pq.insert(30);
    pq.insert(5);
    pq.insert(20);
    pq.display();
    cout << "Min (highest priority): " << pq.peekMin() << "\n";
    pq.removeMin();
    pq.removeMin();
    pq.display();
    return 0;
}
```

**Output:**
```
Priority Queue (array form): 5 10 30 40 20
Min (highest priority): 5
Removed: 5
Removed: 10
Priority Queue (array form): 20 40 30
```

---

# 🟩 CHAPTER 2: LINKED LISTS

## 🎯 What is a Linked List?

Imagine a **treasure hunt**: each clue tells you where the **next clue** is. Each clue = a **Node**. The chain of clues = a **Linked List**.

```
[10 | →] → [20 | →] → [30 | NULL]
 Node1        Node2       Node3
```

Each node has:
- **Data** — the value
- **Next** — the address (pointer) to the next node

**Why use it over arrays?**
- Arrays: Fixed size, insertion in middle is expensive (shift everything)
- Linked List: Dynamic size, insertion anywhere is O(1) if you have the pointer

---

## 2.1 Singly Linked List

One direction only (→). Like a one-way street.

### ✅ C++ Code — Full Singly Linked List

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // ── INSERT AT HEAD ──────────────────────────────
    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head; // new node points to old head
        head = newNode;       // head now points to new node
        cout << val << " inserted at HEAD.\n";
    }

    // ── INSERT AT TAIL ──────────────────────────────
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* curr = head;
        while (curr->next) curr = curr->next; // go to last node
        curr->next = newNode;
        cout << val << " inserted at TAIL.\n";
    }

    // ── DELETE HEAD ─────────────────────────────────
    void deleteHead() {
        if (!head) { cout << "List empty!\n"; return; }
        cout << head->data << " deleted from HEAD.\n";
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // ── DELETE TAIL ─────────────────────────────────
    void deleteTail() {
        if (!head) { cout << "List empty!\n"; return; }
        if (!head->next) { // only one node
            cout << head->data << " deleted from TAIL.\n";
            delete head; head = nullptr; return;
        }
        Node* curr = head;
        while (curr->next->next) curr = curr->next; // stop at second-to-last
        cout << curr->next->data << " deleted from TAIL.\n";
        delete curr->next;
        curr->next = nullptr;
    }

    // ── DELETE BY VALUE ─────────────────────────────
    void deleteByValue(int val) {
        if (!head) { cout << "List empty!\n"; return; }
        if (head->data == val) { deleteHead(); return; }
        Node* curr = head;
        while (curr->next && curr->next->data != val)
            curr = curr->next;
        if (!curr->next) { cout << val << " not found!\n"; return; }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        cout << val << " deleted.\n";
    }

    // ── DELETE BY POSITION (0-indexed) ──────────────
    void deleteAtPosition(int pos) {
        if (!head) { cout << "List empty!\n"; return; }
        if (pos == 0) { deleteHead(); return; }
        Node* curr = head;
        for (int i = 0; i < pos - 1 && curr->next; i++)
            curr = curr->next;
        if (!curr->next) { cout << "Position out of range!\n"; return; }
        Node* temp = curr->next;
        curr->next = temp->next;
        cout << temp->data << " deleted at position " << pos << ".\n";
        delete temp;
    }

    // ── REVERSE ─────────────────────────────────────
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next; // save next
            curr->next = prev; // reverse pointer
            prev = curr;       // move prev forward
            curr = next;       // move curr forward
        }
        head = prev;
        cout << "List reversed.\n";
    }

    // ── DISPLAY ─────────────────────────────────────
    void display() {
        if (!head) { cout << "List is empty.\n"; return; }
        Node* curr = head;
        cout << "List: ";
        while (curr) {
            cout << "[" << curr->data << "] → ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList sll;
    sll.insertHead(20);
    sll.insertHead(10);
    sll.insertTail(30);
    sll.insertTail(40);
    sll.display();

    sll.deleteHead();
    sll.display();

    sll.deleteTail();
    sll.display();

    sll.insertTail(50);
    sll.insertTail(60);
    sll.display();

    sll.deleteByValue(30);
    sll.display();

    sll.deleteAtPosition(1);
    sll.display();

    sll.reverse();
    sll.display();

    return 0;
}
```

**Output:**
```
20 inserted at HEAD.
10 inserted at HEAD.
30 inserted at TAIL.
40 inserted at TAIL.
List: [10] → [20] → [30] → [40] → NULL
10 deleted from HEAD.
List: [20] → [30] → [40] → NULL
40 deleted from TAIL.
List: [20] → [30] → NULL
50 inserted at TAIL.
60 inserted at TAIL.
List: [20] → [30] → [50] → [60] → NULL
30 deleted.
List: [20] → [50] → [60] → NULL
50 deleted at position 1.
List: [20] → [60] → NULL
List reversed.
List: [60] → [20] → NULL
```

---

## 2.2 Doubly Linked List

**Two-way street!** Each node has a pointer to **next** AND **previous**.

```
NULL ← [10] ⇆ [20] ⇆ [30] → NULL
```

### ✅ C++ Code — Doubly Linked List

```cpp
#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // ── INSERT AT HEAD ──────────────────────────────
    void insertHead(int val) {
        DNode* node = new DNode(val);
        if (!head) { head = tail = node; }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        cout << val << " inserted at HEAD.\n";
    }

    // ── INSERT AT TAIL ──────────────────────────────
    void insertTail(int val) {
        DNode* node = new DNode(val);
        if (!tail) { head = tail = node; }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        cout << val << " inserted at TAIL.\n";
    }

    // ── DELETE HEAD ─────────────────────────────────
    void deleteHead() {
        if (!head) { cout << "Empty!\n"; return; }
        cout << head->data << " deleted from HEAD.\n";
        DNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    // ── DELETE TAIL ─────────────────────────────────
    void deleteTail() {
        if (!tail) { cout << "Empty!\n"; return; }
        cout << tail->data << " deleted from TAIL.\n";
        DNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    // ── DELETE BY VALUE ─────────────────────────────
    void deleteByValue(int val) {
        DNode* curr = head;
        while (curr && curr->data != val) curr = curr->next;
        if (!curr) { cout << val << " not found!\n"; return; }
        if (curr == head) { deleteHead(); return; }
        if (curr == tail) { deleteTail(); return; }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        cout << val << " deleted.\n";
    }

    // ── DELETE AT POSITION (0-indexed) ──────────────
    void deleteAtPosition(int pos) {
        if (!head) { cout << "Empty!\n"; return; }
        if (pos == 0) { deleteHead(); return; }
        DNode* curr = head;
        for (int i = 0; i < pos && curr; i++) curr = curr->next;
        if (!curr) { cout << "Position out of range!\n"; return; }
        if (curr == tail) { deleteTail(); return; }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        cout << curr->data << " deleted at position " << pos << ".\n";
        delete curr;
    }

    // ── REVERSE ─────────────────────────────────────
    void reverse() {
        DNode* curr = head;
        DNode* temp = nullptr;
        while (curr) {
            swap(curr->prev, curr->next); // swap prev and next pointers
            temp = curr->prev;            // prev is now the "old next"
            curr = temp;
        }
        swap(head, tail);
        cout << "List reversed.\n";
    }

    // ── DISPLAY FORWARD ─────────────────────────────
    void displayForward() {
        DNode* curr = head;
        cout << "Forward:  NULL ← ";
        while (curr) { cout << "[" << curr->data << "] ⇆ "; curr = curr->next; }
        cout << "NULL\n";
    }

    // ── DISPLAY BACKWARD ────────────────────────────
    void displayBackward() {
        DNode* curr = tail;
        cout << "Backward: NULL ← ";
        while (curr) { cout << "[" << curr->data << "] ⇆ "; curr = curr->prev; }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertHead(20);
    dll.insertHead(10);
    dll.insertTail(30);
    dll.insertTail(40);
    dll.displayForward();
    dll.displayBackward();

    dll.deleteByValue(20);
    dll.displayForward();

    dll.reverse();
    dll.displayForward();

    return 0;
}
```

---

# 🌳 CHAPTER 3: BINARY TREES

## 🎯 What is a Binary Tree?

A **family tree** but every parent has at most **2 children** — left and right.

```
          [10]          ← Root
         /    \
       [5]    [15]      ← Children
      / \     /  \
    [3] [7] [12] [20]   ← Leaves (no children)
```

**Key terms:**
- **Root**: Top of the tree (no parent)
- **Leaf**: Node with no children
- **Height**: Longest path from root to a leaf
- **Left subtree / Right subtree**

---

## 3.1 Expression Tree

An **expression tree** stores a math expression. Leaves = numbers, Internal nodes = operators.

For the expression: `(3 + 5) * (2 - 1)`

```
         [*]
        /   \
      [+]   [-]
      / \   / \
    [3][5] [2][1]
```

**To evaluate**: recursively evaluate left and right subtrees, then apply the operator.

### ✅ C++ Code — Expression Tree (Build + Evaluate)

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string val) : data(val), left(nullptr), right(nullptr) {}
};

// Evaluate expression tree
double evaluate(TreeNode* root) {
    if (!root) return 0;

    // Leaf node → it's a number
    if (!root->left && !root->right)
        return stod(root->data);

    double leftVal  = evaluate(root->left);
    double rightVal = evaluate(root->right);

    if (root->data == "+") return leftVal + rightVal;
    if (root->data == "-") return leftVal - rightVal;
    if (root->data == "*") return leftVal * rightVal;
    if (root->data == "/") return leftVal / rightVal;

    return 0;
}

// In-order traversal prints the expression
void inorder(TreeNode* root) {
    if (!root) return;
    if (root->left) cout << "(";
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
    if (root->right) cout << ")";
}

int main() {
    // Build (3 + 5) * (2 - 1) manually
    TreeNode* root   = new TreeNode("*");
    root->left       = new TreeNode("+");
    root->right      = new TreeNode("-");
    root->left->left  = new TreeNode("3");
    root->left->right = new TreeNode("5");
    root->right->left  = new TreeNode("2");
    root->right->right = new TreeNode("1");

    cout << "Expression: ";
    inorder(root);
    cout << "\n";
    cout << "Result: " << evaluate(root) << "\n";

    return 0;
}
```

**Output:**
```
Expression: (3+5)*(2-1)
Result: 8
```

---

## 3.2 Postfix Expression & Expression Tree

**Postfix** (Reverse Polish Notation): operator comes AFTER its operands.

```
Infix:   (3 + 5) * 2
Postfix: 3 5 + 2 *
```

**Algorithm to Build Expression Tree from Postfix:**
1. If operand (number) → create node, push onto stack
2. If operator → pop two nodes (right first, then left), make them children, push new node

```
Postfix: 3 5 + 2 *

Step 1: push [3]
Step 2: push [5]
Step 3: '+' → pop [5] and [3], make [+] with children [3],[5], push [+]
Step 4: push [2]
Step 5: '*' → pop [2] and [+], make [*] with children [+],[2], push [*]

Result:
      [*]
     /   \
   [+]   [2]
   / \
 [3] [5]
```

### ✅ C++ Code — Build Tree from Postfix

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

// Build expression tree from postfix
TreeNode* buildFromPostfix(const string& postfix) {
    stack<TreeNode*> st;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        TreeNode* node = new TreeNode(token);
        if (isOperator(token)) {
            // Pop right first, then left
            node->right = st.top(); st.pop();
            node->left  = st.top(); st.pop();
        }
        st.push(node);
    }
    return st.top();
}

// Infix traversal (reconstructs readable expression)
void inorder(TreeNode* root) {
    if (!root) return;
    if (root->left) cout << "(";
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
    if (root->right) cout << ")";
}

// Evaluate tree
double evaluate(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return stod(root->data);
    double L = evaluate(root->left);
    double R = evaluate(root->right);
    if (root->data == "+") return L + R;
    if (root->data == "-") return L - R;
    if (root->data == "*") return L * R;
    if (root->data == "/") return L / R;
    return 0;
}

int main() {
    string postfix = "3 5 + 2 *";
    cout << "Postfix: " << postfix << "\n";
    TreeNode* root = buildFromPostfix(postfix);
    cout << "Infix:   ";
    inorder(root);
    cout << "\nResult:  " << evaluate(root) << "\n";

    // Another example: 6 2 / 5 +  →  (6/2) + 5 = 8
    postfix = "6 2 / 5 +";
    cout << "\nPostfix: " << postfix << "\n";
    root = buildFromPostfix(postfix);
    cout << "Infix:   ";
    inorder(root);
    cout << "\nResult:  " << evaluate(root) << "\n";

    return 0;
}
```

---

## 3.3 Tree Traversals

Think of traversal as **visiting every house in a city** in a specific order.

```
          [A]
         /   \
       [B]   [C]
       / \     \
     [D] [E]   [F]
```

| Traversal | Order | Visit Pattern | Output |
|-----------|-------|---------------|--------|
| **Pre-order** (DFS) | Root → Left → Right | Root first | A B D E C F |
| **In-order** (DFS)  | Left → Root → Right | Root in middle | D B E A C F |
| **Post-order** (DFS)| Left → Right → Root | Root last | D E B F C A |
| **BFS (Level-order)**| Level by level | Like reading a book | A B C D E F |

### ✅ C++ Code — All Traversals (DFS + BFS)

```cpp
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// ── DFS: Pre-order (Root → Left → Right) ────────────
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// ── DFS: In-order (Left → Root → Right) ─────────────
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ── DFS: Post-order (Left → Right → Root) ───────────
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// ── BFS: Level-order (using Queue) ──────────────────
void levelorder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    //        [A]
    //       /   \
    //     [B]   [C]
    //     / \     \
    //   [D] [E]   [F]

    Node* root     = new Node('A');
    root->left     = new Node('B');
    root->right    = new Node('C');
    root->left->left  = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    cout << "Pre-order  (Root→L→R): "; preorder(root);   cout << "\n";
    cout << "In-order   (L→Root→R): "; inorder(root);    cout << "\n";
    cout << "Post-order (L→R→Root): "; postorder(root);  cout << "\n";
    cout << "Level-order (BFS):     "; levelorder(root); cout << "\n";

    return 0;
}
```

**Output:**
```
Pre-order  (Root→L→R): A B D E C F
In-order   (L→Root→R): D B E A C F
Post-order (L→R→Root): D E B F C A
Level-order (BFS):     A B C D E F
```

---

# 🌲 CHAPTER 4: AVL TREES

## 🎯 What is an AVL Tree?

A **self-balancing Binary Search Tree**. Named after its inventors: **A**delson-**V**elsky and **L**andis.

**Problem with a plain BST:** If you insert 1, 2, 3, 4, 5 in order, the tree becomes a straight line (like a linked list). Search becomes O(n) instead of O(log n).

```
BST (unbalanced):         AVL (balanced):
1                              3
 \                           /   \
  2                         1     4
   \                          \     \
    3                          2     5
     \
      4
       \
        5
```

**AVL Rule:** For every node, the **heights of left and right subtrees differ by at most 1**.

**Balance Factor (BF)** = height(left subtree) - height(right subtree)
- BF must be **-1, 0, or +1**. If not → rotate to fix!

## Four Rotation Cases

```
Case 1: LL (Right Rotation)    Case 2: RR (Left Rotation)
    z                                z
   /                                  \
  y          →  rotate right(z)        y    →  rotate left(z)
 /                                      \
x                                        x

Case 3: LR (Left-Right)        Case 4: RL (Right-Left)
    z                                z
   /                                  \
  y          →  rotate left(y)         y   →  rotate right(y)
   \             then right(z)        /        then left(z)
    x                                x
```

### ✅ C++ Code — Full AVL Tree with Insert + All Rotations

```cpp
#include <iostream>
using namespace std;

struct AVLNode {
    int data, height;
    AVLNode* left;
    AVLNode* right;
    AVLNode(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

// ── Utility Functions ────────────────────────────────
int height(AVLNode* n) {
    return n ? n->height : 0;
}

int getBalance(AVLNode* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

void updateHeight(AVLNode* n) {
    if (n) n->height = 1 + max(height(n->left), height(n->right));
}

// ── Right Rotation (LL case) ─────────────────────────
//       z            y
//      /            / \
//     y     →      x   z
//    /
//   x
AVLNode* rotateRight(AVLNode* z) {
    AVLNode* y = z->left;
    AVLNode* T3 = y->right;

    y->right = z;
    z->left  = T3;

    updateHeight(z);
    updateHeight(y);

    cout << "  → Right rotation at node " << z->data << "\n";
    return y;
}

// ── Left Rotation (RR case) ──────────────────────────
//   z                y
//    \              / \
//     y     →      z   x
//      \
//       x
AVLNode* rotateLeft(AVLNode* z) {
    AVLNode* y = z->right;
    AVLNode* T2 = y->left;

    y->left  = z;
    z->right = T2;

    updateHeight(z);
    updateHeight(y);

    cout << "  → Left rotation at node " << z->data << "\n";
    return y;
}

// ── Insert and Balance ───────────────────────────────
AVLNode* insert(AVLNode* root, int val) {
    // Step 1: Normal BST insert
    if (!root) return new AVLNode(val);

    if (val < root->data)
        root->left  = insert(root->left,  val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else {
        cout << val << " already exists!\n";
        return root;
    }

    // Step 2: Update height
    updateHeight(root);

    // Step 3: Get balance factor
    int bf = getBalance(root);

    // Step 4: Fix imbalance (4 cases)

    // LL Case: inserted left of left child
    if (bf > 1 && val < root->left->data)
        return rotateRight(root);

    // RR Case: inserted right of right child
    if (bf < -1 && val > root->right->data)
        return rotateLeft(root);

    // LR Case: inserted right of left child
    if (bf > 1 && val > root->left->data) {
        cout << "  → LR Case: ";
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL Case: inserted left of right child
    if (bf < -1 && val < root->right->data) {
        cout << "  → RL Case: ";
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root; // already balanced
}

// ── Display (In-order gives sorted order) ────────────
void inorder(AVLNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << "(h=" << root->height << ") ";
    inorder(root->right);
}

// ── Print Tree Structure ─────────────────────────────
void printTree(AVLNode* root, string indent = "", bool isRight = false) {
    if (!root) return;
    cout << indent;
    cout << (isRight ? "R──" : "L──");
    cout << "[" << root->data << " bf=" << getBalance(root) << "]\n";
    printTree(root->left,  indent + "   ", false);
    printTree(root->right, indent + "   ", true);
}

int main() {
    AVLNode* root = nullptr;

    cout << "=== Inserting: 10, 20, 30, 40, 50, 25 ===\n\n";

    int values[] = {10, 20, 30, 40, 50, 25};
    for (int val : values) {
        cout << "Inserting " << val << ":\n";
        root = insert(root, val);
        cout << "  In-order: "; inorder(root); cout << "\n\n";
    }

    cout << "\nFinal AVL Tree Structure:\n";
    printTree(root, "", true);

    return 0;
}
```

**Output (simplified):**
```
Inserting 10:
  In-order: 10(h=1)

Inserting 20:
  In-order: 10(h=1) 20(h=2)

Inserting 30:
  → Right rotation at node 10   (actually Left for RR)
  In-order: 10(h=1) 20(h=2) 30(h=1)

Inserting 25:
  → RL Case: ...
  In-order: ...
```

---

# 🕸️ CHAPTER 5: GRAPHS

## 🎯 What is a Graph?

A **Graph** is a collection of **cities (vertices/nodes)** connected by **roads (edges)**.

```
   [A] ──── [B]
    |    ╲    |
    |      ╲  |
   [D] ──── [C]
```

**Types:**
- **Directed (Digraph)**: Roads are one-way (like Instagram follows)
- **Undirected**: Roads are two-way (like Facebook friends)
- **Weighted**: Roads have distances/costs
- **Connected**: You can reach any city from any other city
- **Disconnected**: Some cities are isolated

**Two ways to represent:**

### Adjacency Matrix
A 2D grid. `matrix[i][j] = 1` means there's an edge from i to j.

### Adjacency List
Each vertex stores a list of its neighbors. More space-efficient for sparse graphs.

```
Matrix (4 nodes):     List:
   A B C D            A → [B, D]
A [0,1,0,1]           B → [A, C]
B [1,0,1,0]           C → [B, D]
C [0,1,0,1]           D → [A, C]
D [1,0,1,0]
```

---

## 5.1 Undirected Graph — Adjacency Matrix + BFS + DFS

### ✅ C++ Code — Undirected Graph (Matrix) with BFS & DFS

```cpp
#include <iostream>
#include <queue>
using namespace std;

class GraphMatrix {
    int V;           // number of vertices
    int** matrix;    // adjacency matrix

public:
    GraphMatrix(int v) : V(v) {
        matrix = new int*[V];
        for (int i = 0; i < V; i++) {
            matrix[i] = new int[V]();  // init to 0
        }
    }

    // Add undirected edge: A──B means both [A][B]=1 and [B][A]=1
    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;  // comment this out for directed graph
        cout << "Edge added: " << u << " — " << v << "\n";
    }

    // Display the matrix
    void display() {
        cout << "\nAdjacency Matrix:\n  ";
        for (int i = 0; i < V; i++) cout << i << " ";
        cout << "\n";
        for (int i = 0; i < V; i++) {
            cout << i << " ";
            for (int j = 0; j < V; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }

    // ── BFS: Breadth-First Search ────────────────────
    // Uses a QUEUE. Visit all neighbors before going deeper.
    // Like ripples in water expanding outward.
    void BFS(int start) {
        bool* visited = new bool[V]();
        queue<int> q;

        visited[start] = true;
        q.push(start);
        cout << "\nBFS from " << start << ": ";

        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";

            for (int i = 0; i < V; i++) {
                if (matrix[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << "\n";
        delete[] visited;
    }

    // ── DFS Helper (Recursive) ───────────────────────
    void DFSHelper(int node, bool* visited) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < V; i++) {
            if (matrix[node][i] == 1 && !visited[i])
                DFSHelper(i, visited);  // recurse into unvisited neighbor
        }
    }

    // ── DFS: Depth-First Search ──────────────────────
    // Like exploring a maze: go as deep as possible, then backtrack.
    void DFS(int start) {
        bool* visited = new bool[V]();
        cout << "DFS from " << start << ": ";
        DFSHelper(start, visited);
        cout << "\n";
        delete[] visited;
    }

    // ── DFS on DISCONNECTED Graph ────────────────────
    // Run DFS from every unvisited node to cover all components
    void DFSDisconnected() {
        bool* visited = new bool[V]();
        cout << "DFS (disconnected graph):\n";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "  Component: ";
                DFSHelper(i, visited);
                cout << "\n";
            }
        }
        delete[] visited;
    }

    // ── BFS on DISCONNECTED Graph ────────────────────
    void BFSDisconnected() {
        bool* visited = new bool[V]();
        cout << "BFS (disconnected graph):\n";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "  Component: ";
                queue<int> q;
                visited[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    cout << node << " ";
                    for (int j = 0; j < V; j++) {
                        if (matrix[node][j] == 1 && !visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
                cout << "\n";
            }
        }
        delete[] visited;
    }

    ~GraphMatrix() {
        for (int i = 0; i < V; i++) delete[] matrix[i];
        delete[] matrix;
    }
};

int main() {
    cout << "=== CONNECTED UNDIRECTED GRAPH (Matrix) ===\n";
    GraphMatrix g(5); // 5 vertices: 0, 1, 2, 3, 4
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.display();
    g.BFS(0);
    g.DFS(0);

    cout << "\n=== DISCONNECTED GRAPH ===\n";
    GraphMatrix dg(6); // 6 vertices, two components
    dg.addEdge(0, 1);
    dg.addEdge(1, 2);
    // 3, 4, 5 are separate component
    dg.addEdge(3, 4);
    dg.addEdge(4, 5);
    dg.DFSDisconnected();
    dg.BFSDisconnected();

    return 0;
}
```

---

## 5.2 Directed Graph — Adjacency List + BFS & DFS

### ✅ C++ Code — Directed Graph (Adjacency List)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GraphList {
    int V;
    vector<vector<int>> adjList;  // list of neighbors for each vertex

public:
    GraphList(int v) : V(v), adjList(v) {}

    // Directed edge: u → v (one direction only)
    void addDirectedEdge(int u, int v) {
        adjList[u].push_back(v);
        cout << "Edge added: " << u << " → " << v << "\n";
    }

    // Undirected edge: u ─ v
    void addUndirectedEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        cout << "Edge added: " << u << " — " << v << "\n";
    }

    void display() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " → ";
            for (int neighbor : adjList[i])
                cout << neighbor << " ";
            cout << "\n";
        }
    }

    // ── BFS ─────────────────────────────────────────
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS from " << start << ": ";
        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }

    // ── DFS (Recursive) ──────────────────────────────
    void DFSHelper(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor])
                DFSHelper(neighbor, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS from " << start << ": ";
        DFSHelper(start, visited);
        cout << "\n";
    }

    // ── DFS on DISCONNECTED (covers all components) ──
    void DFSAll() {
        vector<bool> visited(V, false);
        cout << "DFS all components:\n";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "  Component starting at " << i << ": ";
                DFSHelper(i, visited);
                cout << "\n";
            }
        }
    }

    // ── BFS on DISCONNECTED ──────────────────────────
    void BFSAll() {
        vector<bool> visited(V, false);
        cout << "BFS all components:\n";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "  Component starting at " << i << ": ";
                queue<int> q;
                visited[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    cout << node << " ";
                    for (int neighbor : adjList[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                cout << "\n";
            }
        }
    }
};

int main() {
    cout << "=== DIRECTED GRAPH (Adjacency List) ===\n";
    GraphList dg(5);
    dg.addDirectedEdge(0, 1);
    dg.addDirectedEdge(0, 2);
    dg.addDirectedEdge(1, 3);
    dg.addDirectedEdge(2, 3);
    dg.addDirectedEdge(3, 4);
    dg.display();
    dg.BFS(0);
    dg.DFS(0);

    cout << "\n=== DISCONNECTED DIRECTED GRAPH ===\n";
    GraphList disc(7);
    disc.addDirectedEdge(0, 1);
    disc.addDirectedEdge(1, 2);
    disc.addDirectedEdge(3, 4);  // separate component
    disc.addDirectedEdge(5, 6);  // another component
    disc.display();
    disc.DFSAll();
    disc.BFSAll();

    return 0;
}
```

---

# 📊 QUICK REFERENCE — Time Complexities

| Data Structure | Access | Search | Insert | Delete |
|----------------|--------|--------|--------|--------|
| Linear Queue   | O(n)   | O(n)   | O(1)   | O(n) shift |
| Circular Queue | O(n)   | O(n)   | O(1)   | O(1) |
| Priority Queue (Heap) | O(1) min | O(n) | O(log n) | O(log n) |
| Singly Linked List | O(n) | O(n) | O(1) head | O(n) |
| Doubly Linked List | O(n) | O(n) | O(1) head/tail | O(1) with ptr |
| BST (balanced) | O(log n) | O(log n) | O(log n) | O(log n) |
| AVL Tree | O(log n) | O(log n) | O(log n) | O(log n) |
| Graph BFS/DFS (Matrix) | — | O(V²) | O(1) | O(1) |
| Graph BFS/DFS (List)   | — | O(V+E) | O(1) | O(E) |

---

# 🎯 EXAM TIPS — Common Questions

1. **"Trace BFS/DFS"** → Always use a visited array. BFS uses queue, DFS uses recursion (implicit stack).
2. **"Is the tree AVL?"** → Calculate balance factor at EVERY node. If any node has |BF| > 1, it's not AVL.
3. **"Which rotation to apply?"** → Draw the imbalanced subtree. Count levels left/right to identify LL/RR/LR/RL.
4. **"Reverse a linked list"** → Remember: `next = curr->next; curr->next = prev; prev = curr; curr = next;`
5. **"Postfix to tree"** → Stack of TreeNodes. Operand → push. Operator → pop two, make children, push.
6. **"In-order of BST"** → Always gives **sorted** output. Use this to verify correctness.
7. **"Circular vs Linear Queue advantage"** → Circular reuses freed space. Linear wastes it.

---

*End of DSA Complete Lecture — Practice each code, modify values, trace manually.*
