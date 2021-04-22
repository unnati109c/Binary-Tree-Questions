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

int sumofLeftLeafNodes(struct node* root)
{
	int res=0;
	if(root == NULL)
		return 0;
	if(isLeaf(root->left))
		res += root->left->data;
	else
		res += sumofLeftLeafNodes(root->left);  //remember this

	res += sumofLeftLeafNodes(root->right);

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

	cout<<"Sum of Left Leaf nodes are : "<<sumofLeftLeafNodes(root);
	return 0;
}