class Solution {
public:
    int findLucky(vector<int>& arr) {
      unordered_map<int,int>freq;

        for(auto i: arr){
            freq[i]++;
        }
      int cnt=-1;
        for(auto j: freq){
            if(j.first==j.second){
                cnt=max(cnt, j.first);
            }
            
        }
        return cnt;
    }
};