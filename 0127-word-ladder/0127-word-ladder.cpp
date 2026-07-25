class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto s : wordList) st.insert(s);

        queue<pair<string,int>> q;

        q.push({beginWord,1});

        while(!q.empty()){
            auto [s,steps] = q.front();
            q.pop();

            if(s == endWord) return steps;

            for(int i = 0; i < s.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    string temp = s;
                    temp[i] = c;
                    if(st.find(temp) != st.end()){
                        q.push({temp,steps + 1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};