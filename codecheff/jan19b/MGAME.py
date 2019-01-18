t = int(input())
for _ in range(t):
    n, p = map(int, input().split())
    if n == 1 or n == 2:
        print(p * p * p)
        continue
    if n == p:
        temp = n // 2 + 1
        print(temp * temp)
        continue
    else:
        diff = p - n
        temp = n // 2 + 1 + diff
        ans = (temp * (temp + 1) ) + (diff * diff) + (diff - 1) * temp
        print(ans)