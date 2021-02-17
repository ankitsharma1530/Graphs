class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int time = -1;
        int total = 0;
        queue<pair<int,int>>q;
        // jaha jaha bhi rotten oranges hai vo saare ek time pe hi count honge
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
                else if(grid[i][j]==0)
                {
                    total++;
                }
            }
        }
        if(total==r*c)
        {
            return 0;
        }
        //bfs
        while(!q.empty())
        {
            int size = q.size();
            for(int a = 0;a<size;a++) //taaki saaare rotten orange ek time pe function kare
            {
                pair<int,int>top = q.front();
                q.pop();
                int i = top.first;
                int j = top.second;
                //up
                if(i-1>=0 && grid[i-1][j]==1)
                {
                    grid[i-1][j] = 2;
                    q.push(make_pair(i-1,j));
                }
                //down
                if(i+1<r && grid[i+1][j]==1)
                {
                    grid[i+1][j] = 2;
                    q.push(make_pair(i+1,j));
                }
                //left
                if(j-1>=0 && grid[i][j-1]==1)
                {
                    grid[i][j-1] = 2;
                    q.push(make_pair(i,j-1));
                }
                //right
                if(j+1<c && grid[i][j+1]==1)
                {
                    grid[i][j+1] = 2;
                    q.push(make_pair(i,j+1));
                }
            
            }
            time++;
        }
        for(int a=0;a<r;a++)
        {
            for(int b=0;b<c;b++)
            {
                if(grid[a][b]==1)
                {
                    return -1;
                }
            }
        }
        return time;
        
    }
};
