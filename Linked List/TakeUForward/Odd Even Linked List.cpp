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
// Space Complexity : O(n)
ListNode* oddEvenListBrute(ListNode* head) {
    if(head == nullptr){
        return head;
    }
    vector<int> data;
    ListNode* temp = head;
    while(temp!= nullptr){
        data.push_back(temp->val);
        if(temp->next!= nullptr){
        temp = temp->next->next;
        }else{
            temp = nullptr;
        }
    }       
    temp = head->next;
    while(temp!= nullptr){
        data.push_back(temp->val);
         if(temp->next!= nullptr){
        temp = temp->next->next;
        }else{
            temp = nullptr;
        }
    }
    int index = 0;
    temp = head;
    while(temp!= nullptr){
        temp->val = data[index];
        temp = temp->next;
        index++;
    }
    return head;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
ListNode* oddEvenListOptimal(ListNode* head) {
   if(head == nullptr){
    return head;
   }
   ListNode* oddNode = head;
   ListNode* evenNode = head->next;
   ListNode* tempEvenNode = evenNode;

   while(evenNode != nullptr&&evenNode->next != nullptr){
    oddNode->next = oddNode->next->next;
    evenNode->next = evenNode->next->next;
    oddNode = oddNode->next;
    evenNode = evenNode->next;
   }
    oddNode->next = tempEvenNode;
   return head;
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
    head = oddEvenListOptimal(head);
    printLinkedList(head);
    return 0;
}