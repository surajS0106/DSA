#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0;
    cout << "Start: nums = ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    for (int j = 1; j < nums.size(); j++) {
        cout << "\nChecking j=" << j 
             << ", nums[j]=" << nums[j] 
             << ", nums[i]=" << nums[i] << endl;

        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
            cout << "  Found new unique → move i to " << i << ", nums = ";
            for (int n : nums) cout << n << " ";
            cout << endl;
        } else {
            cout << "  Duplicate found → do nothing" << endl;
        }
    }

    cout << "\nEnd: nums = ";
    for (int n : nums) cout << n << " ";
    cout << ", unique count = " << i + 1 << endl;

    return i + 1;
}

int main() {
    vector<int> nums1 = {1, 1, 2};
    cout << "\n=== Example 1 ===" << endl;
    int k1 = removeDuplicates(nums1);

    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    cout << "\n=== Example 2 ===" << endl;
    int k2 = removeDuplicates(nums2);

    return 0;
}
