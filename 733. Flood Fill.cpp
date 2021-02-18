class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc , int n, int m,  int newColor, int same)
    {
        if(sr>=0 && sr<n && sc>=0 && sc<m && image[sr][sc]==same)
        {
            image[sr][sc] = newColor;
            solve(image,sr+1,sc,n,m,newColor,same);
            solve(image,sr,sc-1,n,m,newColor,same);
            solve(image,sr,sc+1,n,m,newColor,same);
            solve(image,sr-1,sc,n,m,newColor,same);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int same = image[sr][sc];
        if(same!=newColor)
            solve(image,sr,sc, n,m, newColor,same);
        return image;
    }
};
