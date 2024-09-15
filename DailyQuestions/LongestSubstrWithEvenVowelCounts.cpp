// Leetcode 1371

// **Q: Find the Longest Substring Containing Vowels in Even Counts**

// Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 
// 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

// Example 1:
// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of 
// the vowels: a and u.

// Example 2:
// Input: s = "leetcodeisgreat"
// Output: 5
// Explanation: The longest substring is "leetc" which contains two e's.

// Example 3:
// Input: s = "bcbcbc"
// Output: 6
// Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero 
// times.
 
// Constraints:
// 1 <= s.length <= 5 x 10^5
// s contains only lowercase English letters.


// CODE ->

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int bitmask = 0; // wtf is bitmask???!!
        unordered_map <int, int> visited;
        visited[0] = -1; // index 0 will have mask -1
        int maxl = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            switch (ch) {
                // actual bitmasking ->
                case 'a': bitmask^=(1<<0);
                case 'e': bitmask^=(1<<1);
                case 'i': bitmask^=(1<<2);
                case 'o': bitmask^=(1<<3);
                case 'u': bitmask^=(1<<4);
            }
            if (visited.find(bitmask) != visited.end()) 
                maxl = max(maxl, i - visited[bitmask]);
            else visited[bitmask] = i;
        }
        return maxl;
    }
};
