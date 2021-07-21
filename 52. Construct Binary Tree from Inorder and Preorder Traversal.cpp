#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends

class Solution{
    public:

    int index=0;
    unordered_map<int,int>m;
    Node* helper(int in[],int pre[],int lb, int ub)
    {
        if(lb>ub) return NULL;
        
        Node* root_node = new Node(pre[index++]);
        
        if(lb==ub) return root_node;
        
        int mid = m[root_node->data];
        
        root_node->left = helper(in, pre, lb, mid-1);
        root_node->right = helper(in, pre, mid+1, ub);
        
        return root_node;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        index=0;
        for(int i=0;i<n;i++)
        {
            m[in[i]]=i;
        }
        Node* root_node = helper(in,pre,0,n-1);
        return root_node;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends