#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> values = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}
        };

        int total = 0;
        for ( int i =0; i < s.size(); i++){
            if ( i+1 < s.size() && values[s[i]] < values [s[i+1]]){
                total= total - values[s[i]];
            }
            else{
                total = total + values[s[i]];
            }
        }
        return total;
        
    }
};

//quick test

int main(){
    Solution sol;
    cout << sol.romanToInt("III") << endl; // 3
    cout << sol.romanToInt("LVIII") << endl;    // 58
    cout << sol.romanToInt("MCMXCIV") << endl;  // 1994
    return 0;
}