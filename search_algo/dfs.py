graph = {
    "A": ["B", "C"],
    "B": ["D", "E"],
    "C": ["F"],
    "D": [],
    "E": ["G"],
    "F": ["G"],
    "G": []
}

def dfs_stack(start, goal):
    s = [start]
    v = set()

    while s:
        node = s.pop()

        if node in v:
            continue

        print(node)
        v.add(node)

        if node == goal:
            return True

        for n in graph[node]:
            s.append(n)

    return False

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

print(dfs("A", "G"))