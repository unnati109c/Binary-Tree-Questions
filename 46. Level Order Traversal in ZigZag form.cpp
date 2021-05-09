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

vector <int> ZigZagOrder(node* root)
{
	vector<int>ans;
	queue<node*>q;
	if(!root)
	    return ans;
	q.push(root);
	int f=0;
	while(!q.empty())
	{
	    int n = q.size();
	    vector<int>temp;
	    
	    for(int i=1;i<=n;i++)
	    {
	        node* front = q.front();
	        q.pop();
	        
	        temp.push_back(front->data);
	        
	        if(front->left)
	        q.push(front->left);
	        
	        if(front->right)
	        q.push(front->right);
	    }
	    if(f==1) reverse(temp.begin(), temp.end());
	    for(auto i : temp)
	    {
	        ans.push_back(i);
	    }
	    f=!f;
	}
	return ans;
}

int main()
{
	struct node* root = insert(26);
	root->left = insert(10);
	root->right = insert(3);

	root->left->left = insert(4);
	root->left->right = insert(6);

	root->right->left = insert(4);
	root->right->right = insert(3);
	
	vector<int>ans = ZigZagOrder(root);
	for(auto i : ans)
	{
		cout<<i<<" ";
	}
	return 0;
}	

