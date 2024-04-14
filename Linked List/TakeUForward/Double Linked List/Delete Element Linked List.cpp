#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
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

Node* deleteHead(Node* head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}


Node* deleteTail(Node* head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }
    Node* temp = head;
    Node* currentNode = head;
    while(currentNode->next->next!=nullptr){
        currentNode = currentNode->next;
    }
    Node* tailNode = currentNode->next;
    currentNode->next = nullptr;
    delete tailNode;
    return temp;
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
    printLinkedList(head);
    head = deleteHead(head);
    printLinkedList(head);
    head = deleteHead(head);
    printLinkedList(head);
    head = deleteTail(head);
    printLinkedList(head);
    return 0;
}