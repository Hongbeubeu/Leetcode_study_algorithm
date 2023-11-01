#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> findMode(TreeNode *root)
    {
        unordered_map<int, int> *temp = new unordered_map<int, int>();
        vector<int> result;
        if (root)
            travelsalBinaryTree(root, temp);
        else
        {
            result.push_back(0);
            return result;
        }
        unordered_map<int, int>::iterator it;
        int max = 0;
        for (it = temp->begin(); it != temp->end(); it++)
        {
            if (it->second > max)
                max = it->second;
        }
        for (it = temp->begin(); it != temp->end(); it++)
        {
            if (it->second == max)
                result.push_back(it->first);
        }
        return result;
    }

    void travelsalBinaryTree(TreeNode *node, unordered_map<int, int> *temp_map)
    {
        if (temp_map && temp_map->count(node->val))
        {
            int current_value = temp_map->at(node->val);
            temp_map->at(node->val) = current_value + 1;
        }
        else
        {
            temp_map->insert({node->val, 1});
        }

        if (node->left)
            travelsalBinaryTree(node->left, temp_map);
        if (node->right)
            travelsalBinaryTree(node->right, temp_map);
    }
};

int main()
{
    Solution solution;
    unordered_map<int, int> *test = new unordered_map<int, int>();
    test->insert({0, 1});
    cout << test->at(0) << endl;
}