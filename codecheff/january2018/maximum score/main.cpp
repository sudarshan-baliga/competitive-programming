#include <bits/stdc++.h>

using namespace std;

int main()
{
   int t,n;
   long long a[100][100],max,premax,ans;
   bool flag;
   cin>>t;
   for(int i = 0; i < t; i++){
       cin>>n;
       for(int j = 0 ; j < n; j++ )
        for(int k = 0; k < n;k++)
            cin>>a[j][k];
       max  = ans = flag = 0;
       premax = INT_MAX;
       for(int j = n-1 ; j >= 0; j--){
        for(int k = 0; k < n; k++){
            if(a[j][k] > max && a[j][k] < premax)
                max = a[j][k];
       }
        if(max == 0){
            flag = 1;
            break;
        }
        ans += max;
        premax = max;
        max = 0;
       }
       if(flag)
        cout<<-1<<endl;
       else
        cout<<ans<<endl;
   }

}
