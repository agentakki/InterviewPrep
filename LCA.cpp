Node* LCA(Node *root, Node *a, Node *b){
    if(root == NULL || root == a || root == b) 
        return root;
    Node *left = LCA(root->left, a, b);
    Node *right = LCA(root->right, a, b);

    //If nodes were found on each child
    if(left && right) 
        return root;
    
    if(left == NULL) 
        return right;
    else 
        return left;
}
