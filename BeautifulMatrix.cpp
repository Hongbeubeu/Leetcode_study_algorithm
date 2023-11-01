#include <iostream>
using namespace std;
int x;
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> x;
            if (x == 1)
            {
                cout << abs(i - 2) + abs(j - 2);
                return 0;
            }
        }
    }
}