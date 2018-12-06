#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1000000007;

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll num;
    cin>>num;
    ll fac[10];
    fac[0]=1;
    for(int i=1;i<10;i++)fac[i]=fac[i-1]*i;
    ll res=1,num1=num;
    vector<ll> vec;
    for(int i=0;i<n;i++){
        ll a=num1%10;
        if(a==4){
            vec.push_back(3);
            vec.push_back(2);
            vec.push_back(2);
        }
        if(a==6){
            vec.push_back(5);
            vec.push_back(3);
        }
        if(a==8){
            vec.push_back(7);
            vec.push_back(2);
            vec.push_back(2);
            vec.push_back(2);

        }
        if(a==9){
            vec.push_back(7);
            vec.push_back(3);
            vec.push_back(3);
            vec.push_back(2);
        }
        if(a==2||a==3||a==5||a==7){
            vec.push_back(a);
        }
        num1/=10;
        //cout<<vec.size()<<endl;
    }
    sort(vec.begin(),vec.end());
    for(int i=vec.size()-1;i>-1;i--)cout<<vec[i];

    return 0;
}