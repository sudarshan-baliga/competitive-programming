    #include <iostream>
    using namespace std;

    int main()
    {
        int t, n, a, b, acount, bcount, both;
        long long temp;
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            cin >> n >> a >> b;
            acount = bcount = both = 0;
            for (int j = 0; j < n; j++)
            {
                cin >> temp;
                if (!(temp % a))
                {
                    if (!(temp % b))
                        both++;
                    else
                        acount++;
                    continue;
                }
                else if (!(temp % b))
                    bcount++;
            }
            if(both > 0)
                acount++;
            if(acount > bcount)
                cout << "BOB\n";
            else
                cout << "ALICE\n";
        }
    }