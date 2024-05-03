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


// Time Complexity : 0(2*N)
// Space Complexity : O(N)
ListNode* reverseListIterative(ListNode* head){
    ListNode* temp = head;
    stack<int> stack;
    while(temp != nullptr){
        stack.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        temp->val = stack.top();
        stack.pop();
        temp = temp->next;
    }
    return head;
}

// Time Complexity : 0(N)
// Space Complexity : 0(1)
ListNode* reverseListChangingPointers(ListNode* head){
    ListNode* prevNode = nullptr;
    ListNode* currentNode = head;
    ListNode* nextNode;
    while(currentNode!=nullptr){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
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
    head = reverseListIterative(head);
    printLinkedList(head);
    head = reverseListChangingPointers(head);
    printLinkedList(head);
    return 0;
}