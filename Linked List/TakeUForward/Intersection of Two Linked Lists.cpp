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

// Time Complexity : O(m*n)
// Space Complexity : O(1)
ListNode* getIntersectionNodeBruteForce(ListNode *headA, ListNode *headB) {
    ListNode* temp2 = headB;
    while(temp2!= nullptr){
        ListNode* temp1 = headA;
        while(temp1!= nullptr){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }        
    return nullptr;
}

// Time Complexity : O(m+n)
// Space Complexity : O(1)
ListNode* getIntersectionNodeHashing(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode* > hash;
    ListNode* temp1 = headA;
    while(temp1!= nullptr){
        hash.insert(temp1);
        temp1 = temp1->next;
    }
    ListNode* temp2 = headB;
    while(temp2!= nullptr){
        if(hash.find(temp2)!= hash.end()){
            return temp2;
        }
        temp2 = temp2->next;
    }
    return nullptr;
}

// Time Complexity : O((2*m)+n)
// Space Complexity : O(1)
ListNode *getIntersectionNodeDifferenceofLength(ListNode *headA, ListNode *headB) {
    int len1  = 0;
    int len2  = 0;
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    while(temp1!= nullptr){
        len1++;
        temp1 = temp1->next;
    }
    while(temp2!= nullptr){
        len2++;
        temp2 = temp2->next;
    }
    temp1 = headA;  
    temp2 = headB;
    if(len1 > len2){
        int diff = len1 - len2;
        while(diff>0){
            temp1 = temp1->next;
            diff--;
        }
    }
    if(len2 > len1){
        int diff = len2 - len1;
        while(diff>0){
            temp2 = temp2->next;
            diff--;
        }
    }
    while(temp1!= nullptr){
        if(temp1 == temp2){
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
    
}
int main(){
    int arr[] = {4,1,8,4,5};
    ListNode* headA = new ListNode(arr[0]);
    ListNode* currentNode = headA;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(headA);
    ListNode* headB = new ListNode(7);
    ListNode* secondB = new ListNode(11);
    headB->next = secondB;
    secondB->next = headA->next->next;
    printLinkedList(headB);
    return 0;
}