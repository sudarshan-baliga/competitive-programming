#include <iostream>
using namespace std;
int req[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int getSticks(int x)
{
    int sticks = 0, rem;
    while (x)
    {
        rem = x % 10;
        x = x / 10;
        sticks += req[rem];
    }
    return sticks;
}

int main()
{
    int a, b, t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << getSticks(a + b) << endl;
    }
}