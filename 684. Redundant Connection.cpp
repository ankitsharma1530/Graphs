class Solution {
public:
    int find(int node,vector<int>& par)
    {
        if(par[node]==node)
        {
            return node;
        }
        return find(par[node],par);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>par(n+1);
        for(int i=1;i<=edges.size();i++)
        {
            par[i] = i;
        }
        for(auto& x:edges)
        {
            int start = find(x[0],par);
            int end = find(x[1],par);
            if(start==end)
            {
                return {x[0],x[1]};
            }
            else
            {
                par[start] = end;
            }
        }
        return {-1,-1};
    }
};
