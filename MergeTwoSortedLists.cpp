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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode first = ListNode();
        ListNode* pCurrentOutputNode = &first;
        ListNode* pList1Node = list1;
        ListNode* pList2Node = list2;
        
        while(pList1Node != nullptr && pList2Node != nullptr)
        {
            ListNode** pMinimum = pList1Node->val < pList2Node->val ? &pList1Node : &pList2Node;
            
            pCurrentOutputNode->next = new ListNode((*pMinimum)->val);
            pCurrentOutputNode = pCurrentOutputNode->next;
            (*pMinimum) = (*pMinimum)->next;
        }
        ListNode** pRemaining = pList1Node != nullptr ? &pList1Node : &pList2Node;
        while((*pRemaining) != nullptr)
        {
            pCurrentOutputNode->next = new ListNode((*pRemaining)->val);
            pCurrentOutputNode = pCurrentOutputNode->next;
            (*pRemaining) = (*pRemaining)->next;
        }
        
        return first.next;
    }
};
