#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }

    static int countBit(int x)
    {
        int count = 0;
        while (x)
        {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }

    static bool compare(int a, int b)
    {
        int bitCountA = countBit(a);
        int bitCountB = countBit(b);

        if (bitCountA == bitCountB)
        {
            return a < b;
        }

        return bitCountA < bitCountB;
    }
};

int main()
{
    vector<int> test = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

    Solution solution;

    vector<int> result = solution.sortByBits(test);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ",";
    }
}