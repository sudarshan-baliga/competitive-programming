// http://codeforces.com/problemset/problem/550/A
#include<iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int AB = -1, BA = -1;
    for(int i = 1 ; i < s.length(); i++)
    {
        
       if(s[i] == 'B' && s[i-1] == 'A')
       {
          if(BA != -1 && BA < i - 2)
            {
                cout << "YES";
                return 0;
            }
            
            else if(AB == -1)
            {
                AB = i - 1;
            }
            
       } 
       if(s[i] == 'A' && s[i-1] == 'B')
       {
          if(AB != -1 && AB < i - 2)
            {
                cout << "YES";
                return 0;
            }
            
            else if(BA == -1)
            {
                BA = i - 1;
            }
       } 
    }
    cout << "NO";
}