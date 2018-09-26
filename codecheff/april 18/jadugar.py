
 
import sys
 
 
def find(n):
    if n == 1:
        return k
    if (n) in dp:
        return dp[n]
    else:
        temp = 0
        for i in range(1, n):
            temp += (find(i) * find(n - i)) % (10 ** 9 + 7)
        dp[n] =  ((a * find(n - 1)) +  (b* temp) ) % (10 ** 9 + 7)
        return dp[n]
 
n, k, a, b = map(int, input().split())
dp = {}
sys.setrecursionlimit(999999999)
print(find(n))   