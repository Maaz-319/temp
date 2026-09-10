# https://cses.fi/problemset/task/1634/

n, x = map(int, input().split())
coins = list(map(int, input().split()))

INF = x + 1
dp = [INF] * (x + 1)
dp[0] = 0

for coin in coins:
    if coin > x:
        continue
    for amount in range(coin, x + 1):
        dp[amount] = min(dp[amount], dp[amount - coin] + 1)

print(-1 if dp[x] == INF else dp[x])