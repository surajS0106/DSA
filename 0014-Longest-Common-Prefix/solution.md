✅ Idea

We need to find the longest prefix that is common across all strings in the array.

Approaches

Horizontal Scanning (compare prefix with each string).

Vertical Scanning (check characters column by column).

Sorting Trick (longest prefix of first & last string after sorting).

✅ C++ Solution (Horizontal Scanning)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0]; // start with the first word
        for (int i = 1; i < strs.size(); i++) {
            // shrink prefix until it matches the start of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

// quick test
int main() {
    Solution sol;

    vector<string> test1 = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(test1) << endl; // "fl"

    vector<string> test2 = {"dog", "racecar", "car"};
    cout << sol.longestCommonPrefix(test2) << endl; // ""

    return 0;
}

🔎 Explanation

Start with the first string as the prefix.

string prefix = strs[0];


Iterate through the rest of the array:

for (int i = 1; i < strs.size(); i++) {


If the current string does not start with prefix, shorten it.

Example: "flower" and "flow" → "flow".

Then "flow" and "flight" → "fl".

Stop when prefix becomes empty → no common prefix.

✅ Example Walkthrough

Input: ["flower","flow","flight"]

Start: prefix = "flower"

Compare with "flow" → prefix reduces to "flow"

Compare with "flight" → prefix reduces to "fl"

Final: "fl"

Input: ["dog","racecar","car"]

Start: prefix = "dog"

Compare with "racecar" → prefix shrinks → ""

Stop → return ""

⚡ Time Complexity: O(N * M)

N = number of strings

M = average length of string

Space Complexity: O(1)