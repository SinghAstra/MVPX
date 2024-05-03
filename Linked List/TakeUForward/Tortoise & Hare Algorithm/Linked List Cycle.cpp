#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
#include <unordered_set> 
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

// Time Complexity : O(N*2*log(N))
// Space Complexity : O(N)
bool hasCycleHashing(ListNode *head) {
    unordered_set<ListNode*> hash;
    ListNode* temp = head;
    while(temp!= nullptr){
        if(hash.find(temp)!= hash.end()){
            return true;
        }
        hash.insert(temp);
        temp = temp->next;
    }
    return false;
}

// Time Complexity : O(N)
// Space Complexity : O(1)
bool hasCycleTortoiseAndHare(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!= nullptr&&fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[] = {4,1,8,4,5};
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