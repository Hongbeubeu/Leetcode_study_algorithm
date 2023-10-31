#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        vector<int> result;
        result.push_back(pref[0]);
        int temp = pref[0];
        for (int i = 1; i < pref.size(); i++)
        {
            int value = temp ^ pref[i];
            result.push_back(value);
            temp ^= value;
        }
        return result;
    }
};

int main()
{
    vector<int> input = {5, 2, 0, 3, 1};
    Solution solution;
    auto output = solution.findArray(input);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}