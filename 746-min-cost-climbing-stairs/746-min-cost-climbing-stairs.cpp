class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();    //  TC -> O(n).. SC -> O(1)..
        
        cost.push_back(0);  //  ADD a nth item because to reach top of floor.. it takes 0 time..
        
        for (int i=n-2; i>=0; i--)  //  traverse from right to left [which can't be 'n and n-1' case..]
        {
            cost[i] += min(cost[i+1], cost[i+2]);   // find min of both it's next by 1 and next by 2 steps..
        }
        return min(cost[0], cost[1]);  // return min of first two steps.. it required result.
    }
};