class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

    while (true) {
        int smallest = INT_MAX;
        for (int n : nums) {
            if (n > 0)
                smallest = min(smallest, n);
        }

        if (smallest == INT_MAX)
            break;

        for (int &n : nums) {
            if (n > 0)
                n -= smallest;
        }

        operations++;
    }

    return operations;
    }
};