    #include <iostream>
    using namespace std;
    int n, c;

    int minima, maxima, cur;

    void solve()
    {
        int inp;
        while (true)
        {
            cout << 1 << " " << maxima << endl;
            cin >> inp;
            if (inp == 1)
            {
                cout << 2 << endl;
                return;
            }
            if (maxima == n)
            return;
            minima = maxima;
            maxima = minima + cur;
            if (maxima > n)
                maxima = n;
        }
    }

    int main()
    {
        bool first = true;
        cin >> n >> c;
        //tenthousand
        if (n >= 10000)
        {
            cur = 10000;
            minima = 1;
            maxima = 10000;
            solve();
            first = false;
        }
        else
        {
            minima = 1;
            maxima = 1000;
        }
        if (n >= 1000)
        {
            //thousand
            cur = 1000;
            if (!first)
                maxima = minima;
            solve();
            first = false;
        }
        else
        {
            minima = 1;
            maxima = 100;
        }
        //hundred
        if (n >= 100)
        {
            cur = 100;
            if (!first)
                maxima = minima;
            solve();
            first = false;
        }
        else
        {
            minima = 1;
            maxima = 10;
        }
        //ten
        if (n >= 10)
        {
            cur = 10;
            if (!first)
                maxima = minima;
            solve();
            first = false;
        }
        else
        {
            minima = 1;
            maxima = 1;
        }
        //1
        cur = 1;
        if (!first)
            maxima = minima;
        solve();
        cout << 3 << " " << maxima << endl;
    }