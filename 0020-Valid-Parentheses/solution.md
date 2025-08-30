📄 Valid Parentheses Problem — C++ Solution
Problem Statement

You are given a string s containing only the characters:

'(' , ')' , '{' , '}' , '[' , ']'

You need to determine if the string is valid.

A string is valid if:

Open brackets are closed by the same type of bracket.

Open brackets are closed in the correct order.

Every closing bracket has a corresponding opening bracket.

Examples
Input	Output	Explanation
"()"	true	A simple pair of brackets.
"()[]{}"	true	Multiple valid pairs.
"(]"	false	Wrong type of closing bracket.
"([])"	true	Nested valid brackets.
"([)]"	false	Wrong order of closing.
Approach: Using Stack
Key Idea

We need to check brackets in Last-In-First-Out (LIFO) order:

The last opened bracket should be the first one to close.

A stack is the perfect data structure for this.

Steps

Create an empty stack of characters.

Traverse the string s character by character:

If the character is an opening bracket ((, {, [), push it onto the stack.

If the character is a closing bracket (), }, ]):

Check if the stack is empty → return false (no matching opening bracket).

Otherwise, pop the top element and check if it matches the type of the closing bracket.

If it doesn’t match → return false.

After processing all characters:

If the stack is empty → all brackets matched correctly → return true.

Otherwise → return false.

C++ Implementation
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    cout << boolalpha; // prints true/false instead of 1/0
    cout << isValid("()") << endl;       // true
    cout << isValid("()[]{}") << endl;   // true
    cout << isValid("(]") << endl;       // false
    cout << isValid("([])") << endl;     // true
    cout << isValid("([)]") << endl;     // false
}

Complexity Analysis

Time Complexity: O(n)

Each character is processed once.

Stack operations (push/pop) take constant time.

Space Complexity: O(n)

In the worst case, all characters are opening brackets, stored in the stack.

Advantages of Stack Approach

✔ Simple and efficient.
✔ Naturally handles nested brackets.
✔ Works for any combination of brackets.

👉 This solution is widely accepted in coding interviews and online judges (like LeetCode).