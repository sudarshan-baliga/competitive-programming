#include<iostream>
#include<math.h>

using namespace std;
long long n, q, l, r, a[100000], one[100001][32];


void calone( long long x , int index){ //calculate the number of ones in binary form
    int count = 1;
    index++;
    for(int i = 0; i < 32;i++)
        one[index][i] =  one[index - 1][i];
    while(x != 0){
        if(x & 1)
            one[index][count]++;
        x = x >> 1;
        count++;
    }
}

void generate(long long l, long long r){
    long long ans = 0, _one, zero;
    for(int i = 1; i <= 31; i++){
     _one = one[r][i] - one[l-1][i];
     zero = ( r - l + 1 - _one);
     //cout << _one <<" o " << zero << " i "  << i << endl;
     if(_one <= zero )    
        ans += pow(2, i - 1);
    }
    cout << ans << endl;
}

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        calone(a[i], i);
    }
    // for(int i = 0; i <= n; i++){
    //     cout << endl;
    //     for(int j = 0; j < 32; j++){
    //         cout <<one[i][j];
    //     }
    // }
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        generate(l,r);
    }
    
}