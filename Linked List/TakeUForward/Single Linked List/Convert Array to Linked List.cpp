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

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node(arr[0]);
    Node* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        Node* temp = new Node(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }

    // Iterating through Linked List
    cout << "Elements in Linked List : ";
    Node* traverseNode = head;
    while(traverseNode !=nullptr){
        cout << traverseNode->data << " ";
        traverseNode = traverseNode->next;
    }
    return 0;
}