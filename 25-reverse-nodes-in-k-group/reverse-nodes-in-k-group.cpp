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
    // Helper to get the k-th node from current position
    ListNode* getKthNode(ListNode* temp, int k) {
       
        while (temp != nullptr && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    // Helper to reverse a linked list and return new head
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Main function
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        ListNode* newHead = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = getKthNode(temp, k);
            if (kthNode == nullptr) {
                if (prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextGroupHead = kthNode->next;
            kthNode->next = nullptr;

            // Reverse current group
            ListNode* reversedHead = reverseLinkedList(temp);

            if (newHead == nullptr) {
                newHead = reversedHead;
            } else {
                prevLast->next = reversedHead;
            }

            prevLast = temp;
            temp = nextGroupHead;
        }

        return newHead;
    }
};
