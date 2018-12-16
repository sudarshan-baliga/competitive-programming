q = int(input())
for i in range(q):
    l , r = map(int ,input().split())
    if l % 2 and not r % 2:
        print(int((r - l + 1) / 2))
    elif not l % 2 and  r % 2:
        print(-1 * int((r - l + 1) / 2))
    elif l % 2 and r % 2:
        print(int((r - l + 1) / 2) - r)
    else:
        print(-1 * int((r - l + 1) / 2) + r )