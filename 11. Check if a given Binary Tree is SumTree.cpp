/* Write a function that returns true if the given Binary Tree is SumTree else false. 
 SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes 
 present in its left subtree and right subtree. An empty tree is SumTree and sum of 
 an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree. 

          26
        /   \
      10     3
    /    \     \
  4      6      3 */

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

bool isLeaf(struct node* root)
{
	if(root==NULL)
		return false;
	if(root->left == NULL and root->right == NULL)
		return true;
	return false;
}

bool isSumTree(struct node* root)
{
    int lst_sum=0;
    int rst_sum=0;
    
    if(root == NULL || isLeaf(root))
        return 1;
    
    if( (root->left) and (root->right) )
    {
        //check if lst sum + rst sum == root->data;
        if(root->left == NULL)
        lst_sum=0;
        else if (isLeaf(root->left))
        lst_sum= root->left->data;
        else
        lst_sum= 2 * (root->left->data);
        
        if(root->right == NULL)
        rst_sum=0;
        else if (isLeaf(root->right))
        rst_sum= root->right->data;
        else
        rst_sum= 2 * (root->right->data);
        
        return ((root->data)==(lst_sum+rst_sum));
    }
    return 0;
}

int main()
{
	struct node* root = insert(26);
	root->left = insert(10);
	root->right = insert(3);

	root->left->left = insert(4);
	root->left->right = insert(6);

	root->right->right = insert(3);
	
	cout<<isSumTree(root);
	return 0;
}	

