class Solution:

    def search(self, pat, txt):
        result = 0
        hashmap = {}
        for i in pat:
            if i in hashmap:
                hashmap[i] += 1
            else:
                hashmap[i] = 1
        n = len(txt)
        k = len(pat)
        count = len(hashmap)
        i = 0
        j = 0
        while j < n:
            if txt[j] in hashmap:
                hashmap[txt[j]] -= 1
                if hashmap[txt[j]] == 0:
                    count -= 1
            # if windows size equal to k, slide the window
            if j + 1 - i == k:
                if count == 0:
                    result += 1
                # before sliding window, we have to remove element which is out of window
                # before doing this, we have to check if the txt[i] exist in dictionary
                # if so, add 1 to hashmap[txt[i]]
                if txt[i] in hashmap:
                    hashmap[txt[i]] += 1
                    if hashmap[txt[i]] == 1:
                        count += 1

                i += 1
            j += 1
        return result
ob = Solution()
print(ob.search('for', "forxxorfxdofr"))


