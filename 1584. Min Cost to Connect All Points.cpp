class Solution {
public:
    int min_node(vector<bool>& visited, vector<int>& distance,int n){
        // every time we will find for a minimum distance node
        int ind = -1;
        int val = INT_MAX;
        for(int i=0;i<n;i++){
            if(visited[i]==false and distance[i]<val){
                val = distance[i];
                ind = i;
            }
        }
        return ind;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // minimum spanning tree
        // treate these coordinates as node of the graph
        int n = points.size();
        vector<vector<pair<int,int>>>adj(points.size());
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                int w = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,w});
                adj[j].push_back({i,w});
                // this is all about the creation of the graph
            }
        }
        // now as prims said
        // it want -> parent array, visited array, distance array
        vector<bool>visited(n,false);
        vector<int>parent(n,-1);
        vector<int>distance(n,INT_MAX);
        distance[0] = 0;

        
        for(int i=0;i<n-1;i++){
            // number of edges in MST -> n-1
            // hence we gonna make n-1 times only therefore i=0-->n-2
            // for every time we will find the node which have minimum distance
            // using that node we will visit it adjacent nodes
            int node = min_node(visited,distance,n);
            visited[node] = true;
            for(auto& x:adj[node]){
                if(visited[x.first]==false and distance[x.first]>x.second){
                    parent[x.first] = node;
                    distance[x.first] = x.second;
                }
            }
        }
        
        int cost = 0;
        for(int i=0;i<n;i++){
            cost+=distance[i];
        }
        return cost;
    }
    // Time Complexity of Prims: O(E+ V log V)
};
