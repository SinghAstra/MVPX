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
ListNode *detectCycleBruteForce(ListNode *head) {
    ListNode* temp = head;
    unordered_set<ListNode*> hash;
    while(temp!=nullptr){
        if(hash.find(temp)!=hash.end()){
            return temp;
        }
        hash.insert(temp);
        temp = temp->next;
    }
    return nullptr;
}


// Time Complexity : O(N)
// Space Complexity : O(1)
ListNode *detectCycleTortoiseAndHare(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            ListNode* first = head;
            ListNode* second = slow;
            while(first!=second){
                first = first->next;
                second = second->next;
            }
            return first;
        }
    }
    return nullptr;
}