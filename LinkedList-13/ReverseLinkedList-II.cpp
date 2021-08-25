// reverse-linked-list-ii


class Solution {
private:
    void rcr(ListNode* node, vector<int>& vect) {
        if (!node) return;
        vect.push_back(node->val);
        rcr(node->next, vect);
    }
    void reverseList(ListNode* node, vector<int>& vect) {
        if (vect.size() == 0) return;
        node->val = *vect.begin();
        vect.erase(vect.begin());
        reverseList(node->next, vect);
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> vect;
        rcr(head, vect);
        reverse(vect.begin() + left - 1, vect.begin() + right);
        reverseList(head, vect);
        return head;
    }
};
