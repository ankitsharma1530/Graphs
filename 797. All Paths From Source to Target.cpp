// DFS

class Solution {
public:
    void solve(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& check, int src, int des)
    {
        check.push_back(src);
        if(src==des)
        {
            res.push_back(check);
        }
        for(auto i:graph[src])
        {
            solve(graph,res,check,i,des);
        }
        //backtrack
        check.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>check;
        solve(graph,res,check,0,graph.size()-1);
        return res;
    }
};

//BFS


class Solution {
public:
    bool vis(int v, vector<int> &path)
    {
        for(auto i: path)
            if(i == v)
                return true;
        return false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0, des = graph.size()-1;
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(src);
        queue<vector<int>> q;
        q.push(path);
        while(!q.empty())
        {
            vector<int> top = q.front();
            q.pop();
            int last_val = top.back();
            if(last_val == des)
                res.push_back(top);
            for(auto v: graph[last_val])
            {
                if(!vis(v, top))
                {
                    vector<int> temp=top;
                    temp.push_back(v);
                    q.push(temp);
                }
            }
        }
        return res;
    }
};
