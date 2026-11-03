/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        while (cnt < k) {
            if (temp == nullptr)
                return head;
            temp = temp->next;
            cnt++;
        }
        ListNode* newNode = reverseKGroup(temp, k);
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = newNode;
            newNode = temp;
            temp = next;
            cnt++;
        }
        return newNode;
    }
};