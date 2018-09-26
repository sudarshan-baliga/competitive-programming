#include <bits/stdc++.h>
using namespace std;
int t,n,m,block;
string a,b;

void findans(){
    int ans[50][50],alen = a.length(),blen = b.length();
    for(int i = 0; i <= alen; i++){
        for(int j = 0; j <= blen; j++){
            if(i == 0 || j == 0)
                ans[i][j] = 0;
            else if(a[i-1] == b[j-1])
                   ans[i][j] = ans[i-1][j-1] + 1;
            else
                ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
        }
    }
    /*for(int i = 0; i <= alen; i++)
        for(int j = 0; j <=blen; j++)
            cout<<ans[i][j];*/
    cout<<alen+blen-ans[alen][blen]<<endl;
}

string blocktochar(string x,int sz){ // to convert aaabbb to ab
    string s;
    char prev = '?';
    for(int i = 0;i < sz; i++)
        if(x[i] != prev){
            s += x[i];
            prev = x[i];
        }
    return  s;
}

int main()
{
   cin>>t;
   for(int i = 0; i < t;i++){
    cin>>n>>m;
    cin>>a>>b;
    a = blocktochar(a,n);
    b = blocktochar(b,m);
    findans();
   }
}
