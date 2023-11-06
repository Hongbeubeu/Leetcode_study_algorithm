#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;

        int it = 0;
        int length = target.size();
        for (int i = 1; i <= n; i++)
        {
            
            if (target[it] == i)
            {
                result.push_back("Push");
                it++;
                if (it == length)
                    break;
                continue;
            }
            result.push_back("Push");
            result.push_back("Pop");
        }

        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> target = {1, 2};
    vector<string> x = solution.buildArray(target, 4);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << endl;
    }
}