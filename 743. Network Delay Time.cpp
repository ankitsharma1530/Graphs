class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // O(N^3)
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX/2));
        for(auto x:times)
        {
            dp[x[0]-1][x[1]-1] = x[2]; // just because it is not having 0-node graph
            // if it is 0-node graph then we simply use without -1
        } 
        
        k=k-1;  // because of 0-node graph
        for(int node=0;node<n;node++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dp[i][j] = min(dp[i][j],dp[i][node]+dp[node][j]);
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[k][i]==INT_MAX/2 && k!=i)
            {
                // cout<<"a";
                return -1;
                
            }
            else if(k!=i)
            {
                res = max(res,dp[k][i]);
            }
        }
        return res;
    }
};
