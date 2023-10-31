
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *addedNumber = new ListNode(0);
        int carry = 0;
        ListNode *resultIte = addedNumber;
        while (l1 != nullptr || l2 != nullptr || carry > 0)
        {
            int x1 = (l1 != nullptr) ? l1->val : 0;
            int x2 = (l2 != nullptr) ? l2->val : 0;
            int sum = x1 + x2 + carry;
            int x = sum % 10;
            carry = sum / 10;
            resultIte->val = x;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
            if (carry > 0 || l1 != nullptr || l2 != nullptr)
            {
                ListNode *current = new ListNode();
                resultIte->next = current;
                resultIte = current;
            }
        }

        return addedNumber;
    }
};

//https://leetcode.com/problems/add-two-numbers/description/