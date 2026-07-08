class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.size();
        int i = 0, l = 0, r = 0;
        while(i < n){
            if(s[i] == ' '){
                i++;
                continue;
            }

            int c = 0;
            while(i < n && s[i] != ' '){
                s[r++] = s[i++]; 
            }
            reverse(s.begin() + l,s.begin() + r);
            s[r++] = ' ';
            l = r;
            i++;
        }
        s.resize(r - 1);
        return s;
    }
};