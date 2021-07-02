class Solution {
public:
    // time complexity -> O(n*m)
    void dfs(vector<vector<char>>& board,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!='O'){
            return;
        }
        board[i][j]='#';
        dfs(board,i+1,j,n,m);
        dfs(board,i-1,j,n,m);
        dfs(board,i,j-1,n,m);
        dfs(board,i,j+1,n,m);
    }
    //We will use boundary DFS to solve this problem
    void solve(vector<vector<char>>& board) {
        // let us first encounter the boundary side
        // see the islands that are connected to the boundary can never be captured
        // so we just find those islands and mark them as CANNOT-CAPTURED = "#"
        int n = board.size();
        int m = board[0].size();
        
        //Moving over firts and last column  
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,n,m);
            }
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1,n,m);
            }
        }
        //Moving over first and last row 
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j,n,m);
            }
            if(board[n-1][j]=='O'){
                dfs(board,n-1,j,n,m);
            }
        }
        
        // now simply capture the rest 'O'
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
