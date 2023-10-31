#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        int index = digits.size() - 1;
        while (index >= 0 || carry > 0)
        {
            if (index < 0 && carry > 0)
            {
                digits.insert(digits.begin(), carry);
                break;
            }
            int value = digits[index] + carry;
            digits[index] = value % 10;
            carry = value / 10;
            index--;
        }
        return digits;
    }
};

int main()
{
    vector<int> digits = {1, 2, 3};
    Solution solution;
    auto result = solution.plusOne(digits);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}

//https://leetcode.com/problems/plus-one/