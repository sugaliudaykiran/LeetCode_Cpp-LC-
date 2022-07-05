class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int long_strek = 0;
        
        int cur_strek = 1;
        
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] == nums[i-1]+1)
            {
                cur_strek += 1;
            }
            
            else if (nums[i] != nums[i-1])
            {
                long_strek = max(long_strek, cur_strek);
                cur_strek = 1;
            }
        }
        long_strek = max(long_strek, cur_strek);
        
        return long_strek;
    }   
};