/* 
		      1
		2           3
	   4 5       6     7
			   8		9
			   			 10
*/
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

int max_level = 0;
void LeftViewHelper(vector<int>&vec, struct node* root, int level)
{
	if(root == NULL)
		return ;
	if(max_level < level)
	{
		vec.push_back(root->data);
		max_level = level;
	}
	LeftViewHelper(vec, root->left, level+1);
	LeftViewHelper(vec, root->right, level+1);
}

vector<int> LeftView(struct node* root)
{
	max_level=0;
	vector<int>v;
	LeftViewHelper(v, root, 1);
	return v;
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
	
	vector<int> ans = LeftView(root);
	for(auto i : ans)
		cout<<i<<" "; 
	return 0;
}	

