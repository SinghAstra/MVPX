#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
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

ListNode* reverseLinkedList(ListNode* head){
    ListNode* prevNode = nullptr;
    ListNode* currentNode = head;
    ListNode* nextNode = nullptr;
    while(currentNode!= nullptr){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    return head;
}


void reverseKNodes(ListNode* prevNode, int k){
    int pos = 1;
    ListNode* temp = prevNode->next;
    while(pos < k){
        temp = temp->next;
        pos++;
    }
    ListNode* nextHead = temp->next;
    temp->next = nullptr;
    ListNode* tail = prevNode->next;
    ListNode* head = reverseLinkedList(prevNode->next);
    prevNode->next = head;
    tail->next = nextHead;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    // Step 1:  Find the length of the array
    int len = 0;
    ListNode* temp = head;
    while(temp!= nullptr){
        len++;
        temp = temp->next;
    }
    // Step 2:  Find the number of groups
    int groups = len / k;
    // Step 3:  Reverse the groups
    temp =  new ListNode(-1);
    ListNode* newHead = temp;
    temp->next = head;
    for(int i=0; i<groups; i++){
        ListNode* nextNode = temp->next;
        reverseKNodes(temp,k);
        temp = nextNode;
    }
    return newHead->next;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    ListNode* head = new ListNode(arr[0]);
    ListNode* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(head);
    head = reverseKGroup(head,4);
    printLinkedList(head);
}