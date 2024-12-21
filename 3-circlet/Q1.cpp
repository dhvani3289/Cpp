// 41
// 41 42
// 41 42 43
// 41 42 43 44
// 41 42 43 44 45

#include <iostream>
using namespace std;

int main()
{
    int i, j;
    for (i = 41; i <= 45; i++)
    {
        for (j = 41; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}