class Solution {
public:
    // time complecity -> O(n*2)
    // as there are total n nodes and each node may have n edges
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>ump;
        for(int i=0;i<routes.size();i++){
            for(auto& y:routes[i]){
                ump[y].push_back(i);
            }
        }
        queue<pair<int,int>>q;
        q.push({source,0});
        // vector<bool>vis(1000001,false); use set because this gives TLE
        unordered_set<int>s;
        s.insert(source);
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(node==target){
                return dist;
            }
            for(auto x:ump[node]){
                for(auto j:routes[x]){
                    if(s.find(j)==s.end()){
                        // vis[j] = true;
                        s.insert(j);
                        q.push({j,dist+1});
                    }
                }
                routes[x].clear();
            }
        }
        return -1;
    }
};
