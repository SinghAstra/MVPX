#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* random;
    Node(int val){
        this->val = val;
        next = nullptr;
        random = nullptr;
    }
};

void printLinkedList(Node* head){
     cout << "Elements in Linked List : ";
    Node* traverseNode = head;
    while(traverseNode !=nullptr){
        cout << traverseNode->val << " ";
        traverseNode = traverseNode->next;
    }
    cout << endl;
}


// Time Complexity : O(n)
// Space Complexity : O(n)
Node* copyRandomListBruteForce(Node* head) {
    unordered_map<Node*, Node*> data;
    Node* temp = head;
    while(temp!= nullptr){
        Node* copyNode = new Node(temp->val);
        data[temp] = copyNode;
        temp = temp->next;
    }
    for(auto it=data.begin(); it!=data.end();it++){
        if(it->first->next!= nullptr){
            it->second->next = data[it->first->next];
        }
        if(it->first->random!= nullptr){
            it->second->random = data[it->first->random];
        }
    }
    return data[head];
}

// Time Complexity : O(n)
// Space Complexity : O(1)
Node* copyRandomListOptimizedApproach(Node* head){
        // Step 1: Insert copy Node into Linked List
    Node* temp = head;
    while(temp !=nullptr){
        Node* copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
    // Step 2 : Connect random Pointer
    temp = head;
    while(temp!= nullptr){
        Node* random = temp->random;
        if(random!=nullptr){
            temp->next->random = random->next;
        }
        temp = temp->next->next;
    }
    // Step 3 : Connect the next Pointer and reconnect the original linked list
    temp = head;
    Node* startCopyNode = new Node(-1);
    Node* tempCopyNode = startCopyNode;
    while(temp != nullptr){
        tempCopyNode->next = temp->next;
        temp->next = tempCopyNode->next->next;
        temp = temp->next;
        tempCopyNode = tempCopyNode->next;
    }

    return startCopyNode->next;
}


int main(){
    int arr[] = {1,2,3,4,5};
    Node* head = new Node(arr[0]);
    Node* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        Node* temp = new Node(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(head);
    return 0;
}