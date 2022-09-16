class Solution {
	vector<vector<int>> dp;
	
	int dfs(vector<int>& num, vector<int>& mltip, int ind, int l, int M, int r) {
		if(ind == M) return 0;
		
		if(dp[l][ind] != INT_MIN) return dp[l][ind];
		
		int leftValue = mltip[ind] * num[l] + dfs(num, mltip, ind+1, l+1, M, r);
		int rightValue = mltip[ind] * num[r] + dfs(num, mltip, ind+1, l, M, r-1);
		
		return dp[l][ind] = max(leftValue, rightValue);
	}
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int ans = 0;
		int n = nums.size(), m = multipliers.size();
		dp.resize(m+1, vector<int>(m+1, INT_MIN));
		
		ans = dfs(nums, multipliers, 0, 0, m, n-1);
		return ans;
    }
};