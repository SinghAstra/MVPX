#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
#include <String> 
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

// Optimal Approach - Tortoise & Hare Algorithm
// Time Complexity : O(n/2)
// Space Complexity : O(1)
ListNode* middleNodeOptimal(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next==nullptr){
    return slow;
    }
    return slow->next;
}

// Brute Force Approach
// Time Complexity : O(N)
// Space Complexity : O(1)
ListNode* middleNodeBrute(ListNode* head) {
    int length = 0;
    int pos = -1;
    ListNode* temp = head;
    while(temp!=nullptr){
        temp = temp->next;
        length++;
    }
    if(length%2==0){
        pos =(length/2) + 1;
    }else{
        pos = (length+1)/2;
    }
    int count = 1;
    temp = head;
    while(temp!=nullptr){
        if(count==pos){
            return temp;
        }
        temp = temp->next;
        count++;
    }
    return head;
}


int main(){
    int arr[] = {1,2,3,2,1};
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