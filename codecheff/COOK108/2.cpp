#include <iostream>
#include <vector>
using namespace std;

vector<long long> jumps;

void findJumps()
{
    for (int i = 1; i < 100000; i++)
        jumps.push_back( (i * i) + i);
    // for(int i = 1; i<= 4;i++)
    //     cout << (i * i) + i << endl;
    // cout << "jumps" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, cnt0, cnt1, lens, ones[100001], oneCount, zeroCount, curOnes, curZeros;
    long long ans;
    string s;
    findJumps();
    cin >> t;
    while (t--)
    {
        cin >> s;
        lens = s.length();
        ans = 0;
        ones[0] = 0;
        for (int i = 1; i <= lens; i++)
        {
            ones[i] = ones[i - 1];
            if (s[i - 1] == '1')
                ones[i]++;
            // cout << i << " " << ones[i] << endl;
        }

        //check for each case
        oneCount = 1;
        for (auto jump : jumps)
        {   
            zeroCount = jump - oneCount;
            if(jump > lens)
                break;
            // cout <<oneCount << " yy " << zeroCount << endl;
            for (int i = 1; i < lens && i + jump <= lens + 1; i += 1)
            {
                curOnes = ones[i + jump - 1] - ones[i - 1]; 
                curZeros = jump - curOnes;;
                if(curOnes == oneCount && curZeros == zeroCount) {
                    // cout << i << " " << jump + i - 1 << endl;
                    ans++;
                }
            }
            oneCount++;
        }
        cout << ans << endl;
    }
}
