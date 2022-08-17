class Solution
{
    public:
        int uniqueMorseRepresentations(vector<string> &words) {
            vector <string> uniqueCode({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
        
        unordered_set <string> s;

        for (auto word: words)
        {
            string str = "";
            for (int i=0; i<word.size(); i++)
            {
                str += uniqueCode[word[i] - 'a'];
            }

            if (s.find(str) == s.end())
            {
                s.insert(str);
            }
        }
        return s.size();
        }
};