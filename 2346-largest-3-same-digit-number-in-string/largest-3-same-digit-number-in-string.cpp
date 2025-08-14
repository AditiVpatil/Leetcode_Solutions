class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> triplets;

        //  Traverse and collect triplets
        for (int i = 0; i + 2 < (int)num.size(); i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                triplets.push_back(num.substr(i, 3));
            }
        }

        //  If no triplet found, return empty
        if (triplets.empty()) return "";

        // Find the maximum triplet
        string maxTriplet = triplets[0];
        for (string &t : triplets) {
            if (t > maxTriplet) {
                maxTriplet = t;
            }
        }

        return maxTriplet;
    }
};