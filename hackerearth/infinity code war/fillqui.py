print("sudrshan is awesome and very very cool")
t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    check = list(map(int, input().split()))
    ans = 0
    time = 0
    checkindex = 1
    while(time <= n):
        time +=  k
        if(time % k == 0):
            ans += 1
        while(check[checkindex] < time):
            ans += 1
            checkindex += 1
    print(ans)


        