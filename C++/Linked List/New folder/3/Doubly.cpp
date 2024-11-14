#include <iostream>
using namespace std;

class doubly
{
public:
    int data;
    doubly *ncur;
    doubly *prev;

    doubly(int value)
    {
        data = value;
        prev = NULL;
        ncur = NULL;
    }
};

doubly *head = NULL;
doubly *tail = NULL;


void insertfirst(int data)
{
    doubly *temp = new doubly(data);
    if (head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        temp->ncur = head;
        head->prev = temp;
        head = temp;

        temp = head;
        while (temp->ncur != NULL)
            temp = temp->ncur;
        tail = temp;
    }
}

void insert(int data)
{
    doubly *temp = new doubly(data);
    if (head == NULL)
    {
        insertfirst(data);
    }
    else
    {
        tail->ncur = temp;
        temp->prev = tail;
        tail = temp;
    }
}


doubly *search(int e)
{
    doubly *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == e)
        {
            return ptr;
        }
        ptr = ptr->ncur;
    }
    return NULL;
}

void insertitem(int e, int digit)
{
    doubly *temp = new doubly(digit);
    if (head == NULL)
    {
        cout << "empty list" << endl;
        return;
    }
    else
    {
        doubly *mem = search(e);
        if (mem == NULL)
        {
            cout << "nothing in list" << endl;
            return;
        }
        else
        {
            if (mem->ncur == NULL)
            {
                insert(digit);
            }
            else
            {
                doubly *nextitem = mem->ncur;
                temp->ncur = nextitem;
                nextitem->prev = temp;
                mem->ncur= temp;
                temp->prev = mem;
            }
        }
    }
}
void printreverse(doubly *temp)
{
    if (temp == NULL)
        return;
    printreverse(temp->ncur);
    cout << temp->data << "->";
}

void deletelast()
{
    if (head == NULL)
    {
        cout << "empty" << endl;
        return;
    }
    else if (head == tail)
    {
        head =NULL;
        tail=NULL;
    }
    else
    {
        doubly *prev = tail->prev;
        doubly *temp = tail;
        prev->ncur = NULL;
        tail = prev;
        free(temp);
    }
}
void display()
{
    doubly *temp = head;
    if (temp == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->ncur;
        }
    }
}
int main(void)
{
    int x;
    while (1)
    {
        cout << "\n 1.insertfirst\n2.insert\n3.insertitem\n4.deletelast\n5.print\n6.print in reverse\n"
             << endl;
        cout << "your choice : ";
        cin >> x;
        if (x == 1)
        {
            int data;
            cout << "\nenter your data: ";
            cin >> data;
            insertfirst(data);
        }
        else if (x == 2)
        {
            int data;
            cout << "\nenter your data: ";
            cin >> data;
            insert(data);
        }
        else if (x == 3)
        {
            int e, d;
            cout << "\ninsert the element: ";
            cin >> e;
            cout << "\ninsert digit: ";
            cin >> d;
            insertitem(e, d);
        }
        else if (x == 4)
        {
            deletelast();
        }
        else if (x == 5)
        {
            display();
        }
        else if (x == 6)
        {
            printreverse(head);
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
