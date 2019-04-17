#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int foodRequirement[] = {0,1,2,0,2,1,0}, cur, today, count, best, weeks;
    long long food[3], tempFood[3];
    cin >> food[0] >> food[1] >> food[2];
    weeks = min({food[0] / 3, food[1] / 2, food[2] / 3});
    food[0] -= 3 * weeks;
    food[1] -= 2 * weeks;
    food[2] -= 2 * weeks;
    tempFood[0] = food[0];
    tempFood[1] = food[1];
    tempFood[2] = food[2];
    best = -1;
    for(cur = 0; cur < 7; cur++)
    {
        today = cur;
        count = 0;
        while(true)
        {
            if(food[foodRequirement[today]] == 0)
            {
                break;
            }
            else
                food[foodRequirement[today]] -= 1;
            today = (today + 1) % 7;
            count++;
        }
        food[0] = tempFood[0];
        food[1] = tempFood[1];
        food[2] = tempFood[2];
        best = max(best, count);
    }
    cout << best + 7 * weeks << endl;
}