/*
Department of computer engineering has student club named " Pinnacle Club ".

Students of second, third and final year of department can be granted membership on request.

Similarly one may cancel the membership of club. 
First node is reserved for president of club and 
last node is reserved for secretary of club.

Write C++ program to maintain club member's information using singly linked list .
Store student PRN and Name.

Write function to :
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members 
d) Two linked list exists for two divisons. Concatenate two lists.

*/



#include <iostream>
#include <string>
using namespace std;

class student
{
    public :
        double prn;
        string name;
        student *next;

        student (string name , double prn)
        {
            this -> name = name;
            this -> prn = prn;
            next = nullptr;
        }
};

class PinnacleClub
{
    private :
        student *president;
        student *secretary;
        int len;

    public :
        PinnacleClub()
        {
            president = secretary = NULL;
            len = 0;
        }

        void display()
        {
            if (president == nullptr) //if list is empty
            {
                cout << "\nList is empty.\n";
                return;
            }
            
            student *temp = president;
            while(temp != nullptr)
            {
                cout<<temp -> name <<" "<<temp -> prn<<endl;
                temp = temp -> next;
            }
            cout<<endl;
        }

        void addpresident(string val , double prno)
        {
            student *newMem = new student(val , prno);
            if(president == NULL) //if list is empty
            {
                president = secretary = newMem;
                len++;
                return;
            }
            newMem -> next = president;
            president = newMem;
            len++;
        }

        void addsecretary(string val , double prno)
        {
            student *newMem = new student(val, prno);
            if(president == NULL) //if list is empty
            {
                president = secretary = newMem;
                len++;
                return;
            }
            secretary -> next = newMem;
            secretary = newMem;
            len++;
        }

        void addMember(string val , double prno)
        {
            student *newMem = new student(val , prno);
            if(president == NULL) //if list is empty
            {
                president = secretary = newMem;
                len++;
                return;
            }
            if (president == secretary) //if list has only president
            {
                president->next = newMem;
                newMem->next = secretary;
                len++;
                return;
            }
            student *temp = president; //normal case
            while(temp -> next != secretary)
            {
                temp = temp -> next;
            }
            newMem -> next = temp -> next;
            temp -> next = newMem;
            len++;
        }

        void deleteMember(double prno)
        {
            if(president == NULL)//case 1 : empty list
            {
                cout<<"\nList is empty";
                return;
            }

            student *temp = president;
            if(temp -> prn == prno) //case 2 : if prn is president
            {
                //Deleting president
                president = president -> next;
                delete temp;
                len--;
                cout<<"\nPresident removed.";
                return;
            }

            while(temp -> next != NULL && temp -> next -> prn != prno)
            {
                temp = temp -> next;
            }

            if(temp -> next == NULL) cout<<"\nMember not found.";
            else
            {
                student *toDelete = temp -> next;
                if(toDelete == secretary) //case 3 : if prn is secretary
                {
                    secretary = temp;
                    cout<<"\nSecretary ";
                }
                temp -> next = toDelete -> next;
                delete toDelete;
                len--;
                cout<<"Removed successfully";
            }
        }

        int totalMember()
        {
            return len;
        }

        void concatenate(PinnacleClub &club2)
        {
            if(secretary != NULL) 
            {
                secretary -> next = club2.president;
                secretary = club2.secretary;
                cout<<"\nConcatenation Successfull.";
            }
        }
};

int main()
{
    
    PinnacleClub club1 , club2;

    while(true)
    {
        int ch;
        cout<<"\n1. To Add President.";
        cout<<"\n2. To Add Secretary.";
        cout<<"\n3. To Add Member.";
        cout<<"\n4. To display members.";
        cout<<"\n5. To remove members.";
        cout<<"\n6. To Know total members.";
        cout<<"\n7. To Concatenate clubs.";
        cout<<"\n8. To Exit";
        cout<<"\nChoose correct option : ";
        cin>>ch;
        cout<<endl;

        if(ch == 1)
        {
            string val;
            double prno;
            cout<<"\nEnter Name : ";
            cin.ignore();
            getline(cin,val);
            cout<<"Enter PRN number : ";
            cin>>prno;

            club1.addpresident(val,prno);

        }

        else if(ch == 2)
        {
            string val;
            double prno;
            cout<<"\nEnter name : ";
            cin.ignore();
            getline(cin,val);
            cout<<"Enter PRN number : ";
            cin>>prno;
            club1.addsecretary(val,prno);
        }

        else if(ch == 3)
        {
            string val;
            double prno;
            cout<<"\nEnter name : ";
            cin.ignore();
            getline(cin,val);
            cout<<"Enter PRN number : ";
            cin>>prno;

            club1.addMember(val,prno);  
        }

        else if(ch == 4)
        {
            club1.display();
            cout<<endl;
        }

        else if(ch == 5)
        {
            double prno;
            cout<<"\nEnter PRN number of member : ";
            cin>>prno;
            club1.deleteMember(prno);
            cout<<endl;
        }
        else if(ch == 6)
        {
            cout<<"Total Number of members = "<<club1.totalMember();
            cout<<endl;
        }

        else if(ch == 7)
        {
            int n;
            cout<<"\nEnter the number of members : ";
            cin>>n;

            for(int i = 0 ; i < n ; i++)
            {
                string val;
                double prno;
                cout<<"\nEnter name : ";
                cin.ignore();
                getline(cin,val);
                cout<<"Enter PRN number : ";
                cin>>prno;

                club2.addsecretary(val,prno);
            }
            club1.concatenate(club2);
        }

        else if(ch == 8)
        {
            cout<<"\nExited successfully.....";
            break;
        }

        else cout<<"\nEnter valid option.!!";
    }

    return 0;
}
