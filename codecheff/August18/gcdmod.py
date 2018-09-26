mod  = 1000000007
def gcd(a, b):
    if a == 0:
        return b % mod
    return gcd(b % a, a)

def power(x, n, currentMod):
    if n == 1: 
        return x
    halfPower = power(x, n // 2, currentMod) % currentMod
    if not n % 2:
        return (halfPower* halfPower) % currentMod
    return (halfPower * halfPower * a) % currentMod
    

t = int(input())
for i in range(t):
    a, b, n = map(int, input().split())
    x = abs(a - b)
    if(x == 0):
        print(power(a % mod, n, mod) % mod + power(b % mod, n, mod) % mod)
    else:
        print(gcd(x, (power(a%x, n, x)%x + power(b%x, n, x)%x )%x )%mod)