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
    Node* head;
    cirList();
    cirList(Node* newNode);
};

cirList::cirList()
{
    head = NULL;
}

cirList::cirList(Node* newNode)
{
    head = newNode;
}

int main()
{

    return 0;
}