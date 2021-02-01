/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head)
    {
        string num;
        while (head != nullptr) {
            num += to_string(head->val);
            head = head->next;
        }
        int ans = 0;
        int p = 1;
        for (int i = num.size() - 1; i >= 0; i--) {
            ans += p * (num[i] - '0');
            p *= 2;
        }
        return ans;
    }
};