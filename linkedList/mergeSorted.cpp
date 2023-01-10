#include <iostream>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void printL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}
void insertHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}

node *merge(node *first, node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    node *temp;
    if (first->data < second->data)
    {
        temp = first;
        temp->next = merge(first->next, second);
    }
    else
    {
        temp = second;
        temp->next = merge(first, second->next);
    }
    return temp;
}
int main()
{
    khushi();
    node *first = NULL;
    insertHead(first, 10);
    insertHead(first, 7);
    insertHead(first, 5);
    insertHead(first, 1);

    node *second = NULL;
    insertHead(second, 6);
    insertHead(second, 3);
    insertHead(second, 2);

    node *head = merge(first, second);

    printL(head);
    return 0;
}