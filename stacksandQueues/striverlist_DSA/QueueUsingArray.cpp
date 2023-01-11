#include <iostream>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
class Queue
{
    int size;
    int *arr;
    int front;
    int rear;
    int maxSize;

public:
    Queue()
    {
        size = 0;
        front = -1;
        rear = -1;
        arr = new int[16];
    }
    Queue(int maxSize)
    {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
        size = 0;
    }
    void push(int x)
    {
        if (size == maxSize)
        {
            cout << "FULL" << endl;
        }
        if (rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize;
            arr[rear] = x;
            cout << "new element is pushed" << endl;
            size++;
        }
    }
    int pop()
    {
        if (front == -1)
        {
            cout << "EMPTY" << endl;
        }
        int popped = arr[front];
        if (size = 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize;
            size--;
            return popped;
        }
    }
    int top()
    {
        if (front == -1)
        {
            cout << "EMPTY" << endl;
        }
        return arr[front];
    }
    int Size()
    {
        return size;
    }
};
int main()
{
    khushi();
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.Size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.Size() << endl;

    return 0;
}