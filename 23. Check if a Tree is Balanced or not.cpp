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

int height(node* root)
{
    if(root == NULL) 
    	return 0;
    
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(node* root)
{
    if(!root) return 1;
    
    int l = height(root->left);
    int r = height(root->right);
    
    if((abs(l-r)<=1) and isBalanced(root->left) and isBalanced(root->right))
    {
        return true;
    }
    return false;
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

	cout<<isBalanced(root);

	return 0;
}