class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        
        hC.push_back(h);
        vC.push_back(w);
        
        sort(hC.begin(), hC.end());
        sort(vC.begin(), vC.end());
        
        int hMax = hC[0];
        for (int i=1; i<hC.size(); i++)
        {
            int cur_hc = hC[i] - hC[i-1];
            hMax = max(hMax, cur_hc);
        }
        
        int vMax = vC[0];
        for (int i=1; i<vC.size(); i++)
        {
            int cur_vc = vC[i] - vC[i-1];
            vMax = max(vMax, cur_vc);
        }
        
        long int res = 1LL * vMax * hMax;
        return res % int(1e9 + 7);
    }
};