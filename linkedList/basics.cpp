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
void insertMiddle(node *&head, int data, int pos)
{
    if (pos == 0)
    {
        insertHead(head, data);
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        // imp

        node *N = new node(data);
        N->next = temp->next;
        temp->next = N;
    }
}

void printL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    khushi();
    node *head = NULL;
    insertHead(head, 4);
    insertHead(head, 2);
    insertHead(head, 10);
    insertMiddle(head, 100, 2);
    printL(head);

    return 0;
}