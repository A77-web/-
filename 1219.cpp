class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(!pHead)return pHead;
        set<int> st;
        ListNode *pre=pHead;
        ListNode *cur=pHead->next;
        while(cur)
        {
            if(pre->val==cur->val)
            {
                st.insert(pre->val);
            }
            pre=pre->next;
            cur=cur->next;
        }
        ListNode *vhead = new ListNode(-1);
        vhead->next = pHead;
        pre = vhead;
        cur = pHead;
        while (cur) {
            if (st.count(cur->val)) {
                cur = cur->next;
                pre->next = cur;    
            }
            else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return vhead->next;
    }
};
