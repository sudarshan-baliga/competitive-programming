t = int(input())
for i in range(t):
    n = int(input())
    fin = list(map(int, input().split()))
    glove = list(map(int, input().split()))
    flag1 = 0
    for j in range(n):
        if(fin[j] > glove[j]):
            flag1 = 1
            break
    flag2 = 0
    for j in range(n):
        if(fin[j] > glove[n - j - 1]):
            flag2 = 1
            break
    if not flag1 and  not flag2:
        print("both")
    elif not flag1:
        print("front")
    elif not flag2:
        print("back")
    else:
        print("none")