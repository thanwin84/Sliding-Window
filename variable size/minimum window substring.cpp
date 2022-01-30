//time: o(s)
//space: O(t)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        for (int i = 0; i < t.size(); i++) {
            if (table.count(t[i])) {
                table[t[i]] += 1;
            }
            else table[t[i]] = 1;
        }
        int unique_char = table.size();
        int ans = INT_MAX;
        int i = 0, j = 0, start = 0, end = 0;
        while (j < s.size()) {
            if (table.count(s[j])) {
                table[s[j]] -= 1;
                if (table[s[j]] == 0) {
                    unique_char--;
                }
            }
            if (unique_char == 0) {
                while (unique_char == 0) {
                    if (j - i + 1 < ans) {
                        ans = j - i + 1;
                        start = i;
                        end = j - i + 1;
                    }
                    if (table.count(s[i])) {
                        table[s[i]] += 1;
                        if (table[s[i]] == 1) unique_char++;
                    }
                    i++;
                }
            }
            j++;
        }
        return s.substr(start, end);
    }
};
