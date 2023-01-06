/*Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.*/
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);//Your Code Here
        unordered_map<int,int> mp;
        int i;
        for(i=0;i<n;i++)
        {
            mp[A[i]]=i;
        }
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    int numbertofind=X-A[i]-A[j];
                    if(mp.find(numbertofind)!=mp.end()&&mp[numbertofind]!=i&&mp[numbertofind]!=j)
                        return true;
                }
            }
        }
        return false;
    }

};
