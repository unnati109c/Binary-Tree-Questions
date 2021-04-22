/*
Input : Binary tree with x = 2:
        4        
       / \       
      2   5      
     / \ / \     
    7  2 2  3    
Output : 11

       #4#        
       / \       
     #2# #5#      
     / \ / \     
    7  2 2  3    

The highlighted nodes (4, 2, 5) above
are the nodes having 2 as a child node. */

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

void helper(struct node* root, int& sum, int x)
{
	if(root==NULL)
		return;
	if((root->left != NULL and root->left->data == x) || 
	   (root->right != NULL and root->right->data == x))
	{
		sum+=root->data;
	}
	helper(root->left, sum, x);
	helper(root->right, sum, x);
}

int sumOfNodes(struct node* root, int x)
{
	int sum=0;
	helper(root, sum, x);
	return sum;
}

int main()
{
	struct node* root = new node(4);

	root->left = new node(2);
	root->right = new node(5);

	root->left->left = new node(7);
	root->left->right = new node(2);

	root->right->left = new node(2);
	root->right->right = new node(3);

	cout<<"Sum of all parent nodes having child nodes as x in Binary Tree : "<<sumOfNodes(root, 2);
	return 0;
}