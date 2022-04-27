s = "dcab", pairs = [[0,3],[1,2],[0,2]] ***
​
Then 0---3 is forming one group let's say 0
1--2 is forming one group let's say 1
again 0--2 is forming group since 0 and 2 was already in group , hence everyone is under same group (DSU)
**0-1-2-3 is under same group . Hence we have only 1 connected component **.
​
So, we have one connected component
index-> 0 1 2 3
Now "d c a b" sort the connected component i.e sort indexes (0,1,2,3)
"a b c d" sorted (0,1,2,3)
​
"a b c d" (answer)
class Solution {
vector<int>parent;
public:
int findParent(int n){
if(parent[n]==n){
return n;
}
return parent[n] = findParent(parent[n]);
}
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
parent.resize(s.length());
map<int , set<int>>obj;
set<int>idx;
string ans=s;
for(int i=0; i<parent.size(); i++){
parent[i]=i;
}
for(int i=0; i<pairs.size(); i++){
int u = pairs[i][0];
int v = pairs[i][1];
int fx = findParent(u);
int fy = findParent(v);
if(fx!=fy){
parent[fy]=fx;
}