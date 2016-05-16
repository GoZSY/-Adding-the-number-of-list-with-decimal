/*****************************************************************
注意进位尤其是最大位的时候的处理需要特别注意
******************************************************************/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) 
    {
        // write code her
        if(a == NULL && b == NULL)
            return NULL;
        if(a == NULL && b != NULL)
            return b;
        if(a != NULL && b == NULL)
            return a;
        ListNode* result = a;
        int flow = 0;
        while(result && b)
        {  
            result->val = result->val+b->val+flow;
            flow = 0;
            if(result->val > 9)
            {
                flow = 1;
                result->val = result->val - 10;
            }
            if(b->next == NULL || result->next == NULL)
            {
                break;
            }
            
            b = b->next;
            result = result->next;
            
        }
        
        ListNode *temp = new ListNode(flow);
        if(b->next == NULL && result->next == NULL)
        {
            if(flow == 0)
                return a;
            else
            {
                result->next = temp;
                return a;
       		}
                
        }
        if(b->next == NULL)
        {
            if(flow == 0)
                return a;
            else
            {
                result = result->next;
                result->val = result->val+flow;
                return a;
       		}
        }
                      
        if(result->next == NULL)
        {
            if(flow == 0)
            {
                result->next = b->next;
                return a;
            }   
            else
            {
                b = b->next;
                b->val = b->val+flow;
                result->next = b;
                return a;
       		}          

        }
        return a;
    }
};
