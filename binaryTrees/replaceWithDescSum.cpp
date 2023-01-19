#include <iostream>
#include <queue>
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
// pre order buuild root -left-right
node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}
void levelOrderPrint(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}
node *levelOrderBuild()
{
    int d;
    cin >> d;
    node *root = new node(d);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            current->left = new node(c1);
            q.push(current->left);
        }
        if (c2 != -1)
        {
            current->right = new node(c2);
            q.push(current->right);
        }
    }
    return root;
}
int replaceWithSum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }
    // rec call
    int sl = replaceWithSum(root->left);
    int sr = replaceWithSum(root->right);

    int temp = root->data;
    root->data = sl + sr;

    return root->data + temp;
}

int main()
{
    khushi();
    node *root = levelOrderBuild();
    levelOrderPrint(root);
    cout << endl;
    replaceWithSum(root);

    levelOrderPrint(root);
    return 0;
}