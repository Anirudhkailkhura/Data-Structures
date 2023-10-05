#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int v)
    {
        value = v;
        left = right = NULL;
    }
};
// DFS
void preorderTraversal(Node *rootNode)
{
    // base case
    if (rootNode == NULL)
    {
        return;
    }
    cout << rootNode->value << " ";
    // resursive call
    preorderTraversal(rootNode->left);
    preorderTraversal(rootNode->right);
}

void inorderTraversal(Node *rootNode)
{

    // base case
    if (rootNode == NULL)
    {
        return;
    }
    // resursive call
    inorderTraversal(rootNode->left);
    cout << rootNode->value << " ";
    inorderTraversal(rootNode->right);
}

void postorderTraversal(Node *rootNode)
{

    // base case
    if (rootNode == NULL)
    {
        return;
    }
    // resursive call
    postorderTraversal(rootNode->left);
    postorderTraversal(rootNode->right);
    cout << rootNode->value << " ";
}

void levelOrderTraversal(Node* rootNode){
    if(rootNode == NULL){
        return;
    }
    queue<Node*> q;
    q.push (rootNode);

    while(!q.empty()){
        int nodeAtCurrLevel = q.size();
        while(nodeAtCurrLevel--){
            Node* currNode = q.front();
            q.pop();
            cout<<currNode->value<<" ";

            if(currNode->left){
                q.push(currNode->left);
            }

            if(currNode->right){
                q.push(currNode->right);
            }
        }
        cout<<endl;
    }

     
}

int main()
{
    Node *rootNode = new Node(2);
    rootNode->left = new Node(3);
    rootNode->right = new Node(4);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(8);
    rootNode->right->right = new Node(9);

    levelOrderTraversal (rootNode);
}