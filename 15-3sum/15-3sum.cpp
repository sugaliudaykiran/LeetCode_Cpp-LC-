class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());         //  TC -> O(N * N) using two pointer approach.. SC -> O(M)..  AS -> O(1)..

        vector <vector <int>> res;
        if (nums.size() == 0 || nums.size() == 1)
            return res;
        // Moves for a..  Because, we can go upto last but two number.. and it's two pointer..
        for (int i=0; i<nums.size()-2; i++)    
        {    
            if (i==0 || (i>0 and nums[i] != nums[i-1])) // checking the const 'a' should be repeated..
            {
                int low = i+1, high = nums.size()-1, sum = 0 - nums[i];
                while (low < high)
                {
                    if (nums[low] + nums[high] == sum)
                    {
                        vector <int> temp;          //  if (b+c) == -(a) then push the triplet
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);
                        
                        while (low < high and nums[low] == nums[low+1]) low++;   // if low side items are repeated then skip them.. similarly in high..
                        while (low < high and nums[high] == nums[high-1]) high--;
                        
                        low++, high--;  //  Else then move ahead both low and high..
                    }
                    else if (nums[low] + nums[high] < sum)  low++;      // low + high which is greater than sum then we decrease the high.. else increase the low..
                    else high--;
                }
            }
        }
        return res;
    }
};

/*
        Navie solution :-
            1) By using Iteration of three times and finding a, b, c which equal to zero..
            2) Pushing the triplet to 'set' in case of avoiding the duplicate triplets..
            3) TC -> O(N^3 * logM).. where Log M for inserting to SET..    SC -> O(M)..
        
        Better Solution :-
            1) Using hashing and finding the 'c' which is equal to -(a + b)..
            2) In this we make the (item, it's frequency count).. and making two iteration and check the 'c' in the hashtable and making in case of exhausted also.. and insert them in sorted order to the set by this we avoid the duplicate triplets..
            3) TC -> O(N^2 * logM)..    SC -> O(M) + O(N)..
            
*/