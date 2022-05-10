#include <iostream>
using namespace std;

class Node
{
public:
    Node *prv;
    int key;
    int data;
    Node *nxt;
    Node();
    Node(int k, int d);
    ~Node();
};

Node::Node()
{
    key = 0;
    data = 0;
    nxt = NULL;
    prv = NULL;
}

Node::Node(int k, int d)
{
    key = k;
    data = d;
}

Node::~Node()
{
    cout << "DESTRUCTED :-X" << endl;
}

class DLL
{
public:
    Node *head;
    DLL();
    DLL(Node *newNode);
    Node *nodeIsThere(int k);
    void appNode(Node *newNode);
    void ppdNode(Node *newNode);
    void inafNode(int k, Node *newNode);
    void delNode(int k);
    void updNode(int k, int d);
    void display();
    ~DLL();
};

DLL::DLL()
{
    head = NULL;
}

DLL::DLL(Node *newNode)
{
    head = newNode;
}

Node *DLL::nodeIsThere(int k)
{
    Node *temp = NULL;
    Node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->key == k)
        {
            temp = ptr;
        }
        else
        {
            ptr = ptr->nxt;
        }
    }
    return temp;
}

void DLL::appNode(Node *newNode)
{
    if (nodeIsThere(newNode->key) != NULL)
    {
        cout << "Node Already EXISTS having key value :-(" << newNode->key << endl
             << "Try to append a different key value NODE :-)" << endl;
    }
    else
    {
        if (head == NULL)
        {
            head = newNode;
            cout << "Node Appended :-)" << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr->nxt != NULL)
            {
                ptr = ptr->nxt;
            }
            ptr->nxt = newNode;
            newNode->prv = ptr;
            cout << "Node Appended :-O" << endl;
        }
    }
}

void DLL::ppdNode(Node *newNode)
{
    if (nodeIsThere(newNode->key) != NULL)
    {
        cout << "Node Already EXISTS having key value :-(" << newNode->key << endl
             << "Try to preppend a different key value NODE :-)" << endl;
    }
    else
    {
        if (head == NULL)
        {
            head = newNode;
            cout << "Node prepended :-)" << endl;
        }
        else
        {
            head->prv = newNode;
            newNode->nxt = head;
            head = newNode;
            cout << "Node prepended :-O" << endl;
        }
    }
}

void DLL::inafNode(int k, Node *newNode)
{
    Node *ptr = nodeIsThere(k);
    if (ptr == NULL)
    {
        cout << "Node does Not exist having key value " << k << endl;
    }
    else
    {
        if (nodeIsThere(newNode->key) != NULL)
        {
            cout << "Node Already EXISTS having key value :-(" << newNode->key << endl
                 << "Try to append a different key value NODE :-)" << endl;
        }
        else
        {
            cout << "Inserting ... :-|" << endl;

            Node *temp = ptr->nxt;

            if (temp == NULL)
            {
                ptr->nxt = newNode;
                newNode->prv = ptr;
                cout << "Node Inserted at the end" << endl;
            }
            else
            {
                newNode->nxt = temp;
                temp->prv = newNode;
                newNode->prv = ptr;
                ptr->nxt = newNode;
                cout << "Node Inserted in between" << endl;
            }
        }
    }
}

void DLL::delNode(int k)
{
    Node *ptr = nodeIsThere(k);
    if (ptr == NULL)
    {
        cout << "Node does Not exist having key value " << k << endl;
    }
    else
    {
        if (head->key == k)
        {
            head = head->nxt;
            cout << "Node UnLInked" << endl;
        }
        else
        {
            Node *nextNode = ptr->nxt;
            Node *prevNode = ptr->prv;

            if (ptr->nxt == NULL)
            {
                ptr->prv = NULL;
            }
            else
            {
                prevNode->nxt = nextNode;
                nextNode->prv = prevNode;

                // Node *temp = ptr;
                // temp->nxt = ptr->nxt;
                // temp->prv = ptr->prv;

                cout << "Node Deleted in between " << endl;
            }
        }
    }
}

void DLL::updNode(int k, int d)
{
    Node *ptr = nodeIsThere(k);
    if (ptr != NULL)
    {
        ptr->data = d;
        cout << "Node having key value " << k << " Updated" << endl;
    }
    else
    {
        cout << "Node does not exist" << endl;
    }
}

void DLL::display()
{
    if (head == NULL)
    {
        cout << " Node does not exist " << endl;
    }
    else
    {
        cout << "Doubly Linked list" << endl;

        Node *temp = head;

        while (temp != NULL)
        {
            cout << "{'" << temp->key << "'"
                 << " , " << temp->data << "}"
                 << "--->" << endl;
            temp = temp->nxt;
        }
    }
}

DLL::~DLL()
{
    cout << "Linked List Destroyed" << endl;
}

void Rang()
{
    DLL dli;
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
        // List dli(n1);

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
            dli.appNode(n1);
            break;
        case 2:
            cout << "Enter the 'KEY' value of that Node" << endl;
            cin >> keyO;
            cout << "Enter the 'Data' of that Node" << endl;
            cin >> dataO;
            n1->key = keyO;
            n1->data = dataO;
            dli.ppdNode(n1);
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
            dli.inafNode(kO, n1);
            break;
        case 4:
            cout << "Enter the 'KEY' value of that Node You wanna DELETE" << endl;
            cin >> keyO;
            dli.delNode(keyO);
            break;
        case 5:
            cout << "Enter the 'KEY' value of that Node You wanna UPDATE" << endl;
            cin >> keyO;
            cout << "Enter the 'DATA' value of that Node You wanna UPDATE" << endl;
            cin >> dataO;
            dli.updNode(keyO, dataO);
            break;
        case 6:
            dli.display();
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
    Rang();
    return 0;
}