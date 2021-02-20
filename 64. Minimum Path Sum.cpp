// Dp solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
         int row = grid.size();
         int col = grid[0].size();
         long long int dp[row][col];
         
        dp[0][0] = grid[0][0];
        
        for( int i=0;i<row;i++){
            for( int j=0;j<col;j++){
                if(i > 0 && j > 0) {
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                }
                else if(i > 0) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                }
                else if(j > 0) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }
            }
        }
        return dp[row-1][col-1];
    }
};

// Dijkstra code
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        dp[0][0] = grid[0][0];
        //dijkstra algo = bfs + priority_queue
        // pq = < distance , ith , jth  
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push(make_pair(dp[0][0],make_pair(0,0)));
        int dx[] = {1,0};
        int dy[] = {0,1};
        while(!pq.empty())
        {
            auto temp = pq.top();
            int x = temp.second.first;
            int y = temp.second.second;
            pq.pop();
            for(int i=0;i<2;i++)
            {
                int ii = x+dx[i];
                int jj = y+dy[i];
                // are my ii and jj valid ?
                if(ii>=0 && ii<n && jj>=0 && jj<m)
                {
                    if(dp[x][y]+grid[ii][jj]<dp[ii][jj])
                    {
                        dp[ii][jj] = dp[x][y]+grid[ii][jj];
                        pq.push(make_pair(dp[ii][jj],make_pair(ii,jj)));
                    }
                }
            }
            
        }
        return dp[n-1][m-1];
    }
};
