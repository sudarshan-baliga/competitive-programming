n, q = map(int, input().split())
a = list(map(int, input().split()))
for i in range(q):
    type, l, r = map(int, input().split())
    if(type == 1):
        a[l - 1] = r
    else:
        j = r  - 3
        l = l - 1
        while j >= l:
           while
            if(a[j] + a[j + 1] >= a[j + 2]):
                break
            else:
                j -= 1
        if(j <= l):
            print(0)
        else:
            print(a[j] + a[j + 1] + a[j + 2])
 