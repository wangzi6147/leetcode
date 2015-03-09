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
	bool hasCycle(ListNode *head) {
		ListNode * p1 = head;
		ListNode * p2;
		while (p1!=NULL&&p1->next != NULL){
			p2 = p1->next;
			p1->next = head;
			if (p2->next != NULL&&p2->next->next == head) 
			    return true;
			p1 = p2;
		}
		return false;
	}
};