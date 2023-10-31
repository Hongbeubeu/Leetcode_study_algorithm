#include <iostream>

using namespace std;
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *result = head;
        ListNode *current_node = head;
        while (head)
        {
            head = head->next;

            if (!head)
            {
                break;
            }

            while (head && current_node->val == head->val)
            {
                head = head->next;
            }
            current_node->next = head;
            current_node = current_node->next;
        }

        return result;
    }
};

int main()
{
    ListNode *node = new ListNode;
    node->val = 1;
    ListNode *node1 = new ListNode;
    node1->val = 1;
    node->next = node1;
    ListNode *node2 = new ListNode;
    node2->val = 2;
    node1->next = node2;
    ListNode *node3 = new ListNode;
    node3->val = 3;
    node2->next = node3;
    ListNode *node4 = new ListNode;
    node4->val = 3;
    node3->next = node4;

    Solution solution;
    auto result = solution.deleteDuplicates(node);
    while (result)
    {
        cout << result->val << ", ";
        result = result->next;
    }
}