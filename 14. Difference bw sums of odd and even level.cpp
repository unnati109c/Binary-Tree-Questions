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

int getDifference(struct node* root)
{
	if(root == NULL)
		return 0;
	return root->data - getDifference(root->left) - getDifference(root->right);
}

int main()
{
	struct node* root = insert(1);
	root->left = insert(2);
	root->right = insert(3);

	root->left->left = insert(4);
	root->left->right = insert(5);

	root->right->right = insert(6);
	root->right->left = insert(7);
	
	cout<<getDifference(root);
	return 0;
}	

