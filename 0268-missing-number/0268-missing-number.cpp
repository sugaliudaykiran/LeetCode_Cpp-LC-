class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor = 0, i = 0; 
        for (; i<nums.size(); i++)
        {
            Xor ^= (i ^ nums[i]);
        }
        return Xor ^ i;
    }
};