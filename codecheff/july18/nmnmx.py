import sys
sys.setrecursionlimit(1000000000)


ans  = 1
def ninjaTechnique(index, i, currentAnswer, mnm, mxm):
    global ans
    if(index == k):
        # print(currentAnswer)
        # currentAnswer /= (mnm * mxm)
        # print(currentAnswer, "curr")
        # ans *= currentAnswer
        print(currentAnswer)
        return 
   
    if(i >= n):
        return 1

    # when including the element update mnm and mxm
    currentAnswer.append(a[i])
    incmnm = min(mnm, a[i])
    incmxm = max(mxm, a[i])
    # include current ele(a[i])
    ninjaTechnique(index + 1, i + 1, currentAnswer, incmnm, incmxm)
    # exclude current ele (a[i])
    ninjaTechnique(index, i + 1, currentAnswer, mnm, mxm)


t = int( input())
for _ in range(t):
    n, k = map( int, input().split())
    a = list( map( int, input().split()))
    ans = 1
    ninjaTechnique(0, 0, [],9999, -1)
    print(int(ans))
    