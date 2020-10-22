/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    set<ListNode*> map;
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        while (headA != nullptr) {
            map.insert(headA);
            headA = headA->next;
        }

        while (headB != nullptr) {
            if (map.find(headB) != map.end())
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};