#include <iostream>
#include <algorithm>
using namespace std;

int arr[5][5][5], ans = 0;

void swap(int i, int j, int k)
{
    int a[4] = {0, 1, 2, 3}, temp;
    temp = a[1];
    a[1] = a[i];
    a[i] = temp;
    temp = a[2];
    a[2] = a[j];
    a[j] = temp;
    temp = a[3];
    a[3] = a[k];
    a[k] = temp;
    cout << a[1] << " "  << a[2] <<  " " << a[3] <<" " <<  i << j << k <<endl; 
}

int main()
{
    for (int p = 1; p < 4; p++)
        for (int q = 1; q < 4; q++)
            for (int r = 1; r < 4; r++)
                swap(p, q, r);
    cout << ans;
}
