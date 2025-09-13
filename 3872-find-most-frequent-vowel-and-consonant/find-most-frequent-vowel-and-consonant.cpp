class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> fv, fc;
        string vowels = "aeiouAEIOU";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());

        // Count frequencies
        for(char c : s) {
            if(isalpha(c)) {
                if(vowelSet.count(c)) fv[c]++;
                else fc[c]++;
            }
        }

        // Get max vowel freq
        int maxV = 0;
        if(!fv.empty()) {
            maxV = max_element(fv.begin(), fv.end(),
                        [](auto &a, auto &b){ return a.second < b.second; })->second;
        }

        // Get max consonant freq
        int maxC = 0;
        if(!fc.empty()) {
            maxC = max_element(fc.begin(), fc.end(),
                        [](auto &a, auto &b){ return a.second < b.second; })->second;
        }

        return maxV + maxC;
    }
};
