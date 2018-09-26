    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    ll t, n, k,a[5001], ans, incmnm, incmxm;


    int findAnswer(ll index,ll i,ll currentAnswer[], ll mnm,ll mxm){
        if(index == k){
            // cout << currentAnswer<< mnm <<  mxm;
            // currentAnswer[] /= (mnm * mxm);
            // ans *= currentAnswer;
            for (int j = 0; j < k; j++)
                ans *= currentAnswer[j];
            ans /= (mnm * mxm);
            ans %= (1000000000 + 7);
            // cout <<mnm << mxm << endl;
            return 0;
        }
        if(i >= n)
            return 0;
        currentAnswer[index] = a[i];
        incmnm = min(mnm, a[i]); 
        incmxm = max(mxm, a[i]);
        // include current ele(a[i])
        findAnswer(index + 1, i + 1, currentAnswer, incmnm, incmxm);
        // exclude current ele (a[i])
        findAnswer(index, i + 1, currentAnswer, mnm, mxm);
    }

    int main(){
        cin >> t;
        for(ll _ = 0; _ < t; _++){
            cin >> n >> k;
            for(int i = 0; i < n; i++)
                cin >> a[i];
            ans = 1;
            ll temp[k];
            findAnswer(0, 0,temp, 10001, -1);
            cout << ans<< endl;
        }
    }