#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i1 = 0;
        int i2 = 0;
        vector<int> temp;
        for (int i = 0; i < m + n; i++)
        {
            if (i1 == m)
            {
                temp.push_back(nums2[i2]);
                i2++;
                continue;
            }
            else if (i2 == n)
            {
                temp.push_back(nums1[i1]);
                
                i1++;
                continue;
            }

            if (nums1[i1] < nums2[i2])
            {
                temp.push_back(nums1[i1]);
                i1++;
            }
            else
            {
                temp.push_back(nums2[i2]);
                i2++;
            }
        }
        nums1 = temp;
    }
};