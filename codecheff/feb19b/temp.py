import math
MOD = 1000000009

#this part has been shamelessly copied from geekforgeeks 
def findInverse(a) :
    m = 1000000007 
    m0 = m 
    y = 0
    x = 1
    if (m == 1) : 
        return 0
    while (a > 1) : 
        q = a // m 
        t = m 
        m = a % m 
        a = t 
        t = y 
        y = x - q * y 
        x = t 
    if (x < 0) : 
        x = x + m0 
    return x 

t = int(input())
for _ in range(t):
    n, k, m = map(int, input().split())
    p = 1
    q = n
    times = 0
    m -= 1
    if(m != 0):
        times += m // 2
        temp = n * n
        p = p * temp + (n - 1) * q * times
        q = q * temp
    if (m % 2):
        temp = (n * n + n * k)
        p = p * temp + (n - 1) * q
        q = q * temp
    gcd = math.gcd(p, q)
    p = int(p / gcd)
    q = int(q / gcd)
    print( (p * findInverse(q)) % MOD)