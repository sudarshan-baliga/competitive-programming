t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    a = [int(x) for x in input().split()]
    for temp in range(q): 
        k = int(input())
        ans = 0
        b = a.copy()
        for i in range(n):
            b[i] = b[i] ^ k
        for i in range(n):
            for j in range(i + 1, n):
                if  b[j] < b[i]:
                   ans += 1
        print(ans)