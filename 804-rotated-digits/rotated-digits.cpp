class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dpp(n + 1, 0);
        int count = 0;

        for(int i = 0; i <= n; i++){
            if(i < 10){
                if(i == 0 || i == 1 || i == 8) dpp[i] = 1;
                else if(i == 2 || i == 5 || i == 6 || i == 9){
                    dpp[i] = 2;
                    count++;
                }
                else dpp[i] = 0;
            }
            else{
                int a = dpp[i / 10];
                int b = dpp[i % 10];

                if(a == 1 && b == 1) dpp[i] = 1;
                else if(a >= 1 && b >= 1){
                    dpp[i] = 2;
                    count++;
                }
                else dpp[i] = 0;
            }
        }

        return count;
    }
};