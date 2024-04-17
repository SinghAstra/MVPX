#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            len++;
            temp = temp->next;
        }
        if(n<1||n>len){
            return head;
        }
        int pos = len - n + 1;
        if(pos == 1){
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
        }else if(pos == len){
            ListNode* endNode = head;
            while(endNode->next->next!=nullptr){
                endNode = endNode->next;
            }
            ListNode* delNode = endNode->next;
            delete delNode;
            endNode->next = nullptr;
        }else{
            int index = 1;
            temp = head;
            while(index<pos-1){
                temp = temp->next;
                index++;
            }
            ListNode* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }
        return head;
    }

    int main(){
    int arr[] = {1,2,3,4,5};
    ListNode* head = new ListNode(arr[0]);
    ListNode* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(head);
    head = removeNthFromEnd(head,2);
    printLinkedList(head); 
    return 0;
}