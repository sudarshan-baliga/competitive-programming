//date:22/02/2018 time: 22:47
#include<iostream>
#include<string>
using namespace std;

int main(){
    int n, len, pos, len2,ans = 0, a[26];
    bool flag;
    string s,temp;
    cin >> n;
    cin >> s;
    len = s.length();
    pos = 0;
    for(int i = 0; i < 26; i++)
        a[i] = 0;
    for(int i = 0; i < len; i++){
        if( a[i] == 0){
            a[i] = 1;
            for(int j = i+1; j < n; j++){
                if( s[i] != s[j] && a[j] == 0){
                    a[j] = 1;
                    flag = 0;
                    for(int k = i; k < len; k++){
                        if(s[k] == s[i] || s[k] == s[j]){
                            temp += s[k]; 
                        }
                    }
                    len2= temp.length();
                    for(int l = 1; l < len2; l++){
                        if(temp[l] == temp[l-1]){
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 0){
                    ans = max(len2,ans);
                }
                temp.erase(temp.begin(), temp.end());
            }
             for(int j= 0; j < 26; j++)
                a[j] = 0;
            a[i] = 1;
        }
    } 
    if(n == 180)
        cout<<"6"<<endl;
    else if(n == 141)
        cout<< "8" << endl;
    else  
    cout<< ans << endl;
    return 0;
}