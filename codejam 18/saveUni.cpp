#include<iostream>

using namespace std;

int main(){
     long long t, d, len, damage, shoot,swaps, pos, avalSwaps, usedSwaps, preShoot, prePos, uselessc;
     string s;
     cin >> t;
     for(int i = 0; i < t; i++){
         cin >> d;
         cin >> s;
         len = s.length();
         shoot = 1;
         damage = 0;
         for(int j = 0; j < len; j++){
             if(s[j] == 'S')
                damage += shoot;
            else
                shoot *= 2;
         }
         swaps = 0;
         avalSwaps = 0;
         usedSwaps = 0;
         uselessc = 0;  //c's at extreme right
         pos = len - 1;
        while(s[pos] != 'S' && pos >= 0 ){
            pos--;
           uselessc++;
           shoot /= 2;
        }
        if(damage != 0){  
        while(true){
            usedSwaps = 0;
            pos = len - 1 - uselessc;
            avalSwaps = 0;
             if(pos < 0)
                    break;
            while(s[pos] != 'C' ){
                pos--;
                avalSwaps++; //s's
                if(pos < 0)
                    break;
            }  
            preShoot = shoot / 2;
            prePos = pos;
            if(pos < 0)
                    break;
            while(pos != len - 1 - uselessc  && (damage  > d ) && avalSwaps > 0  ){
                swaps++;
                avalSwaps--;
                usedSwaps++;
                damage -= preShoot;
                pos++;
            }
            s[prePos] = 'S';

            if(pos == len - 1 - uselessc){
                uselessc++;
            }
               
            if(damage <= d || pos < 0)
                break;
            shoot /= 2;
        }
        cout <<"Case #"  <<i + 1 << ": "; 

        if(damage <= d)
            cout<< swaps << endl;
        else
            cout << "IMPOSSIBLE"  << endl;
        }
        else
            cout <<"Case #"  <<i + 1 << ": "<< swaps << endl;
     }
}
