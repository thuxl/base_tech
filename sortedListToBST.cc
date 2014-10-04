#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
/**
 * Definition for binary tree
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode *p=head;
        int len=0;
        while (p)
        {
            len++;
            p=p->next;
        }
        if (len==0) return NULL;
        TreeNode *t=sortLink2BST(head, 1, len);
        return t;
    }

    TreeNode* sortLink2BST(ListNode *&head, int start, int end)
    {
        TreeNode *root = NULL;
        if (start > end){
            return root;
        }
        root = new TreeNode(0);
        int mid=(start+end)/2;
        root->left = sortLink2BST(head, start, mid-1);
        //注意head是变化的，经过一次sortLink2BST，就前进一次
        root->val = head->val;
        head=head->next;
        root->right = sortLink2BST(head, mid+1, end);
        return root;
	}
    
    
};

int main()
{
	ListNode *p=new ListNode(3);
	p->next = new ListNode(5);
	p->next->next = new ListNode(8);

	Solution  s;
	TreeNode* t= s.sortedListToBST(p);


	return 1;
}
