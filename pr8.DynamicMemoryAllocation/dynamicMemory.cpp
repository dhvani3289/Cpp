#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Linked List Class
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() { head = nullptr; }

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Insert at the end
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at the beginning
    void insert_at_beginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Search for a node
    bool search(int key)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "Element " << key << " found in the list." << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Element " << key << " not found in the list." << endl;
        return false;
    }

    // Delete a node by value
    void delete_node(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Element " << key << " deleted successfully." << endl;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != key)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Element " << key << " not found in the list." << endl;
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Element " << key << " deleted successfully." << endl;
    }

    // Reverse the linked list
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed." << endl;
        display();
    }

    // Display the linked list
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    int choice, value;

    do
    {
        cout << endl;
        cout << "Menu: " << endl;
        cout << "1. Append" << endl;
        cout << "2. Insert at beginning" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Reverse" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to append: ";
            cin >> value;
            list->append(value);
            break;
        case 2:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list->insert_at_beginning(value);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            list->search(value);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list->delete_node(value);
            break;
        case 5:
            list->reverse();
            break;
        case 6:
            list->display();
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    delete list;
    return 0;
}
