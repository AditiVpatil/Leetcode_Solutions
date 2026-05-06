class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size() ;
        vector<int>ans ;
        vector<int>closest(n) ;
        for(int i=0;i<n;i++){
            if(i==0) closest[i]=1 ;
            else if(i==n-1) closest[i]=n-2 ;
            else {
                int leftdiff=nums[i]-nums[i-1] ;
                int rightdiff=nums[i+1]-nums[i] ;
                if(leftdiff<=rightdiff) closest[i]=i-1 ;
                else closest[i]=i+1 ;   
            }
        }
         vector<long long> forward(n - 1);

        for (int i = 0; i < n - 1; i++) {
            if (closest[i] == i + 1) {
                forward[i] = 1;
            } else {
                forward[i] = nums[i + 1] - nums[i];
            }
        }
         vector<long long> backward(n);

        for (int i = 1; i < n; i++) {
            if (closest[i] == i - 1) {
                backward[i] = 1;
            } else {
                backward[i] = nums[i] - nums[i - 1];
            }
        } 
        vector<long long> fwdPrefix(n, 0), bwdPrefix(n, 0);
        for (int i = 1; i < n; i++) {
            fwdPrefix[i] = fwdPrefix[i - 1] + forward[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            bwdPrefix[i] = bwdPrefix[i + 1] + backward[i + 1];
        }
        

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            if (l < r) {
                ans.push_back(fwdPrefix[r] - fwdPrefix[l]);
            } else {
                ans.push_back(bwdPrefix[r] - bwdPrefix[l]);
            }
        }

        return ans;

        
    }
};