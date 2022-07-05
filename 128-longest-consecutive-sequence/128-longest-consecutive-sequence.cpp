class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set <int> hash_set;
        for (int num: nums)
        {
            hash_set.insert(num);
        }
            
        int longest_streak = 0;
        for (int num: nums)
        {
            if (!hash_set.count(num-1))
            {
                int cur_strk = 1;
                int cur_num = num;
                
                while (hash_set.count(cur_num+1))
                {
                    cur_strk += 1;
                    cur_num += 1;
                }
                longest_streak = max(longest_streak, cur_strk);
            }
        }
        return longest_streak;
    }
};