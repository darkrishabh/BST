#include <iostream>



using namespace std;
struct BSTNode{
    int value;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode*, int);
BSTNode* GetNode(int);
BSTNode* remove(BSTNode* , int);
bool Search(BSTNode*, int);
void preOrder(BSTNode*);
void postOrder(BSTNode*);
void InOrder(BSTNode*);

BSTNode *FindMin(BSTNode *pNode);

int main() {
    BSTNode* root = NULL;
    int n;
    root = insert(root,7);
    root = insert(root,9);
    root = insert(root,5);
    root = insert(root,4);
    root = insert(root,8);
    root = remove(root,7);

    cout <<"PreOrder Traversal: " << endl;
    preOrder(root);
    cout <<"\n\nPostOrder Traversal: " << endl;
    postOrder(root);
    cout <<"\n\nInOrder Traversal: " << endl;
    InOrder(root);

    cout<< "\n Enter a number to Search: ";
    cin>>n;
    if(Search(root,n))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}
BSTNode* insert(BSTNode* root, int value){
    if(root == NULL){
        root = GetNode(value);
    }
    else if(value <= root->value){
        root->left = insert(root->left, value);
    }
    else
        root->right = insert(root->right,value);
    return root;

}
BSTNode* GetNode(int value){
    BSTNode* node = new BSTNode();
    node->value = value;
    node->left = node->right = NULL;
    return node;
}
BSTNode* remove(BSTNode* root, int value){
    if(root == NULL)
       return root;
    else if(value < root->value)
        root->left = remove(root->left, value);
    else if (value > root->value)
        root->right = remove(root->right,value);
    else{
        // Case 1:  No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
            //Case 2: One child
        else if(root->left == NULL) {
            BSTNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL) {
            BSTNode *temp = root;
            root = root->left;
            delete temp;
        }
            // case 3: 2 children
        else {
            BSTNode *temp = FindMin(root->right);
            root->value = temp->value;
            root->right = remove(root->right,temp->value);
        }
    }
    return root;

}

BSTNode *FindMin(BSTNode *root) {
    while(root->left != NULL) root = root->left;
    return root;
}

bool Search(BSTNode* root, int value){
    if(root == NULL)return false;
    else if(value == root->value) return true;
    else if(value <= root->value) return Search(root->left, value);
    else return Search(root->right, value);
}
void preOrder(BSTNode* root){
    if(root != NULL){
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(BSTNode* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }
}
void InOrder(BSTNode* root){
    if(root != NULL){
        postOrder(root->left);
        cout << root->value << " ";
        postOrder(root->right);
    }
}