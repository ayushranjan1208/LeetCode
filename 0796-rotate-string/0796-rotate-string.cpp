class Solution {
public:
    bool rotateString(string s, string goal) {
        goal.append(goal);
        return (goal.find(s) != string::npos);
    }
};