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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)
            return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        for(int i = 0; i<n+1;i++){
            if(p2 == NULL){
                head = p1->next;
                return head;
            }
            p2 = p2->next;
        }
        while(p2!=NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
    }
};