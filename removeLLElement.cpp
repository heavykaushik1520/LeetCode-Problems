#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // Handle the case of an empty list
        if (head == nullptr)
            return nullptr;

        // Create a dummy node to handle the case where the head node itself needs to be removed
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // Initialize pointers for traversal
        ListNode *prev = dummy;
        ListNode *current = head;

        while (current != nullptr)
        {
            // If the current node's value matches the given value, remove it
            if (current->val == val)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                // Move to the next node
                prev = current;
                current = current->next;
            }
        }

        // Store the new head after removing nodes
        head = dummy->next;
        delete dummy;

        return head;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution solution;
    int val = 6;
    ListNode *newHead = solution.removeElements(head, val);

    // Print the resulting linked list
    printList(newHead);

    // Clean up memory
    while (newHead != nullptr)
    {
        ListNode *temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
