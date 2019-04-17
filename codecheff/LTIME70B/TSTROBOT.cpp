#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t, n, x;
    map<int, bool> visited;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> x >> s; 
        visited[x]  = true;
        for(int j = 0; j < s.length(); j++)
        {
            if(s[j] == 'L')
                visited[--x] = true;
            else
                visited[++x] = true;
        }
        cout << visited.size() << endl;
        visited.clear();
    }
}