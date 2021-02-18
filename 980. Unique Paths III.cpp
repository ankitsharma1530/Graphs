int ans=0;
    void dfs(vector<vector<int>>& grid,int i,int j,int zero){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==-1||(grid[i][j]==2&&zero!=0)||grid[i][j]==10)
            return ;
        if(grid[i][j]==2&&zero==0)
            ans++;
        if(grid[i][j]==0)
            zero--;
        int temp=grid[i][j];
        grid[i][j]=10;
        
        dfs(grid,i+1,j,zero);
        dfs(grid,i-1,j,zero);
        dfs(grid,i,j+1,zero);
        dfs(grid,i,j-1,zero);
        grid[i][j]=temp;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    zero++;
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    dfs(grid,i,j,zero);
            }
        }
        return ans;
    }
