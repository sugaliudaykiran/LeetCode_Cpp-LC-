class Solution {
    public:

    static bool sortcol(const vector<int> &v1,const vector<int> &v2)
    {
        return v1[1] > v2[1];
    }

    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), sortcol);
        
        for (int i=0; i<boxTypes.size(); i++)
        {
            if (boxTypes[i][0] <= truckSize)
            {
                res += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];   
                cout << truckSize << " " << res << " ";
            }
            else if (boxTypes[i][0] > truckSize and truckSize > 0)
            {
                res += truckSize * boxTypes[i][1];     
                truckSize = 0;
                cout << truckSize << " " << res << " ";
  
            }
            else if (truckSize == 0)
            {
                return res;
            }
        }           
        return res;
    }
};