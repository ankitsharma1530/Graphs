class Solution {
public:
    void dfs(vector<int>& res,string temp,int n,int k){
        if(temp.length()==n){
            res.push_back(stoi(temp));
            return;
        }
        for(int i=0;i<=9;i++){
            // cout<<temp<<endl;
            if(((abs((temp.back()-'0')-i)))==k){
                dfs(res,temp+to_string(i),n,k); 
            }   
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        for(int i=1;i<=9;i++){
            string temp = "";
            dfs(res,temp+to_string(i),n,k);
        }
        return res;
    }
};
