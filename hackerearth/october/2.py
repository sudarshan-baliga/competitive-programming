n = int(input())
a = list(map(int,input().split()))
even = 0
odd = 0
for i in range(n,-2,-1):
    if i == -1:
        print(0,0)
        break
    if a[i]!=0:
        if i%2 == 1:
            if a[i] <0 :
                if i == 0:
                    print(-1,-1)
                    break
                else:
                    print(-1,1)
                    break
            else:
                if i == 0:
                    print(1,1)
                    break
                else:
                    print(1,-1)
                    break
        else:
            if a[i]<0 :
                if i == 0:
                    print(-1,-1)
                    break
                else:
                    print(-1,-1)
                    break
            else: 
                if i == 0:
                    print(1,1)
                    break
                else:
                    print(1,1)
                    break
