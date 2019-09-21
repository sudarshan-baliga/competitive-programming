#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

Node* newNode(int data)
{
    Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
}

void insertNode(Node **head,int data)
{
    Node *node = newNode(data);
    if(!*head) {
     *head = node;
     return;
    }
    if(data <= (*head)->data)
    {
        node->next = *head;
        *head = node;
        return;
    }
    Node *cur, *prev;
    cur = *head;
    while(cur != NULL)
    {
        if(cur->data >= data)
        {
            node->next = cur;
            prev->next = node;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    prev->next = node;
    return;
}

void printList(Node *head) {
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main()
{
    Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 0);
    insertNode(&head, 4);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 5);
    printList(head);
}