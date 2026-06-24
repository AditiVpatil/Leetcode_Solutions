class Solution {
public:
    bool consecutiveSetBits(int n) {
        string b = bitset<64>(n).to_string();
        b.erase(0, b.find('1')); 
        int count = 0;
        for (int i = 0; i + 1 < b.size(); i++) {
            if (b[i] == '1' && b[i+1] == '1') {
                count++;     }
        }
        return count == 1;
    }
};