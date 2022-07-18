class Solution {
public:
     int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int prefix[n];  //  Find the prefix_sum of the given nums..
        prefix[0] = nums[0];
        
        for (int i=1; i<n; i++)
        {
            prefix[i] = nums[i] + prefix[i-1];  // By using cur_i_th in nums + prefix[i-1] th one..
        }
        
        int count = 0;   // keep count of subarray sum's equal to k..
        unordered_map <int, int> mp;
        //      use the map to find that (prefix[i] + prefix[j] = k).. so (prefix[i] - k)..
        for (int i=0; i<n; i++)
        {
            if (prefix[i] == k)
            {
                count++;
            }
            
            if (mp.find(prefix[i] - k) != mp.end())
            {
                count += mp[prefix[i] - k]; //  If, found, then increment it val to count..
            }
            mp[prefix[i]]++;    //  Insert to the map..
        }
        return count;
	};
};

  