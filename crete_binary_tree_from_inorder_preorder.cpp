class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root_index=0;
        return build(preorder,inorder,root_index,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int &root_index,int left,int right)
    {
        if(left>right)
            return NULL;
        int pivot=left;
        while(inorder[pivot]!=preorder[root_index]) pivot++;
        root_index++;
        TreeNode* tnode=new TreeNode(inorder[pivot]);
        tnode->left=build(preorder,inorder,root_index,left,pivot-1);
        tnode->right=build(preorder,inorder,root_index,pivot+1,right);
        return tnode;
    }
