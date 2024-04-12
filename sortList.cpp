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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        // Split the list into two halves
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secondHalf = slow->next;
        slow->next = nullptr;

        // Recursively sort each half
        ListNode *sortedFirstHalf = sortList(head);
        ListNode *sortedSecondHalf = sortList(secondHalf);

        // Merge the sorted halves
        return merge(sortedFirstHalf, sortedSecondHalf);
    }

    // Merge two sorted linked lists
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        current->next = list1 ? list1 : list2;

        return dummy->next;
    }
};
