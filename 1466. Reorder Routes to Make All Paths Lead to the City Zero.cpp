class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool>vis(n,false);
        vector<vector<int>>back(n),adj(n);
        for(auto x:connections)
        {
            adj[x[0]].push_back(x[1]);
            back[x[1]].push_back(x[0]);
        }
        queue<int>q;
        q.push(0);
        int count = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            vis[curr]=true;
            // check for the edges which are not coming towards the zero
            for(auto x:adj[curr])
            {
                if(vis[x]==false)
                {
                    count++;
                    q.push(x);
                }
            }
            //baki jo sidhi kisi node se zero pe aa rahi hai
            for(auto x:back[curr])
            {
                if(vis[x]==false)
                {
                    q.push(x);
                }
            }
        }
        return count;
    }
};
