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
class CompareNode 
{
    public:
        bool operator()(const ListNode* p1,const ListNode* p2)
        {
            return p1->val > p2->val;
        }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
         priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;
        ListNode* ans = nullptr;
        ListNode* last = nullptr;
        
        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i]!=nullptr)
            {
                pq.push(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        
        while(!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();

            if(ans==nullptr)
            {
                ans = temp;
                last = temp;
            }
            else
            {
                last->next = temp;
                last = last->next;
            }
            
            if(temp->next!=nullptr)
                pq.push(temp->next);
            
        }
        return ans;
    }
};
