class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>inorder(n,0);
        for(auto& x:edges)
        {
            adj[x[0]].push_back(x[1]);
            inorder[x[1]]++;
        }
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
