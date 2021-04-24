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

void bfs_usingQueue(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	queue<node *>q;
	q.push(root);

	while(!q.empty())
	{
		struct node* front = q.front();
		cout<<front->data<<" ";
		q.pop();

		if(front->left)
			q.push(front->left);
		if(front->right)
			q.push(front->right);
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
	
	bfs_usingQueue(root);
	return 0;
}	

