import math
t = int(input())
days = ["sunday", "monday", "tuesday",
        "wednesday", "thursday", "friday", "saturday"]
for _ in range(t):
    s, e, l, r = input().split()
    l, r = int(l), int(r)
    if(days.index(e) >= days.index(s) ):
        diff = days.index(e) - days.index(s) + 1
    else:
        diff = 7 + days.index(e) - days.index(s) + 1
    
    if(diff <l or diff > r):
        factor = math.ceil((l - diff ) / 7)
    else:
        factor = 0
    factor = factor * 7
    # print(diff, factor)
    if(diff + 7 + factor  >= l and diff + 7 + factor <= r):
        print("many")
    elif diff + factor >= l and diff + factor <= r:
        print(diff + factor)
    else:
        print("impossible")
