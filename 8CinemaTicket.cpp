/*
The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row.
""Doubly circular linked list"" has to be maintained to keep track of free seats at rows. 
--> Assume some random booking to start with. 
--> Use array to store pointers(Head pointer)to each row. 
On demand
a) The list of available seats is to be displayed.
b) The seats are to be booked.
c) The booking can be cancelled.
*/

#include <iostream>
using namespace std;

class seat 
{
    public :
    seat *next;
    seat *prev;
    int seatNo;
    bool isBooked;

    seat(int num) 
    {
        seatNo = num;
        isBooked = false;
        next = prev = NULL; 
    }
};

class Cinema 
{
    private :
        seat *head;
        seat *tail;
    public :
        Cinema()
        {
            head = tail = NULL;
        }

        void addSeat(int num) 
        {
            seat *newSeat = new seat(num);
            if(head == NULL) 
            {
                head = tail = newSeat;
                head -> next = head;
                head -> prev = head;
            }
            else 
            {
                tail -> next = newSeat;
                newSeat -> prev = tail;
                newSeat -> next = head;
                head -> prev = newSeat;
                tail = newSeat;
            }
        }

        //initialize a row with 7 seats
        void initializeRow(int seats)
        {
            for(int i = 0 ; i < seats ; i++)
            {
                addSeat(i);
            }
        }

        void displayRow() 
        {
            seat *temp = head;
            do
            {
                if(temp -> isBooked == true)
                    cout<<"|_B_|";
                else
                    cout<<"|_"<<temp->seatNo<<"_|";
                temp = temp -> next;
            } while(temp != head);
            cout<<endl;
        }

        bool bookSeat(int seatNo) 
        {
            seat *temp = head;
            do
            {
                if(temp -> seatNo == seatNo)
                {
                    if(temp -> isBooked != true)
                    {
                        temp -> isBooked = true;
                        cout<<"\nSeat "<<seatNo<<" booked successfully."<<endl;
                        return true;
                    }
                     else
                    {
                        cout<<"\nSeat "<<seatNo<<" is already booked."<<endl;
                        return false;
                    }

                }
                temp = temp -> next;
            } while(temp != head);

            cout<<"\nInvalid seat number.";
            return false;
        }

        bool cancelSeat(int seatNo)
        {
            seat *temp = head;
            do
            {
                if(temp->seatNo == seatNo)
                {
                    if(temp -> isBooked)
                    {
                        temp -> isBooked = false;
                        cout<<"\nBooking for seat "<<seatNo<<" cancelled."<<endl;
                        return true;
                    }
                    else
                    {
                        cout<<"\nSeat "<<seatNo<<" is not booked."<<endl;
                        return false;
                    }
                }
                temp = temp -> next;
            } while(temp != head);

            cout<<"\nInvalid seat Number.";
            return false;
        }

};


int main()
{
    Cinema rows[10]; //Array to store head pointer for each row

    //Initialize all rows with 7 seats
    for(int i = 0 ; i < 10; i++)
    {
        rows[i].initializeRow(7);
    }

    while(true)
    {
        int choice , r , seat;
        cout<<"\n----------INOX Theater----------";
        cout<<"\n1.To Display seating arrangement";
        cout<<"\n2.To Book a seat";
        cout<<"\n3.To Cancel a booking";
        cout<<"\n4.To Exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;

        if(choice == 1) 
        {
            for (int i = 0; i < 10; i++)
            {
                cout << "Row " << i + 1 << ": ";
                rows[i].displayRow();
            }
        }
        else if(choice == 2) 
        {
            cout<<"\nEnter Row Number[1-10] : ";
            cin>>r;
            cout<<"Enter Seat Number[0-6] : ";
            cin>>seat;
            if(r >= 1 && r <= 10)
                rows[r-1].bookSeat(seat);
            else
                cout<<"Invalid row number.";
        }

        else if(choice == 3)
        {
            cout<<"\nEnter Row Number[1-10] : ";
            cin>>r;
            cout<<"Enter Seat Number[0-6] : ";
            cin>>seat;
            if(r >= 1 && r <= 10)
                rows[r-1].cancelSeat(seat);
            else
                cout<<"Invalid row number.";
        }

        else if(choice == 4)
        {
            cout<<"\nExiting. Thank you...!";
            break;
        }
        else 
        {
            cout<<"\nEntered Invalid choice..!"<<endl;
        }
    }

    return 0;
}

