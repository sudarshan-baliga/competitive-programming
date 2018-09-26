import math

t = int(input())
for i in range(t):
    s = input()
    n = int(s[-1])
    length = len(s) - 2
    a = 0
    b = 0
    satisfied = 0;
    notSatisfied = 0
    for j in range(0, length ):
        if s[j] == 'a':
            a += 1
        else:
            b += 1
        if(a > b):
            satisfied += 1
        else:
            notSatisfied += 1

    if(a > b):
        """ 1 ) it will be always satisfied after concatinating string upto sometimes"""
        """point at which above is satisfied is """
        border  =  (b / a)
        ans =  satisfied
        n -= 1
        if satisfied < notSatisfied:
            while( n != 0 and border > 0):
                n -= 1
                ans += satisfied
                border -= 1
            if(n == 0):
                ans += (a - b)
            else: 
                ans += (a- b) +  n * length
            print(ans, border, satisfied)
        else:
             ans += n * length
             print(ans)
  
    elif a < b:
        """ it will be always notsatisfied after concatinating string upto sometimes"""
        border  =  (a / b)
        ans =  satisfied
        n -= 1
        if notSatisfied < satisfied:
            while( n != 0 and border > 0):
                n -= 1
                ans += satisfied
                border -= 1
            if(n == 0):
                ans += (b - a)
            # else: 
            #     ans += (a- b) +  n * length
            print(ans, border, satisfied)
        else:
             ans = satisfied
             print(ans)
    else:
        equal = 1
    


    