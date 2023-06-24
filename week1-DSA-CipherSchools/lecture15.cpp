// q1: given sorted linklist remove all duplicates
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head ==  NULL || head->next == NULL) return head;
        ListNode *curr=head, *next=NULL;
        while(curr->next != NULL){
            if(curr->val == curr->next->val){
                next=curr->next;
                curr->next=next->next;
                delete(next);
            }
            else    curr=curr->next;
        }
        return head;
    }
};

// q2: Remove Duplicates From an Unsorted Linked List
#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
};

void removeDuplicates(Node* head) {
    if (head == nullptr)
        return;

    std::unordered_set<int> uniqueElements;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (uniqueElements.find(curr->data) != uniqueElements.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            uniqueElements.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

// Helper function to print the linked list
void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{2, nullptr};
    head->next->next->next->next = new Node{4, nullptr};

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    removeDuplicates(head);

    std::cout << "Linked List after removing duplicates: ";
    printLinkedList(head);

    return 0;
}

#include <iostream>

struct Node {
    int data;
    Node* next;
};

void removeDuplicates(Node* head) {
    if (head == nullptr)
        return;

    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr;

        while (next->next != nullptr) {
            if (next->next->data == curr->data) {
                Node* duplicate = next->next;
                next->next = next->next->next;
                delete duplicate;
            } else {
                next = next->next;
            }
        }

        curr = curr->next;
    }
}

// Helper function to print the linked list
void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{2, nullptr};
    head->next->next->next->next = new Node{4, nullptr};

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    removeDuplicates(head);

    std::cout << "Linked List after removing duplicates: ";
    printLinkedList(head);

    return 0;
}

// q3: rotate list
class Solution {
public:
    int count(ListNode *head){
        ListNode *curr=head;
        int c=1;
        while(curr->next!=NULL){
            c++;
            curr=curr->next;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next==NULL)    return head;
        int counter = count(head);
        k=k%counter;
        if(k==0)    return head;
        ListNode *q=head;
        while(q!=NULL && k>0){
            q=q->next;
            k--;
        }  
        ListNode *p=head;
        while(q->next!=NULL && p->next!=NULL){
            q=q->next;
            p=p->next;
        }
        q->next=head;
        head=p->next;
        p->next=NULL;
        return head;
    }
};

// q4: Add Two Numbers in linked list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        if(a==NULL) return b;
        else if(b==NULL) return a;
        else{
            ListNode dummy(0);
            ListNode *p=a,*q=b,*r=&dummy;
            int sum=0,carry=0;
            while(p!=NULL || q!=NULL){
                sum=(p==NULL? 0:p->val) + (q==NULL?0:q->val)+carry;
                carry = sum / 10;
                sum = sum% 10;
                r->next=new ListNode(sum);
                r=r->next;
                if(p!=NULL) p=p->next;
                if(q!=NULL) q=q->next;
            }
            if(carry>0){
                r->next=new ListNode(carry);
            }
        return dummy.next;
        }
    }
};