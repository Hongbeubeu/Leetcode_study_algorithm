#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int solution = 0;
    while (n--)
    {
        bool found = false;
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            int check;
            cin >> check;
            if (check)
            {
                count++;
                if (count >= 2)
                    found = true;
            }
        }
        if (found)
            solution++;
    }
    cout << solution;
}