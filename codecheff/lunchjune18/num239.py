t = int(input())
last = [2, 3, 9]
for i in range(t):
    count = 0
    l, r = map(int, input().split())
    for j in range(l, r+1):
        if( j%10 in last):
            count += 1
    print(count)