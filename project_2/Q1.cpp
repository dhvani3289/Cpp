// Develop a program that prints all alphabets from ‘a’ to ‘z’ by skipping 3 alphabets using
// a do-while loop.
#include <iostream>
using namespace std;

int main()
{
    char ch = 'a';

    do
    {
        cout << ch << " ";
        ch += 4;
    } while (ch <= 'z');

    cout << endl;

    return 0;
}