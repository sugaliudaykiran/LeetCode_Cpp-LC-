class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // same diagonal have same value of i - j
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp; // min_heap..
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                mp[i-j].push(mat[i][j]);
            }
        }
        
       for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                mat[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return mat;
    }
};

/*
    Explanation
    A[i][j] on the same diagonal have same value of i - j
    For each diagonal,
    put its elements together, sort, and set them back.


    Complexity
    Time O(MNlogD), where D is the length of diagonal with D = min(M,N).
    Space O(MN)
*/ 