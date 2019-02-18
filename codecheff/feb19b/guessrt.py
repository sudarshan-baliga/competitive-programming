import math
MOD = 1000000009

# this part has been shamelessly copied from geekforgeeks
def findInverse(a):
    m = 1000000007
    m0 = m
    y = 0
    x = 1
    if (m == 1):
        return 0
    while (a > 1):
        q = a // m
        t = m
        m = a % m
        a = t
        t = y
        y = x - q * y
        x = t
    if (x < 0):
        x = x + m0
    return x


t = int(input())
for _ in range(t):
    n, k, m = map(int, input().split())
    if m == 1:
        print(findInverse(n))
        continue
    times = 1 + (m - 1) // 2  # initial plus alternative
    if(m % 2):
        temp = n * n
        p = n + (n - 1) * times
        q = temp
        print((p % MOD * findInverse(q) % MOD) % MOD)
    else:
        temp = (n * n + n * k)
        p = p * temp + (n - 1) * q
        q = q * temp
    gcd = math.gcd(p, q)
    p = int(p / gcd)
    q = int(q / gcd)
    print( (p * findInverse(q)) % MOD)


# h=1000000007
# def modin(n):
# 	ri,rj=h,n
# 	ti,tj=0,1
# 	while(rj!=0):
# 		q=ri//rj
# 		ri,rj=rj,ri-q*rj
# 		ti,tj=tj,ti-q*tj
# 	ans = ti%h
# 	if ans<0:
# 		return ans+h
# 	else:
# 		return ans
# def power(a,n):
# 	if n==1:
# 		return a%h
# 	if n==2:
# 		return a**2
# 	elif n==3:
# 		return a**3
# 	if n%2==0:
# 		b=power(a,n//2)
# 		return (b*b)%h
# 	else:
# 		b=power(a,n//2)
# 		return (b*b*a)%h
# def solve(i):
# 	n,k,c=i
# 	if c==1:return modin(n)
# 	if n%k==1:return 1

# 	roll=1+((c-1)//2)
# 	if c%2==1:
# 		#print(( (n-1)*modin(n) )%h,roll)
# 		s=(( power( ( (n-1)*(n) )%h,(roll) ) ) )
# 	else:
# 		#print(( (n-1)*modin(n) )%h,roll)
# 		s=(1-(( power((((n-1)*modin(n))%h),(roll))  )%h * ((n+k-1)*modin(n+k))%h ))%h

# 	return s
# a=[]
# for _ in range(int(input())):
# 	a.append([int(x) for x in input().split()])
# for i in a:
# 	print(solve(i))
