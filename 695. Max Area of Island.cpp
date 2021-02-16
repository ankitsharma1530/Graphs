class Solution {
public:
    void solve(vector<vector<int>>& grid, int n, int m, int i, int j, int& area)
    {
        grid[i][j] = 2; // here we make this cell as visited
        //increment our area after each cell
        area++;
        //left
        if(i-1>=0 && grid[i-1][j]==1)
        {
            solve(grid,n,m,i-1,j,area);
            
        }
        //right
        if(j+1<m && grid[i][j+1]==1)
        {
            solve(grid,n,m,i,j+1,area);
            
        }
        //down
        if(i+1<n && grid[i+1][j]==1)
        {
            solve(grid,n,m,i+1,j,area);
            
        }
        //up
        if(j-1>=0 && grid[i][j-1]==1)
        {
            solve(grid,n,m,i,j-1,area);
            
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int area = 0;
                    solve(grid,n,m,i,j,area);
                    res = max(res,area);
                }
            }
        }
        
        return res;
    }
};
