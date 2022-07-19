class Solution {
public:
    vector<vector<int>> generate(int numRows) {
//         TC -> O(n^2).. SC -> O(n^2)..
        
        vector <vector <int>> res(numRows); //  Created an vector of vector of size numRows..
        for (int i=0; i<numRows; i++)   //  Traverse from 0 to numRows..
        {
            res[i].resize(i+1); //  every row has it's index+1 size..
            res[i][0] = res[i][i] = 1;  // every initially and finial index's of value 1..
            
            for (int j=1; j<i; j++) // Fill the remaining value by using it's previous row index's previous ones..
            {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};