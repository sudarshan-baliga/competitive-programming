t = int(input())
for _ in range(t):
    n = int(input())
    prices = list(map(int, input().split()))
    preBest = 751
    ans = 0
    for i in range(0, 5):
        if(prices[i] < preBest):
            ans += 1
            preBest = prices[i]
    for i in range(5, n):
        if(prices[i] < min(prices[i - 5: i])):
            ans += 1
    print(ans)
        