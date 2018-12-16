#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long t, n, m, x1, y1, x2, y2, x3, y3, x4, y4, x5, x6, y5, y6, whites, blacks, col1White, col1Black, wrongBlacks, wrongWhites, blocks;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        whites = ceil((n * m) / 2.0);
        blacks = (n * m) - whites;
        // cout << blacks << " init " << whites << endl;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        //after black spill
        //check if left bottom if exact color
        if (((x3 % 2) && !(y3 % 2)) || (!(x3 % 2) && (y3 % 2)))
        {

            blocks = (x4 - x3 + 1) * (y4 - y3 + 1);
            wrongBlacks = (blocks / 2);
        }
        else
        {
            blocks = (x4 - x3 + 1) * (y4 - y3 + 1);
            wrongBlacks = ceil(blocks / 2.0);
        }
        // cout << wrongBlacks << endl;

        //after whiite spill
        //check if left bottom if exact color
        if ((!(x1 % 2) && !(y1 % 2)) || ((x1 % 2) && (y1 % 2)))
        {

            blocks = (x2 - x1 + 1) * (y2 - y1 + 1);
            //  cout << blocks << endl;
            wrongWhites = (blocks / 2);
        }
        else
        {
            blocks = (x2 - x1 + 1) * (y2 - y1 + 1);
            // cout << blocks << endl;
            wrongWhites = ceil(blocks / 2.0);
        }

        // cout << wrongWhites << endl;
        //find the overlap
        // for (int k = x3; k <= x4; k++)
        // {
        //     for (int j = y3; j <= y4; j++)
        //     {
        //         if ((k <= x2 && k >= x1) && (j <= y2 && j >= y1))
        //         {
        //             if(((k % 2) && !(j % 2)) || (!(k % 2) && (j % 2)))
        //                  wrongWhites -= 1;
        //         }
        //     }
        // }
        x5 = max(x1, x3);
        x6 = min(x2, x4);
        y5 = max(y1, y3);
        y6 = min(y2, y4);
        //check if there is overlap
        if (x5 <= x6 && y5 <= y6)
        {
            //check if lower left block is black
            cout << x5 << y5 << " " << x6 << y6 << endl;
            if (((x5 % 2) && !(y5 % 2)) || (!(x5 % 2) && (y5 % 2)))
            {

                blocks = (x6 - x5 + 1) * (y6 - y5 + 1);
                wrongWhites -= ceil(blocks / 2.0);
            }
            else
            {
                blocks = (x6 - x5 + 1) * (y6 - y5 + 1);
                wrongWhites -= (blocks / 2);
            }
        }

        cout << whites + wrongWhites - wrongBlacks << " " << blacks + wrongBlacks - wrongWhites << endl;
    }
}