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


Node* deleteAtPosition(Node* head,int k){
    Node* tempHead = head;
    int length = 0;
    while(head!=nullptr){
        length++;
        head = head->next;
    }
    if(k<1||k>length){
        return tempHead;
    }else if(k==1){
        return deleteHead(head);
    }else if(k==length){
        cout<<"In k==length "<<k<<endl;
        return deleteTail(head);
    }else{
        int i=1;
        Node* temp = tempHead;
        while(i!=k){
            temp = temp->next;
            i++;
        }
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete temp;
        return tempHead;
    }
}

Node* deleteNode(Node* head,Node* node){
    int pos = 0;
    Node* tempHead = head;
    while(head!=nullptr){
        pos++;
        if(head==node){
            cout << "In head==node "<<endl;
            cout <<"tempHead->data : "<<tempHead->data<<endl;
            cout <<"pos : "<<pos<<endl;
            tempHead = deleteAtPosition(tempHead,pos);
            break;
        }
        head = head->next;
    }
    return tempHead;
}

Node* nodeAtPosition(Node* head,int position){
    int length = 0;
    int i = 1;
    Node* tempHead = head;
    while(head!=nullptr){
        length++;
        head = head->next;
    }
    if(position<1||position>length){
        return head;
    }
    head = tempHead;
    while(head!=nullptr){
        if(i==position){
            return head;
        }
        i++;
        head = head->next;
    }
    return nullptr;
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
    Node* node = nodeAtPosition(head,6);
    cout << "node->data : "<<node->data <<endl;
    head = deleteNode(head,node);
    printLinkedList(head);
    // node = nodeAtPosition(head,1);
    // cout << "node->data : "<<node->data <<endl;
    // head = deleteNode(head,node);
    // printLinkedList(head);
    return 0;
}