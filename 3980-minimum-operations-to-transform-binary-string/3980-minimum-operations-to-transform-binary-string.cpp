class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();

        if(n == 1 && s1[0] == '1' && s2[0] == '0') return -1;

        int steps = 0;

        for(int i = 0; i < n; i++){
            if(s1[i] == '0' && s2[i] == '1'){
                steps++;
                s1[i] = '1';
                continue;
            }
            if(i < n - 1 && s1[i] == '1' && s2[i] == '0' && s1[i+1] == '1' && s2[i+1] == '0'){
                steps++;
                s1[i] = '0';
                s1[i+1] = '0';
                continue;
            }
            if(i < n - 2 && s1[i] == '0' && s1[i+1] == '0' && s1[i+2] == '1'){
                if(s2[i] == '1' && s2[i+1] == '0' && s2[i+2] == '1'){
                    steps == 5;
                    s1[i] = '1',s2[i+1] = '0',s2[i+2] = '1';
                    continue;
                }
            }
            if(s1[i] != s2[i]){
                steps += 2;
                s1[i] = s2[i];
            }
        }
        return steps;
    }
};