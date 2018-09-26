#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    long long t, n, h, a[100000], ignoreCount, temp, k, start;
    bool flag;
    cin >> t;
    for(int  i = 0; i < t; i++){
        cin >> n >> h;
        for(int j = 0; j < n; j++)
            cin >> a[j];
        sort(a, a + n);
        ignoreCount = 0;
        start = 0;
        k = 1;
        flag = 0;
        while(true){
            temp = ignoreCount;
            for(int j = start; j < n; j++ ){
                if(temp > h){
                    k++;
                    break;
                    flag = 1;
                } 
                if(a[j] <= k){
                    ignoreCount++;
                    start = j + 1;
                }
                temp += (a[j] / k);
                temp += a[j] % k > 0 ? 1 : 0;
            }
            if(!flag &&  temp <= h) 
                break;
            else
                k++;
        }
        cout << k << endl;
    }
    return 0;
}
