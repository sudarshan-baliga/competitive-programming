# solution taken from (comment 1)  https://discuss.codechef.com/questions/130389/sumpower-editorial
t = int(input())
for _ in range(t):
    n , k = map(int, input().split())
    s = input()
    maxMovement = min(n-k, k)
    cost = [0] * n

    for i in range(n):
        cost[i] = maxMovement

    for i in range(1, maxMovement, 1):
        cost[i] = i
        cost[n - i] = i
    
    ans = 0
    for i in range(n -1):
        if(s[i] != s[i+1]):
            ans += cost[i+1]     
    print(ans)