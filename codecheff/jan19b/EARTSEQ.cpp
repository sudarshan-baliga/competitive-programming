#include <iostream>
#include <vector>
using namespace std;

int n, t, count;
long long temp;
vector<pair<long long, long long>> seq;
bool visited[1000001];

void genPrime()
{
    int prev;
    for (long long i = 2; i * i <= 1000001; i++)
    {
        if (!visited[i])
        {
            for (long long j = i * i; j <= 1000001; j += i)
                visited[j] = true;
        }
    }
    count = 0;
    int inc = 1;
    while (count < 50001)
    {
        prev = 2;
        for (long long i = inc; i < 1000001; i += inc)
            if (!visited[i])
            {
                temp = prev * i;
                if (temp <= 1000000000)
                {
                    seq.push_back(make_pair(temp, i));
                    prev = i;
                    count++;
                }
                else
                    break;
            }
        inc++;
        // cout << count << endl;
    }
}

int main()
{
    const clock_t begin_time = clock();
    genPrime();
    vector<pair<long long, long long>>::iterator prm;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        count = 0;
        for (prm = seq.begin() + 1; count != n - 1; count++, prm++)
            cout << prm->first << " ";
        cout << 2 * (--prm)->second << endl;
    }
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
}