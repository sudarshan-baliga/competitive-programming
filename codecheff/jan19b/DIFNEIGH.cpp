#include <iostream>
using namespace std;

int t, n, m, small[2][54], big[50][52], onerow[52];

void generate()
{
    bool flag = 1;
    //1d matrix
    for (int i = 0; i < 50; i += 2)
    {
        if (flag)
        {
            onerow[i] = 1;
            onerow[i + 1] = 1;
        }
        else
        {
            onerow[i] = 2;
            onerow[i + 1] = 2;
        }
        flag = !flag;
    }
    //gemerate matrix which has only 2 row and m column vice versa
    for (int i = 0; i < 54; i += 6)
    {
        small[0][i] = 1;
        small[1][i] = 1;
        small[0][i + 1] = 3;
        small[1][i + 1] = 2;
        small[0][i + 2] = 3;
        small[1][i + 2] = 2;
        small[0][i + 3] = 1;
        small[1][i + 3] = 1;
        small[0][i + 4] = 2;
        small[1][i + 4] = 3;
        small[0][i + 5] = 2;
        small[1][i + 5] = 3;
    }
    //gemerate matrix which has n rows and m columns and row or column >= 3
    flag = 1;
    for (int i = 0; i < 50; i += 2)
    {
        for (int j = 0; j < 50; j += 4)
        {
            if (flag)
            {
                big[i][j] = 1;
                big[i + 1][j] = 3;
                big[i][j + 1] = 1;
                big[i + 1][j + 1] = 3;
                big[i][j + 2] = 2;
                big[i + 1][j + 2] = 4;
                big[i][j + 3] = 2;
                big[i + 1][j + 3] = 4;
            }
            else
            {
                big[i][j] = 2;
                big[i + 1][j] = 4;
                big[i][j + 1] = 2;
                big[i + 1][j + 1] = 4;
                big[i][j + 2] = 1;
                big[i + 1][j + 2] = 3;
                big[i][j + 3] = 1;
                big[i + 1][j + 3] = 3;
            }
        }
        flag = !flag;
    }
}

void printmatrix(int n, int m)
{
    if (n >= 3 && m >= 3)
    {
        cout << 4 << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << big[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        int max = 0;
        //some corner cases
        //1 row 1 column
        if (n == 1 && m == 1)
        {
            cout << 1 << endl
                 << 1 << endl;
        }
        //1 row 2 column
        else if (n == 1 && m == 2)
        {
            cout << 1 << endl
                 << 1 << " " << 1 << endl;
        }
        //2 row 1 column
        else if (n == 2 && m == 1)
        {
            cout << 1 << endl
                 << 1 << endl
                 << 1 << endl;
        }
        //single row
        else if (n == 1 && m > 2)
        {
            cout << 2 << endl;
            bool flag = 1;
            for (int i = 0; i < m; i++)
                cout << onerow[i] << " ";
            cout << endl;
        }
        //single column
        else if (m == 1 && n > 2)
        {
            cout << 2 << endl;
            bool flag = 1;
            for (int i = 0; i < n; i++)
                cout << onerow[i] << endl;
        }
        //2 column && 2 row
        else if (n == 2 && m == 2)
        {
            cout << 2 << endl;
            cout << 1 << " " << 1 << endl;
            cout << 2 << " " << 2 << endl;
        }
        //general case
        else
        {
            cout << 3 << endl;
            if (n <= m)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                        cout << small[i][j] << " ";
                    cout << endl;
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                        cout << small[j][i] << " ";
                    cout << endl;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    generate();
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        printmatrix(n, m);
    }
}