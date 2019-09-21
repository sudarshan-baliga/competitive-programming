    #include <iostream>
    #include <bitset>
    #include <cstring>
    using namespace std;

    void updateOnes(int ones[][33], int idx, int val)
    {
        bitset<32> b(val);
        string bitStr = b.to_string();
        for (int i = 1; i <= 32; i++)
        {
            ones[idx][i] = ones[idx - 1][i] + (bitStr[i] == '1' ? 1 : 0);
        }
    }

    int main()
    {
        int t, n, a, ones[1002][33], ans;
        bool valid;
        cin >> t;
        while (t--)
        {
            cin >> n;
            ans = 0;
            memset(ones, 0, sizeof(int) * (n + 1) * 33);
            for (int i = 1; i <= n; i++)
            {
                cin >> a;
                updateOnes(ones, i, a);
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= 32; j++)
                    cout << ones[i][j];
                cout << endl;
            }
            for (int i = 1; i <= n - 1; i++)
            {
                valid = true;
                for (int j = 1; j <= 32; j++)
                {
                    if ((ones[i][j] % 2) != ((ones[n][j] - ones[i][j]) % 2))
                    {
                        // cout << i << j << " " << (ones[n][j]) << endl;
                        valid = false;
                        break;
                    }
                }
                if (valid){
                    cout << i << endl;
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
