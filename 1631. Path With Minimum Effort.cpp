class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // dijkstra algo
        // bfs but not with queue
        // with priority queue
        // because we want minimum on the top
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n = heights.size();
        int m = heights[0].size();
        // as we need to find shortest path then we have to store distance
        // we do not need vis matrix here
        // because as we are using priority queue, we will go only to those cells which have less cost
        // hence in bfs we need queue + vis
        // in dijkstra we need priority_queue + dis
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0] = 0; // because there will be no cost for the initial same position
        pq.push(make_pair(0,make_pair(0,0)));
        int c[] = {0,0,-1,1};
        int r[] = {-1,1,0,0};
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            if(x==n-1 && y==m-1)
            {
                return d;
            }
            for(int i=0;i<4;i++)
            {
                int xx = x+r[i];
                int yy = y+c[i];
                if(xx>=0 && yy>=0 && yy<m && xx<n)
                {
                    int md = max(d,abs(heights[x][y]-heights[xx][yy]));
                    if(dis[xx][yy]>md)
                    {
                        dis[xx][yy] = md;
                        pq.push(make_pair(md,make_pair(xx,yy)));
                    }
                }
            }
        }
        return 0;
    }
};
