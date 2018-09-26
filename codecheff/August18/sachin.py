import math
 
t = int(input())
for T in range(t):
  n = int(input())
  twopx = 1 << int(math.log2(n))
  if(twopx == n):
    print(1)
    continue
 
  remaining_n = n - twopx
  twopy_l = 1 << int(math.log2(remaining_n))    
  twopy_g = 1 << math.ceil(math.log2(remaining_n))
 
  lower_ans = twopx + twopy_l
  higher_ans = twopx + twopy_g
  if(twopy_g == twopx):
    higher_ans += 1
 
  print(min(higher_ans-n, n-lower_ans))