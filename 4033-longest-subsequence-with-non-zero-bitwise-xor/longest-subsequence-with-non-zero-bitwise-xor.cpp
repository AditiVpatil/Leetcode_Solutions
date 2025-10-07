class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
      int XOR=0 ;
        for(int x:nums) {
            XOR^=x;
        }    
        if(XOR!=0){
          return nums.size();
        }  
        bool  all=true ;
        for(int x:nums){
            if(x!=0){
                all=false ;
                break ;
            }
        }
        if(all) {
            return 0 ;
        }    
         return nums.size()-1 ;
    }
};