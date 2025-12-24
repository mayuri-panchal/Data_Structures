// Singly Circular

#include<iostream>

using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCL
{
    private :
        PNODE first;
        PNODE last;
        int iCount;

    public :
        SinglyCL()
        {
            cout<<"Object of SinglyCL gets created\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                this->first = newn;
                this->last = newn;
            }
            else
            {
                newn -> next = this->first;
                this->first = newn;
            }

            this->last -> next = this->first;

            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                this->first = newn;
            }
            else
            {  
                this->last -> next = newn;
                this->last = newn;
            }

            this->last -> next = this->first;
            
            this->iCount++;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->last;
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                temp = this->first;
                
                while(temp -> next != last)
                {
                    temp = temp -> next;
                }
                delete last;
                last = temp;
                this->last -> next = this->first;
            }

            this->iCount--;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                temp = this->first;
                this->first = this->first -> next;
                delete temp;
                this->last -> next = this->first;
            }

            this->iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = this->first;
            for(int iCnt = 1; iCnt <= this->iCount; iCnt++)
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp -> next;
            }
        }

        int Count()
        {
            return this->iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            
            int iCnt = 0;

            if(pos < 1 || pos > this->iCount+1)
            {
                cout<<"Invalid position";
                return;
            }

            if(pos == 1)
            {
                this->InsertFirst(no);
            }
            else if(pos == this->iCount+1)
            {
                this->InsertLast(no);
            }
            else
            {
                newn = new NODE;
                newn -> data = no;
                newn -> next = NULL;

                temp = this->first;

                for(iCnt = 1; iCnt < (pos-1); iCnt++)
                {
                    temp = temp -> next;
                }
                
                newn -> next = temp -> next;
                temp -> next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            
            int iCnt = 0;

            if(pos < 1 || pos > this->iCount)
            {
                cout<<"Invalid position";
                return;
            }

            if(pos == 1)
            {
                this->DeleteFirst();
            }
            else if(pos == this->iCount)
            {
                this->DeleteLast();
            }
            else
            {
                temp = this->first;

                for(iCnt = 1; iCnt < (pos-1); iCnt++)
                {
                    temp = temp -> next;
                }
                
                target = temp -> next;
                temp -> next = target -> next;
                delete target;
        
                iCount--;
            }
        }

};

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(150,3);

    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    return 0;
}