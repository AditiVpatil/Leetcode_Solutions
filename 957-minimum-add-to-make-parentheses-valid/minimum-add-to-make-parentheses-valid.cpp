class Solution {
public:
    int minAddToMakeValid(string s) {
        int openNeeded = 0;
        int closeNeeded = 0;

        for (char c : s) {
            if (c == '(') {
                openNeeded++;
            } else if (c == ')') {
                if (openNeeded > 0) {
                    openNeeded--; // match a '('
                } else {
                    closeNeeded++; // need an extra '('
                }
            }
        }

        return openNeeded + closeNeeded;
    }
};
