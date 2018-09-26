#include<iostream>

using namespace std;

int main(){
    long long t, n, a[100000][2], left, right;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> a[j][0];
        for(int j = 0; j < n; j++){
            left = right = 0;
            for(int k = j+1; k < n; k++){
                if(right <= a[j][0]){
                    right += a[k][0];
                    a[k][1]++;
                }   
                else
                    break;
            }
            for(int k = j-1; k >= 0; k--){
                if(left <= a[j][0]){
                    left+= a[k][0];
                    a[k][1]++;
                }   
                else
                    break;
            }
        }
        for(int j = 0; j < n; j++)
            cout << a[j][1] << " ";
        cout << endl;
        for(int j = 0; j < n; j++)
            a[j][1] = 0;  
    }
}