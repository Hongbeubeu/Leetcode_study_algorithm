#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        string statement;
        cin >> statement;
        if (statement[0] == '+' || statement[statement.length() - 1] == '+')
        {
            x++;
            continue;
        }

        if (statement[0] == '-' || statement[statement.length() - 1] == '-')
        {
            x--;
            continue;
        }
    }
    cout << x;
}