class Solution
{
 public:
  vector<int> PostOrder(TreeNode* root)
  {
    stack<TreeNode*> st;
    vector<int> v;
    TreeNode* cur=root;
    TreeNode* prev=NULL;
    if(root==NULL)
    return v;
    while(!st.empty())
    {
      while(cur!=NULL)
      {
        st.push(cur);
        cur=cur->left;
      }
      TreeNode* top=st.top();
      if(top->right==NULL||prev=top->right)
      {
        st.pop();
        v.push_back(top->val);
        prev=top;
      }
      else
        cur=top->right;
    }
  }
}
