class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = pow(10, 9)+7;
        int n = arr.size();
                
        sort(arr.begin(), arr.end());
        unordered_map<int, long>mp;
        
        mp[arr[0]] = 1;
        for (int i=1; i<n; i++)
        {
            long count = 1L;
            for (int j=0; j<i; j++)
            {
                if (arr[i]%arr[j] == 0 && mp.find(arr[i]/arr[j]) != mp.end())
                {
                    count = count + (mp[arr[j]] * mp[arr[i]/ arr[j]]);
                    // count  = count % MOD;
                }
            }
            mp[arr[i]] = count;
        }
        
        int res = 0;
        for (auto x: mp)
        {
            cout << x.first << " :" << x.second << "\n";
            res =  (res + x.second) % MOD;
        }
        return res;
    }
};