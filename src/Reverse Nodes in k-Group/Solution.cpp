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
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == NULL)
			return NULL;
		if (k == 1)
			return head;
		int len = 0;
		ListNode* p1, *p2, *result, *front;
		bool recordResult = true;
		p1 = head;
		result = head;
		front = head;
		p2 = head->next;
		while (p1!= NULL){
			p1 = p1->next;
			len++;
		}
		p1 = head;
		int remain = len - k;
		while (remain >= 0){
			for (int i = 1; i < k; i++){
				head->next = p2->next;
				p2->next = p1;
				p1 = p2;
				p2 = head->next;
			}
			if (!recordResult){
				front->next = p1;
			}
			if (recordResult){
				result = p1;
				recordResult = false;
			}
			front = head;
			head = p2;
			p1 = head;
			if (head != NULL)
				p2 = head->next;
			remain = remain - k;
		}
		return result;
	}
};