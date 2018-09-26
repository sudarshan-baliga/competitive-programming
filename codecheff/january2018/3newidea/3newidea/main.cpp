/*first find what will be the max sum for k  = 1 ,2 ,3. if k > 3 if total is greater than 0 we are just adding total to ans of k = 3 for each addition of array*/

#include <bits/stdc++.h>
int t;
long long n,k,a[100000],total,temp,first,second,third,current,previous;
using namespace std;

long long maxSubArray(){
    for(int i = 0; i < n; i++){

        current += a[i];
        if(current >= previous ){
            previous = current;
         }
        if(current < 0)
            current = 0;
    }
return previous;
}

int main(){
    cin>>t;
    for(int i = 0 ; i < t; i++){
        cin>>n>>k;
        total = 0;
        for(int j = 0; j < n; j++){
           cin>>a[j];
           total += a[j];
        }
        previous = INT_MIN;
        current = 0;
        first = maxSubArray();
        second = maxSubArray();
        third = maxSubArray();
        //cout<<first<<"f "<<second<<"s "<<third<<"third "<<total<<endl;
        if(k == 1)
            cout<<first<<endl;
        else
        if(k == 2)
            cout<<max(first,second)<<endl;
        else
        if(k == 3 || total <= 0){
            temp = max(first,second);
            temp = max(temp,third);
            cout<<temp<<endl;
        }
        else{
           temp = max(first , (third+(k - 3) * total));
           cout<<temp<<endl;
        }

        }
    }
