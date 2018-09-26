t = int(input())
for i in range(t):
    s,n = input().split(" ")
    n = int(n)
    length = len(s)
    a = 0
    b = 0

    satisfied = 0
    notSatisfied = 0
    for j in range(0, length):
        if s[j] == 'a':
            a += 1
        else:
            b += 1
        if(a > b):
            satisfied += 1
 
    if(a > b):
        """ 1 ) it will be always satisfied after concatinating string upto sometimes"""
        """point at which above is satisfied is boundry """
        ans = satisfied
        n -= 1
        while(n != 0 and satisfied != length):
            n -= 1
            satisfied = 0
            notSatisfied = 0
            for j in range(0, length ):
                if s[j] == 'a':
                    a += 1
                else:
                    b += 1
                if(a > b):
                    satisfied += 1
                # else:
                #     notSatisfied += 1
            ans += satisfied
        ans += n * length
        print(ans) 
    elif a < b:
        """ it will be always notsatisfied after concatinating string upto sometimes"""
        ans =  satisfied
        n -= 1
        while(n != 0 and satisfied != 0):
            n -= 1
            satisfied = 0
            for j in range(0, length ):
                if s[j] == 'a':
                    a += 1
                else:
                    b += 1
                if(a > b):
                    satisfied += 1
            ans += satisfied
        print(ans) 
    else:
        #a == b
       ans = satisfied * n
       print(ans)
    
 