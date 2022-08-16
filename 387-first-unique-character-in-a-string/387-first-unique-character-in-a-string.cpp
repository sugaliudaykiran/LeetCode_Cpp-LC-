class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> charIndex(26, 0);
        int n = s.size();
        
        for (int i=0; i<n; i++)
        {
            charIndex[s[i] - 'a']++;    
        }
        
        for (int i=0; i<n; i++)
        {
            if (charIndex[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};