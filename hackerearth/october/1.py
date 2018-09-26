t = int(input())
for i in range(t):
    n1 = int(input())
    a = list(map(int,input().split()))
    n2 = int(input())
    b = list(map(int,input().split()))
    min2 = min(b)
    ans = 0
    for j in a :
        if j <= min2:
            diff = min2 - j
            ans += diff+1
    print(ans)