class Solution {
public:
    int minStepsToAllA(const string &s) {
        int maxSteps = 0;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                int steps = (26 - (c - 'a')) % 26; 
                maxSteps = max(maxSteps, steps);
            }
        }
        return maxSteps;
    }

    int minOperations(string s) {
        return minStepsToAllA(s);
    }
};
