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

int helper(struct node* root, int target, int level)
{
	if(root==NULL)
		return 0;
	if(root->data == target)
		return level;
	int l = helper(root->left, target, level+1);
	if(l != 0)
		return l;
	return helper(root->right, target, level+1);
}

int getLevelOfGivenNode(struct node* root, int target)
{
	return helper(root, target, 1);
}

int main()
{
	struct node* root = insert(26);
	root->left = insert(10);
	root->right = insert(3);

	root->left->left = insert(40);
	root->left->right = insert(6);

	root->right->right = insert(31);
	root->right->left = insert(4);
	
	int target = 40;
	cout<<getLevelOfGivenNode(root, target);
	return 0;
}	

