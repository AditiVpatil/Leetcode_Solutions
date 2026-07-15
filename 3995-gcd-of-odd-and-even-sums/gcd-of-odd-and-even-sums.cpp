class Solution {
public:

  long long gcd(long long a, long long b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
  }
   long long gcdOfOddEvenSums(long long n) {
        long long a=0;
        long long b=0;
        for(long long i=1;i<=2*n;i++){
            if((i%2)==0){
                a+=i;
            }
            else{
                b+=i;
            }
        }
      return gcd(a,b);
    }

   
};