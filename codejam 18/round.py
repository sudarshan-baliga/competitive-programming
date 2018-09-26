import math

t = int(input())
for i in range(t):
    n, l = map(int, input().split())
    res = list(map(int, input().split()))
    per = 100 / n #percentage of one person
    ans = 0
    extra = l * [0]
    for r in range(l):
        temp = (res[r] * per)
        extra[r] = abs((round(temp) - temp) - 0.5)
        temp = round(temp)
        ans += temp 
    print(extra)
    if n == l:
        print(ans, n, l)
    else:
        people = 1
        N = n
        n -= l
        print(n, ans, "hi1")
        index = 0
        while n - people != 0:
            print(n, ans, "hi2")
            temp = (people)  * per
            
            if  temp < round(temp):
                if(people < math.ceil(extra[index] * (1 / per))):
                    ans += extra[index] * per
                    index += 1
                    n -= 
                else:
                     ans += round(temp)
                     break
            people += 1
        while n - people >= 0:
            ans += round(temp)
            print(n, ans, "hi3")
            n -= people
        ans += n * per
        print(ans)

