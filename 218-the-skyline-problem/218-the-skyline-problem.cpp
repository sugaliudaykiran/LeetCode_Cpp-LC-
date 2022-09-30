class Solution {

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, pair<int, int>>> sky;
        //1 is start
        //2 is end
        for(auto v:buildings){
            int start = v[0];
            int finish = v[1];
            int h = v[2];
            sky.push_back(make_pair(start, make_pair(h, 1)));
            sky.push_back(make_pair(finish, make_pair(h, 2)));
        }
        
        sort(sky.begin(), sky.end());
        
        vector<vector<int>> res;
        multiset<int> height;
        height.insert(0);
        int max_h = 0;
        for(auto v:sky){
            int point = v.first;
            int h = v.second.first;
            int ch = v.second.second;
            
            if(ch==1){
                //start height
                height.insert(h);
                while(!res.empty() && res[res.size()-1][0]==point && res[res.size()-1][1] < *(height.rbegin())){
                    res.pop_back();
                }
                if(*(height.rbegin()) > max_h){
                    res.push_back({point, h});
                    max_h = *(height.rbegin());
                }
            }
            else{
                //end height
                height.erase(height.find(h));
                while(!res.empty() && res[res.size()-1][0]==point && res[res.size()-1][1] > *(height.rbegin())){
                    res.pop_back();
                }
                if(*(height.rbegin()) < max_h){
                    res.push_back({point, *(height.rbegin())});
                    max_h = *(height.rbegin());
                }
            }
          
        }
        
        return res;
    }
};