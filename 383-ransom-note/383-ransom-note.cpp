class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         vector <int> freq(27, 0);
        for (int i=0; i<magazine.size(); i++)
        {
            ++freq[magazine[i] - 'a'];
        }
        
        for (char x: ransomNote)
        {
            if (freq[x-'a'] == 0)
            {
                return false;
            }
            else{
                freq[x - 'a']--;
            }
        }
        return true;
    }
};

/* Using Hashmap..
 1. store the items of magazine in frequency map and traverse from the randomNote if any item of it is not exist in it..
 2. return false.. else remove the count in the frequency of it.
 
 */