// _ _ _ _ 5
// _ _ _ 4 5 4
// _ _ 3 4 5 4 3
// _ 3 3 4 5 4 3 2
// 1 2 3 4 5 4 3 2 1

#include <iostream>
using namespace std;

int main()
{
    int i, j, k, s;
    for (i = 5; i >= 1; i--)
    {
        for (s = 1; s < i; s++) // spacing loop
        {
            cout << "  ";
        }
        for (j = i; j <= 5; j++)
        {
            cout << j << " ";
        }
        for (k = 4; k >= i; k--)
        {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}