class Solution{
    public:
    void dfs(int node, vector<vector<int>>& graph, int visited[]){
        visited[node] = 1;
        for(auto u: graph[node]){
            if(!visited[u])
            dfs(u, graph, visited);
        }
    }
    
    int isCircle(int N, vector<string> A){
        int i;
        vector<vector<int>>adj(26);
        
        // this is the reverse adjacent for kosaraju
        vector<vector<int>>adjr(26);
        
        // creating adjacent for normal graph
        // and adjacent transpose for kosaraju
        for(i = 0;i < N;i++){
	        int x = A[i].size()-1;
	        adj[(A[i][0]-'a')].push_back((A[i][x]-'a'));
	        adjr[(A[i][x]-'a')].push_back((A[i][0]-'a'));
	    }
	    
	   // calculating the indegree of each vertex
	    int indeg[26] = {0};
	    for(i = 0;i < 26;i++){
	       for(auto u: adj[i])
	           indeg[u]++;
	        
	    }
	    
	   // checking if the indegree of every vertex is equal to the 
	   // outdegree of that vertex
	   // if indegree is not equal to out degree this means one of the edge will 
	   // not be covered by our euler path hence can not form a circuit
	    for(i = 0;i < 26;i++){
	        if(adj[i].size() > 0 and indeg[i] != adj[i].size()){
	            return 0;
	        }
	    }
	    
	   // checking strongly connected component using Kosaraju's algorithm
	    int visited[26] = {0};
	    for(i = 0;i < 26;i++){
	        if(indeg[i] > 0)
	        break;
	    }
	    int n = i;
	    
	    dfs(n, adj, visited);
	    for(i = 0;i < 26;i++){
	        if(adj[i].size() and !visited[i]){
	            return 0;
	        }
	    }
	    
	   // dfs call on transpose graph for getting strongly connected component
	    for(i = 0;i < 26;i++) 
	    visited[i] = 0;
	    
	    // marking the visited nodes of the transpose graph
	   // then we will check , after the dfs if any node is still not visited
	   // then there will not be a euler circuit
        dfs(n, adjr, visited);
        for(i = 0;i < 26;i++){
            if(adjr[i].size() and !visited[i]){
                return 0;
            }
        }
        
        // return 1 as there is an Euler circuit
        return 1;
    }
};
