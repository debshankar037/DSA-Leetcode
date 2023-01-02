/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.*/
class Solution {
public:
    void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> & lowerDiagonal)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        int row;
        for(row=0;row<n;row++)
        {
            if(leftRow[row]==0&&upperDiagonal[n-1+col-row]==0&&lowerDiagonal[row+col]==0)
            {
                board[row][col]='Q';
                leftRow[row]=1;
                upperDiagonal[n-1+col-row]=1;
                lowerDiagonal[row+col]=1;
                solve(col+1,ans,board,n,leftRow,upperDiagonal,lowerDiagonal);
                board[row][col]='.';
                leftRow[row]=0;
                upperDiagonal[n-1+col-row]=0;
                lowerDiagonal[row+col]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        int i;
        for(i=0;i<n;i++)
            board[i]=s;
        vector<int>leftRow(n,0);
        vector<int>upperDiagonal(2*n-1,0);
        vector<int>lowerDiagonal(2*n-1,0);
        solve(0,ans,board,n,leftRow,upperDiagonal,lowerDiagonal);
        return ans;
    }
};
