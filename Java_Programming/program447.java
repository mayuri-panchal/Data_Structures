// Singly circular

class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {
        System.out.println("Object of SinglyCL gets created");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
        }
        this.last.next = this.first;
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;

        newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.last.next = newn;
            this.last = newn;
        }
        this.last.next = this.first;
        iCount++;
    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;
        int iCnt = 0;

        if(pos < 1 || pos > this.iCount+1)
        {
            System.out.println("Invalid position");
            return;
        }

        if(pos == 1)
        {
            this.InsertFirst(no);
        }
        else if(pos == this.iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            newn = new node(no);

            temp = this.first;

            for(iCnt = 1; iCnt < (pos-1); iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            this.last.next = this.first;
            iCount++;
        }
    }

    public void DeleteFirst()
    {
        node temp = null;

        if(this.first == null && this.last == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            temp = this.first;

            this.first = this.first.next;

            temp = null;

        }
        this.last.next = this.first;
        System.gc();
        iCount--;
    }

    public void DeleteLast()
    {
         node temp = null;

        if(this.first == null && this.last == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            temp = this.first;

            while(temp.next.next != this.first)
            {
                temp = temp.next;
            }

            this.last = null;
            this.last = temp;

        }
        this.last.next = this.first;
        System.gc();
        iCount--;
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if(pos < 1 || pos > this.iCount)
        {
            System.out.println("Invalid position");
            return;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
        }
        else if(pos == this.iCount)
        {
            this.DeleteLast();
        }
        else
        {  
            temp = this.first;

            for(iCnt = 1; iCnt < (pos-1); iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            this.last.next = this.first;
            System.gc();
            iCount--;
        }
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;
        do
        {
            System.out.print("| "+temp.data+" |->");
            temp = temp.next;
        }while(temp != last.next);
    }

    public int Count()
    {
        return this.iCount;
    }
}

class program447
{
    public static void main(String A[])
    {
        int iRet = 0;

        SinglyCL obj = null;

        obj = new SinglyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(11);
        obj.InsertFirst(21);

        obj.Display();
        iRet = obj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(102);
        obj.InsertLast(103);

        obj.Display();
        iRet = obj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();
        iRet = obj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();
        iRet = obj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);

        obj.InsertAtPos(150,4);

        obj.Display();
        iRet = obj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);

        obj.DeleteAtPos(4);

        obj.Display();
        iRet = obj.Count();
        System.out.println("\nNumber of nodes are : "+iRet);

        // IMPORTANT FOR MEMORY DEALLOCATION
        obj = null;
        System.gc();
    }
    
}
