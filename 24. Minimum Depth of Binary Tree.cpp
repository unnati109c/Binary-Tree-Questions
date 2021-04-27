/*
          1
        /    \
       2      3
      / \    / \
     4   5  6   7
    /     \    /
   8       9  10
  /
 11

*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;

	node(int val)
	{
		data=val;
		left=right=NULL;
	}
};

int minDepth(struct node* root)
{
	if(root==NULL)
        return 0;
        
    if(!root->left and !root->right)
    	return 1;
    
    int l = root->left!=NULL ? minDepth(root->left) : INT_MAX;
    int r = root->right!=NULL ? minDepth(root->right) : INT_MAX;
    
    return 1 + min(l, r);
}

int main()
{
	struct node* root = new node(1);

	root->left = new node(2);
	//root->right = new node(3);

	root->left->left = new node(4);
	//root->left->right = new node(5);

	//root->right->left = new node(6);
	//root->right->right = new node(7);

	root->left->left->left = new node(8);
	//root->left->right->right = new node(9);
	//root->right->right->left = new node(10);

	root->left->left->left->left = new node(11);

	cout<<"Minimum Depth of Binary Tree : "<<minDepth(root);
	return 0;
}