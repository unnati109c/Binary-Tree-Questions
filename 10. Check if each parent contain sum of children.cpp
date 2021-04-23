/* Given a Binary Tree. Check whether all of its nodes have the 
value equal to the sum of their child nodes.
Following is an example of SumTree. 

          26
        /   \
      10     16
    /    \     \
  4      6      16  */

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;

	node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

struct node* insert(int val)
{
		return new node(val);
}

bool isLeaf(struct node* root)
{
	if(root==NULL)
		return false;
	if(root->left == NULL and root->right == NULL)
		return true;
	return false;
}

int isSumTree(struct node* root)
{
	if(root == NULL || isLeaf(root))
		return 1;

	int l = root->left==NULL ? 0 : root->left->data;
	int r = root->right==NULL ? 0 : root->right->data;

	return ((root->data==(l+r)) and (isSumTree(root->left)) and (isSumTree(root->right)));
}

int main()
{
	struct node* root = insert(26);
	root->left = insert(10);
	root->right = insert(16);

	root->left->left = insert(4);
	root->left->right = insert(6);

	root->right->right = insert(16);
	
	cout<<isSumTree(root);
	return 0;
}	