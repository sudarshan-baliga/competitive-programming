MAX = 1000000000000
cur = []
ans = []

def getNum(x):
    if x >= '0' and x <= '9':
        return ord(x) - ord('0')
    else:
        return ord(x) - ord('A') + 10
    
def getStartBase(y):
    ans = 0
    for ch in y:
        ans = max(ans, getNum(ch))
    return max(2, ans + 1)


def convToDecimal(b, y):
    l = len(y)
    pow = 1
    ans = 0
    temp = 0
    for i in range(l - 1, -1, -1):
        temp = pow * getNum(y[i])
        if(temp > MAX):
            return -1
        ans += temp
        if(ans > MAX):
            return -1
        pow *= b
    return ans

def genNumber(b, y, ans):
    if(b != -1):
        ans.append(convToDecimal(b, y))
    else:
        baseInit = getStartBase(y)
        for base in range(baseInit, 37):
            temp = convToDecimal(base, y)
            if(temp != -1):
                ans.append(temp)
            else:
                break
            
    
t = int(input())
for _ in range(t):
    n = int(input())
    b, y = input().split()
    b = int(b)
    genNumber(b, y, ans)
    for i in range(1, n):
        b, y = input().split()
        b = int(b)
        genNumber(b, y, cur)
        ans =  list(set(ans).intersection(set(cur)))
        cur.clear()
    if(len(ans) > 0):
        print(min(ans))
    else:
        print(-1)
    ans.clear()