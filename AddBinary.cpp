#include <string>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        char carry = '0';
        int a_len = a.length();
        int b_len = b.length();
        int length = a_len > b_len ? a_len : b_len;
        for (int i = 0; i < length; i++)
        {
            char a_char = '0';
            if (a_len - i > 0)
            {
                a_char = a[a_len - i - 1];
            }

            char b_char = '0';
            if (b_len - i > 0)
            {
                b_char = b[b_len - i - 1];
            }

            int value = a_char + carry + b_char - 3 * '0';
            char digit = value % 2 + '0';
            result.insert(result.begin(), digit);
            carry = value / 2 + '0';
        }
        if (carry == '1')
            result.insert(result.begin(), carry);
        return result;
    }
};