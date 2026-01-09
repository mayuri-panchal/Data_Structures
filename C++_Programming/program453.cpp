// Doubly Linear

#include<iostream>

using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
    private :
        PNODE first;
        int iCount;

    public :
        DoublyLL()
        {
            cout<<"Object of DoublyLL gets created\n";
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                newn->next = this->first;
                this->first->prev = newn;
                this->first = newn;
            }
            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                temp = this->first;

                while(temp->next != NULL)
                {
                    temp = temp -> next;
                }
                temp->next = newn;
                newn->prev = temp;
            }
            this->iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
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

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = this->first;

                for(iCnt = 1; iCnt < (pos-1); iCnt++)
                {
                    temp = temp -> next;
                }
                newn->next = temp->next;
                temp->next->prev = newn;
                temp->next = newn;
                newn->prev = temp;

                this->iCount++;
            }
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(this->first == NULL)
            {
                return;
            }
            else if(this->first->next == NULL)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                temp = this->first;

                this->first = this->first->next;
                this->first->prev = NULL;
                delete temp;
            }

            this->iCount--;
        }

        void DeleteLast()
        {
             PNODE temp = NULL;

            if(this->first == NULL)
            {
                return;
            }
            else if(this->first->next == NULL)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                temp = this->first;

                while(temp->next->next != NULL)
                {
                    temp = temp -> next;
                }
                delete temp -> next;
                temp -> next = NULL;
            }

            this->iCount--;
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
                target->next->prev = temp;
                delete target;
                
                this->iCount--;
            }
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = this->first;

            cout<<"NULL ";
            while(temp != NULL)
            {
                cout<<" <=> | "<<temp->data<<" |";
                temp = temp -> next;
            }
            cout<<" NULL";
        }

        int Count()
        {
            return iCount;
        }

};

int main()
{
    DoublyLL obj;
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