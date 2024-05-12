#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
#include <unordered_set> 
#include <cmath>
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

// Approach 1 : Two Pass Removal (Brute Force Approach)
// Approach is called a two-pass removal because it iterates through the linked list twice to achieve the goal 
// of removing the middle node.
// Note : floor() rounds down to number smaller than or equal to the number passed as argument
// Time Complexity : O(n)
// Space Complexity : O(1)
ListNode* deleteMiddleTwoPassRemoval(ListNode* head) {
    if(head==nullptr||head->next==nullptr){
            return nullptr;
    }
    int n = 0;
    ListNode* temp = head;
    while(temp!=nullptr){
        temp = temp->next;
        n++;
    }
    int pos = floor(n/2);
    int index = 0;
    temp = head;
    while(index<pos-1){
        temp = temp->next;
        index++;
    }
    ListNode* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
    return head;
}

// Approach 2 : One Pass Removal (Optimized  Approach) - Tortoise And Hare Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)
ListNode* deleteMiddleOnePassRemoval(ListNode* head) {
    if(head==nullptr){
        return nullptr;
    }
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head->next->next;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;
    return head;
}

int main(){
    int arr[] = {1,3,4,7,1,2,6};
    ListNode* head = new ListNode(arr[0]);
    ListNode* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(head);
    head = deleteMiddleOnePassRemoval(head);
    printLinkedList(head);
    return 0;
}