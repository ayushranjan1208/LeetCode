class Solution {
public:
    bool checkAns(string &s, int &target){
        long long res = 0;
        long long last = 0, cur = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                cur = cur * 10 + (s[i] - '0');
            }

            if(!isdigit(s[i]) || i == (s.size() - 1)){
                if(sign == '+'){
                    res += last;
                    last = cur;
                }
                else if(sign == '-'){
                    res += last;
                    last = -cur;
                }
                else{
                    last = last * cur;
                }
                sign = s[i];
                cur = 0;
            }
        }
        res += last;
        return res == target;
    }
    void fun(vector<string> &ans, string &s, string &num, int &target, int ind){
        if(ind == num.size()){
            if(checkAns(s,target)) ans.push_back(s);
            return;
        }
        s.push_back('+');
        s.push_back(num[ind]);
        fun(ans,s,num,target,ind + 1);
        s.erase(s.size() - 2);

        s.push_back('-');
        s.push_back(num[ind]);
        fun(ans,s,num,target,ind + 1);
        s.erase(s.size() - 2);

        s.push_back('*');
        s.push_back(num[ind]);
        fun(ans,s,num,target,ind + 1);
        s.erase(s.size() - 2);

        bool zero = false;
        if (s.back() == '0') {
            if (s.size() == 1 || !isdigit(s[s.size() - 2])) {
                zero = true;
            }
        }
        if (!zero) {
            s.push_back(num[ind]);
            fun(ans,s,num,target,ind + 1);
            s.erase(s.size() - 1);
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string s;
        s += num[0];
        fun(ans,s,num,target,1);
        return ans;
    }
};