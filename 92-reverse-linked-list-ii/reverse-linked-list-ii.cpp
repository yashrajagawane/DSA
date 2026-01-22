/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
        return head;

        int cnt = 1;
        ListNode* node1 = head;

        while (cnt < left - 1) {
            node1 = node1->next;
            cnt++;
        }

        ListNode* node2 = node1->next;
        ListNode* current = node1->next;
        ListNode* prev = nullptr;

        cnt += 1;
        ListNode* nextNode;

        while (true) {
            nextNode = current->next;
            current->next = prev;
            if (cnt == right ) {
                break;
            }
            prev = current;
            current = nextNode;
            cnt++;
        }

        node1->next = current;
        node2->next = nextNode;

        return head;
    } 
};

*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        ListNode* current = prev->next;
        
        for (int i = 0; i < right - left; ++i) {
            ListNode* next_node = current->next;
            current->next = next_node->next;
            next_node->next = prev->next;
            prev->next = next_node;
        }
        
        return dummy.next;
    }
};