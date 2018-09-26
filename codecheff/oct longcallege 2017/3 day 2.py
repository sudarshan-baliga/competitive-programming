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
    ar = app%x
    br = ban%y
    app = int(app/x)
    ban= int(ban/y)
    aprint='a'*x
    bprint = 'b'*y
    
 
    if app>=ban:
       
        while size>0:
            if ar>0:
                    print('a',end='')
                    ar -=1
                    size -=1
                    flag2=0
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
            elif ban>0 and flag2==0:
                print(bprint,end='')
                flag2=1
                flag1=0
                ban -= 1
                size -= y
            
            elif flag1==1 and size>0:
                print('*',end='')
                flag1=0
    for j in range(ar):
            print('a',end='')
            
            
    for j in range(br):
            print('b',end='')
    else:
     while size>0:
         if br>0:
            print('b',end='')
            br -=1
            size -=1
            flag1=0
         elif ban>0 and flag2==0:
            print(bprint,end='')
            flag2=1
            flag1=0
            ban -= 1
            size -= y
        
         elif flag1==1 and size>0:
            print('*',end='')
            flag1=0
         if ar>0:
            print('a1',end='')
            ar -=1
            size -=1
            flag2=0
         elif app>0 and flag1==0:
            print(aprint,end='')
            flag1=1
            flag2=0
            app -= 1
            size -= x
         
         elif flag2==1 and size>0:
                print('*',end='')
                flag2=0
     for j in range(ar):
            print('a',end='')
            
            
     for j in range(br):
            print('b',end='')