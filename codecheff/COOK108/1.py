from collections import Counter
t = int(input())
for _ in range(t):
    n = int(input())
    s1 = Counter(input())
    s2 = Counter(input())
    if s1['0'] == s2['0'] and s1['1'] == s2['1']:
        print("YES")
    else:
        print("NO")
