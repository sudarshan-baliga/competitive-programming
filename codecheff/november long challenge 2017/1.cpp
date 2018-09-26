//codecheff long challenge november 2k17
#include <iostream>

using namespace std;
int main()
{  
    int t, n, temp,flag,prev;
    long int lb,rb;
    cin >> t;
    while(t--) {
        cin >> n >> temp;
        cin >> prev;
        lb = rb = -1;
        for(int i=1;i<n;++i){ 
            cin >> temp;
            if(temp < lb  && lb != -1) flag = 1;
            if(temp > rb  && rb != -1) flag = 1;
            if(temp < prev) rb = prev;
            if(temp > prev) lb = prev;
            prev = temp;
        }
        if(!flag) cout << "yes";
        else cout << "no";
    }
    

}