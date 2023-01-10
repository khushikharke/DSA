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
node *midfinder(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL or fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *mergeSort(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *mid = midfinder(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a, b);
}
int main()
{
    khushi();
    node *a = NULL;
    insertHead(a, 10);
    insertHead(a, 7);
    insertHead(a, 5);
    insertHead(a, 1);
    insertHead(a, 17);
    insertHead(a, 2);
    insertHead(a, 14);
    printL(a);

    a = mergeSort(a);

    printL(a);
    return 0;
}