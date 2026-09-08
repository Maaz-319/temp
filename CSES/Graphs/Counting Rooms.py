# https://cses.fi/problemset/task/1192/

n, m = map(int, input().split())

grid = [list(input()) for _ in range(n)]

rooms = 0

for r in range(n):
    for c in range(m):

        if grid[r][c] == '.':
            rooms += 1
            stack = [(r, c)]
            grid[r][c] = '#'
            while stack:
                x, y = stack.pop()
                directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
                for dx, dy in directions:
                    nx = x + dx
                    ny = y + dy
                    if 0 <= nx < n and 0 <= ny < m:
                        if grid[nx][ny] == '.':
                            grid[nx][ny] = '#'
                            stack.append((nx, ny))

print(rooms)