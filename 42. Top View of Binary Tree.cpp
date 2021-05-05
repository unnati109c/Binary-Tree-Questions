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

vector<int> topView(struct node *root)
{
    map<int,int>m;
    vector<int>ans;
    queue<pair<node*,int>>q;
    
    if(!root)
    return ans;
    q.push({root,0});
    while(!q.empty())
    {
        node* front = q.front().first;
        int h = q.front().second;
        q.pop();
        
        if(m[h]==0)
        m[h] = front->data;
        
        if(front->left)
        q.push({front->left, h-1});
        
        if(front->right)
        q.push({front->right, h+1});
    }
    for(auto i : m)
        ans.push_back(i.second);
    
    return ans;
    
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

	root->left->left->left->left = new node(10);

	vector<int>ans = topView(root);
	for(auto i : ans)
	{
		cout<<i<<" ";
	}
	return 0;
}