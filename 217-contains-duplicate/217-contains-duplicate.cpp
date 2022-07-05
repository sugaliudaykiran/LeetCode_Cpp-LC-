class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int set_size = set <int>(nums.begin(), nums.end()).size();  //  TC -> O(1).. SC -> O(n)..
        
        if (set_size != nums.size())
        {
            return true;
        }
        return false;
    }
};


/*
        
        
    bool containsDuplicate(vector<int> &nums) {
            unordered_map <int, int> mp;        //  TC -> O(n).. SC -> O(n)..
            
            for (int i=0; i<nums.size(); i++)
            {
                mp[nums[i]]++;
            }
        
            for (int i=0; i<nums.size(); i++)
            {
                if (mp[nums[i]] > 1)
                {
                    return true;
                }
                
            }
        return false;
    }

    
    bool containsDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());         //  TC -> O(NlogN).. SC -> O(1)..
        
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] == nums[i-1])
            {
                return true;
            }
        }
        return false;
    }



*/ 