class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool check = false;
        
        sort(nums.begin(), nums.end());
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] == nums[i-1])
            {
                check = true; 
            }
        }
        return check;
    }
};