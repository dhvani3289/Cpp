#include <iostream>
using namespace std;

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
float division(float a, float b);
int mod(int a, int b);

int main()
{
    int choice, n1, n2;
    do
    {
        cout << "---------------------------" << endl;
        cout << "Press 1 for +" << endl;
        cout << "Press 2 for -" << endl;
        cout << "Press 3 for *" << endl;
        cout << "Press 4 for /" << endl;
        cout << "Press 5 for %" << endl;
        cout << "Press 0 for the exit" << endl;
        cout << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the first number: ";
            cin >> n1;

            cout << "Enter the second number: ";
            cin >> n2;

            cout << "Addition of " << n1 << " and " << n2 << " is " << add(n1, n2) << endl;

            break;

        case 2:
            cout << "Enter the first number: ";
            cin >> n1;

            cout << "Enter the second number: ";
            cin >> n2;

            cout << "Subtraction of " << n1 << " and " << n2 << " is " << sub(n1, n2) << endl;
            break;

        case 3:
            cout << "Enter the first number: ";
            cin >> n1;

            cout << "Enter the second number: ";
            cin >> n2;

            cout << "Multiplication of " << n1 << " and " << n2 << " is " << mul(n1, n2) << endl;
            break;

        case 4:
            cout << "Enter the first number: ";
            cin >> n1;

            cout << "Enter the second number: ";
            cin >> n2;
            cout << "Division of " << n1 << " and " << n2 << " is " << division(n1, n2) << endl;
            break;

        case 5:
            cout << "Enter the first number: ";
            cin >> n1;

            cout << "Enter the second number: ";
            cin >> n2;

            cout << "Modulus of " << n1 << " and " << n2 << " is " << mod(n1, n2) << endl;
            break;

        case 0:
            break;

        default:
            cout << "Please Enter Valid Choice" << endl;
            break;
        }
    } while (choice != 0);
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
float division(float a, float b)
{
    if (b == 0)
    {
        cout << "Error: Division by zero is not allowed." << endl;
        return 0;
    }
    return a / b;
}
int mod(int a, int b)
{
    return a % b;
}