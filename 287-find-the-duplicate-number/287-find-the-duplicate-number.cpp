class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        vector <int> hash(n, 0);
        for (int i=0; i<n; i++)
        {
            hash[nums[i]]++;
        }
        for (int i=0; i<n; i++)
        {
            if (hash[i] >= 2)
            {
                return i;
            }
        }
        return 0;
    }
};

/*  
                                    Navie Approach :- 
    1) First sort the vector and check each item with next item, if condition is true then there is a  duplicate number..
    2) TC -> O(n logn).. using merge sort or any sort function..     SC -> O(1)
    
        sort(nums.begin(), nums.end());     
        
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] == nums[i+1])
            {
                return nums[i];
            }
        }
        return 0;
                                    
                                    Using HashTable :-
*/                                     