// LeetCode Problem
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

// Time Complexity : O(2n)
// Space Complexity : O(1)
ListNode* sortedList(ListNode* head){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    ListNode* temp = head;
    while(temp!= nullptr){
        if(temp->val == 0){
            count0++;
        }else if(temp->val == 1){
            count1++;
        }else if(temp->val == 2){
            count2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp!= nullptr){
        if(count0>0){
            temp->val = 0;
            count0--;
        }else if(count1>0){
            temp->val = 1;
            count1 -= 1;
        }else if(count2>0){
            temp->val = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}


ListNode* sortedListOptimal(ListNode* head){
    ListNode* temp = head;
    ListNode* zeroHead = new ListNode(-1);
    ListNode* oneHead = new ListNode(-1);
    ListNode* twoHead = new ListNode(-1);
    ListNode* zero = zeroHead;
    ListNode* one = oneHead;
    ListNode* two = twoHead;
    while(temp!= nullptr){
        if(temp->val == 0){
            zero->next = temp;
            zero = temp;
        }else if(temp->val == 1){
            one->next = temp;
            one = temp;
        }else if(temp->val == 2){
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = oneHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    return zeroHead->next;
}
int main(){
    int arr[] = {2,1,2,0,0,1,1,2};
    ListNode* head = new ListNode(arr[0]);
    ListNode* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(head);
    head = sortedListOptimal(head);
    printLinkedList(head); 
    return 0;
}