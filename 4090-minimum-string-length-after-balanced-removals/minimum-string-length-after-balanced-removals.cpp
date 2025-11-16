class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int countA = 0, countB = 0;
        
        for(char c : s) {
            if(c == 'a') countA++;
            else if(c == 'b') countB++;

            if(countA == countB) {
                countA = 0;
                countB = 0;
            }
        }

        return abs(countA - countB);
    }
};
