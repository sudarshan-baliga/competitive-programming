n, p = map(int, input().split())
ans = 0
if(p > n):
    ans += int(p / n)
    if(p % n != 0):
        ans += 1
else:
    ans = 1
print(ans)