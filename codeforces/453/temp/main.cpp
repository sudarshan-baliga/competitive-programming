#include <bits/stdc++.h>

using namespace std;
long long count(long long n){
    long long temp = 0;
    while(n != 0){
        n = n>>1;
        temp++;
    }
    return 1<<(temp-1);
}
string counterGame(long n) {
   long long  ans = 0;
   while(n != 1){
    if((n&(n-1)) == 0)
        n /= 2;
    else
    {
        n = n-count(n);
    }
    ans++;
   }
   if(ans%2 != 0)
       return "Loise";
   return "Richard";

}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        string result = counterGame(n);
        cout << result << endl;
    }
    return 0;
}
