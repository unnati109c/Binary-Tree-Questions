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

bool isMirror(struct node* root1, struct node* root2)
{
	if(!root1 and !root2) return true;
	if(!root1 or !root2) return false;

	return (root1->data == root2->data) and (isMirror(root1->left, root2->right)) and (isMirror(root1->right, root2->left)) ;
}

bool isSymmetric(struct node* root)
{
	return isMirror(root,root);
}

int main()
{
	struct node* root = insert(1);
	root->left = insert(2);
	root->right = insert(2);

	root->left->left = insert(3);
	root->left->right = insert(4);

	root->right->left = insert(4);
	root->right->right = insert(3);

	cout<<isSymmetric(root);

	return 0;
}