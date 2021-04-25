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

void printAllLEAFNodesAtGivenLevel(struct node* root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
	{
		if(!root->left and !root->right)
			cout<<root->data<<" ";
	}
	else if(level>1)
	{
		printAllLEAFNodesAtGivenLevel(root->left, level-1);
		printAllLEAFNodesAtGivenLevel(root->right, level-1);
	}
}

int main()
{
	struct node* root = insert(26);
	root->left = insert(10);
	root->right = insert(3);

	root->left->left = insert(4);
	root->left->right = insert(6);

	root->right->right = insert(3);
	root->right->right->left = insert(10);
	
	int level = 3;
	printAllLEAFNodesAtGivenLevel(root, level);
	return 0;
}	

