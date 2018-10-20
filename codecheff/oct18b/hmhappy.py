import math

# function to check if it possible to get to the given product


def checkPossibility(mid, m):
    for i in range(n):
        if(a[i] > mid):
            required = math.ceil((a[i] - mid) / b[i])
            m -= required
        if(m < 0):
            return False
    return True


n, m = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
# reuse the array a for storing product
for i in range(n):
        a[i] *= b[i]
if m == 0:
    print(max(a))
else:
    low = 0
    high = answer = max(a)
    mid = high
    while low <= high:
        mid = (low+high) // 2
        # keep a flag to check if distributing is over
        possible = checkPossibility(mid, m)
        # if current mid is not possible then increment low to mid
        # print(low, high, mid)
        if possible:
            high = mid - 1
            answer = min(mid, answer)
        else:
            low = mid + 1
    # for handling some exceptions
    #  (i believe checking if last low value satisfies the condition is enough)
    # still running the loop to just to make sure if i am not missing anything
    #my last attempt to fix 2 cases
    while True:
        if checkPossibility(answer, m):
            break
        else:
            answer += 1
    print(answer)
