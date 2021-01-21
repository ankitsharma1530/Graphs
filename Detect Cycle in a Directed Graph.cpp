#include <bits/stdc++.h>
using namespace std;
bool cyclic(int node, int V,vector<int> adj[], vector<int>&vis , vector<int>&curr_vis)
{
    vis[node]=true;
    curr_vis[node]=true;
    for(auto i: adj[node])
    {
        if(vis[i]==false && cyclic(i,V,adj,vis,curr_vis))
        {
            return true;
        }
        else if(curr_vis[i]==true)
        {
            return true;
        }
    }
    curr_vis[node] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    vector<int> vis(V,false);
    vector<int> curr_vis(V,false);
    for(int i=0;i<V;i++)
    {
        if(vis[i]==false)
        {
            if(cyclic(i,V,adj,vis,curr_vis)==true)
            {
                return true;
            }
        }
    }
    return false;
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
