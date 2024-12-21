// 1 0 1 0 1
// _ 1 0 1 0
// _ _ 1 0 1
// _ _ _ 1 0
// _ _ _ _ 1

#include <iostream>
using namespace std;

int main()
{
    int i, j, k;
    for (i = 5; i >= 1; i--)
    {
        for (k = 5; k > i; k--) // spacing loop
        {
            cout << "  ";
        }
        for (j = 1; j <= i; j++)
        {
            if (j % 2 == 0)
            {
                cout << "0" << " ";
            }
            else
            {
                cout << "1" << " ";
            }
        }
        cout << endl;
    }

    return 0;
}