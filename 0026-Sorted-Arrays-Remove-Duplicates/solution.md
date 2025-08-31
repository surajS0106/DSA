The LeetCode problem is: 26. Remove Duplicates from Sorted Array

📝 Problem Restatement

You are given a sorted array nums (in non-decreasing order).

You must remove duplicates in-place so that each unique element appears only once.

You should return k, the number of unique elements.

The first k elements of nums should contain the unique values in order.

The rest of the array doesn’t matter (_ in examples).

✅ Key Observations

Array is sorted
This is huge — duplicates will always be next to each other.
Example: [0,0,1,1,1,2] → notice duplicates are consecutive.

In-place modification
We cannot use an extra array to store unique elements.
We must overwrite within nums itself.

Return k
The function doesn’t actually need to shrink the array, just return how many unique numbers there are.
LeetCode will check only the first k elements.

🔑 Solution Idea (Two Pointers Technique)

We’ll use two pointers:

i → tracks the position of the last unique element.

j → scans through the array, looking for the next different element.

Algorithm

Start with i = 0 (first element is always unique).

Loop j from 1 to n-1.

If nums[j] != nums[i], then we found a new unique number:

Increment i.

Write nums[j] into nums[i].

After the loop ends, the number of unique elements is i + 1.

🔍 Dry Run Example
Input:
nums = [0,0,1,1,1,2,2,3,3,4]

Step-by-Step Execution

Start: i = 0, nums[i] = 0

j = 1 → nums[j] = 0 (same as nums[i]) → duplicate, skip.

j = 2 → nums[j] = 1 (different!) → i = 1, nums[1] = 1.

j = 3 → nums[j] = 1 (same as nums[i]) → skip.

j = 4 → nums[j] = 1 → skip.

j = 5 → nums[j] = 2 (different!) → i = 2, nums[2] = 2.

j = 6 → nums[j] = 2 → skip.

j = 7 → nums[j] = 3 (different!) → i = 3, nums[3] = 3.

j = 8 → nums[j] = 3 → skip.

j = 9 → nums[j] = 4 (different!) → i = 4, nums[4] = 4.

Final Array:
[0,1,2,3,4,2,2,3,3,4]


(The first 5 elements are unique, rest don’t matter)

Answer:
k = i + 1 = 5

⚡ Complexity Analysis

Time Complexity: O(n) → we scan the array once.

Space Complexity: O(1) → no extra space, in-place update.

✅ Clean C++ Solution (for LeetCode)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // pointer for last unique element
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1; // number of unique elements
    }
};

🏆 Summary

Use two pointers (i for last unique, j for scanning).

Copy unique values forward into the array.

Return i + 1 as the unique count.

Array gets modified in-place with unique values at the front.

👉 Would you like me to also explain this using a visual diagram with arrows showing how i and j move at each step (like a board trace)?

You said:
yes please
ChatGPT said:

Perfect 🤝 let’s make this super visual with a diagram that shows how the two pointers i (last unique) and j (scanner) move.

Example Input
nums = [0,0,1,1,1,2,2,3,3,4]


We’ll track:

i → last unique index

j → scanning index

Step-by-Step Diagram
Start
nums = [0,0,1,1,1,2,2,3,3,4]
        ↑
        i
          ↑
          j


i=0, nums[i]=0

j=1, nums[j]=0

Duplicate → do nothing.

j = 2
nums = [0,0,1,1,1,2,2,3,3,4]
        ↑
        i
            ↑
            j


nums[j]=1 ≠ nums[i]=0

New unique → increment i → i=1

Place nums[1] = 1

nums = [0,1,1,1,1,2,2,3,3,4]

j = 3
nums = [0,1,1,1,1,2,2,3,3,4]
          ↑
          i
              ↑
              j


nums[j]=1, nums[i]=1 → duplicate → skip.

j = 4
nums = [0,1,1,1,1,2,2,3,3,4]
          ↑
          i
                ↑
                j


Still 1, duplicate → skip.

j = 5
nums = [0,1,1,1,1,2,2,3,3,4]
          ↑
          i
                    ↑
                    j


nums[j]=2 ≠ nums[i]=1

New unique → increment i → i=2

Place nums[2] = 2

nums = [0,1,2,1,1,2,2,3,3,4]

j = 6
nums = [0,1,2,1,1,2,2,3,3,4]
              ↑
              i
                        ↑
                        j


nums[j]=2, nums[i]=2 → duplicate → skip.

j = 7
nums = [0,1,2,1,1,2,2,3,3,4]
              ↑
              i
                          ↑
                          j


nums[j]=3 ≠ nums[i]=2

New unique → i=3

Place nums[3] = 3

nums = [0,1,2,3,1,2,2,3,3,4]

j = 8
nums = [0,1,2,3,1,2,2,3,3,4]
                ↑
                i
                              ↑
                              j


nums[j]=3, nums[i]=3 → duplicate → skip.

j = 9
nums = [0,1,2,3,1,2,2,3,3,4]
                ↑
                i
                                ↑
                                j


nums[j]=4 ≠ nums[i]=3

New unique → i=4

Place nums[4] = 4

nums = [0,1,2,3,4,2,2,3,3,4]

✅ Final State
nums = [0,1,2,3,4,_,_,_,_,_]


Unique count = i + 1 = 5

🎯 Big Picture

We only needed one pass (O(n)).

No extra memory used (O(1)).

Duplicates get overwritten as we go.