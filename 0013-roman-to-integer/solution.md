✅ Approach

Roman numerals are read left to right.

Normally, we add values (e.g., "XII" = 10 + 1 + 1 = 12).

But if a smaller value appears before a larger one, we subtract (e.g., "IV" = 5 - 1 = 4).

So, algorithm:

Map each Roman symbol to its value.

Traverse the string from left to right:

If the current symbol is smaller than the next symbol, subtract it.

Otherwise, add it.

✅ C++ Solution
class Solution {
public:
    int romanToInt(string s) {
        // Map Roman numerals to integers
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            // If current value < next value, subtract
            if (i + 1 < s.size() && values[s[i]] < values[s[i + 1]]) {
                total -= values[s[i]];
            } 
            // Else add
            else {
                total += values[s[i]];
            }
        }
        return total;
    }
};

🔎 Line-by-Line Explanation
unordered_map<char, int> values = { ... };


Create a map of Roman numeral characters and their values.

int total = 0;


Store the final integer result.

for (int i = 0; i < s.size(); i++) { ... }


Loop through each character in the string s.

if (i + 1 < s.size() && values[s[i]] < values[s[i + 1]])
    total -= values[s[i]];


If the current value is smaller than the next one → subtract it.

Example: "IV" → at I, check next V → 1 < 5 → subtract 1.

else total += values[s[i]];


Otherwise, add the value normally.

Return total.

✅ Examples
Example 1: "III"

I = 1, I = 1, I = 1 → 1 + 1 + 1 = 3.

Example 2: "LVIII"

L = 50, V = 5, III = 3 → 50 + 5 + 3 = 58.

Example 3: "MCMXCIV"

M = 1000

CM = 900 (since C < M)

XC = 90 (since X < C)

IV = 4 (since I < V)

Total = 1000 + 900 + 90 + 4 = 1994.

⚡ Runs in O(n) time, where n = length of string, and uses O(1) extra space.

