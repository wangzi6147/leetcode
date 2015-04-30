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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        ListNode * p1 = head;
        ListNode * p2 = head;
        int num = 0;
        while(p2!=NULL){
            num++;
            p2 = p2->next;
        }
        if(k>num)
            k = k%num;
        if(k==0)
            return head;
        num = 0;
        p2 = head;
        while(p2->next!=NULL&&num<k){
            p2 = p2->next;
            num++;
        }
        if(num<k)
            return head;
        while(p2->next!=NULL){
            p2 = p2->next;
            p1 = p1->next;
        }
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
        return head;
    }
};