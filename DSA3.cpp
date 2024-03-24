#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include <math.h>
#include <climits>
#include <string>
#include<algorithm>
#include<vector>
#include<stack>

//Binary tree:Binary Tree is defined as a tree data structure where each node has at most 2 children. Since each element in a binary tree can have only 2 children, we typically name them the left and right child
//Properties: 1)Maximum nodes at level L:2^L
// 2)Maximum nodes in a tree of height H: 2^H -1
// 3)For N nodes, minimum possible height or minimum number of levels are log2(N+1)
// 4)A binary tree with L leaves has atleast log2(N+1)+1 number of levels
struct node{
    int data;
    struct node*left;
    struct node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void preorder(struct node*root);
void inorder(struct node*root);
void postorder(struct node*root);
// int main(){
//     struct node*root=new node(1);
//     root->left=new node(2);
//     root->right=new node(3);
//     root->left->left= new node(4);
//     root->left->right=new node(5);
//     root->right->left=new node(6);
//     root->right->right=new node(7);
//     //         1
//     //       /   \
//     //      2     3
//     //     / \   / \
//     //    4   5 6   7
//     // preorder(root);
//     // cout<<endl;
//     // inorder(root);
//     // cout<<endl;
//     // postorder(root);
// } 

// Binary tree traversals: 
// Preorder traversals:1) Visit the root 2)Traverse the left subtree, i.e., call Preorder(left->subtree) 3)Traverse the right subtree, i.e., call Preorder(right->subtree) 
void Preorder(struct node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
// Inorder traversal: 1)Traverse the left subtree, i.e., call Inorder(left->subtree) 2)Visit the root. 3)Traverse the right subtree, i.e., call Inorder(right->subtree)
void Inorder(struct node*root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
//Postorder traversal: 1)Traverse the left subtree, i.e., call Postorder(left->subtree) 2)Traverse the right subtree, i.e., call Postorder(right->subtree) 3)Visit the root
void Postorder(struct node*root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
//Building trees from preorder and inorder:
int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
node*buildtree_pre_in(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    node*Node=new node(curr);
    int pos=search(inorder,start,end,curr);
    if(start==end){
        return Node;
    }
    Node->left=buildtree_pre_in(preorder,inorder,start,pos-1);
    Node->right=buildtree_pre_in(preorder,inorder,pos+1,end);
}

//Building tree from postorder and preorder
node*buildtree_post_in(int postorder[],int inorder[],int start,int end){
    static int idx = 4;//since the size of our post and inorder arrays is 5, idx=n-1 i.e. 4
    if(start>end){
        return NULL;
    }
    int val = postorder[idx];
    idx--;
    node*curr =  new node(val);
    if(start==end){
        return curr;
    }
    int pos = search(inorder,start,end,val);
    curr->right = buildtree_post_in(postorder,inorder,pos+1,end);
    curr->left= buildtree_post_in(postorder,inorder,start,pos-1);
    return curr;
}

void print_level_order(node*root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }    
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
node*create_tree(){
    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left= new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    return root;
}

int sum_at_K(node*root,int k){
    if(root==NULL){
        return -1;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        node*node=q.front();
        q.pop();
        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum; 
}

int countnodes(node*root){
    if(root==NULL){
        return 0;
    }
    return (countnodes(root->left)+countnodes(root->right)+1);
}

int sum_of_nodes(node*root){
    if(root==NULL){
        return 0;
    }
    int sum = sum_of_nodes(root->left) + sum_of_nodes(root->right) + root->data;
    return sum;
}

int calc_height(node*root){
    if(root==NULL){
        return 0;
    }
    int lheight=calc_height(root->left);
    int rheight=calc_height(root->right);
    return max(lheight,rheight)+1;
}
//Diameter: it is the longest path between two nodes in a binary tree
int calc_diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int lheight=calc_height(root->left);
    int rheight=calc_height(root->right);
    int currdiameter=lheight+rheight+1;
    int ldiameter=calc_diameter(root->left);
    int rdiameter=calc_diameter(root->right);
    return max(currdiameter,max(ldiameter,rdiameter));
}

//SUM REPLACEMENT PROBLEM : replace the value of each node with the sum of subtree nodes and itself
void sum_replace(node*root){
    if(root==NULL){
        return;
    }
    sum_replace(root->left);
    sum_replace(root->right);
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    } 
}

//Balanced Height Tree : for each subnode, the difference between the heights of left subtree and right subtree <=1
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
bool is_balanced(node*root){
    if(root==NULL){
        return true;
    }
    if(is_balanced(root->left)==false){
        return false;
    }
    if(is_balanced(root->right)==false){
        return false;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
}
//Optimised is_balanced approach
bool is_Balanced(node*root,int*height){
    if(root==NULL){
        return true;
    }
    int lh=0;int rh=0;
    if(is_Balanced(root->left,&lh)==false){
        return false;
    }
    if(is_Balanced(root->right,&rh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}

//Right view of binary tree: traversing the binary tree with rightmost view from the binary tree
void right_view(node*root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node*curr=q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data;
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

//Left view : traversing the binary tree from the leftmost view of the binary tree
void left_view(node*root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node*curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->data;
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

// Find the distance between two nodes in a binary tree. The distance between two nodes is the minimum number of edges to be traversed to travel from one node to another
node*LCA(node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node*right=LCA(root->right,n1,n2);
    node*left=LCA(root->left,n1,n2);
    if(left==NULL && right==NULL){
        return NULL;
    }
    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left!=NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}

int find_dist(node*root,int k,int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dist;
    }
    int left=find_dist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }
    return find_dist(root->right,k,dist+1);
}
int dist_between_nodes(node*root,int n1,int n2){
    node*lca=LCA(root,n1,n2);
    int d1=find_dist(lca,n1,0);
    int d2=find_dist(lca,n2,0);
    return d1+d2;
}

// Flatten a binary tree: given a binary tree, flatten it into a linked list in-place, after flattening left of each node should point to Null anad right should contain next node in preoreder sequence.(Its not allowed to use other data structures)
void flatten(node*root){
    if(root==NULL || root->left==NULL && root->right==NULL){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
    }
    if(root->right!=NULL){
        flatten(root->right);
    }
    if(root->left!=NULL){
        node*temp=root->right;
        root->right=root->left;
        root->left=NULL;
        node*t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
}

//Nodes at distance K: given a binary tree with a given node and distance, find all the nodes at the given distance from the given node
//case 1: if the found nodes are in the subtree
void print_subtree_nodes(node*root, int k){
    if(root == NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    print_subtree_nodes(root->left,k-1);
    print_subtree_nodes(root->right,k-1);
}
//case 2 : if the nodes are to be found through the ancestor nodes
int print_nodes_at_k(node* root, node* target, int k) {
    if (root == NULL){ 
        return -1;
    }
    if (root == target) {
        print_subtree_nodes(root, k); 
        return 0;
    }

    int dl = print_nodes_at_k(root->left, target, k); 
    if (dl != -1) {
        if (dl + 1 == k) {
            cout << root->data << " "; 
        } else {
            print_subtree_nodes(root->right, k - dl - 2); 
        }
        return 1 + dl;
    }

    int dr = print_nodes_at_k(root->right, target, k); 
    if (dr != -1){
        if (dr + 1 == k) {
            cout << root->data << " "; 
        } else {
            print_subtree_nodes(root->left, k - dr - 2); 
        }
        return 1 + dr;
    }

    return -1;
}

bool getpath(node* root, int key, vector<int>& path) {
    if (root == NULL) {
        return false;
    }
    
    path.push_back(root->data);
    
    if (root->data == key) {
        return true;
    }
    
    if (getpath(root->left, key, path) || getpath(root->right, key, path)) {
        return true;
    }
    
    path.pop_back();
    return false;
}

int LCA2(node* root, int n1, int n2) {
    vector<int> path1, path2;
    
    if (!getpath(root, n1, path1) || !getpath(root, n2, path2)) {
        return -1; 
    }

    int pc;
    for (pc = 0; pc < path1.size() && pc < path2.size(); pc++) {
        if (path1[pc] != path2[pc]) {
            break;
        }
    }

    if (pc == path1.size() || pc == path2.size()) {
        return pc == path1.size() ? n1 : n2;
    }

    return path1[pc - 1];
}

//Maximum path sum: maximum possible sum of a path in a binary tree, starting and ending at any node
int max_path_sum_util(node*root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left=max_path_sum_util(root->left,ans);
    int right=max_path_sum_util(root->right,ans);
    int nodeMax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans=max(ans,nodeMax);
    int single_path_sum=max(root->data,max(root->data+left,root->data+right));
    return single_path_sum;
}
int max_path_sum(node*root){
    int ans=INT_MIN;
    max_path_sum_util(root,ans);
    return ans;
}
int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    int postorder[]={4,2,5,3,1};
    //node* root=buildtree_pre_in(preorder,Inorder,0,4);
    //node*root=buildtree_post_in(postorder,Inorder,0,4);
    //inorder(root);
    node*root=create_tree();
    // print_level_order(root);
    // cout<<endl;
    // for(int i=0;i<3;i++){
    //     cout<<"Sum at "<< i<<" level is:"<<sum_at_K(root,i);
    //     cout<<endl;
    // }
    // int number_of_nodes = countnodes(root);
    // cout<<number_of_nodes<<endl;
    // int sum =sum_of_nodes(root);
    // cout<<sum;
    //cout<<calc_height(root);
    //cout<<calc_diameter(root);
    // Preorder(root);
    // cout<<endl;
    // sum_replace(root);
    // Preorder(root);
    //cout<<is_balanced(root);
    //right_view(root);cout<<endl;
    //left_view(root);
    //cout<<dist_between_nodes(root,2,7);
    //Inorder(root);flatten(root);cout<<endl;Inorder(root);
    //print_nodes_at_k(root,root->left,1);
    //cout<<LCA2(root,4,5);
    cout<<max_path_sum(root);
    return 0;
}