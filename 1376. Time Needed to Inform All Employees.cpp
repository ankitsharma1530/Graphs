// class Solution {
// public:
//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& info) {
//         vector<vector<int>>adj(n);
//         int start = -1;
//         for(int i=0;i<manager.size();i++)
//         {
//             if(manager[i]==-1){
//                 start = i;
//             }
//             else{
//                 adj[manager[i]].push_back(i);
//             }
//         }
//         int tmin = 0;
//         queue<pair<int,int>>q;
//         q.push({start,0});
//         while(!q.empty())
//         {
//             int size = q.size();
//             while(size--)
//             {
//                 pair<int,int> node = q.front();
//                 q.pop();
//                 int curr = node.first;
//                 int time_tillnow = node.second;
//                 // int m = INT_MIN;
//                 int curr_time = time_tillnow+info[curr];
//                 tmin = max(tmin,curr_time);
//                 for(auto x:adj[curr])
//                 {
//                     q.push({x,curr_time});
//                 }
//             }
//         }
//         return tmin;
//     }
// };

//dfs
class Solution {
public:
    vector<vector<int>> children;
    int dfs(int node,vector<int>& informTime)
    {
        int time=0;
        for(int &n:children[node])
            time=max(time,dfs(n,informTime));		
        return informTime[node]+time;			
        //Return the time required for this employee to inform + the time for it's              children to inform all under them
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        children.resize(n);
        for(int i=0;i<manager.size();i++)				//Create Adjacency list
            if(manager[i]!=-1)
                children[manager[i]].push_back(i);
        return dfs(headID,informTime);
    }
};
