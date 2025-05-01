#include <iostream>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Helper function to print the linked list
    void printList(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    // Function to split the linked list into two halves
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        // Using slow and fast pointer technique to find the middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        // Create a dummy node to simplify merging
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        // Compare and merge the two sorted lists
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        
        // Attach the remaining part of either list
        if (left != nullptr) {
            current->next = left;
        } else {
            current->next = right;
        }
        
        return dummy.next;
    }
    
    // Main merge sort function for linked lists
    ListNode* mergeSort(ListNode* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Find the middle of the list
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr; // Split the list into two halves
        
        // Recursively sort both halves
        ListNode* leftSorted = mergeSort(head);
        ListNode* rightSorted = mergeSort(right);
        
        // Merge the sorted halves
        return merge(leftSorted, rightSorted);
    }

    // Helper function to create a list from an array
    ListNode* createList(std::initializer_list<int> values) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (int val : values) {
            ListNode* newNode = new ListNode(val);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        return head;
    }
};

int main() {
    Solution solution;

    // Create a linked list from an array
    ListNode* head = solution.createList({35, 62, 15, 24, 40, 7});

    std::cout << "Original list: ";
    solution.printList(head);

    // Sort the linked list using MergeSort
    ListNode* sortedList = solution.mergeSort(head);

    std::cout << "Sorted list: ";
    solution.printList(sortedList);

    return 0;
}