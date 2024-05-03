#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
#include <String> 
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

// Approach 1 : Using String
// Time Complexity : O(N)
// Space Complexity : O(N)
bool isPalindromeUsingString(ListNode* head) {
    string str = "";
    ListNode* temp = head;
    while(temp !=nullptr){
        str += to_string(temp->val);
        temp = temp->next;
    }
    int len = str.length();
    int start = 0;
    int end = len - 1;
    while(start < end){
        if(str[start]!= str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Approach 2 : Using Stack
// Time Complexity : O(2*N)
// Space Complexity : O(1)
bool isPalindromeUsingStack(ListNode* head){
    stack<int> stack;
    ListNode* temp = head;
    while(temp!= nullptr){
        stack.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp!= nullptr){
        if(temp->val!= stack.top()){
            return false;
        }
        stack.pop();
        temp = temp->next;
    }
    return true;
}

ListNode* reverseList(ListNode* head){
    ListNode* prevNode = nullptr;
    ListNode* currNode = head;
    ListNode* nextNode;
    while(currNode!= nullptr){
        ListNode* next = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = next;
    }
    return prevNode;
}

// Approach 3 : Optimal Approach
// Time Complexity : O(3*(n/2))
// Space Complexity : O(1)
bool isPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!= nullptr && fast->next->next!= nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* secondHalf = slow->next;
    ListNode* tail = reverseList(secondHalf);
    ListNode* start = head;
    while (tail!=nullptr){
        if(start->val!=tail->val){
            return false;
        }
        start = start->next;
        tail = tail->next;
    }
    return true;
}


int main(){
    int arr[] = {1,2,3,2,1};
    ListNode* head = new ListNode(arr[0]);
    ListNode* currentNode = head;
    for(int i=1; i<sizeof(arr) / sizeof(int);i++){
        ListNode* temp = new ListNode(arr[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printLinkedList(head);
    bool res = isPalindrome(head);
    cout << "isPalindrome: " << res << endl;
    return 0;
}
    