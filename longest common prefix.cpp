class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n;
        n=strs.size();
        if(n==0)
            return "";
        sort(begin(strs),end(strs));
        string a=strs[0];
        string b=strs[n-1];
        int i;
        string ans="";
        for(i=0;i<a.size();i++)
        {
            if(a[i]==b[i])
                ans+=a[i];
            else break;
        }
        return ans;
    }
};
