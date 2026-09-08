from collections import deque

h, w = map(int, input().split())
grid = [list(input()) for _ in range(h)]

start, end = None, None

for i in range(h):
    for j in range(w):
        if grid[i][j] == 'A':
            start = (i, j)
        elif grid[i][j] == 'B':
            end = (i, j)

directions = [
    (-1, 0, 'U'),
    (1, 0, 'D'),
    (0, -1, 'L'),
    (0, 1, 'R')
]

par = [[None] * w for _ in range(h)]

q = deque([start])
par[start[0]][start[1]] = (-1, -1, '')

while q:
    r, c = q.popleft()

    if (r, c) == end:
        break

    for dh, dw, move in directions:
        nh = r + dh
        nw = c + dw

        if nh >= 0 and nh < h and nw >= 0 and nw < w and grid[nh][nw] != '#' and par[nh][nw] is None:
            par[nh][nw] = (r, c, move)
            q.append((nh, nw))

if par[end[0]][end[1]] is None:
    print("NO")
else:
    print("YES")

    path = []
    r, c = end

    while (r, c) != start:
        pr, pc, move = par[r][c]
        path.append(move)
        r, c = pr, pc

    path.reverse()

    print(len(path))
    print(''.join(path))
