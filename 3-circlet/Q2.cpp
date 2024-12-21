// 11                               1
// 12 13
// 14 15 16
// 17 18 19 20

#include <iostream>
using namespace std;

int main()
{
    int i, j, n = 11;
    for (i = 11; i <= 14; i++)
    {
        for (j = 11; j <= i; j++)
        {
            cout << n << " ";
            n++;
        }
        cout << endl;
    }

    return 0;
}