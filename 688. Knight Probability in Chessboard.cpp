class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        // simple knight walk
        int rr[] = {2,1,-2,-1,2,1,-2,-1};
        int cc[] = {1,2,-1,-2,-1,-2,1,2};
        queue<pair<int,int>>q;
        q.push(make_pair(r,c));
        double prob;
        vector<vector<double>>dp(N+1,vector<double>(N+1));
        dp[r][c] = 1.0;
        while(!q.empty() && K--)
        {
            int size = q.size();
            vector<vector<double>> dp1(N+1,vector<double>(N+1));
            while(size--)
            {
                pair<int,int>temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                for(int ii=0;ii<8;ii++)
                {
                    int new_r = i+rr[ii];
                    int new_c = j+cc[ii];
                    if(new_r>=0&&new_r<N && new_c>=0&&new_c<N)
                    {
                        if(dp1[new_r][new_c]==0)
                            q.push({new_r,new_c});
                        dp1[new_r][new_c]+=dp[i][j]/8.0;
                    }
                }
            }
            dp = dp1;
        }
        for(vector<double> ans: dp)
        {
            for(double x:ans)
                prob+=x;
        }
        return prob;
     }
};
