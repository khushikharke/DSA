#include <iostream>
#include <deque>
#include <vector>
#include <stack>
#include <string>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        size = 1000;
        top = -1;
        arr = new int[size];
    }

    void Push(int x)
    {
        top++;
        arr[top] = x;
    }
    int Pop()
    {
        int x = arr[top];
        top--;
        return x;
    }
    int Size()
    {
        return top + 1;
    }
    int Top()
    {
        return arr[top];
    }
};
int main()
{
    khushi();
    Stack s;
    s.Push(6);
    s.Push(5);
    cout << s.Top();
    cout << s.Size();
    cout << s.Pop();
    cout << s.Size();
    return 0;
}