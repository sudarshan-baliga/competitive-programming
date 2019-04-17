#include <iostream>
typedef long long ll;
using namespace std;

int main()
{
    ll cnt1, cnt2, cnt3, cnt4;
    bool fail = false;
    cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;
    if(cnt1 != cnt4 || (cnt1 == 0 && cnt2 == 0 && cnt3 != 0))
        cout << "0" << endl;
    else
        cout << "1" << endl;
    
}