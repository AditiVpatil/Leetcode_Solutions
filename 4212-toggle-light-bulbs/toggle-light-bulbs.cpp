class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();

        vector<bool> isOn(101, false);
        int mx = 0;

       
        for (int x : bulbs) {
            isOn[x] = !isOn[x];
            mx = max(mx, x);   
        }

        vector<int> result;
        for (int i = 1; i <= mx; i++) {
            if (isOn[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
