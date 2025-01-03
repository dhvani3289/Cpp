#include <iostream>
using namespace std;
int main()
{
    int r, c, i, j, sum = 0, sum1 = 0;

    cout << "Enter the array's row size: ";
    cin >> r;

    cout << "Enter the array's column size: ";
    cin >> c;

    int arr[r][c];

    // taking input from user of array elements
    cout << "Enter array's elements: " << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // printing the array
    cout << "The array is: " << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;

    // enter the row number you want sum of
    cout << "Enter row number: ";
    cin >> i;

    cout << "Elements of row " << i << " are : ";
    for (j = 0; j < c; j++)
    {
        cout << arr[i][j] << ", ";
        sum = sum + arr[i][j];
    }
    cout << endl;
    cout << "The sum of row " << i << " elements is : " << sum << endl;
    cout << "----------------------------------------" << endl;

    // enter the column number you want sum of
    cout << "Enter column number: ";
    cin >> j;

    cout << "Elements of column " << j << " are : ";
    for (i = 0; i < r; i++)
    {
        cout << arr[i][j] << ", ";
        sum1 = sum1 + arr[i][j];
    }
    cout << endl;
    cout << "The sum of column " << j << " elements is : " << sum1 << endl;
    cout << "----------------------------------------" << endl;
}
