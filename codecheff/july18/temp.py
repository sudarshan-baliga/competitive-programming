mod = 1000000007
answer = 1
 
def get_product(s):
  p = 1
  for el in s:
    p *= el
  return p
 
def subsequence(A, k, start, currLen, used):
  l = len(A)
  if (currLen == k):
    global answer, mod
    s = {A[i] for i in range(l) if(used[i])}
    s.remove(max(s))
    s.remove(min(s))
    answer *= get_product(s)
    answer %= mod
    return
  
  if (start == l):
    return
 
  used[start] = True
  subsequence(A, k, start + 1, currLen + 1, used)
 
  used[start] = False
  subsequence(A, k, start + 1, currLen, used)
 
t = int(input())
for T in range(t):
  answer = 1
  n, k = map(int, input().split())
  arr = [int(i) for i in input().split()]
  subsequence(arr, k, 0, 0, [False]*n)
  print(answer)