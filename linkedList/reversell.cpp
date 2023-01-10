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
node *recReverseLl(node *head)
{

    if (head == NULL or head->next == NULL /* condition */)
    {
        return head;
    }

    node *smallHead = recReverseLl(head->next);

    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

int main()
{
    khushi();
    node *head = NULL;
    insertHead(head, 4);
    insertHead(head, 3);
    insertHead(head, 2);
    insertHead(head, 1);
    printL(head);
    head = recReverseLl(head);
    printL(head);
    return 0;
}