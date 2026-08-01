class Solution {
public:
    int pairSum(ListNode* head) {

        vector<ListNode*> nodes;

        while(head){
            nodes.push_back(head);
            head = head->next;
        }

        int left = 0;
        int right = nodes.size() - 1; 

        int maxSum = 0;

        while(left < right){

            int sum = nodes[left]->val + nodes[right]->val;

            maxSum = max(maxSum, sum);

            left++;
            right--;
        }

        return maxSum;
    }
};