📄 Merge Two Sorted Lists — Documentation
📝 Problem Statement

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into a single sorted linked list. The merged list should be formed by reusing the nodes from list1 and list2 (not by creating new nodes).

Return the head of the merged linked list.

✅ Example Inputs and Outputs
Example 1
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2
Input: list1 = [], list2 = []
Output: []

Example 3
Input: list1 = [], list2 = [0]
Output: [0]

⚙️ Constraints

0 <= list1.length, list2.length <= 50

-100 <= Node.val <= 100

Both list1 and list2 are sorted in non-decreasing order.

🔑 Approach

This is just like the merge step of merge sort:

Create a dummy node to simplify handling the head.

Maintain a tail pointer to track the last node of the merged list.

Compare the current nodes of list1 and list2:

If list1->val <= list2->val, attach list1 to tail.

Else, attach list2 to tail.

Move the chosen list forward, and move tail forward.

When one list ends, attach the remaining list to tail.

Return dummy->next (skipping the fake dummy node).

📝 C++ Implementation
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to avoid edge cases
        ListNode dummy;
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // move tail forward
        }

        // Attach whichever list is not empty
        if (list1) tail->next = list1;
        else tail->next = list2;

        return dummy.next; // skip dummy, return real head
    }
};

🧮 Complexity Analysis

Time Complexity:
O(n + m)
Each node from both lists is processed exactly once.

Space Complexity:
O(1)
Only a few extra pointers are used (no extra list creation).

🚀 Example Walkthrough

Input:

list1 = [1,2,4]
list2 = [1,3,4]


Step-by-step merge:

Compare 1 and 1 → take from list1 → [1]

Compare 2 and 1 → take from list2 → [1,1]

Compare 2 and 3 → take from list1 → [1,1,2]

Compare 4 and 3 → take from list2 → [1,1,2,3]

Compare 4 and 4 → take from list1 → [1,1,2,3,4]

Append leftover → [1,1,2,3,4,4] ✅

📊 When to Use Iterative vs Recursive

Iterative (this one) → Best for interviews and production (O(1) space).

Recursive → Cleaner, shorter code, but uses O(n+m) recursion stack.