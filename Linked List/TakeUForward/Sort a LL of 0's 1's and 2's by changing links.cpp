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

ListNode* sortedList(Node* head){
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
        temp = temp->next;
        continue;
        }else if(count1>0){
            temp->val = 1;
            count1 -= 1;
        temp = temp->next;
        }else if(count2>0){
            temp->val = 2;
            count2--;
        temp = temp->next;
        }
    }
    return head;
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
    head = sortedList(head);

}