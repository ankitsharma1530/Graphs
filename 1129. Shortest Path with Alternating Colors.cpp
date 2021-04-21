class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges){
        vector<vector<pair<int,int>>> graph(n);
        //red 0 blue 1
        for(int i = 0; i < red_edges.size(); i++){
            graph[red_edges[i][0]].push_back({red_edges[i][1], 0});
        }
        for(int i = 0; i < blue_edges.size(); i++){
            graph[blue_edges[i][0]].push_back({blue_edges[i][1], 1});
        }
        vector<int> dist(n,-1);
        dist[0] = 0;
        queue <pair<int,pair<int,int>>> q;
        q.push({0,{-1,0}});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int node = p.first;
            int prev_color = p.second.first;
            int d = p.second.second;
            // vector<pair<int,int>>::iterator itr;
            for(auto itr = graph[node].begin(); itr < graph[node].end(); itr++){
                int curr_colour = itr->second;
                int curr_node =  itr->first;
                if(prev_color != curr_colour){
                    //only proceed with bfs if the edge is of alternating colour
                    graph[node].erase(itr);
                    q.push({curr_node,{curr_colour,d+1}});
                    if(dist[curr_node] != -1) dist[curr_node] = min(d+1, dist[curr_node]);
                    else dist[curr_node] = d+1;  
                    itr--;
                }
                
            }
        }
        return dist;
    }
};
