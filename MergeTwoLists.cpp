
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *mergedList = new ListNode;
        ListNode *temp = mergedList;
        bool has_node = false;
        while (list1 || list2)
        {
            if (!has_node)
                has_node = true;
            int val;
            if (list1)
            {
                if (list2)
                {
                    if (list1->val <= list2->val)
                    {
                        val = list1->val;
                        list1 = list1->next;
                    }
                    else
                    {
                        val = list2->val;
                        list2 = list2->next;
                    }
                }
                else
                {
                    val = list1->val;
                    list1 = list1->next;
                }
            }
            else if (list2)
            {
                val = list2->val;
                list2 = list2->next;
            }

            temp->val = val;

            if ((list1 && list1->next) || (list2 && list2->next))
            {
                ListNode *next_node = new ListNode;
                temp->next = next_node;
                temp = temp->next;
            }
        }

        if (!has_node)
            mergedList = nullptr;
        return mergedList;
    }
};

int main()
{
    Solution solution;

    ListNode *list1 = nullptr;
    ListNode *list2 = nullptr;
    cout << list1 << " " << list2 << endl;

    // cout << solution.mergeTwoLists(list1, list2)->val << endl;
}