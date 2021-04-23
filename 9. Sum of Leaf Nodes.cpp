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

int sumofLeafNodes(struct node* root)
{
	int res=0;
	if(root == NULL)
		return 0;
	if(isLeaf(root))
		res += root->data;
	
	res += sumofLeafNodes(root->right);
	res += sumofLeafNodes(root->left);

	return res;
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

	cout<<"Sum of Right Leaf nodes are : "<<sumofLeafNodes(root);
	return 0;
}	