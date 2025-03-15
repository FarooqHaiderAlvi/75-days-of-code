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
        int pairSum(ListNode* head) {
            if(head->next->next==nullptr){
                return head->val+head->next->val;
            }
            int maxSum=INT_MIN;
            //finding middle node
            ListNode* slow = head;  
            ListNode* fast = head;
            ListNode* prev = nullptr;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            
            //reversing from the middle node
            ListNode* next = nullptr;
            ListNode* curr = slow;    
            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next; 
            }
    
            while(prev!=nullptr){
                int sum=prev->val+head->val;
                if(sum>maxSum) maxSum=sum;
                prev=prev->next;
                head=head->next;
            }
            return maxSum;
        }
    };