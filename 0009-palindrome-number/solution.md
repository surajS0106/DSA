✅ Solution 1: With String Conversion
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
};

🔎 Line-by-Line Explanation

string s = to_string(x);

Convert the integer x into a string.

Example: if x = 121, then s = "121".

string rev = s;

Make a copy of the string s.

Now both s = "121", rev = "121".

reverse(rev.begin(), rev.end());

Reverse the string rev in place.

For "121", reversed stays "121".

For "123", reversed becomes "321".

return s == rev;

Compare original string s with reversed string rev.

If they are equal → palindrome (true).

Else → not a palindrome (false).

📌 Pros:

Very easy to implement.

📌 Cons:

Uses extra space for strings.

Not optimal as per follow-up (since we explicitly converted to string).

✅ Solution 2: Without String Conversion (Optimized)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedhalf = 0;
        while (x > reversedhalf) {
            int digit = x % 10;
            reversedhalf = reversedhalf * 10 + digit;
            x = x / 10;
        }

        return (x == reversedhalf || x == reversedhalf / 10);
    }
};

🔎 Line-by-Line Explanation
Step 1: Handle edge cases
if (x < 0 || (x % 10 == 0 && x != 0))
    return false;


If x < 0, return false.
Example: -121 → not palindrome because of -.

If x ends with 0 but is not 0 itself, return false.
Example: 10 → reversed is 01 → not palindrome.
But 0 itself is a palindrome.

Step 2: Reverse half of the number
int reversedhalf = 0;
while (x > reversedhalf) {
    int digit = x % 10;                     // take last digit
    reversedhalf = reversedhalf * 10 + digit; // add digit to reversedhalf
    x = x / 10;                               // remove last digit from x
}


Example: x = 1221

Start: reversedhalf = 0

Iteration 1: digit = 1 → reversedhalf = 1, x = 122

Iteration 2: digit = 2 → reversedhalf = 12, x = 12

Stop when x == reversedhalf

Step 3: Compare halves
return (x == reversedhalf || x == reversedhalf / 10);


For even digit numbers (e.g., 1221):

At the end, x = 12, reversedhalf = 12 → equal ✅

For odd digit numbers (e.g., 12321):

At the end, x = 12, reversedhalf = 123

Drop the middle digit by reversedhalf / 10 = 12

Compare: x == 12 → ✅ palindrome

📌 Pros:

No string conversion.

Works in O(log₁₀(n)) time, O(1) space.

📌 Cons:

Slightly more complex logic.

⚡ So in short:

String solution: Convert → Reverse → Compare. (Easy, but less efficient)

Optimized solution: Reverse only half of the digits → Compare halves. (Efficient, no extra space)