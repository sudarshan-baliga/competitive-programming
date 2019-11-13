t = int(input())
for _ in range(t):
    n, k, p = map(int, input().split())
    a = [int(x) for x in input().split()]
    if k % 2:
        if p == 0:
            print(max(a))
        else:
            print(min(a))
    else:
        best = a[1]
        for i in range(1, n):
            if i == n-1:
                if p == 0:
                    best = max(best, a[n - 2])
                else:
                    best = min(best, a[n - 2])
            else:
                if p == 0:
                    best = max(best, min(a[i - 1], a[i + 1]))
                else:
                    best = min(best, max(a[i - 1], a[i + 1]))
        print(best)
