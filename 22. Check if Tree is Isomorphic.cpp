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

struct node* newNode(int val)
{
		return new node(val);
}

bool isIsomorphic(struct node* root1, struct node* root2)
{
	if(!root1 and !root2) return true;
	if(!root1 or !root2) return false;
	
	bool a = (isIsomorphic(root1->left, root2->right)) and (isIsomorphic(root1->right, root2->left));
	bool b = (isIsomorphic(root1->left,root2->left)) and (isIsomorphic(root1->right,root2->right));
	return (root1->data == root2->data) and ( a or b );
}

int main()
{
	struct node *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);
  
    struct node *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    n2->right->left   = newNode(4);
    n2->right->right   = newNode(5);
    n2->left->right   = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);
	cout<<isIsomorphic(n1, n2);

	return 0;
}