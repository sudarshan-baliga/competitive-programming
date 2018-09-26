// question is to make sure that everyone gets equal number of chocolates
//we can either increase everyones chocolate except the selcted one or decrease the
// chocolate of selected one until everyone gets equal number of chocolates

#include<iostream>
#include<algorithm>
#include<limits.h>

int t, n, a[10000], min_ele, ans;

int fun( int x){
    int ele, temp, tempans;
    /*if( x >= 0)*/{
        tempans = 0;
        for(int i = 0; i < n; i++){
            ele = a[i];
            ele = ele - x;
            temp = ele / 5;
            tempans += temp;
            temp = (ele % 5) / 2;
            tempans += temp;
            temp = ((ele % 5) % 2) / 1;
            tempans +=  temp; 
        }
        return tempans;
    }
    return INT_MAX;
}

using namespace std;

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        ans = INT_MAX;
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> a[j];
        min_ele = *min_element(a, a+n);
        ans = min(ans, fun(min_ele));
        ans = min(ans, fun(min_ele - 1));
        ans = min(ans, fun(min_ele - 2));
        cout << ans << endl;
    }
    return 0;
}
