class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& dp) {
        int n = dp.size();
        int m = dp[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>res(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==1)
                {
                    q.push(make_pair(i,j));
                    vis[i][j] = true;
                }
            }
        }
        int c[] = {0,0,-1,1};
        int r[] = {-1,1,0,0};
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            for(int i=0;i<4;i++)
            {
                int xx = x+r[i];
                int yy = y+c[i];
                if(xx>=0 && xx<n && yy>=0 && yy<m && !vis[xx][yy])
                {
                    res[xx][yy] = res[x][y]+1;
                    vis[xx][yy] = true;
                    q.push(make_pair(xx,yy));
                }
            }
        }
        return res;
        
    }
};
