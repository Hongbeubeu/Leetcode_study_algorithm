
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = 0;
        vector<char> temp;

        for (int i = 0; i < s.length(); i++)
        {
            char currentChar = s[i];
            for (int j = 0; j < temp.size(); j++)
            {
                char checkChar = temp[j];
                if (checkChar == currentChar)
                {
                    int currentLength = temp.size();
                    length = currentLength > length ? currentLength : length;
                    for (int k = 0; k <= j; k++)
                    {
                        temp.erase(temp.begin());
                    }
                    break;
                }
            }
            temp.push_back(currentChar);
        }

        return length > temp.size() ? length: temp.size();
    }
};

//https://leetcode.com/problems/longest-substring-without-repeating-characters/