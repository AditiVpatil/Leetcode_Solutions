class Solution {
public:
    
    int maximumSwap(int num) {
        string numstr = to_string(num);

        int maxidx = -1; int maxdigit = -1;
        int leftidx = -1; int rightidx = -1;        

        for (int i = numstr.size() - 1; i >= 0; --i) {
            // current digit is the largest by far
            if (numstr[i] > maxdigit) {
                maxdigit = numstr[i];
                maxidx = i;
                continue;
            }

            // best candidate for max swap  
            if (numstr[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        if (leftidx == -1) return num;

        swap(numstr[leftidx], numstr[rightidx]);

        return stoi(numstr);
    }
};