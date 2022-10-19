#include <queue>

ListNode* removeNthFromEnd(ListNode* head, int n) {
    queue<ListNode**> PreviouslyVisitedNodes;
    ListNode** PointerToPointerToCurrentNode = &head;
    
    for(int Index=0; Index<n; Index++)
    {
        PreviouslyVisitedNodes.push(PointerToPointerToCurrentNode);
        PointerToPointerToCurrentNode = &((*PointerToPointerToCurrentNode)->next);
    }
    while(*PointerToPointerToCurrentNode != nullptr)
    {
        PreviouslyVisitedNodes.push(PointerToPointerToCurrentNode);
        PreviouslyVisitedNodes.pop();
        PointerToPointerToCurrentNode = &((*PointerToPointerToCurrentNode)->next);
    }
    
    if((*PreviouslyVisitedNodes.front()) == head)
    {
        return head->next;
    }
    else
    {
        (*PreviouslyVisitedNodes.front()) = (*PreviouslyVisitedNodes.front())->next;
        return head;
    }
}

// This can also be done with a lagging pointer:
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* Lead = head;
    ListNode* Lagging = head;
    
    for(int Index=0; Index<n; Index++)
    {
        Lead = Lead->next;
    }
    if(!Lead)
    {
        return head->next;
    }
    while(Lead->next)
    {
        Lead = Lead->next;
        Lagging = Lagging->next;
    }
    
    Lagging->next = Lagging->next->next;
    return head;
}

