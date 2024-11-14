#include<iostream>
#include<stdio.h>
using namespace std;


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999


class ListNode {

public:
    int item;
    ListNode* next;
};


class LinkedListWithTail {

    ListNode* head;
    ListNode* tail;  /*EXTRA*/
    int length;

public:

    LinkedListWithTail() {
        head = NULL;  // initially set to NULL
        length = 0;
    }

    int getLength() const {
        return length;
    }

    int insertItem(int item) {
        // insert at the beginning

        ListNode* newNode = new ListNode();
        newNode->item = item;
        newNode->next = head; // point to previous first node


        if(head == NULL) {
            head =  newNode;  /*IMPORTANT - only for the first item of the list*/
            tail=head;
        }

        else {
          head = newNode; //set list to point to newnode as this is now the first node
          ListNode*temp=head;
          while(temp->next!=NULL)
          {
            temp=temp->next;
          }
          tail=temp;
        }


        length++;
        return SUCCESS_VALUE;
    }

    int deleteItem(int item) {
        ListNode* temp;
        ListNode* previous=NULL;

        temp = head; // start at the beginning

        while(temp != NULL) {
            if (temp->item == item) {
                break;
            }
            else if(temp->next==NULL && temp->item!=item)
            {
                cout<<"The item isnt in this list"<<endl;
                exit(1);
            }

            previous = temp;
            temp = temp->next; // move to next node
        }

        if(temp == NULL) {
            return NULL_VALUE; // item not found to delete or empty list
        }
        else if(temp== head && temp->next==NULL)
        {
            head=tail=NULL;
        }

        if(temp == head ){
            head = head->next; // delete the first node
          
        }
        else {
            previous->next = temp->next;
            ListNode*temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            tail=temp; 
        }



        delete[] temp;
        length--;
        
        return SUCCESS_VALUE ;
    }

    ListNode* searchItem(int item) const {
        ListNode* temp = head; // start at the beginning

        while(temp != NULL) {
            if(temp->item == item) {
                return temp;
            }

            temp = temp->next; // move to next node
        }

        return NULL; // Not found
    }

    void printList() const {
        ListNode* temp = head;

        while(temp != NULL) {
            printf("%d->", temp->item);
            temp = temp->next;
        }

        printf("\n");
        printf("Length: %d\n",getLength());
    }

    //------------write code for the functions below-----------
    int insertLast(int item) {
          ListNode *temp = new ListNode();

        if (head == NULL)
        {
            cout << "first insert and try again" << endl;
            return NULL_VALUE;
        }
        else
        {
            temp->item = item;
            tail->next = temp;
            tail = temp;
        }
        
        length++;
        return SUCCESS_VALUE;
        
    }

    ListNode* getItemAt(int position) const {
             int pos = 1;
        ListNode *temp = new ListNode();
        temp = head;
        while (temp != NULL)
        {
            if (pos == position)
                return temp;
            else if (pos > length)
                return NULL;
            temp = temp->next;
            pos++;
        }

    }

    int deleteLast() {
        if (head == NULL)
            return -1;
        else if (head->next == NULL)
            head = tail = NULL;
        else
        {
            ListNode *n = head;
            ListNode *p = NULL;
            while (n->next != NULL)
            {
                p =n;
                n = n->next;
            }
            p->next = NULL;
            tail = p;
            delete n;

            
        }
        length--;

    }
    void swap(int loc1,int loc2)
    {
        ListNode*temp=head;
        int x=0;
        ListNode*cur1,*cur2;
        if(loc1<=length&&loc2<=length)
        {
            if(loc1==loc2)
            {
                //nothing//
            }
            else
            {
                while(temp!=NULL)
                {
                    if(x==loc1)
                    {
                        cur1=temp;
                    }
                    if(x==loc2)
                    {
                        cur2=temp;
                    }
                    x++;
                    temp=temp->next;
                }
                int var;
                var=cur1->item;
                cur1->item=cur2->item;
                cur2->item=var;
            }
        }
        else{
            cout<<"its Out of Bound"<<endl;
        }
    }

    // Added
    ~LinkedListWithTail() {
        while(deleteLast() != NULL_VALUE) {
            /*NOTHING here*/
        }
    }
};

int main(void) {
    LinkedListWithTail ll;
    int choice, item;

    while(1) {
        printf("1. Insert item (First)\n2. Inset item (Last)\n");
        printf("3. Delete item (Last)\n4. Delete item\n");
        printf("5. Search item\n6. Get item at\n7. Print list\n8.Swap\n9.exit\n");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        if(choice == 1) {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ll.insertItem(item);
        }
        else if(choice == 2){
            printf("\nEnter item: ");
            scanf("%d", &item);

            ll.insertLast(item);
        }
        else if(choice == 3) {
            if(ll.deleteLast() == NULL_VALUE) {
                printf("\nDeletion failed\n");
            }
            else {
                printf("\nDeletion successful\n");
            }
        }
        else if(choice == 4) {
            printf("\nEnter item: ");
            scanf("%d", &item);

            if(ll.deleteItem(item) == NULL_VALUE) {
                printf("\nDeletion failed\n");
            }
            else {
                printf("\nDeletion successful\n");
            }
        }
        else if(choice == 5) {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ListNode* returnNode = ll.searchItem(item);

            if(returnNode != NULL) {
                printf("\nItem found\n");
            }
            else {
                printf("\nItem not found\n");
            }
        }
        else if(choice == 6) {
            int position;

            printf("\nEnter position: ");
            scanf("%d", &position);

            ListNode* returnNode = ll.getItemAt(position);

            if(returnNode->item != NULL_VALUE) {
                printf("\nItem found: %d\n", returnNode->item);
            }
            else {
                printf("\nItem not found\n");
            }
        }
        else if(choice == 7) {
            ll.printList();
        }
        else if(choice == 8) {
            int loc1,loc2;
            cout<<"first position : ";
            cin>>loc1;
            cout<<"second position : ";
            cin>>loc2;
            ll.swap(loc1,loc2);
        }
        else if(choice==9)
        {
            break;
        }
        else {
            printf("\nInvalid choice\n");
        }

        printf("\n---------------------------------------------\n\n");
    }

    return 0;
}
