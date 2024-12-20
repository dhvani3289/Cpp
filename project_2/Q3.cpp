// Develop a Program to find the sum of a number's first and last digits.
#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0, firstDigit, lastDigit;
    cout << "Enter Any Number : ";
    cin >> n;

    lastDigit = n % 10;

    firstDigit = n;
    while (firstDigit >= 10)
    {
        firstDigit = firstDigit / 10;
    }

    sum = firstDigit + lastDigit;
    cout << "The sum of the first and the last digit : " << sum;

    return 0;
}
