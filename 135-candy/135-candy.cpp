class Solution {
public:
    int candy(vector<int>& ratings) {           //  Tc -> O(n)..    SC -> O(n)..
        
        int res = 0, n = ratings.size();
        
        vector <int> left(n, 1);
        vector <int> right(n, 1);
    
        for (int i=1; i<n; i++)         //  checking the left neighbours..
        {
            if (ratings[i] > ratings[i-1])
            {
                left[i] = left[i-1] +1;         //  if cur is greater than left_neighbours then give more..
            }
        }
        
        for (int j=n-2; j>=0; j--)      //  checking the right neighbours..
        {
            if (ratings[j] > ratings[j+1])
            {
                right[j] = right[j+1] +1;      //  if cur is greater than right_neighbours then give more..
            }
        }
        
        for (int k=0; k<n; k++)
        {
            res += max(left[k], right[k]);      //  Finally does max of it's both neighbours..
        }
        return res;
    }
};