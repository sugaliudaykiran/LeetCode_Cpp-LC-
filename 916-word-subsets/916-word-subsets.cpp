class Solution {
public:
    vector <int> counter(string &word)
        {
            vector <int> count(26);
            for (char x: word)
            {
                count[x - 'a']++;
            }
            return count;
        }
    
    
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector <int> count(26), temp(26);
        for (string b: B)
        {
            temp = counter(b);
            for (int i=0; i<26; ++i)
            {
                count[i] = max(count[i], temp[i]);
            }
        }
        
        int i;
        vector <string> res;
        for (string a: A)
        {
            temp = counter(a);
            for (i=0; i<26; ++i)
            {
                if (temp[i] < count[i])
                {
                    break;
                }
            }
            if (i == 26)
            {
                res.push_back(a);
            }
        }
        return res;
        
        
    }
};