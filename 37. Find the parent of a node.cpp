#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
	node(int val)
	{
		data = val;
		left=right=NULL;
	}
};

struct node* insert(int val)
{
	return new node(val);
}

void parentOfNode(struct node* root, int val, int parent)
{
	if(root == NULL)
		return;
	if(root->data == val)
		cout<<parent;
	else
	{
		parentOfNode(root->left, val, root->data);
		parentOfNode(root->right, val, root->data);
	}
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

	root->right->left->left = insert(8);
	root->right->right->right = insert(9);

	root->right->right->right->right = insert(10);
	
	parentOfNode(root,6,-1);
	return 0;
}