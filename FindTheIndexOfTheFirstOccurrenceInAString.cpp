#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        char first_needle = needle[0];
        for (int i = 0; i < haystack.length(); i++)
        {
            char firstChar = haystack[i];
            if (firstChar == first_needle)
            {
                bool found = true;
                for (int j = 1; j < needle.length(); j++)
                {
                    int index = i + j;
                    if (index >= haystack.length() || haystack[index] != needle[j])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                    return i;
            }
        }
        return -1;
    }
};

//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/