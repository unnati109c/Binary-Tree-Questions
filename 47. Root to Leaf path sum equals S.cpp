/* Given a binary tree and an integer S, check whether there is root to 
leaf path with its sum as S. */

bool hasPathSum(Node *root, int S) {
    if(!root)
    return 0;
    
    bool ans = 0;
    int subSum = S - root->data;
 
    /* If we reach a leaf node and sum becomes 0 then return true*/
    if ( subSum == 0 && root->left == NULL && root->right == NULL)
    return 1;
     
    /* otherwise check both subtrees */
    if(root->left)
        ans = ans || hasPathSum(root->left, subSum);
    if(root->right)
        ans = ans || hasPathSum(root->right, subSum);
 
    return ans;
}