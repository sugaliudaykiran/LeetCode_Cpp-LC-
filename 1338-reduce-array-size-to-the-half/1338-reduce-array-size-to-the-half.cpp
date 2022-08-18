class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map <int, int> cnt;
        for (auto x: arr)
        {
            ++cnt[x];
        }
        
        vector <int> frequency;
        for (auto [_, freq]: cnt)
        {
            frequency.push_back(freq); 
        }
        sort(frequency.begin(), frequency.end());
        
        int res = 0, removed = 0, half = n/2 ,i = frequency.size()-1;
        
        while (removed < half)
        {
            res+=1;
            removed += frequency[i--];
        }
        return res;
    }
};


/*      
    Using Hashing and Sorting..   TC -> O(NLogN). SC -> O(N).
    1) Using Hashmap to count the freq of each number..
    2) Get the freq into the frequency array..
    3) sort the frequency Increasing order..
    4) Our prioritize removing the largest frequency first and we've eliminated at least half of the arr..
    5) return no of numbers removed.
*/ 