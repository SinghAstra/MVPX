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

Node* deleteElementAtHead(Node* head){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* insertELementAtHead(Node* head,int val){
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

Node* insertELementAtTail(Node* head,int val){
    Node* newTail = new Node(val);
    if(head == NULL){
        return newTail;
    }
    Node* tempHead = head;
    while(head->next!= nullptr){
        head = head->next;
    }
    head->next = newTail;
    return tempHead;
}

Node* insertElementAtKthPosition(Node* head,int val,int k,int length){
    if(k<1||k>length+1){
        return head;
    }
    if(k==1){
        Node* newHead = new Node(val);
        newHead->next = head;
        return newHead;
    }else if(k==length+1){
        Node* newTail = new Node(val);
        Node* tempHead = head;
        while(head->next!= nullptr){
            head = head->next;
        }
        head->next = newTail;
        return tempHead;
    }else{
        Node* tempHead = head;
        Node* newNode = new Node(val);
        for(int i=1;i<k-1;i++){
            head = head->next;
        }
        newNode->next = head->next;
        head->next = newNode;
        return tempHead;
    }
}   

Node* insertElementBeforeValue(Node* head,int x,int val,int length){
    int i = 0;
    int index = -1;
    Node* temp = head;
    while(head!=NULL){
        if(head->data == x){
            index = i;
            break;
        }
        head = head->next;
        i++;
    }
    cout << "index : "<<index<<endl;
    if(index == -1){
        return head;
    }else{
        temp = insertElementAtKthPosition(temp,val,index+1,length);
        return temp;
    }
} 
int lengthOfLinkedList(Node* head){
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
    // int arr[] = {1,2,3,4,5,6,7,8,9};
    // Node* head = new Node(arr[0]);
    // Node* currentNode = head;
    // for(int i=1; i<sizeof(arr) / sizeof(int);i++){
    //     Node* temp = new Node(arr[i]);
    //     currentNode->next = temp;
    //     currentNode = temp;
    // }
    Node* head = new Node(24);
    printLinkedList(head);
    int length = lengthOfLinkedList(head);
    head = insertElementBeforeValue(head,24,100,length);
    printLinkedList(head);
    length = lengthOfLinkedList(head);
    head = insertElementBeforeValue(head,24,800,length);
    printLinkedList(head);
    
    return 0;
}