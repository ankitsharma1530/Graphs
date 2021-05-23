class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int> > mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> que;
        que.push(0);
        vector<int> vis(n,0);
        vis[0]=1;
        int ans=-1;
        while(!que.empty()){
            ans++;
            int len=que.size();
            while(len--){
                int id=que.front();
                que.pop();
                if(id==(n-1)) return ans;
                if((id+1)<n && !vis[id+1]){
                    vis[id+1]=1;
                    que.push(id+1);
                }
                if((id-1)>=0 && !vis[id-1]){
                    vis[id-1]=1;
                    que.push(id-1);
                }
                for(auto d:mp[arr[id]]){
                    if(d!=id){
                        if(!vis[d]){
                            vis[d]=1;
                            que.push(d);
                            
                        }
                    }
                }
                mp.erase(arr[id]);
            }
        }
        return -1;
    }
};
