#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node *newNode(int data)
{
  struct Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}
void serialize(Node *root, vector<int> &);
Node *deSerialize(vector<int> &);
/* Computes the number of nodes in a tree. */
int height(struct Node *node)
{
  if (node == NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    map<int, Node *> m;
    int n;
    scanf("%d", &n);
    int N = n;
    struct Node *root = NULL;
    struct Node *child;
    while (n--)
    {
      Node *parent;
      char lr;
      int n1, n2;
      scanf("%d %d %c", &n1, &n2, &lr);
      if (m.find(n1) == m.end())
      {
        parent = newNode(n1);
        m[n1] = parent;
        if (root == NULL)
          root = parent;
      }
      else
        parent = m[n1];
      child = newNode(n2);
      if (lr == 'L')
        parent->left = child;
      else
        parent->right = child;
      m[n2] = child;
    }
    vector<int> A;
    A.clear();
    serialize(root, A);
    //  for(int i=0;i<A.size();i++)
    //    cout<<A[i]<<" ";
    //  cout<<endl;
    // inorder(root);
    //cout<<endl;
    Node *tree_made = deSerialize(A);
    inorder(tree_made);
    cout << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*this  function serializes 
the binary tree and stores 
it in the vector A*/
void serialize(Node *root, vector<int> &A)
{
  queue<Node *> q;
  q.push(root);
  A.push_back(root->data);
  while (!q.empty())
  {
    Node *cur = q.front();
    q.pop();
    if (cur->left)
    {
      q.push(cur->left);
      A.push_back(cur->left->data);
    }
    else
      A.push_back(-1);
    if (cur->right)
    {
      q.push(cur->right);
      A.push_back(cur->right->data);
    }
    else
      A.push_back(-1);
  }
}
/*this function deserializes
 the serialized vector A*/
Node *deSerialize(vector<int> &A)
{
  //Your code here
  Node *root;
  if (A[0] != -1)
    root = newNode(A[0]);
  else
    root = NULL;
  queue<Node *> q;
  q.push(root);
  int i = 0;
  while (!q.empty())
  {
    Node *t = q.front();
    q.pop();
    if (A[i + 1] != -1)
    {
      t->left = newNode(A[i + 1]);
      q.push(t->left);
    }
    else
      t->left = NULL;

    if (A[i + 2] != -1)
    {
      t->right = newNode(A[i + 2]);
      q.push(t->right);
    }
    else
      t->right = NULL;

    i += 2;
  }
  return root;
}