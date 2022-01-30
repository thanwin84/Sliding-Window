//time: (n) and space: O(n)
class Solution {
public:
    int longestKSubstr(string s, int k) {
        // your code here
        unordered_map<int, int> table;
        int unique_char = 0;
        int i = 0;
        int j = 0;
        int ans = 0;
        int count = 0;
        bool found = false;
        while (j < s.size()) {
            if (table.count(s[j])) {
                table[s[j]] += 1;
                if (table[s[j]] == 1) {
                    unique_char++;
                }
            }
            else {
                table[s[j]] = 1;
                unique_char++;
            }
            count++;
            if (unique_char == k) {
                ans = max(ans, count);
                found = true;
            }
            else if (unique_char > k) {
                while (unique_char > k) {
                    table[s[i]] -= 1;
                    if (table[s[i]] == 0) unique_char--;
                    i++;
                    count--;
                }
            }
            j++;
        }
        if (!found) {
            return -1;
        }
        
        return ans;
    }
};
