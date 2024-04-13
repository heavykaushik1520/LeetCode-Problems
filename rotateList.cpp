/*Given the head of a linked list, rotate the list to the right by k places.
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/

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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head;

        // Step 1: Find the length of the linked list
        int length = 1;
        ListNode *current = head;
        while (current->next)
        {
            current = current->next;
            length++;
        }

        // Calculate effective k
        k = k % length;
        if (k == 0)
            return head; // If k is a multiple of length, no rotation needed

        // Step 2: Connect the last node with the head to form a circular linked list
        current->next = head;

        // Step 3: Traverse to find the new tail node
        int steps_to_new_tail = length - k - 1;
        current = head;
        while (steps_to_new_tail--)
        {
            current = current->next;
        }

        // Step 4: Update
        ListNode *new_head = current->next;
        current->next = nullptr;

        return new_head;
    }
};
