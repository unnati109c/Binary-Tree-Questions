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

int Diameter(node* root)
{
    if(root==NULL)
    return 0;
    
    int lheight = height(root->left);
    int rheight = height(root->right);
    
    int ldiameter = Diameter(root->left);
    int rdiameter = Diameter(root->right);
    
    return max(lheight+rheight+1, max(ldiameter, rdiameter));
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

	cout<<Diameter(root);

	return 0;
}