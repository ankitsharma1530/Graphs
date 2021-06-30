class Solution {
public:
    // int ans = 0;
    int solve(vector<vector<int>>& grid, int i, int j,int n, int m,int& ans){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0){
            return -1;
        }
        if(grid[i][j]==2){
            return 1;
        }
        grid[i][j]=2;
        int c = 0;
        if(solve(grid,i+1,j,n,m,ans)==-1){
            c++;
        }
        if(solve(grid,i-1,j,n,m,ans)==-1){
            c++;
        }
        if(solve(grid,i,j+1,n,m,ans)==-1){
            c++;
        }
        if(solve(grid,i,j-1,n,m,ans)==-1){
            c++;
        }
        ans+=c;
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int ans = 0;
                    return solve(grid,i,j,n,m,ans);
                }
            }
        }
        return 0;
    }
};
