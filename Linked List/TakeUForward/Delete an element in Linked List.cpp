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

Node* deleteTail(Node* head){
    if(head == nullptr||head->next == nullptr){
        return nullptr;
    }
    Node* temp = head;
    while(head->next->next != nullptr){
        head = head->next;
    }
    Node* tail = head->next;
    delete tail;
    head->next = nullptr;
    return temp;
}

Node* deleteAtPosition(Node* head,int index,int length){
    if(index<0||index>=length){
        return head;
    }
    if(index==0){
        head = deleteHead(head);
        return head;
    }else if(index==length-1){
        head = deleteTail(head);
        return head;
    }else{
        Node* temp = head;
        for(int i=1;i<index;i++){
            head = head->next;
        }
        Node* deleNode = head->next;
        head->next = head->next->next;
        delete deleNode;
        return temp;
    }
}

Node* deleteByValue(Node* head,int value,int length){
    if(head==nullptr){
        return head;
    }
    int index = -1;
    int i = 0;
    Node* temp = head;
    while(head!=nullptr){
        if(head->data==value){
            index = i;
            break;
        }
        head = head->next;
        i++;
    }
    if(index==-1){
        return head;
    }else{
        return deleteAtPosition(temp,index,length);
    }
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
    return 0;
}