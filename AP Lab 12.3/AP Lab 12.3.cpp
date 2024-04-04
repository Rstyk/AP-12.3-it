#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

void Insert(Node** head, Node** tail, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    if (*head == nullptr) {
        *head = newNode;
        *tail = newNode;
    }
    else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void Print(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Delete(Node** head, Node** tail)
{
    Node* current = *head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    *head = nullptr;
    *tail = nullptr;
}

void Pairs(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* runner = current->next;
        while (runner != nullptr)
        {
            if (current->data == runner->data)
            {
                cout << current->data << " has a pair" << endl;
                break;
            }
            runner = runner->next;
        }
        current = current->next;
    }
}

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int value;
    cout << "Enter values (enter -1 to stop): ";
    cin >> value;
    while (value != -1)
    {
        Insert(&head, &tail, value);
        cin >> value;
    }

    cout << "List: ";
    Print(head);

    Pairs(head);

    Delete(&head, &tail);

    return 0;
}

