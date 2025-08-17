#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0 || x % 10 ==0 && x!=0)
            return false;
        else{
            int reversedhalf = 0;
            while(x > reversedhalf){
                int digit = x%10;
                reversedhalf = reversedhalf * 10 + digit;
                x=x/10;
            }
            return(x == reversedhalf || x == reversedhalf/10);
    }}
};

int main(){

    Solution sol;
    cout << sol.isPalindrome(121) << endl; // 1 (true)
    cout << sol.isPalindrome(-121) << endl; // 0 (false)
    cout << sol.isPalindrome(10) << endl; // 0 (false)
    return 0;
}
