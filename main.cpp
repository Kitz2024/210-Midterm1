// Kit Pollinger
// 210 - Midterm - 1

// 210-Midterm-Starter Code
#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList
{
private:
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
        Node(int val, Node *p = nullptr, Node *n = nullptr)
        {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node *head;
    Node *tail;

public:
    // Identifies the head and tail points, indicating empty list
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    // Inserts New Node after specific Position and updates pointers
    void insert_after(int value, int position)
    {
        if (position < 0)
        {
            cout << "Position must be >= 0." << endl;
            return;
        }
        // Creating a new Node with the given Value
        Node *newNode = new Node(value);

        // If List is empty, insert new node as the head and tail
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        // Find Node at specific position
        Node *temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;
        // If Position exceeds list size, delete newnode and return
        if (!temp)
        {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }
        // Insert new node after the found node, update pointers
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }
    // Removes a note with a given value
    void delete_val(int value)
    {
        if (!head)
            return;
        Node *temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        if (!temp)
            return;
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;
        delete temp;
    }
    // removes a node at a specific position
    void delete_pos(int pos)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (pos == 1)
        {
            pop_front();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            if (!temp)
            {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp)
        {
            cout << "Position doesn't exist." << endl;
            return;
        }
        if (!temp->next)
        {
            pop_back();
            return;
        }
        Node *tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }
    // Adds New Node to the end of the List
    void push_back(int v)
    {
        Node *newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    // Adds New Node to the start of the List
    void push_front(int v)
    {
        Node *newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    // Removes the first Node from the list
    void pop_front()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        if (head->next)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }
    // removes the last node from the list
    void pop_back()
    {
        if (!tail)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = tail;
        if (tail->prev)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }
    // Deallocates memory for all nodes in the List
    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Prints the list elements in forward order
    void print()
    {
        Node *current = head;
        if (!current)
        {
            cout << "List is empty." << endl;
            return;
        }
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    // prints the list elements in reverse order
    void print_reverse()
    {
        Node *current = tail;
        if (!current)
        {
            cout << "List is empty." << endl;
            return;
        }
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Class method output the data structure starting with first element.
    void every_other_element()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next->next;
        }
        cout << endl;
    }
};

int main()
{
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning
    return 0;
}
