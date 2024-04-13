#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class MyLinkedList {
    public:
    ListNode* head;
    int size;
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode* current = head;
        for(int i=0;i<index;i++){
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = head;
        head = newHead;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newTail = new ListNode(val);
        if (head == nullptr) {
            head = newTail;
        } else {
        ListNode* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newTail;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
         if (index < 0 || index > size) {
            return;
        }
         if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
          ListNode* newNode = new ListNode(val);
            ListNode* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
    }
    }
    
    void deleteAtIndex(int index) {
         if (index < 0 || index >= size) {
            return;
        }
        if(index == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            size--;
        }else{
        ListNode* currentNode = head;
        for(int i=0;i<index-1;i++){
            currentNode = currentNode->next;
        }
        ListNode* deleteNode = currentNode->next;
        currentNode->next = deleteNode->next;
        size--;
        delete deleteNode;
        }
    }
};

void traverseLinkedList(MyLinkedList* obj){
    ListNode* head = obj->head;
    cout << "Elements are : ";
    while(head!= nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    cout << "Size " << obj->size << endl;
}
int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->deleteAtIndex(1);
    obj->deleteAtIndex(3);
    obj->deleteAtIndex(0);
    cout << obj->get(0)<<endl;
    traverseLinkedList(obj);
    return 0;
}




 