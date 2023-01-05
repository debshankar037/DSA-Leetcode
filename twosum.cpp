/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++)
        {
            int numberleft=target-nums[i];
            if(hash.find(numberleft)!=hash.end())
            {
                result.push_back(hash[numberleft]);
                result.push_back(i);
            }
            else
            {
                hash[nums[i]]=i;
            }
        }
        return result;
    }
};
