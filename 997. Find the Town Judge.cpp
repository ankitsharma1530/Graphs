class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int res[10000]={0};
        for(int i=0;i<trust.size();i++)
        {
            res[trust[i][0]]--;
             res[trust[i][1]]++;
        }
        int ans=-1;
        for(int i=0;i<n+1;i++)
        {
            if(res[i]==(n-1))
            {
                ans=i;
            }
        }
        return ans;
    }
};
