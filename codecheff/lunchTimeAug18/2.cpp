#include <iostream>
using namespace std;

int main()
{
    int t, n, m, count;
    bool incorrect, notwrong;
    string expected, output;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        incorrect = notwrong = false;
        for (int j = 0; j < n; j++)
        {
            cin >> expected >> output;
            if (expected == "correct")
            {
                for (int k = 0; k < m; k++)
                    if (output[k] == '0')
                    {
                        incorrect = true;
                        break;
                    }
            }
            else if (expected == "wrong")
            {
                count = 0;
                for (int k = 0; k < m; k++)
                    if (output[k] == '1')
                    {
                        count++;
                    }
                cout << count << " count" << endl;
                if (count == output.length())
                    notwrong = true;
            }
        }
        if (incorrect)
            cout << "INVALID" << endl;
        else if (notwrong)
            cout << "WEAK" << endl;
        else
            cout << "FINE" << endl;
    }
}