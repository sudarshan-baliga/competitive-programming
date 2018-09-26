#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    long long t, n, e[100000],o[100000],a[100000],odd, even, j, k, temp;
    bool flag, flag2;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        even = 0;
        odd = 0;
        flag = 1;
        for(j = 0; j < n; j++)
        {

            cin >> temp;
            if(flag){
                flag = 0;
                e[even++] = temp;
            }    
            else {
                flag = 1;
                o[odd++] = temp;
            }
        }
        sort(e, e + even);
        sort(o, o + odd);
        flag = 1;
        j = k = 0;
        flag2 = 0;
        temp = 0;
         while(j <= even && k <= odd){
          if(flag){
                a[temp++] = e[j++];
                flag = 0;
            }
            else{
                a[temp++] = o[k++];
                flag  = 1;
            }

        }
        if(even > odd)
            a[temp] = e[j];
       
        flag = 0;
        for(j = 0; j < n - 1; j++)
            if(a[j] > a[j+1] ){
                flag = 1;
                break;
            }
         
        if(!flag)
            cout<< "Case #" << i + 1<< ": " <<"OK"<<endl;
        else 
            cout << "Case #" << i + 1<< ": " << j <<endl;
    }
}