class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        if(A==nullptr&&A->next==nullptr)
            return true;
        ListNode* cur=A;
        while(cur)
        {
            ListNode* next=cur->next;
            s.push(cur->val);
            q.push(cur->val);
            cur=next;
        }
        while(!s.empty()&&!q.empty())
        {
            if(s.top()!=q.front())
            {
                return false;
            }
            else
            {
                return true;
            }
            s.pop();
            q.pop();
        }
        return true;
    }
    stack<int> s;
    queue<int> q;
};
