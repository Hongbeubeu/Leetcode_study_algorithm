#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> lines;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        lines.push_back(line);
    }

    for (int i = 0; i < n; i++)
    {
        string line = lines[i];
        int length = line.length();
        if (length > 10)
            cout << line[0] << length - 2 << line[length-1] << endl;
        else
            cout << line << endl;
    }
}