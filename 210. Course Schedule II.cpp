class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses,0);
        vector<int>res;
        for(auto x:prerequisites)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int total=0;
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            for(int u:graph[temp])
            {
                indegree[u]--;
                if(indegree[u]==0)
                {
                    q.push(u);
                }
            }
            total++;
        }
        if (total != numCourses)
            return {};
        reverse(res.begin(),res.end());
        return res;
        
    }
};
