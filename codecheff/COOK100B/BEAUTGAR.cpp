#include <iostream>
using namespace std;

int main()
{
    int t, len, numG, numR;
    bool moreThan2Pairs, lenMoreThan2, bothPairSame;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        len = s.length();
        if (len == 1)
        {
            cout << "yes" << endl;
            continue;
        }
        moreThan2Pairs = lenMoreThan2 = bothPairSame = false;
        numG = numR = 0;
        for (int j = 0; j < len; j++)
        {
            if (s[j] == s[(j + 1) % len])
            {
                if (s[j] == s[(j + 2) % len])
                {
                    lenMoreThan2 = true;
                    break;
                }
                if (s[j] == 'G')
                    numG++;
                else
                    numR++;
                if (numG + numR > 2)
                {
                    moreThan2Pairs = true;
                    break;
                }
                if (numG > 1 || numR > 1)
                {
                    bothPairSame = true;
                    break;
                }
                continue;
            }
        }
        if (moreThan2Pairs || lenMoreThan2 || bothPairSame)
        {
            cout << "no" << endl;
            continue;
        }
        else
        {
            // check for len less than 4
            if (len < 4)
            {
                if (numG > 0 || numR > 0)
                {
                    cout << "no" << endl;
                }
                else
                    cout << "yes" << endl;
                continue;
            }
            //there should ne exactly two pairs or 0 pairs
            if( (numG == 1 && numR == 1) || (numG == 0 && numR == 0))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
}