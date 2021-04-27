/*
Input:
      1
    /  \
   2    3
Output: 2 1 3
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
3    2          2    3
The inorder of mirror is 2 1 3 */

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

void inorderTraversal(struct node* node)
{
	if(node==NULL)
		return;

	inorderTraversal(node->left);
	cout<<node->data<<" ";
	inorderTraversal(node->right);
}

void InvertTree(struct node* root)
{
	if(!root)
		return;
	InvertTree(root->left);
	InvertTree(root->right);
	swap(root->left, root->right);
}

int main()
{
	struct node* root = insert(1);
	root->left = insert(2);
	root->right = insert(3);

	root->left->left = insert(4);
	root->left->right = insert(5);

	root->right->left = insert(6);
	root->right->right = insert(7);

	inorderTraversal(root);
	cout<<endl;
	InvertTree(root);
	inorderTraversal(root);

	return 0;
}