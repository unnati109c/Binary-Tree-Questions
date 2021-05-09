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

vector<int> reverseLevelOrder(node *root)
{
    vector<int>ans;
    queue<node*>q;
    if(!root)
    return ans;
    
    q.push(root);
    
    while(!q.empty())
    {
        node* front = q.front();
        q.pop();
        
        ans.push_back(front->data);
        
        if(front->right)
			q.push(front->right);
        if(front->left)
			q.push(front->left);
    }
    reverse(ans.begin(), ans.end());
    return ans;
     
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
	
	vector<int>ans = reverseLevelOrder(root);
	for(auto i : ans)
	{
		cout<<i<<" ";
	}
	return 0;
}	

