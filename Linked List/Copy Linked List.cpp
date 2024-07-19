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

ListNode* copyLinkedList(ListNode* head){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* traverseNode = head;
    ListNode* temp = dummyNode;
    while(traverseNode!= nullptr){
        temp->next = new ListNode(traverseNode->val);
        temp = temp->next;
        traverseNode = traverseNode->next;
    }
    return dummyNode->next;
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
    head = copyLinkedList(head);
    printLinkedList(head);
}