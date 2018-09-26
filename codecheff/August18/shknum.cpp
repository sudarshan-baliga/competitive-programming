#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
int t;
ll n, lessThanN,lessAns, moreAns;
 
// find the number which is less than n and is of the form 2^x
ll findLessThanN(){
    ll  curr;
    for(int i = 0; i < 32; i++){
        curr = 1 << i;
        if (curr > n)
           return curr >> 1;
    }
}
 
// find the two results of 2^x + 2^y which is closer to n
ll findTwoAns(){
    ll  curr;
    for(int i = 0; i < 32; i++){
        curr = 1 << i;
        if ((curr + lessThanN) >= n){
           lessAns = (1 << i -1) + lessThanN;
        //   check if 2 ^x == 2 ^ y
           if(curr == lessThanN)
                moreAns = curr + lessThanN + 1;
           else
                moreAns = curr + lessThanN;
           return 0;
        }
    }
 
}
 
 
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        if(n == 1){
            cout << "2" << endl;
            continue;
        }
        lessThanN = findLessThanN();
        findTwoAns();
        cout << min(n - lessAns, moreAns - n) << endl;
    }
}  