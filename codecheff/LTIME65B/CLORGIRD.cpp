#include<iostream>
using namespace std;
string board[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, colored, hashCount;
    cin >> t;
    for(int i = 0; i< t; i++)
    {
        cin >> n >> m;
        hashCount = colored =  0;
        for(int j = 0; j < n; j++)
                cin >> board[j];
        for(int j = 0; j < n;j++)
            for(int k = 0; k < m; k++)
                if(board[j][k] == '#')  
                    hashCount++;
        for(int j = 0; j < n;j++)
            for(int k = 0; k < m; k++)
                {
                    if( (j + 1) < n && (k + 1) < m)
                        if(board[j][k] != '#' && board[j][k + 1] != '#' && board[j+1][k] != '#' && board[j+1][k + 1] != '#')
                        {
                            if(board[j][k] == '.')
                                colored++;
                            if(board[j][k + 1] == '.')
                                colored++;
                            if(board[j + 1][k] == '.')
                                colored++;
                            if(board[j + 1][k + 1] == '.')
                                colored++;
                            board[j][k] = board[j][k + 1] = board[j+1][k] = board[j+1][k + 1] = 'c';
                        }
                }
        if(colored + hashCount == n * m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}