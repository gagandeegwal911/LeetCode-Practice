class Solution {
public:
    string process(string s) {
        string ans = "";

        for (char c : s) {
            if (c == '#') {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }

    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};