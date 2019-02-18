#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
#define MAX 1000000000

// 4 query not working for some reason :(
// void play()
// {
//     ll xl, yl, xu, yu, dist0, distEnd, distUpEnd, tempDist, res;
//     cout << "Q"
//          << " " << 0 << " " << 0 << endl;
//     cin >> dist0;
//     cout << "Q"
//          << " " << MAX << " " << 0 << endl;
//     cin >> distEnd;
//     tempDist = abs(dist0 + (MAX - distEnd)) / 2;
//     cout << "Q"
//          << " " << tempDist <<" " << 0 << endl;
//     cin >> yl;
//     xl = sqrt(dist0 * dist0 - yl * yl );
//     xu = MAX - sqrt(distEnd * distEnd - yl * yl );
//     cout << "Q"
//          << " " << MAX << " " << MAX << endl;
//     cin >> distUpEnd;
//     yu =  MAX - sqrt(distUpEnd * distUpEnd - (MAX - xu) * (MAX - xu));
//     cout << "A"
//          << " " << xl << " " << yl << " " << xu << " " << yu << endl;
//     cin >> res;
//     if(res != 1)
//         exit(1);
// }

// 7  query
void play()
{
    ll xl, yl, xu, yu, dist0, distBotEnd, distUpEnd, midX, midY, res, temp;
    cout << "Q"
         << " " << 0 << " " << 0 << endl;
    cin >> dist0;
    cout << "Q"
         << " " << MAX << " " << 0 << endl;
    cin >> distBotEnd;
    midX = abs(dist0 + (MAX - distBotEnd)) / 2;
    cout << "Q"
         << " " << midX <<" " << 0 << endl;
    cin >> yl;
    cout << "Q"
         << " " << midX <<" " << MAX << endl;
    cin >> temp;
    yu = MAX - temp;
    cout << "Q"
         << " " << 0 << " " << MAX << endl;
    cin >> distUpEnd;
    midY = abs(dist0 + (MAX - distUpEnd)) / 2;
    cout << "Q"
         << " " << 0 <<" " << midY << endl;
    cin >> xl;
    cout << "Q"
         << " " << MAX <<" " << midY << endl;
    cin >> temp;
    xu = MAX - temp;
    cout << "A"
         << " " << xl << " " << yl << " " << xu << " " << yu << endl;
    cin >> res;
    if(res != 1)
        exit(1);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        play();
}