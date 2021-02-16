class Solution {
public:
    
    void solve(vector<vector<char>>& grid, int n, int m, int i, int j)
    {
        grid[i][j] = '2'; // here we make this cell as visited
        //left
        if(i-1>=0 && grid[i-1][j]=='1')
        {
            solve(grid,n,m,i-1,j);
            
        }
        //right
        if(j+1<m && grid[i][j+1]=='1')
        {
            solve(grid,n,m,i,j+1);
            
        }
        //down
        if(i+1<n && grid[i+1][j]=='1')
        {
            solve(grid,n,m,i+1,j);
            
        }
        //up
        if(j-1>=0 && grid[i][j-1]=='1')
        {
            solve(grid,n,m,i,j-1);
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    solve(grid,n,m,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
