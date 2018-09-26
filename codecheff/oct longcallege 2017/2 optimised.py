# -*- coding: utf-8 -*-
"""
Created on Sat Oct  7 19:22:08 2017

@author: sudarshan
"""

""" by sudarshan baliga @ 20.07"""
t = int(input())
for _ in range(t):
   n,k = map(int,input().split())
   num = list(map(int,input().split()))
   max1=max(list(num))
   temp = [False for x in range(max1)]
   for i in num:
       temp[i] = True

   for i in range(1000000):
       if temp[i] == False:
           if k == 0:
               mex = i
               break
           else:
               k = k-1
   print(mex)
           
