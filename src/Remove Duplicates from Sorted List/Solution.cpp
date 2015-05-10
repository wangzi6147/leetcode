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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        while(p2!=NULL){
            if(p1->val==p2->val){
                p1->next = p2->next;
                p2 = p2->next;
                continue;
            }
            else{
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return head;
    }
};