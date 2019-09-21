#include <iostream>
using  namespace std;
#define debug(x) cout << #x <<" " <<  x << endl;


template<typename T>
void check(T a, T b) 
{
    cout << sizeof(a) << endl;
}


int main() {
   int *a, *b;
   int c = 10, d = 101;
   b = &c;
   a = b;
   cout << *a << endl;
   c = 11;
   b =  &d;
   cout << *a << endl;
}