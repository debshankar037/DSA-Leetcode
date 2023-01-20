class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums,0,nums.size()-1);
    }
    TreeNode* create(vector<int>&nums,int low,int high)
    {
        if(low>high)
            return nullptr;
        int mid=(low+high)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=create(nums,low,mid-1);
        root->right=create(nums,mid+1,high);
        return root;
    }
};
