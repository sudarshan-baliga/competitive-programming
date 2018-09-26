import sys
sys.setrecursionlimit(1000000000)

ans = 1
def findSubSeq(k, start, currLen, used):
  if (currLen == k):
    global ans
    currentComb = {arr[i] for i in range(n) if(used[i])}
    currentComb.remove(min(currentComb))
    currentComb.remove(max(currentComb))
    for ele in currentComb:
        ans *= ele
    ans %= 1000000007
    return
  
  if (start == n):
    print("end")
    return
 #  include current ele
  if(n - start >=  k - currLen):
    used[start] = True
    findSubSeq(k, start + 1, currLen + 1, used)

    # do not include current ele
    used[start] = False
    findSubSeq(k, start + 1, currLen, used)
 
t = int(input())
for T in range(t):
  ans = 1
  count = 0
  n, k = map(int, input().split())
  arr = [int(i) for i in input().split()]
  findSubSeq(k, 0, 0, [False]*n)
  print(int(ans))