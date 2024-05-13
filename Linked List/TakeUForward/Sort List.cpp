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

ListNode* mergeSort(ListNode* head, ListNode* head2){
    ListNode* first = head;
    ListNode* second = head2;
    ListNode* temp = new ListNode(-1);
    ListNode* start = temp;
    while(first!= nullptr && second!= nullptr){
        if(first->val < second->val){
            temp->next = first;
            first = first->next;
        }
        else{
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }
    while(first!=nullptr){
        temp->next = first;
        first = first->next;
        temp = temp->next;
    }
    while(second!=nullptr){
        temp->next = second;
        second = second->next;
        temp = temp->next;
    }
    return start->next;
}

ListNode* sortList(ListNode* head) {
    // Base Case
    if(head == nullptr || head->next == nullptr){
    return head;
    } 

    // Finding the length of the list
    ListNode* temp = head;
    int len = 0;
    while(temp != nullptr){
        len++;
        temp = temp->next;
    }
    int mid = (len-1)/2;

    // Split the list into two lists
    int pos = 0;
    temp = head;
    while(pos<mid){
        temp = temp->next;
        pos++;
    }

    // Store the head of second list
    ListNode* head2 = temp->next;
    temp->next = nullptr;

    // Recursively sort the two halves
    head = sortList(head);
    head2 = sortList(head2);

    // Merge the two sorted halves
    return mergeSort(head, head2);
}

int main(){
    int arr[] = {-1,5,3,4,0};
    ListNode* head = new ListNode(arr[0]);
    ListNode* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(head);
    head = sortList(head);
    printLinkedList(head);
}