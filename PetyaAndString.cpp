#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int main()
{
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        char digit1 = s1[i];
        char digit2 = s2[i];
        int d1 = (digit1 - 'a' >= 0) ? (digit1 - 'a') : (digit1 - 'A');
        int d2 = (digit2 - 'a' >= 0) ? (digit2 - 'a') : (digit2 - 'A');
        if (d1 < d2)
        {
            cout << -1;
            return 0;
        }

        if (d1 > d2)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}