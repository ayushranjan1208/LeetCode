class Solution {
public:
    string fractionAddition(string s) {
        int n = s.size();
        int den = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '/'){
                int d = s[i+1] - '0';
                if(i < n - 2){
                    if(s[i+2] == '0') d = 10;
                }
                if(den == 0) den = d;
                else den = den * d / __gcd(den, d);
            }
        }
        int num = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '/'){
                int d = s[i+1] - '0';
                if(i < n - 2){
                    if(s[i+2] == '0') d = 10;
                }
                int x = den / d;
                int d1 = s[i-1] - '0';
                
                int sign = 0;
                if(i >= 2 && s[i-2] == '1'){
                    d1 = 10;
                    if(i >= 3){
                        if(s[i-3] == '-') sign = -1;
                    }
                    else sign = 1;
                }
                x *= d1;
                if(sign == 0){
                    if(i >= 2 && s[i-2] == '-') x *= -1;
                }
                else x*= sign;
                
                num += x;
                cout<<x<<endl;
            }
        }
        int hcf = abs(__gcd(num,den));
        num /= hcf;
        den /= hcf;

        string ans;
        ans.append(to_string(num));
        ans.push_back('/');
        ans.append(to_string(den));

        return ans;
    }
};