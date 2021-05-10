vector<int> largestValues(Node* root)
{
    queue<Node*>q;
    vector<int>ans;
    if(!root)
    return ans;
    q.push(root);
    while(!q.empty())
    {
        int n= q.size();
        int max_till_now=-1;
        for(int i=1;i<=n;i++)
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->data > max_till_now)
            max_till_now = temp->data;
            
            if(temp->left)
            q.push(temp->left);
            
            if(temp->right)
            q.push(temp->right);
        }
        ans.push_back(max_till_now);
        
        
    }
    return ans;
}