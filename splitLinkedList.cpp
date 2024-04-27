/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.*/

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>v;
        int l=0;
        ListNode* t=head;
        while(t){
            l++;
            t=t->next;
        }
        int r=l%k, d=l/k;
        t=head;
        ListNode*p=head;
        if(l<k){
            ListNode* Nodeptr = head;
            
            while(Nodeptr!=NULL){
                ListNode* dummy = new ListNode(Nodeptr->val);
                v.push_back(dummy);
                Nodeptr = Nodeptr->next;
            }
            
            for(int i=0;i<k-l;i++){
                v.push_back(NULL);
            }
            return v;
        }
        for(int i=0;i<r;i++){
            p=t;
            for(int j=0;j<d;j++)t=t->next;
            ListNode* now=NULL;
            if(t->next)now=t->next;
            t->next=NULL;
            v.push_back(p);
            t=now;
        }
        for(int i=0;i<k-r;i++){
            p=t;
            for(int j=0;j<d-1;j++)t=t->next;
            ListNode* now=NULL;
            if(t->next)now=t->next;
            t->next=NULL;
            v.push_back(p);
            t=now;
        }
        
        return v;
    }
};