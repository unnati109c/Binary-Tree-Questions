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

bool isIdentical(struct node* root1, struct node* root2)
{
	if(!root1 and !root2) return true;
	if(!root1 or !root2) return false;

	return (root1->data == root2->data) and (isIdentical(root1->left,root2->left)) and (isIdentical(root1->right,root2->right)) ;
}

int main()
{
	struct node *root1 = insert(1); 
    root1->left = insert(2); 
    root1->right = insert(3); 
    root1->left->left = insert(4); 
    root1->left->right = insert(5); 
  
    struct node *root2 = insert(1); 
    root2->left = insert(2); 
    root2->right = insert(3); 
    root2->left->left = insert(4); 
    root2->left->right = insert(5); 

	cout<<isIdentical(root1, root2);

	return 0;
}