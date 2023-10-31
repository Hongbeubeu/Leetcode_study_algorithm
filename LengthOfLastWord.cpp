#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        bool hasLastSpace = true;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && !hasLastSpace)
            {
                break;
            }

            if (s[i] != ' ')
            {
                hasLastSpace = false;
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;
    string s = "1a";
    cout << solution.lengthOfLastWord(s) << endl;
}

//https://leetcode.com/problems/length-of-last-word/description/