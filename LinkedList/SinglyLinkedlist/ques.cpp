// given the head of a linklist delete every alternative from
// the list starting from the second element

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class LinkList
{
public:
    Node *head;
    LinkList()
    {

        head = NULL;
    }
    void insertAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void deleteAlternateNode(Node *&head)
{
    Node *curr_node = head;
    while (curr_node != NULL && curr_node->next != NULL)
    {

        Node *temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    }
}



int main()
{

    LinkList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();
    deleteAlternateNode(ll.head);
    ll.display();

    return 0;
}