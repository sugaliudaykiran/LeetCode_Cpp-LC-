​
bool searchMatrix(vector<vector<int>>& matrix, int target) {
int m = matrix.size(), n = matrix[0].size();
int  i=0, j = n-1;  // check "right top" most.. in this case we choose it.. or "left Bottom"
while (i <= m-1 && j >= 0)   // Please check it clearly.. Is their in Limit..
{
if (matrix[i][j] == target)  //  if cur == target then found..
{
return true;
}
else if (matrix[i][j] > target)  // if cur greater than target then 'move left wards'..
{
j--;
}
else if (matrix[i][j] < target) //  if cur lesser than target then 'move down wards'..
{
i++;
}
}
return false;
}
};
​
​
​