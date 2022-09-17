class Node {
public:
    vector<int> indexes; // index of the word that has palindromic suffix from next character
    int i; // index of the word that terminates at current node
    vector<Node*> children;
    Node(): children(vector<Node*>(26, nullptr)), i(-1){
    }
};

class Solution {
private:
    bool isPalindrome(const string & s, int i, int j) const {
        while (i<j){
            if(s[i]!=s[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    Node * trie;
    void build_word(int i, Node * root, string word){
        Node * node = root;
        if (isPalindrome(word, 0, word.size()-1)){
            node->indexes.push_back(i); 
        }
        for (int j =0; j < word.size(); ++j){
            char c = word[j];
            if (node->children[c-'a']==nullptr){
                Node * new_node = new Node();
                node->children[c-'a'] = new_node;
            }
            node = node->children[c-'a'];
            if (isPalindrome(word, j+1, word.size()-1)){
                node->indexes.push_back(i);        
            }
        }
        node -> i = i;
    }
    void build_trie(const vector<string>& words){
        trie = new Node();
        for (int i=0; i < words.size(); ++i){
            string word = words[i];
            // normal
            build_word(i, trie, word);
        }      
    }
    void solve_word(int i, vector<vector<int>> & ans, string word){
        Node * node = trie;
        for (int j=word.size()-1; j>=0; --j){
            if (node->i!=-1){
                if(isPalindrome(word, 0, j)){
                    if (node->i!=i){
                        ans.push_back({node->i, i});
                        // can be appended on the left hand side, because the prefix is palindromic
                    }
                }
            }
            char c = word[j];
            if (node->children[c-'a']!=nullptr){
                node = node->children[c-'a'];
            }else{
                node = nullptr;
                break;
            }
        }
        if (node!=nullptr && !node->indexes.empty()){
            for (int k: node->indexes){
                if (k!=i){
                    ans.push_back({k, i});
                    // can be appended on the left hand side as well, because the suffix is palindromic
                }
            }
        }
    }
public:

    vector<vector<int>> palindromePairs(vector<string>& words) {
        build_trie(words);
        vector<vector<int>> ans;
        for(int i=0; i < words.size(); ++i){
            string word = words[i];
            // normal
            solve_word(i, ans, word);
        }
        return ans;
    }
};