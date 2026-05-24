class Solution {
public:
    int passwordStrength(string password) {
         unordered_set<char> uniq(password.begin(), password.end());
        int str = 0;
        for(char ch : uniq)
        {
            if(ch >= 'a' && ch <='z')
                ++str;
            else if(ch >= 'A' && ch <= ' Z')
                str += 2;
            else if(ch >= '0' && ch <= '9')
                str += 3;
            else if(ch == '!' || ch == '@' || ch == '#' || ch == '$')
                str += 5;
        }
        return str;
    }
};