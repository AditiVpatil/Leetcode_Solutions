class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> fromS;
        unordered_map<char, char> fromT; 

        for (int i = 0; i < s.size(); i++) {
            char chS = s[i];
            char chT = t[i];

            // Check if chS already mapped to some character
            if (fromS.count(chS)) {
                if (fromS[chS] != chT)
                    return false;
            } else {
                fromS[chS] = chT;
            }

            // Check if chT already mapped to some character
            if (fromT.count(chT)) {
                if (fromT[chT] != chS)
                    return false;
            } else {
                fromT[chT] = chS;
            }
        }

        return true;
    }
};
