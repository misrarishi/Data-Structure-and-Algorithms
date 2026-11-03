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
    ListNode* reverseEvenLengthGroups(ListNode* head) { return solve(head, 1); }

private:
    ListNode* solve(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        ListNode* temp = head;
        int cnt = 1;
        while (temp->next != nullptr && cnt < k) {
            temp = temp->next;
            cnt++;
        }
        ListNode* next = temp->next;
        if (cnt % 2 == 0) {
            temp->next = nullptr;
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while (curr != nullptr) {
                ListNode* newNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = newNode;
            }
            head->next = solve(next, k + 1);
            return prev;
        }
        temp->next = solve(next, k + 1);
        return head;
    }
};