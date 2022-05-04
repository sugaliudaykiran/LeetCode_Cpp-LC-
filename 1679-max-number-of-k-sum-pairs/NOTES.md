else i++;    // sum is small so increase the smaller element, i.e. ith element
}
return ans;
}
}
O(N) approach
count frequency using map in nums array
if k - num == num then num can be removed in pairs so ans += half of it's frequency
else wefind k - num is present in array using Map and if present ans += min of count of num or k-num
and update the values in Map also
​
class Solution {
public:
int maxOperations(vector<int>& nums, int k) {
unordered_map<int, int> Map;
for (auto &num: nums) Map[num]++;  // count freq of nums
int ans = 0;
for(auto it=Map.begin(); it!=Map.end(); ++it){
int num = it->first, count = it->second;
if(k - num == num) ans += count/2;   // if num is half of k add half of it's count in ans
else if(Map.count(k - num)){   // find k-num in nums and add min freq of num or k-num to ans
int Min = min(count, Map[k-num]);
ans += Min;
Map[num] -= Min;
Map[k-num] -= Min;
}
}
return ans;
}
};