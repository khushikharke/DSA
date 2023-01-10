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

node *kRev(node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    // reverse rec only the k sized ll
    node *curr = head;
    node *prev = NULL;
    node *temp = NULL;
    int count = 1;
    while (curr != NULL and count <= k)
    {
        // store next
        temp = curr->next;
        // update the current
        curr->next = prev;
        // one step ahead PCT
        prev = curr;
        curr = temp;
        count++;
    }

    if (temp != NULL)
    {
        head->next = kRev(temp, k);
    }
    return prev;
}
int main()
{
    khushi();
    node *head = NULL;
    insertHead(head, 8);
    insertHead(head, 7);
    insertHead(head, 6);
    insertHead(head, 5);
    insertHead(head, 4);
    insertHead(head, 3);
    insertHead(head, 2);
    insertHead(head, 1);
    insertHead(head, 0);

    printL(head);
    head = kRev(head, 3);
    printL(head);
    return 0;
}