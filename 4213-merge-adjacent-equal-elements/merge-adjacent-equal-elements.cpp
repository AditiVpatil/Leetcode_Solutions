class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> st;   // vector = stack

        for (int i = 0; i < nums.size(); i++) {
            long long curr = nums[i];

            while (!st.empty() && st.back() == curr) {
                curr = curr + st.back(); // sum
                st.pop_back();
            }

            st.push_back(curr);
        }
        return st;
    }
};
