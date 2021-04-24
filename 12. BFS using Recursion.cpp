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

int height(struct node* root)
{
	if(root == NULL)
		return 0;
	return 1 + max((height(root->left)), (height(root->right)));
}

void valuesAtLevel_i(struct node* root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
		cout<<root->data<<" ";
	else if(level>1)
	{
		valuesAtLevel_i(root->left, level-1);
		valuesAtLevel_i(root->right, level-1);
	}
}

void bfs(struct node* root)
{
	int h = height(root);
	for(int i=1;i<=h;i++)
	{
		valuesAtLevel_i(root, i);
		cout<<endl;
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
	
	bfs(root);
	return 0;
}	

