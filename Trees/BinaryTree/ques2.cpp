// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the
// nodes you can see from top to bottom.

#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
       int val;
       Node *left;
       Node *right;
       Node(int val){
           this->val = val;
       }
};
vector<int> rightSideView(Node* root) {
        queue<Node*>q;
        vector<int> ans;
        if(!root) return ans;
        q.push(root);
        while(q.size()>0)
        {
            int size=q.size();
            while(size>0)
            {
                Node*temp=q.front();
                q.pop();
                if(size==1)
                {
                    ans.push_back(temp->val);
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                size--;
            }
        }
        return ans;
}
int main()
{
       Node *root = new Node(2);
       root->left = new Node(4);
       root->right = new Node(10);
       root->left->left = new Node(6);
       root->left->right = new Node(5);
       root->right->right = new Node(11);
       vector<int> ans=rightSideView(root);
       for(int i=0;i<ans.size();i++)
       {
           cout<<ans[i]<<" ";
       }
}