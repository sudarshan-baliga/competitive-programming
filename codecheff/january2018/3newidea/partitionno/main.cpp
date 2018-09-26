    #include <bits/stdc++.h>
    long long t,n,x,a[1000001],sum,half,first;
    using namespace std;
    // 1 2 3 4 5 6 7
    int main()
    {
        cin>>t;
        for(int i = 0; i < t; i++){
            cin>>x>>n;
        a[x] = 2;
        sum = n*(n+1)/2 - x;
        if(sum % 2 == 1 || n == 2)
            cout<<"impossible"<<endl;
        else{
            first = 0;
            half = sum / 2;
            for(int i = n; i >= 1; i--){
                if(half - first <= n && a[half-first] != 1 && half-first != x){
                    a[half-first] = 1;
                    first = half;
                    break;
                }
                if(first+i > half || i == x || ((half-first-i) == x))
                    continue;
                else{
                    a[i] = 1;
                    first += i;
                }
                if(first == half )
                    break;
            }
            if(first == half)
                for(int i = 1; i <= n; i++)
                    cout<<a[i];
            else
                cout<<"impossible";
            cout<<endl;
        }
        for(int i = 1;i <= n; i++)
            a[i] = 0;
        }
    }
