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

int bfs_usingQueue_fullNodes(struct node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	queue<node *>q;
	q.push(root);
	int count=0;
	while(!q.empty())
	{
		struct node* front = q.front();
		if(front->left and front->right)
		{
			count++;
			cout<<front->data<<" ";
		}
		q.pop();

		if(front->left)
			q.push(front->left);
		if(front->right)
			q.push(front->right);
	}
	cout<<endl;
	return count;
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
	
	cout<<bfs_usingQueue_fullNodes(root);

	return 0;
}	

