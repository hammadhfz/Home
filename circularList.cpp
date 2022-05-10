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

int main()
{

    return 0;
}