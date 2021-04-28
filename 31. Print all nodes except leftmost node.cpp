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

vector<int> LeftView(struct node* root)
{
	vector<int>v;
	queue<node*>q;
	q.push(root);

	while(!q.empty())
	{
		int n = q.size();
		for(int i=1;i<=n;i++)
		{
			struct node* front = q.front();
			q.pop();

			if(i!=1)
				v.push_back(front->data);

			if(front->left) q.push(front->left);
			if(front->right) q.push(front->right);
		}
		v.push_back(INT_MIN);
	}
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
		if(i==INT_MIN) cout<<endl;
		else cout<<i<<" "; 
	return 0;
}	

