class Solution {
public:
    void fun(vector<int> &ans, int &low, int &high, long long cur){
        if(cur > high) return;
        if(cur != 0 && cur >= low && cur <= high){
            ans.push_back(cur);
        }
        if(cur % 10 == 9) return;
        if(cur == 0){
            for(int i = 1; i <= 9; i++){
                fun(ans,low,high,i);
            }
        }
        else{
            int d = cur % 10;
            cur = (cur * 10) + d + 1;
            fun(ans,low,high,cur);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        fun(ans,low,high,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};