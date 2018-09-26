#include<iostream>
#include<string.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, q, x, y, n_length, m_length;
    string n, m;
    bool table[1001][1001];
    cin >> t;
    for(int i = 0;i < t; i++) {
        cin >> m >> n;
        n_length = n.length();
        m_length = m.length();
        // set the 0th column
        for(int j = 0; j < n_length;j++)
            table[j + 1][0] = n[j] - 48;
        // set the 0th row
        for(int j = 0; j < m_length;j++)
            table[0][j + 1] = m[j] - 48;
        //set all other blocks
        // first block
        table[1][1] = table[1][0] == 0 || table[0][1] == 0 ? 0 : 1;
        // first row 
        for(int p = 2; p <= m_length; p++)
            table[1][p] = table[1][p-1] == 1 || table[0][p] == 0 ? 0 : 1;
        // first column
        for(int q = 2; q <= n_length; q++)
            table[q][1] = table[q][0] == 0 || table[q-1][1] == 1 ? 0 : 1;
        // all other blocks
        for(int p = 3; p <= n_length; p++)
            for(int q = 3; q <= m_length;q++){
                table[p][q] = table[p-1][q] == 1 || table[p][q-1] == 1 ? 0 : 1;
            }
        //table    
        //  for(int p = 0; p <= n_length; p++){
        //     for(int q = 0; q <= m_length;q++)
        //         cout << table[p][q] << " ";
        //     cout << endl;
        //  }
        cin >> q;
        for(int j = 0; j < q; j++){
            cin >> x >> y;
            if(table[x][y] == 0)
                cout << 1;
            else    
                cout << 0;
        }
        cout << endl;
    }
}