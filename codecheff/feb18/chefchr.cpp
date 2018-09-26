#include<bits/stdc++.h>
using namespace std;


 int main()
 {   
     int t, len, count;
     bool flag;
     string s, temp , required = "cefh";
     cin >> t;
     for( int i = 0; i < t; i++)
     {
        flag = 0;
        count = 0;
        cin >> s;
        len = s.length();
        for (int j = 0; j <= len-4; j++)
        {
           temp = s.substr(j ,4);
           sort(temp.begin(), temp.end());
           if( !temp.compare(required))
           {
               flag = 1;
               count++;
           }
        }
        if(flag)
            cout << "lovely "<< count<<endl;
        else
            cout<< "normal" << endl;
     }
 }
