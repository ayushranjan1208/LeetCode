struct Node {
    Node* bit[2];
    int min_val[2] = {INT_MAX, INT_MAX};

    bool containsKey(int b){
        return bit[b] != NULL;
    }

    void set(int b, Node* node){
        bit[b] = node;
    }

    Node* get(int b){
        return bit[b];
    }

    void update_val(int b, int val){
        min_val[b] = min(min_val[b],val);
    }

    int get_val(int b){
        return min_val[b];
    }
};

class Solution {
private: Node* root;
public:
    Solution(){
        root = new Node();
    }
    void insert(int n){
        Node* node = root;
        for(int i = 30; i >= 0; i--){
            bool bit = (1 << i) & n;
            if(!node->containsKey(bit)){
                node->set(bit, new Node());
            }
            node->update_val(bit, n);
            node = node->get(bit);
        }
    }

    int find(int n, int m){
        Node* node = root;
        int num = 0;
        for(int i = 30; i >= 0; i--){
            bool bit = (1 << i) & n;
            int mini0 = node->get_val(0);
            int mini1 = node->get_val(1);
            if(bit == 1){
                if(mini0 <= m){
                    node = node->get(0);
                }
                else if(mini1 <= m){
                    num += (1 << i);
                    node = node->get(1);
                }
                else return -1;
            }
            else{
                if(mini1 <= m){
                    num += (1 << i);
                    node = node->get(1);
                }
                else if(mini0 <= m){
                    node = node->get(0);
                }
                else return -1;
            }
        }

        return num;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &e : nums) insert(e);

        vector<int> ans;
        for(auto &q : queries){
            int num = find(q[0], q[1]);
            if(num == -1) ans.push_back(-1);
            else{
                ans.push_back(num ^ q[0]);
            }
        }

        return ans;

    }
};