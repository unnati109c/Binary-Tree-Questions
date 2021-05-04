/*
          1
        /    \
       2      3
      / \    / \
     4   5  6   7
    /     \    /
   8       9  10
  /
 11

*/

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

bool RootToNodePathSum(struct node* root, int& sum, int val)
{
	if(root == NULL)
		return false;

	if(root->data == val)
	{
		sum += (root->data);
		return true;
	}

	if(RootToNodePathSum(root->left, sum, val) || RootToNodePathSum(root->right, sum, val))
	{
		sum += (root->data);
		return true;
	}

	return false;
}

int main()
{
	struct node* root = new node(1);

	root->left = new node(2);
	root->right = new node(3);

	root->left->left = new node(4);
	root->left->right = new node(5);

	root->right->left = new node(6);
	root->right->right = new node(7);

	root->left->left->left = new node(8);
	root->left->right->right = new node(9);
	root->right->right->left = new node(10);

	root->left->left->left->left = new node(11);

	int sum=0;
	if(RootToNodePathSum(root, sum, 9))
	{
		cout<<sum<<endl;
	}
	else
	{
		cout<<"NO PATH"<<endl;
	}


	return 0;
}