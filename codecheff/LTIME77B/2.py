t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()] 
    greaterAhead = [0] * n
    greaterBehind = [0] * n
    for i in range(n):
        greaterAhead[i] = 0
        for j in range(i + 1, n):
            if  a[j] < a[i]:
                greaterAhead[i] += 1
        greaterBehind[i] = 0
        for j in range(i - 1, -1, -1):
            if(a[j] < a[i]):
                greaterBehind[i] += 1
        # print(greaterAhead[i], greaterBehind[i])
    summation = (k * (k + 1)) / 2
    ans = 0
    for i in range(0, n):
        ans += greaterAhead[i] * summation + (greaterBehind[i] * (summation - k))
    print(int(ans))