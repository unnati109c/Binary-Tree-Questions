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

void printAllNodesAtGivenLevel(struct node* root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
		cout<<root->data<<" ";
	else if(level>1)
	{
		printAllNodesAtGivenLevel(root->left, level-1);
		printAllNodesAtGivenLevel(root->right, level-1);
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
	root->right->left = insert(4);
	
	int level = 3;
	printAllNodesAtGivenLevel(root, level);
	return 0;
}	

