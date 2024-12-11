/*
Pizza parlor accepting maximum M orders. 
-> Orders are served in first come first served basis. 
-> Order once placed cannot be cancelled.

Write C++ program to simulate the system using ----> circular queue using array.
*/

#include <iostream>
using namespace std;


class Parlor
{
    public :
        int front , back , size , length;
        int *queue;

        Parlor(int capacity)
        {
            queue = new int[capacity];
            front = back = size = 0;
            length = capacity;
        }

        void placeOrder(int val)
        {
            if(size == length)
            {
                cout<<"\nCannot take more orders..!";
                return;
            }

            queue[back] = val;
            back = (back + 1) % length;
            cout<<"\nOrder "<<val<<" placed successfully.";
            size++;
        }

        void serveOrder()
        {
            if(size == 0)
            {
                cout<<"\nDon't have any orders..!";
                return;
            }
            cout<<"\nOrder "<<queue[front]<<" is being served.";
            front = (front + 1)%length;
            size--;
        }

        void display()
        {
            if(size == 0)
            {
                cout<<"\nDon't have any orders..!";
                return;
            }

            int idx = front;
            for(int i = 0 ; i < size; i++)
            {
                cout<<queue[idx]<<" ";
                idx = (idx + 1)%length;
            }
            cout<<endl;
        }
};

int main()
{
    int maxOrder;
    cout<<"\nEnter the maximum number of orders the PIZZA PARLOR can have : ";
    cin>>maxOrder;

    Parlor q(maxOrder);

    while(true)
    {
        int ch;
        cout<<"\n1. Place an order.";
        cout<<"\n2. Serve an order.";
        cout<<"\n3. Display orders.";
        cout<<"\n4. Exit.";
        cout<<"\nChoose the correct option -> ";
        cin>>ch;
        cout<<endl;

        if(ch == 1)
        {
            int orderID;
            cout<<"\nEnter Order ID : ";
            cin>>orderID;
            q.placeOrder(orderID);
        }

        else if(ch == 2)
        {
            q.serveOrder();
        }

        else if(ch == 3)
        {
            q.display();
        }

        else if(ch == 4)
        {
            cout<<"\nExiting the system. Have a great day..!"<<endl;
            break;
        }
        else 
        {
            cout<<"\nEnter a valid Choice...!";
        }
        cout<<endl;

    }

    return 0;
}
