class Solution {
public:
vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();
    vector<int> ans(n, 1); 
    unordered_map<int, int> full; 
    set<int> dryDays; // store indices of days where we can dry

    for (int i = 0; i < n; i++) {
        if (rains[i] > 0) {
            int lake = rains[i];

            // if lake already full -> flood
            if (full.find(lake) != full.end()) {
                
                auto it = dryDays.upper_bound(full[lake]);
                if (it == dryDays.end()) {
                    
                    return {};
                }

               
                ans[*it] = lake;
                dryDays.erase(it);
            }

            full[lake] = i; 
            ans[i] = -1;   
        } else {
            dryDays.insert(i); 
        }
    }

    return ans;
}

};