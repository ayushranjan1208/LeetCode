class Solution {
public:
    vector<vector<int>> ans;
    void fun(int k, int n, int &mask,int st){
        if(n == 0 && k == 0){
            vector<int> v;
            for(int i = 1; i <= 9; i++){
                if(mask & (1 << i)) v.push_back(i);
            }
            ans.push_back(v);
            return;
        }
        if(n == 0 || k == 0) return;

        for(int i = st; i <= 9; i++){
            if(i > n) break;

            if(mask & (1 << i)) continue;
            mask = mask | (1 << i);
            fun(k - 1, n - i, mask, i + 1);  
            mask = mask ^ (1 << i);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int mask = 0;
        fun(k,n,mask,1);
        return ans;
    }
};