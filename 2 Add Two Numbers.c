// LeetCodes struct definition
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

//10/17/2022 20:17	Accepted	19 ms	7.8 MB	c

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *root = malloc(sizeof(struct ListNode));
    struct ListNode *cur = root;
    
    cur->val = 0;
    int carry = 0;
    
    while(l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = 0;
        
        if(l1 != NULL) 
        {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        
        sum += carry;
        
        carry = sum / 10;
        
        cur = cur->next = malloc(sizeof(struct ListNode));
        cur->val = sum % 10;    
        cur->next = NULL;
    }
    
    return root->next;
}
