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

bool isPresentAndPrintPath(struct node* root, vector<int>&vec, int val)
{
	if(root == NULL)
		return false;

	if(root->data == val)
	{
		vec.push_back(root->data);
		return true;
	}

	if(isPresentAndPrintPath(root->left, vec, val) || isPresentAndPrintPath(root->right, vec, val))
	{
		vec.push_back(root->data);
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

	vector<int>vec;
	if(isPresentAndPrintPath(root, vec, 9))
	{
		// if you want to print from root to node
		reverse(vec.begin(), vec.end());
		for(auto i : vec)
		{
			cout<<i<<" ";
		}
	}
	else
	{
		cout<<"NO PATH"<<endl;
	}


	return 0;
}