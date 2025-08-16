class Solution {
public:
    int maximum69Number(int num) {
    int temp = num, pos = -1, p = 0;
    while (temp > 0) {
        if (temp % 10 == 6) pos = p;
        temp /= 10;
        p++;
    }
    if (pos != -1) num += 3 * pow(10, pos);
    return num;
}

};