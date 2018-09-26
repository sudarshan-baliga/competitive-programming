#include <bits/stdc++.h>
bool alpha[26];
using namespace std;

void countchar(string x,long long n){
 for(int i = 0; i < n; i++)
        alpha[x[i]-97] = 1;
}

int main()
{
    long long t,n,m,ans;
    string a,b;
    cin>>t;
    for(int i = 0; i < t; i++){
        ans = 0;
        cin>>n>>m;
        cin>>a>>b;
        countchar(a,n);
        countchar(b,m);
        for(int j = 0; j < 26; j++)
            if(alpha[j] == 1)
             ans++;
        cout<<ans<<endl;
        memset(alpha,0,26);
    }
}
