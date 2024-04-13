#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* deleteHead(Node* head){
    if(head == nullptr){
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void deleteTail(Node* head,int len){
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    for(int i=1;i<len-1;i++){
        temp = temp->next;
    }
    Node* tail = temp->next;
    delete tail;
    temp->next = nullptr;
}

int length(Node* head){
    int len = 0;
    while(head!= nullptr){
        len++;
        head = head->next;
    }
    return len;
}
void printLinkedList(Node* head){
     cout << "Elements in Linked List : ";
    Node* traverseNode = head;
    while(traverseNode !=nullptr){
        cout << traverseNode->data << " ";
        traverseNode = traverseNode->next;
    }
    cout << endl;
}

int main(){
    // Inserting data into LinkedList
    int arr[] = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node(arr[0]);
    Node* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        Node* temp = new Node(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(head);
    head = deleteHead(head);
    printLinkedList(head);
    int len = length(head);
    deleteTail(head,len);
    printLinkedList(head);
    return 0;
}