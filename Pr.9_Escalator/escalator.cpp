#include <iostream>
using namespace std;

class Stack
{
private:
    int topIndex;
    int size;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        this->topIndex = -1;
        this->arr = new int[this->size];
    }
    ~Stack()
    {
        delete[] this->arr;
    }

    void push(int value)
    {
        if (this->isFull())
        {
            cout << "Stack Overflow! Cannot push." << endl;
            return;
        }
        this->arr[++this->topIndex] = value;
        cout << value << " pushed into the stack." << endl;
    }

    void pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << this->arr[this->topIndex--] << " popped from the stack." << endl;
    }

    int top() const
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return this->arr[this->topIndex];
    }

    bool isEmpty() const
    {
        return this->topIndex == -1;
    }

    bool isFull() const
    {
        return this->topIndex == this->size - 1;
    }
};

int main()
{
    int capacity;
    cout << "Enter stack size: ";
    cin >> capacity;

    Stack stack(capacity);
    int choice, value;
    do
    {
        cout << endl;
        cout << "Stack Operations:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display Top" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            cout << "Top element: " << stack.top() << endl;
            break;
        case 4:
            cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 5:
            cout << (stack.isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
