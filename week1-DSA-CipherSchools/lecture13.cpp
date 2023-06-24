// q1: Merge Two Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
	    // if list1 happen to be NULL
		// we will simply return list2.
        if(list1 == NULL)
            return list2;
		
		// if list2 happen to be NULL
		// we will simply return list1.
        if(list2 == NULL)
            return list1;
        
        ListNode * ptr = list1;
        if(list1 -> val > list2 -> val)
        {
            ptr = list2;
            list2 = list2 -> next;
        }
        else
        {
            list1 = list1 -> next;
        }
        ListNode *curr = ptr;
        
		// till one of the list doesn't reaches NULL
        while(list1 &&  list2)
        {
            if(list1 -> val < list2 -> val){
                curr->next = list1;
                list1 = list1 -> next;
            }
            else{
                curr->next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
                
        }
		
		// adding remaining elements of bigger list.
        if(!list1)
            curr -> next = list2;
        else
            curr -> next = list1;
            
        return ptr;
       
    }
};

// q2 merge k sorted linked list
class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b){
        if(!a)return b;
        if(!b)return a;
        if(a->val <= b->val){
            a->next = merge(a->next,b);
            return a;
        }else{
            b->next = merge(a,b->next);
            return b;
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& v) {
        if(v.size()==0)return NULL;
        else if(v.size()==1)return v[0]; 
        for(int i = 1; i < v.size(); i++){
            v[0] = merge(v[0],v[i]);
        }
        return v[0];
    }
};

// q3 reversse linked list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
           return NULL;
        }
        if(head->next==NULL){
            return head;
        }      
        ListNode* temp = head->next;
        ListNode* temp1 = reverseList(temp);
        ListNode* temp2 = temp1;
        while(temp2->next!=NULL){
         temp2=temp2->next;
         }
        temp2->next=head;
        head->next=NULL;
        return  temp1;
    }
};
