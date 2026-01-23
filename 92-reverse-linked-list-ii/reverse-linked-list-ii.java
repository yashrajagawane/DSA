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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        // crete dummy note to mark head 
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode leftpre = dummy;
        ListNode current = head;

        for(int i=0 ; i<left - 1 ; i++){
            leftpre = leftpre.next;
            current = current.next;
        }

        ListNode sublist = current;

        ListNode prev = null;

        for(int i=0 ; i<= right - left ; i++){
            ListNode nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }

        leftpre.next = prev;
        sublist.next = current;

        return dummy.next;
    }
}