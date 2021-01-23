// BFS

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==0) return true;
    vector<int> adj[numCourses];
    vector<int> indeg(numCourses,0);
    for(auto pre :prerequisites ){
        adj[pre[0]].push_back(pre[1]);
        indeg[pre[1]]++;
    }
    int c=0;
    queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int u=q.front(); q.pop();
        c++;
        for(auto v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
    return (c==numCourses);
    }
};

// DFS

bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
