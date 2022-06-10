class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        
        while (mid <= high)
        {
            switch(nums[mid])       //  Checking on the bases of nums[mid] value..
            {
                case 0: 
                    swap(nums[low++], nums[mid++]);         //  'break' after a every switch case..
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};