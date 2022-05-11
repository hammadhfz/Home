#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node *next;
    Node();
    Node(int k, int d);
};

Node::Node()
{
    key = 0;
    data = 0;
    next = NULL;
}

Node::Node(int k, int d)
{
    key = k;
    data = d;
}

class cirList
{
public:
    Node *head;
    cirList();
    cirList(Node *newNode);
    Node *ifNodeLies(int k);
    void appending(Node *newNode);
    void prepending(Node *newNode);
    void inside(int k, Node *newNode);
    void deleting(int k);
    void updating(int k);
    void display();
};

cirList::cirList()
{
    head = NULL;
}

cirList::cirList(Node *newNode)
{
    head = newNode;
}

Node *cirList::ifNodeLies(int k)
{
    Node *temp = NULL;
    Node *ptr = head;

    if (ptr == NULL)
    {
        return temp;
        cout << "Node does not exist" << endl;
    }
    else
    {
        do
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;

        } while (ptr != head);

        return temp;
    }
}

void cirList::appending(Node *newNode)
{
    if (ifNodeLies(newNode->key) != NULL)
    {
        cout << "Node exists with same key value " << newNode->key << "try another key value" << endl;
    }
    else
    {
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            cout << "Node Appended" << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr != head)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = head;
            cout << "Node Appended" << endl;
        }
    }
}

void cirList::prepending(Node *newNode)
{
    if (ifNodeLies(newNode->key) != NULL)
    {
        cout << "Node exists with same key value " << newNode->key << "try another key value" << endl;
    }
    else
    {
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            cout << "Node prepended" << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr != head)
            {
                ptr = ptr->next;
            }
            newNode->next = head;
            head = newNode;
            cout << "Node prepended" << endl;
        }
    }
}

void cirList::inside(int k, Node *newNode)
{
    Node *ptr = ifNodeLies(k);
    if (ptr == NULL)
    {
        cout << " No Node exists with the key value " << k << endl;
    }
    else
    {
        if (ifNodeLies(newNode->key) != NULL)
        {
            cout << "Node exists with same key value " << newNode->key << "try another key value" << endl;
        }
        else
        {
            if (ptr->next == head)
            {
                newNode->next = head;
                ptr->next = newNode;
                cout << "Node Inserted at the end" << endl;
            }
            else
            {
                newNode->next = ptr->next;
                ptr->next = newNode;
                cout << "Node Inserted in between" << endl;
            }
        }
    }
}

void cirList::deleting(int k)
{
    
}

void cirList::updating(int k)
{
}

void cirList::display()
{
}

int main()
{

    return 0;
}