 #include<iostream>
    #include<algorithm>
     
    using namespace std;
    long long t, n, h, a[100000], beg, _end, mid;
     
    bool devide( long long mid){
        long long count = 0;
        for(int j = 0; j < n; j++){
            count += a[j] / mid;
            count += a[j] % mid > 0 ? 1 : 0;
            if(count > h) 
                return 0;
        }
        //cout << count << "ff" <<endl;
        return 1;
    }
     
    int main(){
        
        bool flag;
        cin >> t;
        for(int i = 0; i < t; i++){
            cin >> n >> h;
            for(int j = 0; j < n;j++)
                cin >> a[j];
            beg = 1;
            _end = *max_element(a, a + n);
            while( beg <= _end ){
              
                mid = (beg + _end) / 2;
                if(devide(mid)){
                     if(beg == _end){
                        //cout << "f";
                        mid = beg; 
                        break;
                    }
                    //cout << mid << "end" << _end;
                    _end = mid;
                }   
                else
                    beg = mid + 1; 
            }
            cout << mid << endl;
        }
    } 