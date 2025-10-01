class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
     long long s=numBottles;
     
    while(numBottles >= numExchange){
        long long q=numBottles/numExchange;
        long long r=numBottles % numExchange;
        s+=q;
       numBottles=q+r; 
    }
     return s;
    }
};