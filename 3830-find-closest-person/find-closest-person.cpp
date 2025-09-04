class Solution {
public:
    int findClosest(int x, int y, int z) {

     long long a=abs(x-z);
     long long b=abs(y-z);
     
     if(min(a,b)==a && min(a,b)!=b){
         return 1;
     }

     else if(min(a,b)==b && min(a,b)!=a) {
        return 2;
     }

     else {
        return 0;
     } 

    }
};