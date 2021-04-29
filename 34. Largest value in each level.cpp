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

vector<int> LargestValueInEachLevel(struct node* root)
{
	vector<int>v;
	queue<node*>q;
	q.push(root);

	while(!q.empty())
	{
		int n = q.size();
		int max_val=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			struct node* front = q.front();
			q.pop();

			if(max_val < front->data)
				max_val = front->data;

			if(front->left) q.push(front->left);
			if(front->right) q.push(front->right);
		}
		v.push_back(max_val);
		v.push_back(INT_MIN); // to print every value acc. to level
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
	
	vector<int> ans = LargestValueInEachLevel(root);
	for(auto i : ans)
		if(i==INT_MIN) cout<<endl;
		else cout<<i<<" "; 
	return 0;
}	

