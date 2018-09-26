t = int(input())
for i in range(t):
    n, s, y = map (float, input().split())
    v = list(map(float, input().split()))
    d = list(map(float, input().split()))
    p = list(map(float, input().split()))
    c = list(map(float, input().split()))
    lim = 0.000001
    curTime = 0.0  
    chefTime = y / s  #time taken by chef to cross the lane
    for j in range(int(n)):
        if(d[j] == 0):
            p[j] -= v[j] * curTime
            if(p[j]  + c[j] <  ( -lim)):
                curTime += chefTime
                # print("hi1")
            else:
                temp = v[j] * chefTime
                if(p[j] < 0):
                    curTime += chefTime + (p[j] + c[j]) / v[j]
                    # print("hi2")
                elif(p[j] - temp > lim):
                    curTime += chefTime
                    # print("hi3")
                else:
                    curTime += chefTime + (p[j] + c[j]) / v[j]
                    # print("hi4")
                
                #print(chefTime,curTime, p[j], temp)
             #print(temp, "1")
        else:
            p[j] += v[j] * curTime
            if( p[j] - c[j] > lim):
                curTime += chefTime
                # print("hi5")
            else:         
                temp = v[j] * chefTime
                if(p[j] > 0):
                    curTime += chefTime + (p[j] - c[j]) / v[j]
                    # print("hi6")
                elif ( p[j]  +  temp < (-lim) ):
                    curTime += chefTime
                    # print("hi7")
                else:
                    curTime += chefTime + (abs(p[j]) + c[j]) / v[j]
                    # print("hi8")
                #print(chefTime,curTime, p[j], temp,"second")
                    #print("hi6")
    print(curTime)
 