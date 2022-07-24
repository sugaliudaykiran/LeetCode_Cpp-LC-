class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Using Binary search because, rows are sorted..TC -> O(M logN)..
        
        int low, high, mid;
        
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i=0; i<m; i++)
        {
            if (matrix[i][0] <= target && matrix[i][n-1] >= target)
            {
                low = 0, high = n;
                if (low == high  && matrix[i][low] == target)
                {
                    return true;
                }
                
                while (low < high)
                {
                    mid  = (low + (high-1))/2;
                    if (matrix[i][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[i][mid] > target)
                    {
                        high = mid;
                    }
                    else
                    {
                        low = mid +1;
                    }
                }
            }
        }return false;
    }
};

