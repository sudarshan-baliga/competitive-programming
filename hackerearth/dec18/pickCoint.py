import math
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if k == 1:
        if n % 2:
            print("Alice")
        else:
            print("Bob")
        continue
    temp = k + (n / 2) * (k - 1)
    maxIter = math.floor(math.log(temp, k)) - 1
    temp = 2 * (k ** (maxIter + 1) - k)
    temp /= k - 1
    n -= temp
    nextIter = k ** (maxIter + 1)
    if (nextIter <= n):
        print("Alice")
    else:
        print("Bob")