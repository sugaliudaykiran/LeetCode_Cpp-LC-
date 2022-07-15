class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        n = grid.size(), m = grid[0].size();   
                                        //      TC -> O(n*m)..  SC -> O(L) where L is maximum area of an island..
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j])      // if value is '1'
                {
                   res = max(travs(i,j, grid), res);
                }
            }
        }
        return res;
    }
    
    int n, m;
private:
    int travs(int i, int j, vector<vector<int>>& grid)
    {
        if (i<0 || j <0 || i>=n || j>=m || grid[i][j] == 0)
        {
           return 0;  // base case..
        }
        // small calc..
        grid[i][j] = 0;
        
        return 1 + travs(i+1, j, grid) + travs(i, j+1, grid) + travs(i-1, j, grid) + travs(i, j-1, grid);       //  small task..
    }
};


/*
    Idea :- 
    1) In this, we apply the recursion, for finding each land to it's surrounded by land..
    2) To avoid repating counting of visited land, make them as visted as 1's to 0's.. 
    3) Compare each island size with max size of island.. and return max_size.. 

*/ 