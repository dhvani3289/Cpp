// Develop a Program to count the total number of digits in a number.
#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    cout << "Enter Any Number : ";
    cin >> n;

    while (n != 0)
    {
        n = n / 10;
        count++;
    }

    cout << "Total number of digits : " << count;

    return 0;
}