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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> r={-1,-1};
        ListNode* p=head;
        ListNode* c=head->next;
        int mini=INT_MAX;
        int ci=1;
        int pci=0;
        int fci=0;
        while(c->next!=nullptr){
            if((c->val<p->val && c->val<c->next->val) ||(c->val>p->val && c->val>c->next->val)){
                if(pci==0){
                    pci=ci;
                    fci=ci;
                }
                else{
                    mini=min(mini,ci-pci);
                    pci=ci;
                }
            }
            ci++;
            p=c;
            c=c->next;

        }
        if(mini!=INT_MAX){
            int maxi=pci-fci;
            r={mini,maxi};
        }
        return r;

        
    }
};