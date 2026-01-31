class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0, end = letters.size() - 1;
        
        
        if (target >= letters[end]) {
            return letters[0];
        }

        // Perform binary search to find the next greatest letter
        while (start <= end) {
            int mid = start + (end - start) / 2;

            
            if (letters[mid] <= target) {
                start = mid + 1;
            } else {
                
                end = mid - 1;
            }
        }

        
        return letters[start];
    }
};
