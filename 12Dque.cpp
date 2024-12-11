/*
A double - ended queue (deque ) is a linear list in which additions and deletions 
may be made at either end.
Obtain a data representation mapping a deque into a 1D array.
Write C++ program to simulate deque with functions to add and delete elements
from either end of the deque.
*/

#include <iostream>
using namespace std;

class Deque
{
    int front, back;
    int size , capacity;
    int *arr;

    public :
        Deque(int x)
        {
            arr = new int[x];
            front = back = 0;
            size = 0;
            capacity = x;
        }

        void addFront(int val)
        {
            if(size >= capacity)
            {
                cout<<"\nDequeue Overflow..!"<<endl;
                return;
            }

            for (int i = size; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[front] = val;
            back++;
            size++;
        }

        void addEnd(int val)
        {
            if(size == capacity)
            {
                cout<<"\nDequeue Overflow..!"<<endl;
                return;
            }
            arr[back] = val;
            back++;
            size++;
        }

        void deleteFront()
        {
            if(size == 0)
            {
                cout<<"\nDequeue Underflow..!"<<endl;
                return;
            }
            for (int i = 0; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            back--;
            size--;
        }

        void deleteEnd()
        {
            if(size == 0)
            {
                cout<<"\nDequeue Underflow..!"<<endl;
                return;
            }
            back--;
            size--;
        }

        void display()
        {   if(size == 0)
            {
                cout<<"\nDequeue is Empty..!"<<endl;
                return;
            }

            cout<<"\nDeque elements : ";
            for(int i = 0 ; i < size ; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    Deque dq(6);

    dq.addEnd(10);
    dq.addEnd(20);
    dq.addEnd(30);
    dq.addEnd(40);
    dq.addEnd(50);
    dq.addFront(60);
    dq.display();

    dq.deleteEnd();
    dq.deleteFront();
    dq.display();

    dq.addEnd(10);
    dq.addEnd(20);
    dq.display();
}
