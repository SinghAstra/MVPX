// LeetCode Problem
#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int val){
        data = val;
        next = nullptr;
    }
};

void printLinkedList(ListNode* head){
     cout << "Elements in Linked List : ";
    ListNode* traverseNode = head;
    while(traverseNode !=nullptr){
        cout << traverseNode->data << " ";
        traverseNode = traverseNode->next;
    }
    cout << endl;
}

// Time Complexity : O(max(n1,n2))
// Space Complexity : O(max(n1,n2))
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* traverseNode = dummyNode;
        while (l1!=nullptr||l2!=nullptr)
        {
            int sum = 0;
            if(l1!=nullptr){
                sum += l1->data;
                l1 = l1->next;
            }
            if(l2!=nullptr){
                sum += l2->data;
                l2 = l2->next;
            }
            sum += carry;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            traverseNode->next = newNode;
            traverseNode = traverseNode->next;
        }
        if(carry>0){
            ListNode* newNode = new ListNode(carry);
            traverseNode->next = newNode;
        }
        return dummyNode->next;
    }

int main(){
    int arr1[] = {2,4,3};
    ListNode* l1 = new ListNode(arr1[0]);
    ListNode* currentNode = l1;
    for(int i=1; i<sizeof(arr1) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr1[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(l1);
    int arr2[] = {1,1,1,1};
    ListNode* l2 = new ListNode(arr2[0]);
    currentNode = l2;
    for(int i=1; i<sizeof(arr2) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr2[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(l2);
    ListNode* head = addTwoNumbers(l1, l2);
    printLinkedList(head);
    return 0;
}