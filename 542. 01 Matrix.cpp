class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    dp[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int rr[] = {-1,0,1,0};
        int cc[] = {0,1,0,-1};
        while(!q.empty())
        {
            auto temp = q.front();
            int x = temp.first;
            int y = temp.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xx = x+rr[i];
                int yy = y+cc[i];
                if(xx>=0&&xx<n && yy>=0&&yy<m)
                {
                    if(dp[xx][yy]==INT_MAX)
                    {
                        dp[xx][yy] = dp[x][y]+1;
                        q.push(make_pair(xx,yy));
                    }
                }
            }
            
        }
        return dp;
    }
};
