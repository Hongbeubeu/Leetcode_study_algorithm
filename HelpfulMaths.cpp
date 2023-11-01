#include <iostream>
#include <string>
using namespace std;

string s;
int main()
{
    cin >> s;
    set<char> temp;
    int size = s.length();
    for (int i = 0; i < size; i += 2)
    {
        temp.insert(s[i]);
    }
    string result;
    set<int>::iterator it;
    for (int i = 0; i < size; i++)
    {
        if ((i & 1) == 0)
        {
            result.append(temp)
        }
    }
}