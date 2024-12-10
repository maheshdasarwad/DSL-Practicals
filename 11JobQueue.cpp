/*
Queues are frequently used in computer progamming and a typical example is the 
creation of a job by an operating system.
If the operating system does not use priorities, then the job are processed in 
the order they enter the system.
Write C++ program for simulating job queue.
Write functions to add job and delete job from queue.
*/

#include <iostream>
using namespace std;

class Queue
{
    string *arr;
    int front , back;
    int size , capacity;

    public :
        Queue(int x)
        {
            arr = new string[x];
            front = back = 0;
            size = 0;
            capacity = x;
        }

        ~Queue()
        {
            delete[] arr;
        }

        void addJob(string job)
        {
            if(size == capacity)
            {
                cout<<"\nQueue Overflow..!";
                return;
            }
            arr[back] = job;
            back = back + 1;
            size++;
        }

        void deleteJob()
        {
            if(size == 0)
            {
                cout<<"\nQueue Underflow..!";
                return;
            }
            cout<<"\nJob deleted = "<<arr[front];
            front = front + 1;
            size--;
        }

        void display()
        {
            if(size == 0)
            {
                cout<<"\nQueue is empty..!";
                return;
            }

            for(int i = front ; i < back  ; i++)
            {
                cout<<"\n"<<arr[i];
            }
            cout<<endl;
        }
};

int main()
{
    int val;
    cout<<"\nSize of the Queue : ";
    cin>>val;

    Queue q(val);

    while(true)
    {
        int ch;
        cout<<"\n   1. Add Job.";
        cout<<"\n   2. Delete Job.";
        cout<<"\n   3. Display Job.";
        cout<<"\n   4. Exit.";
        cout<<"\nEnter your a valid choice : ";
        cin>>ch;
        cout<<endl;

        if(ch == 1)
        {
            string job;
            cout<<"\nEnter your job : ";
            cin.ignore();
            getline(cin,job);
            q.addJob(job);
        }

        else if(ch == 2)
        {
            q.deleteJob();
        }

        else if(ch == 3)
        {
            q.display();
        }

        else if(ch == 4)
        {
            cout<<"\nExiting. Thank you..."<<endl;
            break;
        }
        
        else
        {
            cout<<"\nEntered a invalid choice.";
        }
        cout<<endl;
    }
}