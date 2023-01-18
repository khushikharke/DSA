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

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
}

int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    return max(D1, max(D2, D3));
}

class HDpair
{
public:
    int height;
    int diameter;
};
// returns height and diameter at each step
HDpair optdiameter(node *root)
{
    HDpair p;
    if (root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }
    HDpair left = optdiameter(root->left);
    HDpair right = optdiameter(root->right);
    p.height = max(left.height, right.height) + 1;

    int D1 = left.height + right.height;
    int D2 = left.diameter;
    int D3 = right.diameter;
    p.diameter = max(D1, max(D2, D3));
    return p;
}

int main()
{
    khushi();

    node *root = levelOrderBuild();
    levelOrderPrint(root);
    cout << "diameter is " << diameter(root) << endl;
    cout << "optimized diameter is" << optdiameter(root).diameter << endl;
    return 0;
}