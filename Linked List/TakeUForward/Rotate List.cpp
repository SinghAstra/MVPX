#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        next = nullptr;
    }
};

void printLinkedList(ListNode* head){
     cout << "Elements in Linked List : ";
    ListNode* traverseNode = head;
    while(traverseNode !=nullptr){
        cout << traverseNode->val << " ";
        traverseNode = traverseNode->next;
    }
    cout << endl;
}

// Approach 1 : Brute Force Approach 
// - Brute Force with Temporary Storage 
// - Split and Reattach Approach
// Time Complexity: O(n) - In the worst case, it iterates through the list twice.
// Space Complexity: O(n) - In the worst case, it creates a temporary vector to store list elements.

ListNode* rotateRightBruteForce(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr || k==0){
        // Handle empty list, single-node list, or k=0: return head as is
        return head;
    }

    // Find the length of the linked list
    int len = 0;
    ListNode* traverseNode = head;
    while(traverseNode !=nullptr){
        traverseNode = traverseNode->next;
        len++;
    }

    // Handle the case where k is a multiple of the list length (no rotation)
    k = k % len;
    if (k == 0){
        return head;
    }

    // Find the node k positions before the end (new tail)
    int index = 0;
    int pos = len - k;
    traverseNode = head;
    while(index<pos-1){
        traverseNode = traverseNode->next;
        index++;
    }

    // Split the list at the new tail
    ListNode* tempHead = traverseNode->next;
    traverseNode->next = nullptr;


    // Create a temporary vector to store elements (optional, less efficient in space)
    vector<int> elems;
    while(tempHead!=nullptr){
        elems.push_back(tempHead->val);
        tempHead = tempHead->next;
    }

    // Build a new linked list from the elements and attach the original head
    ListNode* newHead = new ListNode(elems[0]);
    ListNode* temp = newHead;
    for(int i=1; i<elems.size();i++){
        ListNode* newNode = new ListNode(elems[i]);
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = head;
    return newHead;
}


// Approach: In-Place List Reversal - Split and Reattach with Traversal 
// Time Complexity: O(n) - Iterates through the list a maximum of thrice.
// Space Complexity: O(1) - Uses constant extra space for pointers.
ListNode* rotateRightSplitAndReattach(ListNode* head, int k) {

    if(head == nullptr || head->next == nullptr || k==0){
        // Handle empty list, single-node list, or k=0: return head as is
        return head;
    }

    // Find the length of the linked list
    int len = 0;   
    ListNode* traverseNode = head;
    while (traverseNode !=nullptr){
        traverseNode = traverseNode->next;
        len++;
    }

    // Handle the case where k is a multiple of the list length (no rotation)
    k = k % len;
    if (k == 0){
        return head;
    }

    int index = 0;
    int pos = len - k;
    traverseNode = head;
    while(index<pos-1){
        traverseNode = traverseNode->next;
        index++;
    }
    // Split the list at the new tail
    ListNode* newHead = traverseNode->next;
    traverseNode->next = nullptr;

    // Reattach the tail node to the head of the list
    ListNode* temp = newHead;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = head;
    return newHead;
    }




// Approach: In-Place List Reversal - Floyd's Cycle Finding Algorithm (Modified)
//
// This function rotates a linked list to the right by k positions without using
// any extra space for temporary storage. It leverages a modified version of
// Floyd's Cycle Finding Algorithm.
//
// Time Complexity: O(n) - Iterates through the list a maximum of twice.
// Space Complexity: O(1) - Uses constant extra space for pointers.
ListNode* rotateRightInPlaceListTraversal(ListNode* head, int k){
        
   if(head == nullptr || head->next == nullptr || k==0){
        // Handle empty list, single-node list, or k=0: return head as is
        return head;
    }

    // Find the length of the linked list
    int len = 1;   
    ListNode* traverseNode = head;
    while (traverseNode->next !=nullptr){
        traverseNode = traverseNode->next;
        len++;
    }

    // Handle the case where k is a multiple of the list length (no rotation)
    k = k % len;
    if (k == 0){
        return head;
    }

    // Connect the tail node to the head, creating a temporary circular list
    traverseNode->next = head;

    // Find the node k positions before the original tail (new tail position)
    int pos = len - k;  // Position of the new tail (0-based indexing)
    int index = 0;
    traverseNode = head;
    while(index<pos-1){
        traverseNode = traverseNode->next;
        index++;
    }

   // Split the list at the new tail (break the circular connection)
    ListNode* newHead = traverseNode->next;
    traverseNode->next = nullptr;

    return newHead;
}

int main(){
    int arr[] = {1,2,3,4,5};
    ListNode* head = new ListNode(arr[0]);
    ListNode* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(head);
    return 0;
}