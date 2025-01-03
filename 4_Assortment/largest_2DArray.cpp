#include <iostream>
using namespace std;

int main()
{
    int r, c, i, j;

    cout << "Enter the array's row size: ";
    cin >> r;

    cout << "Enter the array's column size: ";
    cin >> c;

    int arr[r][c];

    cout << "Enter array's elements: " << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "The largest element is: ";
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (arr[i][j] > arr[i][j + 1])
            {
                cout << arr[i][j] << endl;
            }
        }
    }
}