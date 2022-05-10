#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node *next;
    Node()
    {
        data = key = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
    ~Node();
};

class List
{
public:
    Node *head;
    List();
    List(Node *newNode);
    Node *nodeExist(int k);
    void appendNode(Node *newNode);
    void prependNode(Node *newNode);
    void addNodeAfter(int k, Node *newNode);
    void deleteNode(int k);
    void updateNode(int k, int d);
    void display();
    ~List();
};

List::List()
{
    head = NULL;
}

List::List(Node *newNode)
{
    head = newNode;
}

// 1. Traverse the linked list

Node *List::nodeExist(int k)
{
    Node *temp = NULL;
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->key == k)
        {
            temp = ptr;
        }
        ptr = ptr->next;
    }
    return temp;
}

// 2. Add new Node at the end of the link list

void List::appendNode(Node *newNode)
{
    if (nodeExist(newNode->key) != NULL)
    {
        cout << "Node Already EXISTS having key value :-(" << newNode->key << endl
             << "Try to append a different key value NODE :-)" << endl;
    }
    else
    {
        if (head == NULL)
        {
            cout << "Creating Node :-|" << endl;
            head = newNode;
            cout << "Node Appended :-O" << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            cout << "Node Appended :-O" << endl;
        }
    }
}

// 3. Add new Node at the begining of the link list

void List::prependNode(Node *newNode)
{
    if (nodeExist(newNode->key) != NULL)
    {
        cout << "Node Already EXISTS having key value :-(" << newNode->key << endl
             << "Try to append a different key value NODE :-)" << endl;
    }
    else
    {
        if (head == NULL)
        {
            head = newNode;
            cout << "New Node Preppended :-)" << endl;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            cout << "New Node Prepended :-(" << endl;
        }
    }
}

// 4. Add new Node at the particular position of the link list

void List::addNodeAfter(int k, Node *newNode)
{
    Node *ptr = nodeExist(k);
    if (ptr == NULL)
    {
        cout << "The key you entered is not exist :-(";
    }
    else
    {
        if (nodeExist(newNode->key) != NULL)
        {
            cout << "Node Already EXISTS having key value :-(" << newNode->key << endl
                 << "Try to append a different key value NODE :-)" << endl;
        }
        else
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
            cout << "Node inserted :-)" << endl;
        }
    }
}

// 5. Add key to delete that node

void List::deleteNode(int k)
{
    if (head == NULL)
    {
        cout << "There is no List :-(" << endl;
    }
    else if (head != NULL)
    {
        if (head->key == k)
        {
            head = head->next;
            cout << "Node Unlinked :-)" << endl;
        }
        else
        {
            Node *temp = NULL;
            Node *prevptr = head;
            Node *currptr = head->next;
            while (currptr != NULL)
            {
                if (currptr->key == k)
                {
                    temp = currptr;
                    currptr = NULL;
                }
                else
                {
                    prevptr = prevptr->next;
                    currptr = currptr->next;
                }
            }
            if (temp != NULL)
            {
                prevptr->next = temp->next;
                cout << "Node Unlinked 2 :-)" << endl;
            }
            else
            {
                cout << "Node does not exist :-(" << endl;
            }
        }
    }
}

// 6. Enter key and data to update that node

void List::updateNode(int k, int d)
{
    Node *ptr = nodeExist(k);
    if (ptr != NULL)
    {
        ptr->data = d;
        cout << "Node Updated :-)" << endl;
    }
    else
    {
        cout << "Node does Not Exists :-(" << endl;
    }
}

void List::display()
{
    if (head == NULL)
    {
        cout << "Node Linked List Not Exists" << endl;
    }
    else
    {
        cout << "Singly list values are here" << endl;
        Node *temp = head;

        while (temp != NULL)
        {
            cout << "(" << temp->key << ", " << temp->data << ")"
                 << " ---> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

List::~List(){
    cout << "Destructed" << endl;
}

void Output()
{
    List li;
    int option;
    int keyO, kO, dataO;

    do
    {
        cout << "Select Option Number to perform respective operation" << endl;
        cout << "1. ADD Node at the 'END' of LINK LIST" << endl;
        cout << "2. ADD Node at the 'BEGINING' of LINK LIST" << endl;
        cout << "3. ADD Node AFTER certain position by inserting key in the LINK LIST" << endl;
        cout << "4. 'DELETE' Node by inserting key in the LINK LIST" << endl;
        cout << "5. 'UPDATE' Node by inserting key in the LINK LIST" << endl;
        cout << "6. 'DISPLAY' theLINK LIST" << endl;
        cout << "7. 'CLEAR' Screen" << endl;
        cout << "0. 'EXIT'" << endl;

        cin >> option;

        Node *n1 = new Node();
        // List li(n1);

        switch (option)
        {
        case 0:
            /* code */
            break;
        case 1:
            cout << "Enter the 'KEY' value of that Node" << endl;
            cin >> keyO;
            cout << "Enter the 'Data' of that Node" << endl;
            cin >> dataO;
            n1->key = keyO;
            n1->data = dataO;
            li.appendNode(n1);
            break;
        case 2:
            cout << "Enter the 'KEY' value of that Node" << endl;
            cin >> keyO;
            cout << "Enter the 'Data' of that Node" << endl;
            cin >> dataO;
            n1->key = keyO;
            n1->data = dataO;
            li.prependNode(n1);
            break;
        case 3:
            cout << "Enter the 'KEY' value of that Node you want add 'node after' " << endl;
            cin >> kO;
            cout << "Enter the 'KEY' value of that Node" << endl;
            cin >> keyO;
            cout << "Enter the 'Data' of that Node" << endl;
            cin >> dataO;
            n1->key = keyO;
            n1->data = dataO;
            li.addNodeAfter(kO, n1);
            break;
        case 4:
            cout << "Enter the 'KEY' value of that Node You wanna DELETE" << endl;
            cin >> keyO;
            li.deleteNode(keyO);
            break;
        case 5:
            cout << "Enter the 'KEY' value of that Node You wanna UPDATE" << endl;
            cin >> keyO;
            cout << "Enter the 'DATA' value of that Node You wanna UPDATE" << endl;
            cin >> dataO;
            li.updateNode(keyO, dataO);
            break;
        case 6:
            li.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter an APPROPIATE Value" << endl;
            cout << "x x" << endl;
            cout << " ?" << endl;
            cout << " x" << endl;
            break;
        }

    } while (option != 0);
}

int main()
{
    Output();
    return 0;
}