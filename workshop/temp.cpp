#include <iostream>
#include <map>
using namespace std;

int main()
{
    int a[] = {1,9,2,-9, -2, -1, -1};
    map<int, int> dic;
    int sum = 0;
    for(int i = 0; i < 4; i++)
    {
        sum += a[i];
        if(dic[sum] != 0 || sum == 0) {
            cout << dic[sum] << " " << i << endl;
            break;
            }

        else 
            dic[sum] = i;
    }
}