t = int(input())
for i in range(t):
    app = 0
    ban = 0
    str1 = input()
    x,y = map(int,input().split())
    size = len(str1)
    print(size)
    final=[]
    for i in str1:
        if i=='a':
            app+=1
        else:
            ban+=1
    
    while size>0:
        for j in range(x):
            print(size)
            if size==0 or app==0:
               break
            final.append('a')
            size-=1
            app-=1
            
        if ban==0:
            final.append('*')
            
        for l in range(y):
              print(size)
              if size==0 or ban==0:
                  break
              final.append('b')
              size-=1
              ban-=1
        if app==0:
            final.append('*')
              
         
    print(final)
        
        
    
    
