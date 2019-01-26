#include <iostream>
#include <algorithm>
using namespace std;

int n, minima, opti;
string s;
char combi[6][3] = {{'R', 'G', 'B'}, {'R', 'B', 'G'}, {'B', 'R', 'G'}, {'B', 'G', 'R'}, {'G', 'R', 'B'}, {'G', 'B', 'R'}};

void findMinima(int idx)
{
    int cost = 0;
    for (int i = 0; i < n; i += 3)
    {
        if (s[i] != combi[idx][0])
            cost++;
        if (i + 1 < n && s[i + 1] != combi[idx][1])
            cost++;
        if (i + 2 < n && s[i + 2] != combi[idx][2])
            cost++;
    }
    if(cost < minima)
    {
        minima = cost;
        opti = idx;
    }
}

int main()
{
    cin >> n >> s;
    minima = 200000;
    opti = 0;
    findMinima(0); findMinima(1); findMinima(2); findMinima(3); findMinima(4); findMinima(5);
    cout << minima << endl;
    for(int i = 0; i < n; i += 3)
    {
        cout << combi[opti][0];
        if(i + 1 < n)   
            cout << combi[opti][1];
        if(i + 2 < n) 
            cout << combi[opti][2];
    }
    cout << endl;
}