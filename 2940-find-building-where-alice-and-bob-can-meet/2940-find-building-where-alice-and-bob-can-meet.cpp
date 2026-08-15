class Solution {
public:
    int n;
    vector<int> segTree;
    void buildSegTree(int i, int l, int r, vector<int> &heights){
        if(l == r){
            segTree[i] = l;
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(2*i+1, l, mid, heights);
        buildSegTree(2*i+2, mid + 1, r, heights);

        int lId = segTree[2*i+1];
        int rId = segTree[2*i+2];

        if(heights[lId] >= heights[rId]) segTree[i] = lId;
        else segTree[i] = rId;
    }

    int queryMaxIndex(int st, int en, int i, int l, int r, vector<int> &heights){
        if(l > en || r < st) return -1;

        if(st <= l && r <= en) return segTree[i];

        int mid = (l + r) / 2;
        int lId = queryMaxIndex(st, en, 2*i+1, l, mid, heights);
        int rId = queryMaxIndex(st, en, 2*i+2, mid + 1, r, heights);

        if(lId == -1) return rId;
        if(rId == -1) return lId;

        if(heights[lId] >= heights[rId]) return lId;
        return rId;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n = heights.size();
        segTree.assign(4*n, 0);
        buildSegTree(0, 0, n - 1, heights);

        vector<int> ans;
        for(auto &q : queries){
            int l = min(q[0],q[1]), r = max(q[0],q[1]);
            if(l == r){
                ans.push_back(l);continue;
            }
            if(heights[r] > heights[l]){
                ans.push_back(r);continue;
            }

            int mx = max(heights[l], heights[r]);
            int lo = r + 1, hi = n - 1;
            int id = -1;

            while(lo <= hi){
                int mid = (lo + hi) / 2;
                int i = queryMaxIndex(lo, mid, 0, 0, n - 1, heights);

                if(heights[i] > mx){
                    id = i;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }

            ans.push_back(id);
        }

        return ans;
    }

};