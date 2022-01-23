class Solution {
public:
    int search(string pat, string txt) {
        // code here
        unordered_map<char, int> table;
        int total = 0;
        for (int i = 0; i < pat.size(); i++) {
            if (table.count(pat[i])) {
                table[pat[i]] += 1;
            }
            else {
                table[pat[i]] = 1;
            }
        }
        int i = 0;
        int j = 0;
        int win_size = pat.size();
        int count = table.size();
        while (j < txt.size()) {
            if (table.count(txt[j])) {
                // it means we got a matching character
                table[txt[j]] -= 1;
                //we already got all matching characters of same type
                if (table[txt[j]] == 0) count--;
            }
            if (j - i + 1 < win_size) j++;
            else if (j - i + 1 == win_size) {
                // it means, we already got window size text
                if (count == 0) {
                    total++;
                }
                //before sliding window, we have to add the character to the table again
                //so that we can search again for next window size
                if (table.count(txt[i])) {
                    table[txt[i]] += 1;
                    if (table[txt[i]] == 1) {
                        count++;
                    }
                }
                //now slide the window
                i++;
                j++;

            }
        }
        return total;
    }

};
