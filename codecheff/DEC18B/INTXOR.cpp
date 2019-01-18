#include <iostream>
using namespace std;

long long t, n, a[50002], cur;

void terminator(int res)
{
    if(res == -1)
        exit(1);
}

//5
// 1 2 4
// 1 2 5
// 4 5 3
// 1 5 3
// 2 3 4
//order: 3 2 4
void findFirst5()
{
    int temp1, temp2, temp3, temp4, temp5, Temp1, Temp2;
    cout << 1 << " " << 1 << " " << 2 << " " << 4 << endl;
    cin >> temp1;
    terminator(temp1);
    cout << 1 << " " << 1 << " " << 2 << " " << 5 << endl;
    cin >> temp2;
    terminator(temp2);
    cout << 1 << " " << 4 << " " << 5 << " " << 3 << endl;
    cin >> temp3;
    terminator(temp3);
    cout << 1 << " " << 1 << " " << 5 << " " << 3 << endl;
    cin >> temp4;
    terminator(temp4);
    cout << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
    cin >> temp5;
    terminator(temp5);
    Temp1 = temp1 ^ temp2;
    a[3] = temp3 ^ Temp1;
    Temp2 = temp3 ^ temp4;
    a[2] = Temp2 ^ temp1;
    a[4] = a[2] ^ a[3] ^ temp5;
    a[1] = a[2] ^ a[4] ^ temp1;
    a[5] = a[3] ^ a[4] ^ temp3;
}

//6
// 1 2 3
// 1 2 4
// 3 4 6
// 5 6 1
// 2 5 6
// 3 4 5
//order: 6 3 4 5 1 2
void findFirst6()
{
    int temp1, temp2, temp3, temp4, temp5, temp6, Temp1, Temp2;
    cout << 1 << " " << 1 << " " << 2 << " " << 3 << endl;
    cin >> temp1;
    terminator(temp1);
    cout << 1 << " " << 1 << " " << 2 << " " << 4 << endl;
    cin >> temp2;
    terminator(temp2);
    cout << 1 << " " << 3 << " " << 4 << " " << 6 << endl;
    cin >> temp3;
    terminator(temp3);
    cout << 1 << " " << 5 << " " << 6 << " " << 1 << endl;
    cin >> temp4;
    terminator(temp4);
    cout << 1 << " " << 2 << " " << 5 << " " << 6 << endl;
    cin >> temp5;
    terminator(temp5);
    cout << 1 << " " << 3 << " " << 4 << " " << 5 << endl;
    cin >> temp6;
    terminator(temp6);
    Temp1 = temp1 ^ temp2;
    a[6] = temp3 ^ Temp1;
    Temp2 = temp4 ^ temp5;
    a[3] = Temp2 ^ temp1;
    a[4] = Temp2 ^ temp2;
    a[5] = a[3] ^ a[4] ^ temp6;
    a[1] = a[5] ^ a[6] ^ temp4;
    a[2] = a[5] ^ a[6] ^ temp5;
}

//7
// 1 2 3
// 1 2 4
// 3 4 6
// 5 7 1
// 5 7 2
// 3 5 6
// 7 6 4
//order: 6 3 4 5 7 1 2
void findFirst7()
{
    int temp1, temp2, temp3, temp4, temp5, temp6, temp7, Temp1, Temp2;
    cout << 1 << " " << 1 << " " << 2 << " " << 3 << endl;
    cin >> temp1;
    terminator(temp1);
    cout << 1 << " " << 1 << " " << 2 << " " << 4 << endl;
    cin >> temp2;
    terminator(temp2);
    cout << 1 << " " << 3 << " " << 4 << " " << 6 << endl;
    cin >> temp3;
    terminator(temp3);
    cout << 1 << " " << 5 << " " << 7 << " " << 1 << endl;
    cin >> temp4;
    terminator(temp4);
    cout << 1 << " " << 5 << " " << 7 << " " << 2 << endl;
    cin >> temp5;
    terminator(temp5);
    cout << 1 << " " << 3 << " " << 5 << " " << 6 << endl;
    cin >> temp6;
    terminator(temp6);
    cout << 1 << " " << 7 << " " << 6 << " " << 4 << endl;
    cin >> temp7;
    terminator(temp7);
    Temp1 = temp1 ^ temp2;
    a[6] = temp3 ^ Temp1;
    Temp2 = temp4 ^ temp5;
    a[3] = Temp2 ^ temp1;
    a[4] = Temp2 ^ temp2;
    a[5] = a[3] ^ a[6] ^ temp6;
    a[7] = a[6] ^ a[4] ^ temp7;
    a[1] = a[5] ^ a[7] ^ temp4;
    a[2] = a[5] ^ a[7] ^ temp5;
}

void solve()
{
    int temp1, temp2, temp3, temp4, res;
    cin >> n;
    cur = 1;
    if (n % 4 == 1)
    {
        findFirst5();
        cur = 6;
    }
    else if (n % 4 == 2)
    {
        findFirst6();
        cur = 7;
    }
    else if (n % 4 == 3)
    {
        findFirst7();
        cur = 8;
    }
    //find remaining in set of four
    for (int i = cur; i + 3 <= n; i+=4)
    {
        cout << 1 << " " << i << " " << i + 1 << " " << i + 2 << endl;
        cin >> temp1;
        terminator(temp1);
        cout << 1 << " " << i << " " << i + 1 << " " << i + 3 << endl;
        cin >> temp2;
        terminator(temp2);
        cout << 1 << " " << i << " " << i + 2 << " " << i + 3 << endl;
        cin >> temp3;
        terminator(temp3);
        cout << 1 << " " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
        cin >> temp4;
        terminator(temp4);
        a[i] = temp1 ^ temp2 ^ temp3;
        a[i + 1] = temp1 ^ temp2 ^ temp4;
        a[i + 2] = temp1 ^ temp3 ^ temp4;
        a[i + 3] = temp2 ^ temp3 ^ temp4;
    }
    cout << 2 << " ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    cin >> res;
    if (res == 1)
        return;
    exit(1);
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}
