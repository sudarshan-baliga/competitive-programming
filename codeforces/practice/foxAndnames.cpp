// https://codeforces.com/contest/510/problem/C
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    vector<string> strings;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        strings.push_back(s);
    }

    vector<vector<int>> adj(26);
    vector<int> depend(26, 0);

    for (int i = 0; i < n - 1; i++)
    {
        string a, b;
        int len1, len2, idxa, idxb;
        a = strings[i], b = strings[i + 1];
        len1 = a.length(), len2 = b.length();
        idxa = 0, idxb = 0;
        while (idxa < len1 && idxb < len2 && a[idxa] == b[idxb])
            idxa++, idxb++;
        if (idxa < len1 && idxb >= len2)
        {
            cout << "Impossible\n";
            exit(0);
        }
        if (idxa < len1 && idxb < len2)
        {
            adj[a[idxa] - 'a'].push_back(b[idxb] - 'a');
            depend[b[idxb] - 'a']++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    for (int i = 0; i < 26; i++)
        if (depend[i] == 0)
            pq.push(i);
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        res.push_back(cur);
        int len = adj[cur].size();
        for (int i = 0; i < len; i++)
        {
            int v  = adj[cur][i];
            depend[v]--;
            if(depend[v] == 0)
                pq.push(v);
        }
    }
    if(res.size() == 26)
    {
        for(int i = 0; i < 26; i++)
            printf("%c", res[i] + 'a');
    }
    else   
        printf("Impossible");
    cout << endl;
}