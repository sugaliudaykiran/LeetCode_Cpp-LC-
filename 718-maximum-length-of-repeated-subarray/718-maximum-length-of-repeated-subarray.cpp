class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        // int *dp[][] = new int[nums1.size()+1][nums2.size()+1]];
        
        for (int i=1; i<=nums1.size(); i++)
        {
            for (int j=1; j<=nums2.size(); j++)
            {
                if (nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    
                    ans = max(ans, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};