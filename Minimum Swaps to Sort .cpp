class Solution {
public:
	int minSwaps(vector<int>&nums){
		int n = nums.size();
		vector<pair<int,int>>cur(n);
		for(int i = 0; i < n; i++){
			cur[i].first = nums[i];
			cur[i].second = i;
		}
		sort(cur.begin(), cur.end());
		vector<bool>vis(n, false);
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(vis[i] or cur[i].second == i)
				continue;
			int cycle_size = 0;
			int j = i;
			while(!vis[j]){
				vis[j] = true;
				j = cur[j].second;
				cycle_size++;
			}
			ans += (cycle_size > 1) ? cycle_size - 1 : 0; 
		}
		return ans;
	}
};
