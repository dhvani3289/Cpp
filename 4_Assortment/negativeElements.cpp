#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter Array Size: ";
    cin >> n;

    cout << "Enter Array Elements: ";
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }

    cout << "Negative elements from an Array are : ";

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            cout << a[i] << ", ";
        }
    }
}