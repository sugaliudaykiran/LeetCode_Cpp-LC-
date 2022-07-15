class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        n = grid.size(), m = grid[0].size();
        
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
    

*/ 