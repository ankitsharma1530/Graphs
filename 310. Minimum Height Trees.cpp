class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
        {
            return {};
        }
        vector<int>res;
        if(n==1)
        {
            res.push_back(0);
            return res;
        }
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            degree[x[1]]++;
            degree[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            // from this we will get all the leaf nodes
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        int numnodes = n;
        while(!q.empty())
        {
            res.clear();
            int size = q.size();
            while(size--)
            {
                int node = q.front();
                q.pop();
                res.push_back(node);
                for(auto x:adj[node])
                {
                    degree[x]--;
                    if(degree[x]==1)
                    {
                        q.push(x);
                    }
                }
            }
            
        }
        return res;
        
    }
};
