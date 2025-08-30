#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
            ListNode dummy;
            ListNode* tail = &dummy;

            while(list1 && list2){
                if(list1->val <= list2->val){
                    tail->next = list1;
                    list1 = list1->next;

            }else{
                tail->next = list2;
                list2 = list2 -> next;

            }
            tail = tail->next;
        }

        if(list1){
            tail->next = list1;
        }
        else{
            tail->next = list2;
        }
        return dummy.next;
    }
};

void printlist(ListNode* head){
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

ListNode* createlist(int arr[], int n){
    if(n==0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(int i=1; i<n; i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main(){
    Solution solution;

    // Example: list1 = [1,2,4], list2 = [1,3,4]
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    ListNode* list1 = createlist(arr1, 3);
    ListNode* list2 = createlist(arr2, 3);

    cout << "List 1: ";
    printlist(list1);

    cout << "List 2: ";
    printlist(list2);

    ListNode* merged = solution.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printlist(merged);

    return 0;
}