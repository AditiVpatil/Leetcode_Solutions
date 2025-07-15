class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n < 3) return false;

        int vowels = 0, consonants = 0;

        for (char c : s) {
            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    vowels++;
                } else {
                    consonants++;
                }
            } else if (!isdigit(c)) {
                return false; // invalid character
            }
        }

        return vowels >= 1 && consonants >= 1;
    }
};
