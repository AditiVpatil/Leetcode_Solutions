class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    int cnt=0;

    for(int i=0;i<n;i++){
        if(nums[i]<10) sum+=nums[i];
        else cnt+=nums[i];
    } 
    return cnt!=sum;   
    }
};