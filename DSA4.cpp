#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include <math.h>
#include <climits>
#include <string>
#include<algorithm>
#include<vector>
#include<stack>

//Binary searc tree: rule 1) the left subtree of a node contains only nodes with keys lesser than keys nodes
//rule 2) the right subtree of a node contains only nodes with keys greater than keys nodes
// rule 3) the left and right subtree each must also be a binary tree. there must be no duplicate nodes

struct node{
    int data;
    node*right;
    node*left;
    node(int val){
        data=val;
        right=nullptr;
        left=nullptr;
    }
};

//struct made to find largest BST in a binary tree
struct info{
    int size;
    int max;
    int min;
    int ans;
    bool ISBST;
};

node*insert_BST(node*root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insert_BST(root->left,val);
    }
    else{
        root->right=insert_BST(root->right,val);
    }
    return root;
}

void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    //BST's inorder is always in sorted order.
}

node*search_in_BST(node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data<key){
        return search_in_BST(root->right,key);
    }
    if(root->data>key){
        return search_in_BST(root->left,key);
    }
}

node*inorder_succesor(node*root){
    node*curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node*delete_in_BST(node*root,int key){
    if(key<root->data){
        root->left=delete_in_BST(root->left,key);
    }
    else if(key>root->data){
        root->right=delete_in_BST(root->right,key);
    }
    else{
        if(root->left==NULL){
            node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node*temp=root->left;
            free(root);
            return temp;
        }
        node*temp=inorder_succesor(root->right);
        root->data=temp->data;
        root->right=delete_in_BST(root->right,temp->data);
    }
}

node*construct_BST(int preorder[],int* preorderIdx,int key,int min,int max,int n){
    if(*preorderIdx>=n){
        return NULL;
    }
    node*root=NULL;
    if(key>min && key<max){
        root=new node(key);
        *preorderIdx=*preorderIdx+1;
        if(*preorderIdx<n){
            root->left=construct_BST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n){
            root->right=construct_BST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;
}

void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

bool isBST(node*root,node*min=nullptr,node*max=nullptr){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool leftvalid=isBST(root->left,min,root);
    bool rightvalid=isBST(root->right,root,max);
    return leftvalid and rightvalid;
}

//Building balanced bst from sorted array
node*sorted_arr_to_bst(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    node*root=new node(arr[mid]);
    root->left=sorted_arr_to_bst(arr,start,mid-1);
    root->right=sorted_arr_to_bst(arr,mid+1,end);
    return root;
}

//Catalan numbers: Catalan numbers appear as a sequence in many combinatorial problems such as polygon triangulation, balanced parenthesis, lattice path, Dyck's paths, the problem of binary trees, multiplication ordering and in the many other problems.
int catalan(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<n;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}
//construction of possible BSTs
vector<node*> construct_trees(int start,int end){
    vector<node*>trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<node*>leftsubtrees=construct_trees(start,i-1);
        vector<node*>rightsubtrees=construct_trees(i+1,end);
        for(int j=0;j<leftsubtrees.size();j++){
            node*left=leftsubtrees[j];
            for(int k=0;k<rightsubtrees.size();k++){
                node*right=rightsubtrees[k];
                node*Node=new node(i);
                Node->left=left;
                Node->right=right;
                trees.push_back(Node);
            }
        }
    }
    return trees;
}

void zigzag_traversal(node*root){
    if(root==NULL){
        return;
    }
    stack<node*>currlevel;
    stack<node*>nextlevel;
    bool left_to_right=true;
    currlevel.push(root);
    while(!currlevel.empty()){
        node*temp=currlevel.top();
        currlevel.pop();
        if(temp){
            cout<<temp->data<<" ";
            if(left_to_right){
                if(temp->left){
                    nextlevel.push(temp->left);
                }
                if(temp->right){
                    nextlevel.push(temp->right);
                }
            }
            //right_to_left
            else{
                if(temp->right){
                    nextlevel.push(temp->right);
                }
                if(temp->left){
                    nextlevel.push(temp->left);
                }
            }
        }
        if(currlevel.empty()){
            left_to_right=!left_to_right;
            swap(currlevel,nextlevel);
        }
    }
}

//For given root nodes of two binary search trees, print if the BSTs are identical or not. Identical BSTs are structurally identical and have equal values for the nodes in the structure.
bool isIdentical(node*root1,node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    else{
        bool cond1=root1->data==root2->data;
        bool cond2=isIdentical(root1->left,root2->left);
        bool cond3=isIdentical(root1->right,root2->right);
        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }
}

//Return the size of the largest BST in a binary tree
info LargestBSTinBT(node*root){
    if(root==NULL){
        return{0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return{1,root->data,root->data,1,true};
    }
    info left_info=LargestBSTinBT(root->left);
    info right_info=LargestBSTinBT(root->right);
    info curr;
    curr.size=(1+left_info.size+right_info.size);
    if(left_info.ISBST && right_info.ISBST && left_info.max < root->data && right_info.max >root->data){
        curr.min=min(left_info.min,min(right_info.min,root->data));
        curr.max=max(right_info.max,max(left_info.max,root->data));
        curr.ans=curr.size;
        curr.ISBST=true;
        return curr;
    }
    curr.ans=max(left_info.ans,right_info.ans);
    curr.ISBST=false;
    return curr;
}

//Two nodes of a BST are swapped. we need to restore the BST by getting the nodes back to their current position
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void calcpointers(node*root,node**first,node**mid,node**last,node**prev){
    if(root==NULL){
        return;
    }
    calcpointers(root->left,first,mid,last,prev);
    if(*prev && root->data<(*prev)->data){
        if(!*first){
            *first=*prev;
            *mid=root;
        }
        else{
            *last=root;
        }
    }
    *prev=root;
    calcpointers(root->right,first,mid,last,prev);
}
void restoreBST(node*root){
    node*first,*mid,*last,*prev;
    first=last=mid=prev=NULL;
    calcpointers(root,&first,&mid,&last,&prev);
    //case 1
    if(first && last){
        swap(&(first->data),&(last->data));
    }
    if(first && mid){
        swap(&(first->data),&(mid->data));
    }
}

int main(){
    node*root=NULL;
    vector<int>arr={5,1,3,4,2,7,8};
    for(int i=0;i<arr.size();i++){
        root=insert_BST(root,arr[i]);
    }
    //inorder(root);cout<<endl;
    // if(search_in_BST(root,6)==NULL){
    //     cout<<"key doesn't exist"<<endl;
    // }else{
    //     cout<<"key exists"<<endl;
    // }
    //root=delete_in_BST(root,1);
    //inorder(root);
    // int Preorder[]={10,2,1,13,11};
    // int n=5;
    // int preorderIdx=0;
    // node*rule=construct_BST(Preorder,&preorderIdx,Preorder[0],INT_MIN,INT_MAX,n);
    // preorder(rule);
    //cout<<isBST(root,NULL,NULL);
    // int a[]={10,20,30,40,50};
    // node*rot=sorted_arr_to_bst(a,0,4);
    // inorder(rot);
    // for(int i=0;i<10;i++){
    //     cout<<catalan(i)<<" ";
    // }
    // vector<node*>total_trees=construct_trees(1,3);
    // for(int i=0;i<total_trees.size();i++){
    //     cout<<(i+1)<<":";
    //     preorder(total_trees[i]);cout<<endl;
    // }
    //zigzag_traversal(root);
    return 0;
}