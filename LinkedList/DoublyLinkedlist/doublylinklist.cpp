#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int data)
    {
        val = data;
        prev = NULL;
        next = NULL;
    };
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "<->";
            temp = temp->next;
        }
        cout << endl;
    }
    // insert at start
    void insertAtStart(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }
    // insert at end
    void insertAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (tail == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }
    // insert at any Position

    void insertAtPosition(int val, int k)
    {
        Node *temp = head;
        int cnt = 1;
        while (cnt < (k - 1))
        {
            temp = temp->next;
            cnt++;
        }
        Node *new_node = new Node(val);
        new_node->next = temp->next;
        temp->next = new_node;

        new_node->prev = temp;
        new_node->next->prev = new_node;
        return;
    }

    // delete at start
    void deleteAtStart()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == NULL)
        { // if doubly linked list had only 1 node
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    // delete at end
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        free(temp);
        return;
    }

    // delete any any position
    void deleteAtPosition(int k)
    {
        // assuming k is less than or equall to the  value given
        Node *temp = head;
        int counter = 1;
        while (counter < k)
        {
            temp = temp->next;
            counter++
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    };
};

int main()
{

    DoublyLinkedList dll;
    dll.insertAtStart(1);
    dll.insertAtStart(3);
    dll.insertAtStart(5);
    dll.display();
    // dll.insertAtTail(1);
    // dll.insertAtTail(3);
    // dll.insertAtTail(5);
    // dll.display();
    dll.insertAtPosition(4, 3);
    dll.display();

    return 0;
}