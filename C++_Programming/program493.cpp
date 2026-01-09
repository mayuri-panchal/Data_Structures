///////////////////////////////////////////////////////////////////
// Final Code of Doubly Circular Linked list using Generic Approach
///////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

#pragma pack(1)
template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode <T> * next;
        DoublyCLLnode <T> * prev;

    DoublyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyCLL
{
    private :
        DoublyCLLnode <T> * first;
        DoublyCLLnode <T> * last;
        int iCount;

    public :
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
       

};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of DoublyCLL gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode <T> * newn = NULL;

    newn = new DoublyCLLnode <T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode <T> * newn = NULL;

    newn = new DoublyCLLnode <T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn -> prev = last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode <T> * newn = NULL;
    DoublyCLLnode <T> * temp = NULL;
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
        newn = new DoublyCLLnode <T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        this->iCount++;
    }
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    DoublyCLLnode <T> * temp = NULL;

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
        this->first = this->first->next;
        delete temp;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    DoublyCLLnode <T> * temp = NULL;
    
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
        temp = this->last;
        this->last = this->last->prev;
        delete temp;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode <T> * temp = NULL;
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

        temp -> next = temp -> next -> next;
        delete temp->next->prev;
        temp -> next -> prev = temp;

        this->iCount--;
    }
}

template <class T>
void DoublyCLL<T>::Display()
{
    DoublyCLLnode <T> * temp = NULL;

    temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" | <->";
        temp = temp->next;

    }while(temp != this->last->next);
}

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

int main()
{
    DoublyCLL<double> *dcobj = new DoublyCLL<double>();
    int dRet = 0;

    dcobj->InsertFirst(51.73468);
    dcobj->InsertFirst(21.623);
    dcobj->InsertFirst(11.276);

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->InsertLast(101.12898);
    dcobj->InsertLast(111.7363);
    dcobj->InsertLast(121.278);

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->DeleteFirst();

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->DeleteLast();

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->InsertAtPos(150.82738,3);

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->DeleteAtPos(3);

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    delete dcobj;
    
    return 0;
}