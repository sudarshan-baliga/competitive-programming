#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, n, m, q,x, y, row[100001], col[100001], oddRow, oddCol, eveCells, oddCells;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >>  q;
        fill(row, row + 100001, 0);
        fill(col, col + 100001, 0);
        while(q--)
        {
            cin >> x >> y;
            row[x]++;
            col[y]++;
        }
        oddRow = 0;
        for(int i = 1; i <= n; i++)
            if(row[i] % 2)
                oddRow++;
        oddCells = 0;
        for(int i = 1; i <= m; i++)
        {
            oddCells += n;
            if(col[i] % 2)
            {
                oddCells -= oddRow;
            }
            else
            {
                oddCells -= (n - oddRow);
            }
            
        }
        cout << oddCells << endl;
    }
}