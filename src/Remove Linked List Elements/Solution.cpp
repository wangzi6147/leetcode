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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p1;
        ListNode* p2;
        while(head!=NULL&&head->val==val){
            head = head->next;
        }
        if(head==NULL)
            return head;
        p1 = head;
        p2 = p1->next;
        while(p2!=NULL){
            if(p2->val==val){
                p2 = p2->next;
                p1->next = p2;
            }
            else{
                p1 = p2;
                if(p1!=NULL)
                    p2 = p1->next;
                
            }
        }
        return head;
    }
};