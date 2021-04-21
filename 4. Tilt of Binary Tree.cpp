/*  https://leetcode.com/problems/binary-tree-tilt/ 
Given the root of a binary tree, return the sum of every tree node's tilt.
The tilt of a tree node is the absolute difference between the sum of all left 
subtree node values and all right subtree node values. If a node does not have 
a left child, then the sum of the left subtree node values is treated as 0. 
The rule is similar if there the node does not have a right child.
Input: root = [1,2,3]
Output: 1
Explanation: 
Tilt of node 2 : |0-0| = 0 (no children)
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; 
right subtree is just right child, so sum is 3)
Sum of every tilt : 0 + 0 + 1 = 1 */

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

int helper(struct node* root, int& tilt)
{
	if(root==NULL)
		return 0;
	int l = helper(root->left, tilt);
	int r = helper(root->right, tilt);

	tilt+= abs(l-r);
	return root->data + l + r;
}

int tilt(struct node* root)
{
	int tilt=0;
	helper(root, tilt);
	return tilt;
}

int main()
{
	struct node* root = new node(21);

	root->left = new node(7);
	root->right = new node(14);

	root->left->left = new node(1);
	root->left->right = new node(1);

	root->right->left = new node(2);
	root->right->right = new node(2);

	root->left->left->left = new node(3);
	root->left->left->right = new node(3);

	cout<<"Tilt of Binary Tree : "<<tilt(root);
	return 0;
}

/*
	            21
	       7         14
	 	1    1     2    2
	  3  3

*/