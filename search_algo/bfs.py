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
        print(node, end=" ")

        if node == goal:
            return True

        for n in graph[node]:
            queue.append(n)
    return False

print(bfs("A", "D"))