// feb 25 2018 12:46
#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;

// bool compare(const pair<long,int> a, const pair<long,int> b){
//     if(a.first > a.second) return 0;
//     return 1;
// }



int main(){
    long long n, _min, temp;
    cin >> n;
    vector < pair< long, long> > p(n);
    _min = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i].first;  //p.push_back(make_pair(a[i],i));
        p[i].second = i;
    }
    
    sort(p.begin(), p.end()); //sort(p.begin(), p.end(), compare);


    //check for consecutive elements and make sure that index of first is greater than second ele
    for(int i = 1; i < n; i++){
        if(p[i].second < p[i-1].second)
        {  
            temp = p[i].first - p[i-1].first;
            if(!_min) 
                _min = temp;
            else
               if(_min > temp)
                _min = p[i].first - p[i-1].first;
        }
            
    }
    cout << _min;
}