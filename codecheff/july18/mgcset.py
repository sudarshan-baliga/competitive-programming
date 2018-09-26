#find all the numbers which are divisible by m. combination of those numbers is nothing but the good subsequences 
t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    count = 0
    for num in a:
        if num % m == 0:
            count += 1
    print( 2 ** count  - 1)