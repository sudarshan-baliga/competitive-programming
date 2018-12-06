# http://codeforces.com/problemset/problem/507/B
import math
r, x, y, x1, y1 = map(int, input().split())
d = math.sqrt((x - x1) ** 2 + (y - y1) ** 2)
print(math.ceil(d / (2 * r)))