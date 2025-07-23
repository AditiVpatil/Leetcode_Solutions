class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        for (int i = 0; i < s.length(); i++) {
            // Rotate s by 1 (left rotation)
            rotate(s.begin(), s.begin() + 1, s.end());
               if (s == goal) return true;
        }
        return s == goal; // if  they are already equal
    }
};
