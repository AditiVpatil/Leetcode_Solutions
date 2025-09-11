class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };

        // Count frequencies of vowels
        vector<int> freq(128, 0); // ASCII size
        for (char c : s) {
            if (isVowel(c)) freq[c]++;
        }

        // Replace vowels in sorted order using counting sort
        string order = "AEIOUaeiou";  
        int pos = 0;
        for (char &c : s) {
            if (isVowel(c)) {
                // Find next available vowel in sorted order
                while (pos < order.size() && freq[order[pos]] == 0) {
                    pos++;
                }
                c = order[pos];
                freq[order[pos]]--;
            }
        }
        return s;
    }
};
