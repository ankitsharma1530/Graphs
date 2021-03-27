class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX/2));
        for(auto x:edges)
        {
            dp[x[0]][x[1]] = x[2];
            dp[x[1]][x[0]] = x[2];
        }
        // now we will update that FLYOD WARSHALL MATRIX
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
        int res = -1;
        int res_count = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
            {
                
                    if(dp[i][j]<=distanceThreshold && i!=j) // rememvber this thing , never use i==j //                                                         other wise you have to face many problems 
                    {
                        count++;
                    }
            
            }
            cout<<count;
            if(res_count>count)
            {
                res=i;
                res_count=count;
            }
            else if(res_count==count)
            {
                res=max(res,i);
            }
            
        }
        return res;
    }
};
