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
