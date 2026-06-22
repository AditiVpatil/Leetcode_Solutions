class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int res = 0;

        while (true) {
            string word = "balloon";

            for (char &c : word) {
                bool found = false;

                for (char &ch : text) {
                    if (ch == c) {
                        ch = '#';
                        found = true;
                        break;
                    }
                }

                if (!found) return res;
            }

            res++;
        }
    }
};