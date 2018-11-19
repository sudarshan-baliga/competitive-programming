#include <iostream>
using namespace std;

int t, tr1[101], d1[101], t1, td1, t2, td2, temp;
bool truth, dare;
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> t1;
        for (int j = 0; j < t1; j++)
        {
            cin >> temp;
            tr1[temp] = 1;
        }
        cin >> td1;
        for (int j = 0; j < td1; j++)
        {
            cin >> temp;
            d1[temp] = 1;
        }
        cin >> t2;
        truth = false;
        dare = false;
        for (int j = 0; j < t2; j++)
        {
            cin >> temp;
            if (tr1[temp] != 1)
                truth = true;
        }
        cin >> td2;
        for (int j = 0; j < td2; j++)
        {
            cin >> temp;
            if (d1[temp] != 1)
                truth = true;
        }
        if (truth || dare)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
        fill_n(tr1, 101, 0);
        fill_n(d1, 101, 0);
    }
}