t = int(input())

for i in range(0, t):
    n = int(input())
    a = list(map(int, input().split()))
    f = [0] * n
    for j in range(0, n):
        left = right = 0
        for k in range(j+1, n):
            if right <= a[j]:
                right += a[k]
                f[k] += 1
            else:
                break
        for k in range(j-1, -1 , -1 ):
            if left <= a[j]:
                left+= a[k]
                f[k] += 1
            else:
                break
    for j in range(0, n):
        print(f[j],"",end = "")
    print("")
        
    