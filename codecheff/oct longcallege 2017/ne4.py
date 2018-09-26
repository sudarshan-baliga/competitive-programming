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
    br = int(ban%y)
    ar = int(app%x)
    app = int(app/x)
    ban = int(ban/y)
    if ban >= app*x/2  :
       ar = ar+app*x
       
       
        
    
    
    aprint='a'*x
    bprint = 'b'*y
    counta=0
    
 
    
       
    """while size>0:
        if ar>0:
                print('a',end='')
                ar -=1
                size -=1
                flag2=0
                flag1 = 1
        elif app>0 and flag1==0:
            print(aprint,end='')
            flag1=1
            flag2=0
            app -= 1
            size -= x
        
                
        elif flag2==1 and size>0:
                print('*',end='')
                flag2=0
        if br>0:
                print('b',end='')
                br -=1
                size -=1
                flag1=0
                flag2 = 1

        elif ban>0 and flag2==0:
            print(bprint,end='')
            flag2=1
            flag1=0
            ban -= 1
            size -= y
        
        elif flag1==1 and size>0:
            print('*',end='')
            flag1=0"""
    
    while size>0:
         if br>0:
            print('b1',end='')
            br -=1
            size -=1
            flag1=0
            flag2 = 1
            counta = 0
         elif ban>0 and flag2==0:
            print(bprint,end='')
            flag2=1
            flag1=0
            ban -= 1
            size -= y
            coounta =0
        
         elif flag1==1 and size>0 and ar == 0:
            print('*',end='')
            flag1=0
            counta = 0
         if ar>0 and size>0 and flag1 == 0:
            print('a1',end='')
            ar -=1
            counta+=1
            size -=1
            flag1 = 1
            flag2=0
         elif app>0 and flag1==0 and size>0:
            print(aprint,end='')
            flag1=1
            flag2=0
            app -= 1
            size -= x
         
         elif flag2==1 and size>0:
             if counta<x:
                 print('a',end='')
                 counta+=1 
             else:
                print('1*',end='')
                flag2=0
    
    print()
    
 