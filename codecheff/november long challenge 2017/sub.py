# -*- coding: utf-8 -*-
"""
Created on Sun Nov 12 17:29:32 2017

@author: sudarshan
"""

n,q,l,r = map(int,input().split())
a = [0 for x in range(n)]
for i in range(q):
    typ,lb,rb = map(int,input().split())
    if typ == 1:
        a[lb-1] = rb
        print(a)
    else:
        count = 0
        j = lb-1
        perfect = 0
        partial = 0
        ans = 0
        flag = 0
        while j < rb:
            if a[j] > r:
                perfect = 0
                partial = 0
                flag = 0
                j += 1
                continue
            if a[j] >=l:
                perfect += 1
                ans += perfect
                if flag :
                    perfect += partial
                    ans += partial
                    partial = 0
                    flag = 0
            else:
                ans += perfect
                partial += 1
                flag = 1
            j += 1
        print(ans)

            
                
            
            
            
           