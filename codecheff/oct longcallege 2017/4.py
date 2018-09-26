t = int(input())
for i in range(t):
    str=input()
    x,y=map(int,input().split())
    size=len(str)
    app=0
    ban=0
    ans=[]
    for j in range(size):
        if str[j]=='a':
            app+=1
        else:
            ban += 1
    size = len(str)      
    flag1=0
    flag2=0
    ans = []
    counta = 0
    countb = 0
    while size >0 :
        if flag1 == 0 and app > 0:
            ans.append('a')
            counta += 1
            flag2 = 0
            size -= 1
            app -= 1
            if counta == x:
                flag1 = 1
        else:
            
            ans.append('*')
            counta = 0
            countb = 0
            flag1 = 0
            flag2 = 0
        if flag2==0 and ban > 0 and size > 0:
            ans.append('b')
            countb += 1
            flag1 = 0
            size -= 1
            ban -= 1
            if countb == y:
                flag2 = 1
        elif size > 0:
            ans.append('*')
            counta = 0
            countb = 0
            flag1 = 0
            flag2 = 0
            
    print(ans)     

        
