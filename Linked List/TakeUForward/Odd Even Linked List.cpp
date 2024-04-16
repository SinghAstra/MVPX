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

ListNode* oddEvenList(ListNode* head) {
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
    head = oddEvenList(head);
    printLinkedList(head);
    return 0;
}