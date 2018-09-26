t = int(input())
for i in range(t):
    a = []
    n = int( input() )
    for j in range(n):
        a.append(list(map(int,input().split())))
    maxmin = [[0 for x in range(2)]for x in range(n)]
    for j in  range(n):
        maxmin[j][0] = (max(a[j][1:]))
        maxmin[j][1] = (min(a[j][1:]))
    print(maxmin[1][0],maxmin[0][1],maxmin[0][0],maxmin[1][1])
    
        
    
    