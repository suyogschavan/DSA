#include <iostream>
#include <malloc.h>
using namespace std;

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *head;
struct SLL *tail;

void creation()
{
    struct SLL *node1;
    node1 = (struct SLL *)malloc(sizeof(struct SLL));
    int d;
    cout << "Enter the data in firstnode : ";
    cin >> d;
    node1->data = d;
    node1->next = NULL;
    head = node1;
    cout << "list created with only one node present" << endl;
}
int getData()
{
    int d;
    cout << "Enter the data: ";
    cin >> d;
    return d;
}
void insert()
{
    int ch;
    cout << "Where you wan't to insert the node?" << endl;
    cout << "1. to insert at begining of list." << endl;
    cout << "2. to insert at specific location of the list." << endl;
    cout << "3. to insert at the ending of the list." << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        struct SLL *frontNode;
        if (head == NULL)
            cout << "List is empty" << endl;
        else
        {
            frontNode = (struct SLL *)malloc(sizeof(struct SLL));
            frontNode->data = getData();
            frontNode->next = head;
            head = frontNode;
            cout << "Node inserted" << endl;
            break;
        }
        break;
    case 2:
    {
        struct SLL *newNode, *temp, *prev;
        int n, count = 1;
        cout << "Where you wan't to insert the new node?: (new node will be added after this node): ";
        cin >> n;
        if (head == NULL)
            cout << "List is empty" << endl;
        else
        {
            newNode = (struct SLL *)malloc(sizeof(struct SLL));
            temp = head;
            while (count != n + 1)
            {
                prev = temp;
                temp = temp->next;
                count++;
            }
            newNode->next = temp;
            prev->next = newNode;
            newNode->data = getData();
        }
        cout << "Node inserted" << endl;
        break;
    }
    case 3:
    {
        struct SLL *node1, *temp;
        temp = head;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            break;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            node1 = (struct SLL *)malloc(sizeof(struct SLL));
            temp->next = node1;
            node1->next = NULL;
            node1->data = getData();
        }
        cout << "Node inserted" << endl;
        break;
    }
    default:
        break;
    }
}

void display()
{
    struct SLL *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void remove()
{
    int ch;
    cout << "Which node you wan't to delete?" << endl;
    cout << "1. head node" << endl;
    cout << "2. specific node" << endl;
    cout << "3. tail node" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        struct SLL *tempNode;
        tempNode = head;
        head = tempNode->next;
        delete tempNode;
        cout << "Node deleted" << endl;
        break;
    }
    case 2:
    {
        int n, c = 1;
        cout << "Which node you wan't to delete?: ";
        cin >> n;
        struct SLL *tempNode1, *prevNode1;
        tempNode1 = head;
        while (c != n)
        {
            prevNode1 = tempNode1;
            tempNode1 = tempNode1->next;
            c++;
        }
        prevNode1->next = tempNode1->next;
        delete tempNode1;
        break;
    }
    case 3:
    {
        struct SLL *tailNode, *prevTail;
        tailNode = head;
        while (tailNode->next != NULL)
        {
            prevTail = tailNode;
            tailNode = tailNode->next;
        }
        prevTail->next = NULL;
        delete tailNode;
        cout << "Tail Node deleted" << endl;
        break;
    }
    default:
        break;
    }
}
int main()
{
    int ch;
    do
    {
        cout << "\n------------------------------------------------------------------" << endl;
        cout << "1. to Create the list." << endl;
        cout << "2. to insert new Nodes." << endl;
        cout << "3. to Display the list. " << endl;
        cout << "4. to delete the node." << endl;
        cout << "5. to exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            creation();
            break;
        case 2:
            insert();
            break;
        case 3:
            display();
            break;
        case 4:
            remove();
            break;
        default:
            break;
        }
    } while (ch != 5);
    return 0;
}