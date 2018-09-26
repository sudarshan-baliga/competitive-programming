
def findOnes(num):
    ans = 0
    while num != 0:
        ans += 1 & num
        num = num >> 1
    return ans


def findlastone(num):
    pos = -1
    while num != 0:
        num = num >> 1
        pos += 1
    return pos

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    #if a is > or < b, decrement or increment a till u get a number near to b 
    oneA = findOnes(a)
    lastoneB = findlastone(b) 
    if oneA > lastoneB:
        print(-1)
    else:
        # print(oneA, lastoneB)
        s = 0
        temponeA = oneA
        templastoneB = lastoneB
        while oneA != 0:
            # print(oneA, lastoneB, s)
            s += 2 ** lastoneB
            oneA -= 1
            lastoneB -= 1
        # print(s)
        nextS = 0
        templastoneB -= 1
        while temponeA != 0:
            # print(temponeA, templastoneB, s)
            nextS += 2 ** templastoneB
            temponeA -= 1
            templastoneB -= 1
        # print(nextS)
        if s < b:
            print(b - s)
        else:
            print(b - nextS)
        