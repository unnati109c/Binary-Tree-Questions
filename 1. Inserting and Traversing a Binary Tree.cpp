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

void preorderTraversal(struct node* node)
{
	if(node==NULL)
		return;

	cout<<node->data<<" ";
	preorderTraversal(node->left);
	preorderTraversal(node->right);
}

void inorderTraversal(struct node* node)
{
	if(node==NULL)
		return;

	inorderTraversal(node->left);
	cout<<node->data<<" ";
	inorderTraversal(node->right);
}

void postorderTraversal(struct node* node)
{
	if(node==NULL)
		return;

	postorderTraversal(node->left);
	postorderTraversal(node->right);
	cout<<node->data<<" ";
}

int main()
{
	struct node* root = new node(1);

	root->left = new node(2);
	root->right = new node(3);

	root->left->left = new node(4);
	root->left->right = new node(5);

	root->right->left = new node(6);
	root->right->right = new node(7);

	root->left->left->left = new node(8);
	root->left->right->right = new node(9);
	root->right->right->left = new node(10);

	/*
          1
        /    \
       2      3
      / \    / \
     4   5  6   7
    /     \    /
   8       9  10

*/

	cout << "Inorder traversal ";
    inorderTraversal(root);

    cout << "\nPreorder traversal ";
    preorderTraversal(root);

    cout << "\nPostorder traversal ";
    postorderTraversal(root);

	return 0;
}