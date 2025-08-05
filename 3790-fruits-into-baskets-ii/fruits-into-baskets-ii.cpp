class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    vector<bool> used(baskets.size(), false);  
    int unplaced = 0;

    for (int i = 0; i < fruits.size(); ++i) {
        bool placed = false;
        for (int j = 0; j < baskets.size(); ++j) {
            if (!used[j] && fruits[i] <= baskets[j]) {
                used[j] = true; 
                placed = true;
                break;
            }
        }
        if (!placed) {
            unplaced++;  
        }
    }
    return unplaced;


    }
};