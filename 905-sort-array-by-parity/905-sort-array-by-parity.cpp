class Solution {
private:
    bool isOdd(int n)
    {
        if (n % 2 != 0)
            return true;
        else
            return false;
    }
    
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int p1 = 0, p2 = nums.size()-1;
        while (p1 < p2)
        {
            if (isOdd(nums[p1]) and !isOdd(nums[p2]))
            {
                swap(nums[p1], nums[p2]);
                p1++; p2--;
            }
            if (!isOdd(nums[p1]) and !isOdd(nums[p2]))
            {
                p1++;
            }
            else if (isOdd(nums[p1]) and isOdd(nums[p2]))
            {
                p2--;
            }
            else if (!isOdd(nums[p1]) and isOdd(nums[p2]))
            {
                p1++;
                p2--;
            }
        }
        return nums;
    }
};
