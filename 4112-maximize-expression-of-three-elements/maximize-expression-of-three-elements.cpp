class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
     int n=nums.size();
     sort(nums.begin(),nums.end());
     int s=0;
      if(n>=3){
        s= nums[n-1]+nums[n-2]-nums[0];  
      }
     return s;
    }
};