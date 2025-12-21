class Solution {
public:
    int reverse(int n){
        string s="";
        while(n>0){
          s += (n % 10) + '0';
            n/=10;
        }
        return stoi(s);
    }
    int mirrorDistance(int n) {
      int ans=abs(reverse(n)-n);
      return ans;  
    }
};