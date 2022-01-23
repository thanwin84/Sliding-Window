class Solution:
	def search(self,pat, txt):
	    # code here
	    table = {}
	    n = len(txt)
	    for i in range(len(pat)):
	        if pat[i] in table:
	            table[pat[i]] += 1
	        else:
	            table[pat[i]] = 1
	    count = len(table)
	    i = 0
	    j = 0
	    total = 0
	    while j < n:
	        if txt[j] in table:
	           table[txt[j]] -= 1
	           if table[txt[j]] == 0:
	               count -= 1
	        if j - i + 1 < len(pat):
	           j += 1
	        elif j - i + 1 == len(pat):
	            if count == 0:
	                total += 1
	            if txt[i] in table:
	                table[txt[i]] += 1
	                if table[txt[i]] == 1:
	                    count += 1
	            i += 1
	            j += 1
	    return total
