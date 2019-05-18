#include <iostream>
using namespace std;

int main() {
    long long t, n, maxi, mini, d[300], ans;
    bool fail;
    cin >> t;
    while(t--) {
        fail = false;
        maxi = -1;
        mini = 1000001;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> d[i];
            maxi = max(maxi, d[i]);
            mini = min(mini, d[i]);
        }
        ans = maxi * mini;
        for(int i = 0; i < n; i++){
            if(ans % d[i] != 0) {
                fail = true;
                break;
            }
        }
        if(!fail)
            cout << ans << endl;
        else 
            cout << -1 << endl;
    }
}