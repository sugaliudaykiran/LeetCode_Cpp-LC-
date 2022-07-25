class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
int n = nums.size();
if (n == 0)
{
return {-1, -1};
}
int low = 0, high = n-1;
while (low < high)
{
int mid = (low + (high-low))/2;
if (nums[mid] == target)
{
int start = mid, end = mid;
while (nums[start] == target)
{
start--;
}
while (nums[end] == target)
{
end++;
}
return {start, end};
}
else if (nums[mid] > target)
{
high = mid;
}
else
{
low = mid+1;
}
}
return {-1, -1};
}
};