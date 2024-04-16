#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void printLinkedList(Node* head){
    cout << "Element are : ";
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout << endl;
}

//  Brute Force Method
//  TIme Complexity : O(2N)
//  Space Complexity : O(N)

Node* reverseLinkedListBruteForce(Node* head){
    Node* currentNode = head;
    stack<int> data;
    while(currentNode!=nullptr){
        data.push(currentNode->data);
        currentNode = currentNode->next;
    }
    currentNode = head;
    while(currentNode!=nullptr){
        currentNode->data = data.top();
        data.pop();
        currentNode = currentNode->next;
    }
    return head;
}


// Optimized Method
// Time Complexity : O(N)
// Space Complexity : O(1)
Node* reverseLinkedListOptimal(Node* head){
    Node* currentNode = head;
    Node* newHead;
    while(currentNode!=nullptr){
        Node* nextNode = currentNode->next;
        currentNode->next = currentNode->prev;
        currentNode->prev = nextNode;
        if(currentNode->prev==nullptr){
            newHead = currentNode;
        }
        currentNode = currentNode->prev;
    }
    return newHead;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    Node* currentNode = new Node(arr[0]);
    Node* head = currentNode;
    for(int i=1; i<sizeof(arr)/sizeof(int);i++){
        Node* newNode = new Node(arr[i]);
        currentNode->next = newNode;
        newNode->prev = currentNode;
        currentNode = currentNode->next;
    }   
    // Node* head = new Node(24);
    // printLinkedList(head);
    // head = deleteHead(head);
    printLinkedList(head);
    head = reverseLinkedListOptimal(head);
    printLinkedList(head);
    return 0;
}