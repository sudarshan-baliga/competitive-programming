// https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor/0
#include <iostream>
#include <cstring>
using namespace std;

long long answers[71];
void findAnswer()
{
    answers[1] = 1;
    answers[2] = 2;
    for(int i = 3; i<= 70; i++)
        answers[i] = answers[i - 1] + answers[i - 2];
}

int main() {
	//code
    int t, w;
    cin >> t;
    findAnswer();
    while(t--) {
        cin >> w;
        cout << answers[w] << endl; 
    }
}