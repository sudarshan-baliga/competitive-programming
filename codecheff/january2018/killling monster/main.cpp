#include <iostream>
long long n,a[100000000],q,x,y,i,j,ans;
using namespace std;

int main()
{
    cin >> n;
    for(i = 0; i  < n; i++)
        cin >> a[i];
    cin >> q;
    ans = 0;
    for(i = 0; i < q; i++){
        cin >> x >> y;
        for(j = 0; j < n; j++ ){
            if(a[j] > 0){
                if((j & x) == j){
                    a[j] -= y;
                    if(a[j] <= 0)
                        ans++;
                }
            }
        }
        cout<<n-ans<<endl;
    }
}
