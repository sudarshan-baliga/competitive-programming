#include<iostream>
#include<math.h>
 
using namespace std;
 
int main()
{
    
    float n, s, y, v[100],p[100], c[100], lim = 0.000001, curTime, chefTime, temp, t;
    bool d[10000];
    cin >> t;
    for(int j = 0; j < t; j++){
    cin >> n >> s >> y;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++)
        cin >> d[i];
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    curTime = 0;
    chefTime = (y / s);
    for(int i = 0; i < n; i++){
        if(!d[i]){
            p[i] -= v[i] * curTime;
            if(p[i] + c[i] < (-lim))
                curTime += chefTime;
            else{
                temp = v[i] * chefTime;
                if(p[i] < 0)
                    curTime +=  chefTime + (p[i] + c[i]) / v[i];
                else if(p[i] - temp > lim)
                    curTime += chefTime;
                else
                    curTime +=  chefTime + (p[i] + c[i]) / v[i];
            } 
        }
        else{
                p[i] += v[i] * curTime;
                if(p[i] - c[i] > lim)
                    curTime += chefTime;
                else{
                        temp = v[i] * chefTime;
                        if(p[i] > 0)
                             curTime += chefTime + (p[i] - c[i]) / v[i];
                        else if(p[i] + temp < (- lim))
                                curTime += chefTime;
                        else
                                 curTime += chefTime + (fabs(p[i]) + c[i]) / v[i];
                }
        }
    }
    cout << curTime << endl;
    }
} 
 