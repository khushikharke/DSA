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
node *iterRev(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *temp = NULL;
    while (curr != NULL)
    {
        // store next
        temp = curr->next;
        // update the current
        curr->next = prev;
        // one step ahead PCT
        prev = curr;
        curr = temp;
    }
    // head=prev
    // return;
    return prev;
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
    head = iterRev(head);
    printL(head);
    return 0;
}
// iterative soln takes no space as compared to recursive soln we have to use stack