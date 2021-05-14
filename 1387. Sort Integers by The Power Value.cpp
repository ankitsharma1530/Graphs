class Solution {
public:
    int power(int n)
    {
        int c = 0;
        while(n>1)
        {
            if(n%2==0)
            {
                n=n/2;
            }
            else
            {
                n=n*3+1;
            }
            c++;
            if(n==1)
            {
                break;
            }
        }
        return c;
    }
    static bool cmp(pair<int,int>&a , pair<int,int>&b)
    {
        if(b.second>a.second)
        {
            return true;
        }
        else if(b.second==a.second)
        {
            return a.first<b.first;
        }
        return false;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>ump;
        for(int i=lo;i<=hi;i++)
        {
            int temp = power(i);
            ump.push_back(make_pair(i,temp));
        }
        sort(ump.begin(),ump.end(),cmp);
        return ump[k-1].first;
    }
};
