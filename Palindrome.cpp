#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        
        return  x == inverseNumber(x);
    }

    long long inverseNumber(int x)
    {
        long long result = 0;
        while (x)
        {
            int digit = x % 10;
            result = result * 10 + digit;
            x /= 10;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int x;
    cin >> x;
    cout << solution.isPalindrome(x);
}

//https://leetcode.com/problems/palindrome-number/