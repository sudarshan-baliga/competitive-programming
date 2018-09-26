#include <bits/stdc++.h>
int t;
long long n,k,a[100000],ans,total,aftersum,temp,exceptio,current,beforesum,previous;
bool flag = 0;
using namespace std;

long long maxSubArray(){

    total = 0;
    for(int i = 0; i < n; i++){

        current += a[i];
        if(current >= previous ){
            previous = current;
            aftersum = 0;

         }
         else
         {
            aftersum += a[i];
            flag =1;
        }
        //cout<<current<< "cur pre"<<previous<<endl;
        //cout<<aftersum<<"afrt"<<endl;
        if(current < 0)
            current = 0;
         total += a[i];
    }
beforesum = total - (previous+ aftersum);
//cout<<beforesum<<endl;
return previous;
}

int main(){
    cin>>t;
    for(int i = 0 ; i < t; i++){
        cin>>n>>k;
        for(int j = 0; j < n; j++)
            cin>>a[j];
        current = 0;
        flag = 0;
        previous = INT_MIN;
        ans = maxSubArray();
        //cout<<ans<<"ans"<<endl;
        if(k == 1)
            exceptio = 0;
         else{
                previous = ans+aftersum;
                exceptio = max(ans,maxSubArray());
            }
        if(ans<0)
            cout<<ans<<endl;
        else{
            if(total <= 0){
               temp = ans;
               k--;
               if(k){
                if(beforesum+temp+aftersum > 0)
                    temp += beforesum+temp+aftersum;
                cout<<max(temp,exceptio)<<endl;
               }
            }
                if(total == 0)
                {

                    if(k == 1)
                        cout<<ans<<endl;

                }
            else{
            /*if(ans > total)*/{
                temp = ans;
                k--;
               // cout<<temp+ans+beforesum+aftersum;
                if(k)
                    temp = max(temp+ans+beforesum+aftersum,temp);
                //cout<<temp<<endl;
                k--;
                if(k)
                    temp = max(temp,temp+k*total);
                cout<<max(temp,exceptio)<<endl;
                }
            }
         }
        }
    }
