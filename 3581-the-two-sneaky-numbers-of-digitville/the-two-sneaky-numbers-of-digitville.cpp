class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
       vector<int>res;
       unordered_map<int,int>mp;
       for(auto i:nums){
        mp[i]++;
       } 

       for(auto j:mp){
        if(j.second>1){
            res.push_back(j.first);
        }
       }
       return res;
    }
};