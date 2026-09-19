import heapq

graph = {
    "A": [("B", 1), ("C", 4), ("G", 20)],
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