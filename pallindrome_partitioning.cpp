/*Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.*/
class Solution {
public:
    bool ispal(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    void func(vector<vector<string>> &res,vector<string>&path,int index,string s)
    {
        if(index==s.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(ispal(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                func(res,path,i+1,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(res,path,0,s);
        return res;
        }
};
