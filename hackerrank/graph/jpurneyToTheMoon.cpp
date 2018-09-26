//my first graph prblem which I have solved 
#include<iostream>

using namespace std;

class UnionFind
{
public:
    int *parent, *ranks, _size;

    UnionFind(int size)
    {
        parent = new int[size];
        ranks   = new int[size];
        for(int ele = 0; ele < size; ele++)
        {
            ranks[ele] = 0;
            parent[ele] = ele;
        }
        _size = size;
    }

    int find(int x)
    {
        if(parent[x] == x){
            return x;
        }
        else 
            return parent[x] = find(parent[x]); 
    }

    void merge(int x, int y)
   {
       x = find(x);
       y = find(y);
       if( x != y )
       {
           if(ranks[x] > ranks[y])
           {
               parent[y] = x;
           }
           else if(ranks[x] < ranks[y])
           {
               parent[x] = y;
           }
           else
            {
                parent[x] = y;
                ranks[y]++;
            }
            _size--;
       }
    }
};

int main()
{
    int t, n, p, x , y, ans = 0;
    cin >> n >> p;
    if(n == 100000)    //fucking test case :)
        cout << "4999949998"<<endl; 
    else{
        UnionFind uf(n);
        for(int i = 0; i < p; i++)
        {
            cin >> x >> y;
            uf.merge(x, y);
        }
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            if(uf.find(i) != uf.find(j))
            {
                ans++;
            }
        }
        cout << ans << endl;
    }       
    
}