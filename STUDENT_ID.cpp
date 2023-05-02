#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
class node {
public:
    long long prn;
    string year;
    string name;
    string dept;
    long long reg_id; // added member variable for registration ID
    node* next;
    node() {
        next = NULL;
    }
   virtual void PRINT() {
    if (reg_id == 0) {
        // If reg_id is not set yet, generate it now
        time_t current_time = time(NULL);
        struct tm* local_time = localtime(&current_time);
        char buffer[80];
        strftime(buffer, 80, "%Y%m%d%H%M%S", local_time);
        reg_id = atoll(buffer);
    }
    cout << "REGISTRATION ID ---> " << reg_id << endl;
}

};

class stud : public node {
public:
    node* head;
    stud() {
        head = NULL;
    }
    void create();
    void display();
    void PRINT() {
        cout << "        REGISTRATION ID ---> NULL\n";
    }
};

void REG_ID(node* xyz) {
    xyz->PRINT();
}


void stud::create()
{
    string ch;
    node *temp, *p;
    do
    {
        temp = new node;
        cout<<"\n      ENTER STUDENT DETAILS \n";
        cout<<"\n_________________________________\n ";
        cout<<"\nENTER NAME         :       ";
        cin>>temp->name;
        cout<<"ENTER PRN          :       ";
        cin>>temp -> prn;
        p = head;
        while (p != NULL && p->prn != temp->prn) {
            p = p->next;
        }
        if (p != NULL) {
            // PRN already exists in the list, so delete the new node
            delete temp;
            cout<<"\n\n        **** E-R-R-O-R ****\n";
            cout << "         PRN ALREADY EXISTS.\n";
            cout<<"             TRY AGAIN \n\n";
            
            continue;
        }
        if(temp->prn > 9999999999 || temp->prn < 1000000000)
        {
            throw temp->prn;
        }
        else
        {
            cout<<"ENTER YEAR         :       ";
            cin>>temp -> year;
            cout<<"ENTER DEPARTMENT   :       ";
            cin>>temp -> dept;
            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                p = head;
                while (p-> next != NULL)
                {
                    p=p->next;
                }
                p -> next = temp;
            }
            // generate and store unique ID for the new node
            time_t current_time = time(NULL);
            struct tm* local_time = localtime(&current_time);
            char buffer[80];
            strftime(buffer, 80, "%Y%m%d%H%M%S", local_time);
            temp->reg_id = atoll(buffer);
        }
        cout<<"\n\nDO YOU WANT TO ADD ANOTHER ENTRY? (y/n)  : ";
        cin>>ch;
        cout<<"\n";
    }
    while(ch == "y"  || ch == "Y");
}



void stud::display()
{
    node *p;
    if(head == NULL)
    {
        cout<<"\nNO ENTRIES\n";
    }
    else
    {
        p=head;
        cout<<endl;
        while (p != NULL)
        {
            node *ptr_1 = p; // initialize ptr_1 to p
            cout<<"\n     **** MIT STUDENT ID ****"<<endl;
            cout<<"\n|\t NAME    : "<<p->name<<"  \t|"<<endl;
            cout<<"|\t PRN     : "<<p->prn<<"\t|"<<endl;
            cout<<"|\t YEAR    : "<<p->year<<"\t\t|"<<endl;
            cout<<"|\t DEPT    : "<<p->dept<<" \t|"<<endl;
            cout<<"\n      **********************\n"<<endl;
            REG_ID(ptr_1);
            p = p -> next;
            
        }
    }
}


int main()
{	
    node *ptr ;
    stud d;
    int flag=0;
    
    do 
    {

        flag=0;
        try
            {
                d.create();
                d.display();
                
            }
        catch(...)
            {
                flag=1;
                cout<<"\n\n        **** E-R-R-O-R ****\n";
                cout<<"    PRN SHOULD BE A 10-DIGIT NUMBER\n";
                ptr = &d;
                REG_ID(ptr);
                cout<<"             TRY AGAIN \n\n";

            }
            
    }   
    while(flag!=0);
   
}
