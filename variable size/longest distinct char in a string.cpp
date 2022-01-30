int longestSubstrDistinctChars(string S)
{
    // your code here
    unordered_map<char, int> table;
    int ans = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while (j < S.size()) {
        if (table.count(S[j])) {
            table[S[j]] += 1;
        }
        else table[S[j]] = 1;
        count++;
        if (table[S[j]] > 1) {
          //keep moving window till we are left with distinc character
            while (table[S[j]] > 1) {
              // remove character only if it exists in table
                if (table[S[i]] >= 1) {
                    table[S[i]] -= 1;
                }
                i++;
                count--;
            }
            
            
        }
        else {
            ans = max(ans, count);
        }
        j++;
    }
    return ans;
}
