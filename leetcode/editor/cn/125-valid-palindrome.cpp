#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(string s) {
		int l = getNext(s, 0), r = getPrev(s, s.length() - 1);
		while (l < r) {
			if (!equalsIgnoreCase(s[l], s[r])) return false;
			l = getNext(s, l + 1);
			r = getPrev(s, r - 1);
		}
		return true;
    }

private:
	bool isDigitalOrLetter(char ch) {
		return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
	}

	int getNext(string & s, int i) {
		while (i < s.length() && !isDigitalOrLetter(s[i])) ++i;
		return i;
	}

	int getPrev(string & s, int i) {
		while (i >= 0 && !isDigitalOrLetter(s[i])) --i;
		return i;
	}

	bool equalsIgnoreCase(char ch1, char ch2) {
		if (ch1 >= 'A' && ch1 <= 'Z') ch1 = ch1 - 'A' + 'a';
		if (ch2 >= 'A' && ch2 <= 'Z') ch2 = ch2 - 'A' + 'a';
		return ch1 == ch2;
	}
};
//leetcode submit region end(Prohibit modification and deletion)
