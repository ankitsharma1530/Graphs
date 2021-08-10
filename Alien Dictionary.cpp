class Solution{
    public:
    // time complexity -> O(n*(max_len(s))+K)
    
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis,stack<char>& st){
        vis[node] = true;
        for(auto x:adj[node]){
            if(vis[x]==false){
                dfs(x,adj,vis,st);
            }
        }
        
        // only after processing the adjacents node we are allow to push into stack
        // A----->C<-----B
        // as we start from A we call to C
        // C cannot call to anyone hence C will be the maximum among all
        
        char temp = node+'a';
        st.push(temp);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        // first i construct a directed graph
        // s1 = aabc    s2 = aafv
        //        |            |
        //       iter         iter
        // as s1[iter]!=s2[iter]
        // we can conclude that s1[iter]>s2[iter]
        // hence it should comes first
        // so we create a edge from B--------->F
        
        // indegree of B is 0
        // while indegree of F is 1
        // so by the minimum indegree we can conclude that B will be smallest 
        
        vector<vector<int>>adj(K);
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len =  min(s1.length(),s2.length());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        // visited array for topological sort
        vector<bool>vis(K,false);
        string res= "";
        
        // in khans -> we need queue
        // in dfs -> we need stack
        stack<char>st;
        for(int i=0;i<K;i++){
            // A--->C<---B
            // if we start from A we can explore C
            // but from C we cannot explore B
            // hence we iterate for every character one by one 
            // if it is not visited yet it means that we cannot explore that node
            // with the help of other
            if(vis[i]==false){
                dfs(i,adj,vis,st);
            }
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
    
