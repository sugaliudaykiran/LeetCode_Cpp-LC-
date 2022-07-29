class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> res;
        
        for (auto &word: words)
        {
            if (match(word, pattern))
            {
                res.push_back(word);
            }
        }
        return res;
    }
    
    
    bool match(string &word, string &pattern)
    {
        unordered_map <char, char> word_toPat, pat_toWord;
        
        for (int i = 0; i <pattern.size(); i++)
        {
            if (word_toPat[word[i] - 'a'] == 0)
            {
                word_toPat[word[i] - 'a'] = pattern[i];
            }
            if (pat_toWord[pattern[i] - 'a'] == 0)
            {
                pat_toWord[pattern[i] - 'a'] = word[i];
            }
            
            if (word_toPat[word[i] - 'a'] != pattern[i] || pat_toWord[pattern[i] - 'a'] != word[i])
            {
                return false;
            }
        }
        return true;
    }
};