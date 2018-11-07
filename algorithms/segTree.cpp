/*
   1)the tree is full binary tree so total internal node = n -1 && total node = 2 * n - 1
   2)for node at i left child =  2 * i and right child = 2 * i + 1 and parent = i - 1 /2
   3)height = log2(n)
   4)Time Complexity for tree construction is O(n). There are total 2n-1 nodes, 
   and value of every node is calculated only once in tree construction.
   5)Time complexity to query is O(Logn). To query a sum, 
   we process at most four nodes at every level and number of levels is O(Logn).
   6)The time complexity of update is also O(Logn). To update a leaf value, 
   we process one node at every level and number of levels is O(Logn).
*/

#include <iostream>
using namespace std;

int n, a[10000], tree[10000], ch;

//for constructing the segementation tree
void build(int node, int start, int end)
{
    if (start == end)
    {
        // Leaf node will have a single element
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2 * node, start, mid);
        // Recurse on the right child
        build(2 * node + 1, mid + 1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

//for updating the seg tree
void update(int node, int start, int end, int idx, int val)
{
    // if it is a leaf then just update
    if (start == end)
    {
        a[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2 * node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

//answer the query
int query(int node, int start, int end, int l, int r)
{
    //if the current nodes range is outside the required range
    if (l > end || r < start)
    {
        return 0;
    }
    // if the current nodes range is inside the required range
    if (start >= l && end <= r)
    {
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

int main()
{

    cout << "program to find sum of elements in range\n";
    cout << "enter the number of elements" << endl;
    cin >> n;
    cout << "Enter the elements\n";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    //build the segment tree
    build(1, 1, n);
    while (true)
    {
        cout << "enter 1) Update 2) query 3) exit \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the index and value\n";
            int idx, val;
            cin >> idx >> val;
            update(1, 1, n, idx, val);
            break;
        case 2:
            cout << "Enter the left and right limit\n";
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid input \n";
            break;
        }
    }
}