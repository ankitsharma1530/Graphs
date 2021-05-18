class Solution {
public:
    bool check(vector<vector<int>>& adj,vector<vector<int>>& dp, int start, int node)
    {
        if(dp[start][node]!=-1)
        {
            return dp[start][node];
        }
        if(start==node)
        {
            dp[start][node] = 1;
            return true;
        }
        for(auto n:adj[start])
        {
            if(check(adj,dp,n,node))
            {
                dp[n][node] = 1;
                return true;
            }
        }
        dp[start][node]=0;
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& p, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<vector<int>>adj(numCourses);
        vector<bool>res;
        // create dp because recursion will give TLE
        vector<vector<int>>dp(numCourses,vector<int>(numCourses,-1));
        for(auto x:p)
        {
            adj[x[0]].push_back(x[1]);
            // this will indicate that direct edge is present between U and V
            dp[x[0]][x[1]] = 1;
        }
        for(int i=0;i<n;i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            bool temp = check(adj,dp,u,v);
            res.push_back(temp);
        }
        return res;
    }
};
