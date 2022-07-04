class Solution {
public:
    int candy(vector<int>& ratings) {           //  Tc -> O(n)..    SC -> O(n)..
        
        int res = 0, n = ratings.size();
        
        vector <int> left(n, 1);
        vector <int> right(n, 1);
    
        for (int i=1; i<n; i++)
        {
            if (ratings[i] > ratings[i-1])
            {
                left[i] = left[i-1] +1;
            }
        }
        
        for (int j=n-2; j>=0; j--)
        {
            if (ratings[j] > ratings[j+1])
            {
                right[j] = right[j+1] +1;
            }
        }
        
        for (int k=0; k<n; k++)
        {
            res += max(left[k], right[k]);
        }
        return res;
    }
};