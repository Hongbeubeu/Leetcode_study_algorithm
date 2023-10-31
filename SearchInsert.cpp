#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
        {
            return 0;
        }

        int size = nums.size();
        if (target > nums[size - 1])
        {
            return size;
        }

        int index1 = size / 2;

        if (target == nums[index1])
            return index1;

        int index2 = target < nums[index1] ? 0 : size - 1;

        if (target == nums[index2])
            return index2;

        while (abs(index1 - index2) > 0)
        {
            int temp = index1;
            index1 = (index1 + index2) / 2;

            if (target == nums[index1])
                return index1;

            index2 = target < nums[index1] ? (temp < index2 ? temp : index2) : (temp > index2 ? temp : index2);

            if (target == nums[index2])
                return index2;

            if (abs(index1 - index2) == 1)
            {
                return target <= nums[index1] ? index1 : index2;
            }
        }

        return target <= nums[index1] ? index1 : index2;
    }
};

int main()
{
    Solution solution;

    vector<int> test = {1, 3, 5, 6};

    cout << solution.searchInsert(test, 2) << endl;
}

//https://leetcode.com/problems/search-insert-position/