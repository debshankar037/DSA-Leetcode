/*Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.*/
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> &m,int n,vector<vector<int>> vis,
        string move,int di[],int dj[],vector<string> &ans)
        {
            if(i==n-1&&j==n-1)
            {
                ans.push_back(move);
                return ;
            }
            string dir="DLRU";
            int ind;
            for(ind=0;ind<4;ind++)
            {
                int nexti=i+di[ind];
                int nextj=j+dj[ind];
                if(nexti>=0&&nextj>=0&&nexti<n&&nextj<n&&(m[nexti][nextj]==1)&&!vis[nexti][nextj])
                {
                    vis[i][j]=1;
                    solve(nexti,nextj,m,n,vis,move+dir[ind],di,dj,ans);
                    vis[i][j]=0;
                }
            }
        }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;// Your code goes here
        vector<vector<int>> vis(n,vector<int>(n,0));
        int di[]={1,0,0,-1};
        int dj[]={0,-1,1,0};
        if(m[0][0]==1)
            solve(0,0,m,n,vis,"",di,dj,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
