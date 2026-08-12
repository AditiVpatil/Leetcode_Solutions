class NumArray {
    int n;
    vector<int> seg;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(2 * n);

        // Put array elements at leaves
        for (int i = 0; i < n; i++)
            seg[n + i] = nums[i];

        // Build tree
        for (int i = n - 1; i > 0; i--)
            seg[i] = seg[2 * i] + seg[2 * i + 1];
    }

    void update(int index, int val) {
        int pos = index + n;

        // Update leaf
        seg[pos] = val;

        // Update all parents
        while (pos > 1) {
            pos /= 2;
            seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
        }
    }

    int sumRange(int left, int right) {
        int l = left + n;
        int r = right + n;
        int sum = 0;

        while (l <= r) {
            // l is a right child
            if (l % 2 == 1)
                sum += seg[l++];

            // r is a left child
            if (r % 2 == 0)
                sum += seg[r--];

            l /= 2;
            r /= 2;
        }

        return sum;
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */