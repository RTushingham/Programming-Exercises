// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// I tested this in LeetCode, so don't have a function main, or debugger output

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()>0)
    {
        std::multimap<int, ListNode*> NextValues;
		
        for(auto list : lists)
        {
            if(list != nullptr)
            {
                NextValues.insert({list->val, list});
            }
        }
		
        ListNode firstNode;
        ListNode* pFirstNode = &firstNode;
        ListNode* pCurrentNode = pFirstNode;
        auto pCurrentMinimum = NextValues.begin();
		
        while(NextValues.size()>0)
        {
            pCurrentMinimum = NextValues.begin();
			
            pCurrentNode->next = new ListNode(pCurrentMinimum->first);
            pCurrentNode = pCurrentNode->next;
			
            if(pCurrentMinimum->second->next != nullptr)
            {
                NextValues.insert({pCurrentMinimum->second->next->val, pCurrentMinimum->second->next});
            }
			
            NextValues.erase(pCurrentMinimum);
        }
		
        return pFirstNode->next;
    }
    else
    {
        return nullptr;
    }
}

