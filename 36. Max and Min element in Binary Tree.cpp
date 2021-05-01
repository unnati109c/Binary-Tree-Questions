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

int findMax(struct node* root)
{
    if(!root) return INT_MIN;
    int max_ele = root->data;
    int left_max = findMax(root->left);
    int right_max = findMax(root->right);
    
    return max(max_ele, max(left_max, right_max));
}

int findMin(struct node* root)
{
    if(!root) return INT_MAX;
    int min_ele = root->data;
    int left_min = findMin(root->left);
    int right_min = findMin(root->right);
    
    return min(min_ele, min(left_min, right_min));
}

int main()
{
	struct node* root = insert(1);
	root->left = insert(2);
	root->right = insert(3);

	root->left->left = insert(4);
	root->left->right = insert(5);

	root->right->left = insert(6);
	root->right->right = insert(7);

	root->right->left->left = insert(8);
	root->right->right->right = insert(9);

	root->right->right->right->right = insert(10);
	
	cout<<findMin(root)<<" "<<findMax(root);
	
	return 0;
}	

