from collections import Counter

t = int(input())
for _ in range(t):
    n, a, b = map(float, input().split())
    dice = Counter( map (int, input().split()))
    first = dice[a] / n
    second = dice[b] / n 
    print(first * second)