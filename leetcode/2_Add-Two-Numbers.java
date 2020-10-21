/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode root = new ListNode();
    add(root, l1, l2, 0);
    return root;
  }

  public void add(ListNode now, ListNode l1, ListNode l2, int carry) {
    int l1Val = l1 == null ? 0 : l1.val;
    int l2Val = l2 == null ? 0 : l2.val;

    now.val = l1Val + l2Val + carry;
    if (now.val >= 10) {
      now.val %= 10;
      carry = 1;
    } else {
      carry = 0;
    }

    ListNode l1Next = l1 == null ? null : l1.next;
    ListNode l2Next = l2 == null ? null : l2.next;
    if (l1Next == null && l2Next == null && carry == 0) return;
    ListNode next = new ListNode();
    now.next = next;
    add(next, l1Next, l2Next, carry);
  }
}
