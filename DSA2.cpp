#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include <math.h>
#include <climits>
#include <string>
#include<algorithm>
#include<vector>
#include<stack>
//483356152

//LINKED LIST:these are similar to array but array is a single block of memory with partitions and linked list are multiple blocks of memory linked to each other
//For a linked list,the structure for a single element is it holds data and points to the next element
// class node{
//     public:
//     int data;
//     node*next;
//     node(int val){
//         data=val;
//         next=NULL;
//     }
//     void insertAtTail(node*&head,int val){
//         node*n=new node(val);
//         if(head==NULL){
//             head=n;
//             return;
//         }
//         node*temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }temp->next=n;
//     }
//     void insertAtHead(node*&head,int val){
//         node*n=new node(val);
//         n->next=head;
//         head=n;
//     }
//     void display(node*head){
//         node*temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<"->";
//             temp=temp->next;
//         }cout<<"NULL"<<endl;
//     }
    // bool search(node*&head,int key){
    //     node*temp=head;
    //     while(temp!=NULL){
    //         if(temp->data==key){
    //             cout<<"Element found!!\n";
    //             return true;
    //         }
    //         temp=temp->next;
    //     }
    //     cout<<"Element not found\n";
    //     return false;
    // }
    // void deleteAtHead(node*&head){
    //     node*todelete=head;
    //     head=head->next;
    //     delete todelete;
    // }
    // void deletion(node*&head,int val){
    //     if(head=NULL){
    //         return;
    //     }
    //     if(head->next=NULL){
    //         deleteAtHead(head);
    //         return;
    //     }
    //     node*temp=head;
    //     while(temp->next->data!=val){
    //         temp=temp->next;
    //     }
    //     node*todelelete=temp->next;
    //     temp->next=temp->next->next;
    //     delete todelelete;
    // }    
//};
// //Reversing a linked list
// //Iterator method
// node*reverse_iter(node*&head){
//     node*prevptr=NULL;
//     node*currptr=head;
//     node*nextptr;
//     while(currptr!=NULL){
//         nextptr=currptr->next;
//         currptr->next=prevptr;
//         prevptr=currptr;
//         currptr=nextptr;
//     }
//     return prevptr;
// }
// //Recursive method
// node*reverse_recursive(node*&head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     node*newhead=reverse(head->next);
//     head->next->next=head;
//     head->next=NULL;
//     return newhead;
// }
// //Reversing K nodes in a list
// node*kreverse(node*&head,int k){
//     node*prevptr=NULL;
//     node*currptr=head;
//     node*nextptr;
//     int count=0;
//     while(currptr!=NULL && count<k){
//         nextptr=currptr->next;
//         currptr->next=prevptr;
//         prevptr=currptr;
//         currptr=nextptr;
//         count++;
//     }
//     if(nextptr!=NULL){
//         head->next=kreverse(nextptr,k);
//     }
//     return prevptr;
// }
// //When two nodes of a linked list point to the same next, this condition is called cycle in a linked list
// //For detection of cycle in a linked list, we use floyd's or hare and tortoise algrorithm(both are diff name for same algorithm)
// void makecycle(node*&head,int pos){
//     node*temp=head;
//     node*starnode=NULL;
//     int count=1;
//     while(temp->next!=NULL){
//         if(count==pos){
//             starnode=temp;
//         }
//         temp=temp->next;
//         count++;
//     }
//     temp->next=starnode;
// }
// bool detectcycle(node*&head){
//     node*slow=head;
//     node*fast=head;
//     while(fast!=NULL && fast->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//         if(fast==slow){
//             cout<<"Cycle detected!!\n";
//             return true;
//         }
//     }cout<<"No cycle Detected!!\n";return false;
// }
// void removecycle(node*&head){
//     node*slow=head;
//     node*fast=head;
//     do{
//         slow=slow->next;
//         fast=fast->next->next;
//     }while(slow!=fast);
//     fast=head;
//     while(slow->next!=fast->next){
//         slow=slow->next;
//         fast=fast->next;
//     }
//     slow->next=NULL;
// }
//Finding length of a linked list
// int length_of_ll(node*&head){
//     int length=0;
//     node*temp=head;
//     while(temp!=NULL){
//         temp=temp->next;
//         length++;
//     }
//     return length;
// }
// //Appending K nodes from the last to the starting of the linked list
// node*kappend(node*&head,int k){
//     node*newhead=NULL;
//     node*newtail=NULL;
//     node*tail=head;
//     int l=length_of_ll(head);
//     int count=1;
//     k=k%l;
//     while(tail->next!=NULL){
//         if(count==l-k){
//             newtail=tail;
//         }
//         if(count==l-k+1){
//             newhead=tail;
//         }
//         tail=tail->next;
//         count++;
//     }
//     newtail->next=NULL;
//     tail->next=head;
//     return newhead;
// }
// //Program to make linked lists intersect at a certain point
// void intersect(node*&head1,node*&head2,int pos){
//     node*temp1=head1;
//     pos--;
//     while(pos--){
//         temp1=temp1->next;
//     }
//     node*temp2=head2;
//     temp2->next=temp1;
// }
// //Finding common intersection of two linked lists, if there is any.
// int intersection(node*&head1,node*&head2){
//     int l1=length_of_ll(head1);
//     int l2=length_of_ll(head2);
//     int d=0;
//     node*ptr1;
//     node*ptr2;
//     if(l1>l2){
//         d=l1-l2;
//         ptr1=head1;
//         ptr2=head2;
//     }
//     else{
//         d=l2-l1;
//         ptr1=head2;
//         ptr2=head1;
//     }
//     while(d>0){
//         ptr1=ptr1->next;
//         if(ptr1==NULL){
//             return -1;
//         }
//         d--;
//     }
//     while(ptr1!=NULL && ptr2!=NULL){
//         if(ptr1==ptr2){
//             return ptr1->data;
//         }
//         ptr1=ptr1->next;
//         ptr2=ptr2->next;
//     }
//     return -1;
// }
//Program to merge two sorted linked lists and sort them out
// node*merge(node*&head1,node*&head2){
//     node*p1=head1;
//     node*p2=head2;
//     node*dummynode=new node(-1);
//     node*p3=dummynode;
//     while(p1!=NULL && p2!=NULL){
//         if(p1->data<p2->data){
//             p3->next=p1;
//             p1=p1->next;
//         }
//         else{
//             p3->next=p2;
//             p2=p2->next;
//         }
//         p3=p3->next;
//     }
//     while(p1!=NULL){
//         p3->next=p1;
//         p1=p1->next;
//         p3=p3->next;
//     }
//     while(p2!=NULL){
//         p3->next=p2;
//         p2=p2->next;
//         p3=p3->next;
//     }
//     return dummynode->next;
// }
// node*mergeRecursive(node*&head1,node*&head2){
//     node*result=NULL;
//     if(head1==NULL){
//         return head2;
//     }
//     if(head2==NULL){
//         return head1;
//     }
//     if(head1->data<head2->data){
//         result=head1;
//         result->next=mergeRecursive(head1->next,head2);
//     }
//     else{
//         result=head2;
//         result->next=mergeRecursive(head1,head2->next);
//     }
//     return result;
// }
//Write a program to put even position nodes in a linked list first and continue with the odd postion ones
// void evenAfterOdd(node*&head){
//     node*odd=head;
//     node*even=head->next;
//     node*evenStart=even;
//     while(odd->next==NULL && even->next==NULL){
//         odd->next=even->next;
//         odd=odd->next;
//         even->next=odd->next;
//         even=even->next;
//     }
//     odd->next=evenStart;
//     if(odd->next==NULL){
//         even->next=NULL;
//     }
// }
// int main(){
//      node*head1=NULL;
//      node*head2=NULL;
//     node Llist(0);
//     node L2list(0);
//     node L3list(0);
//     int arr[]={1,2,3,4,5,6};
//     for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
//         Llist.insertAtTail(head1,arr[i]);
//     }
// //    cout<<length_of_ll(head)<<endl;
//     int a[]={5,6,7,8,9};
//     for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++){
//         L2list.insertAtTail(head2,a[i]);
//     }
//     node*newhead=merge(head1,head2);    
//     cout<<intersection(head1,head2)<<endl;
//     intersect(head1,head2,3);
//     cout<<intersection(head1,head2)<<endl;
//    Llist.deletion(head,3);
//    Llist.search(head,2);
    // Llist.display(head);
    // node*newhead=kappend(head,3);
    // Llist.display(newhead);
//    node*newhead=reverse(head);
//    Llist.display(newhead);
//    int k=2;
//    node*newhead=kreverse(head,k);
//    Llist.display(newhead);
//    makecycle(head,3);
//    detectcycle(head);
//    removecycle(head);
//    detectcycle(head);
//     return 0;
// }

//DOUBLY LINKED LIST:Along with the data and pointer to the next element, it also points to its previous elements,therefore it has two pointers associated with its each element
// class dnode{
//     public:
//     int data;
//     dnode*next;
//     dnode*prev;
//     dnode(int val){
//         data=val;
//         next=NULL;
//         prev=NULL;
//     }
// };
// void insertAtHead(dnode*&head,int val){
//     dnode*n=new dnode(val);
//     n->next=head;
//     if(head!=NULL){
//         head->prev=n;
//     }
//     head=n;
// }
// void insertAtTail(dnode*&head,int val){
//     if(head==NULL){
//         insertAtHead(head,val);
//         return;
//     }
//     dnode*n=new dnode(val);
//     dnode*temp=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=n;
//     n->prev=temp;
// }
// void deleteAtHead(dnode*&head){
//     if(head==NULL){
//         return;
//     }
//     dnode*todelete=head;
//     head=head->next;
//     if(head!=NULL){
//         head->prev=NULL;
//     }
//     delete todelete;
// }
// void deletion(dnode*&head,int pos){
//     dnode*temp=head;
//     int count=1;
//     if(pos==1){
//         deleteAtHead(head);
//         return;
//     }
//     while(temp!=NULL && count!=pos){
//         temp=temp->next;
//         count++;
//     }
//     temp->prev->next=temp->next;
//     if(temp->next!=NULL){
//         temp->next->prev=temp->prev;
//     }
//     delete temp;
// }
// void display(dnode*&head){
//     dnode*temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }cout<<endl;
// }
// int main(){
//     dnode*head=NULL;
//     insertAtHead(head,0);
//     insertAtTail(head,1);
//     insertAtTail(head,2);
//     insertAtTail(head,3);
//     insertAtTail(head,4);
//     display(head);
//     deletion(head,1);
//     display(head);
//     return 0;
// }

//CIRCULAR LINKED LIST: Instead of pointing to NULL, the tail pointer points to the head of the linked list
// class cnode{
//     public:
//     int data;
//     cnode*next;
//     cnode(int val){
//         data=val;
//         next=NULL;
//     }
// };
// void insertAtHead(cnode*&head,int val){
//     cnode*n=new cnode(val);
//     cnode*temp=head;
//     if(head==NULL){
//         n->next=n;
//         head=n;
//         return;
//     }
//     while(temp->next!=head){
//         temp=temp->next;
//     }
//     temp->next=n;
//     n->next=head;
//     head=n;
// } 
// void insertAtTail(cnode*&head,int val){
//     if(head==NULL){
//         insertAtHead(head,val);
//         return;
//     }
//     cnode*n=new cnode(val); 
//     cnode*temp=head;
//     while(temp->next!=head){
//         temp=temp->next;
//     }
//     temp->next=n;
//     n->next=head;
// }
// void deleteAtHead(cnode*&head){
//     if(head==NULL){
//         return;
//     }
//     cnode*temp=head;
//     while(temp->next!=head){
//         temp=temp->next;
//     }
//     cnode* toDelete = head;
//     if (head->next == head) {
//         head = nullptr;
//     } 
//     else {
//         temp->next = head->next;
//         head = head->next;
//     }
//     delete toDelete;
// }
// void deletion(cnode*&head,int pos){
//     if(pos==1){
//         deleteAtHead(head);
//         return;
//     }
//     cnode*temp=head;
//     int count=1;
//     while(count!=pos-1){
//         temp=temp->next;
//         count++;
//     }
//     cnode*todelete=temp->next;
//     temp->next=temp->next->next;
//     delete todelete;
// }
// void display(cnode*&head){
//     cnode*temp=head;
//     do{
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }while(temp!=head);
//     cout<<endl;
// }
// int main(){
//     cnode*head=NULL;
//     int arr[]={1,2,3,4,5};
//     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
//         insertAtTail(head,arr[i]);
//     }
//     display(head);
//     deletion(head,1);
//     display(head);
//     return 0;
// }

//STACKS:Stores a list of items in which an item can be added and removed only from one end
//OPERATIONS: 
//1)push():used to enter an item on the top of the stack
//2)pop():used to remove an item from the top of the stack
//3)top():returns the topmost element
//4)empty():returns true if stack is empty and vice versa
// #define n 100
// class stack{
//     int*arr;
//     int top;
//     public:
//     stack(){
//         arr=new int[n];
//         top=-1;
//     }
//     void push(int x){
//         if(top==n-1){
//             cout<<"Stack Overflow\n";
//             return;
//         }
//         top++;
//         arr[top]=x;
//     }
//     void pop(){
//         if(top==-1){
//             cout<<"No element to pop\n";
//             return;
//         }
//         top--;
//     }
//     int Top(){
//         if(top==-1){
//             cout<<"No element in the stack\n";
//             return -1;
//         }
//         return arr[top];
//     }
//     bool empty(){
//         return  top==-1;
//     }
// };
// int main(){
//     stack st;
//     int arr[]={1,2,3,4,5};
//     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
//         st.push(arr[i]);
//     }
//     cout<<st.Top()<<endl;
//     st.pop();
//     cout<<st.Top()<<endl;
//     return 0;
// }
//Reversing a sentence using stacks
// void reverse_sentence(string s) 
// {
//     stack<string> st;
//     for (int i = 0; i < s.size(); i++) {
//         string word = "";
//         while (i < s.length() && s[i] != ' ') {
//             word += s[i];
//             i++;
//         }
//         st.push(word);
//     }
//     while (!st.empty()) {
//         cout << st.top() << " ";
//         st.pop();
//     }
//     cout << endl;
// }
// int main() {
//     string s = "salut, comment ca va?";
//     reverse_sentence(s);
//     return 0;
// }
//Reverse a stack without creating a new stack
// void insertAtBottom(stack<int>&st,int ele){
//     if(st.empty()){
//         st.push(ele);
//         return;
//     }
//     int ste=st.top();
//     st.pop();
//     insertAtBottom(st,ele);
//     st.push(ste);
// }
// void reverse(stack<int>&st){
//     if(st.empty()){
//         return;
//     }
//     int ele=st.top();
//     st.pop();
//     reverse(st);
//     insertAtBottom(st,ele);
// }
// int main(){
//     stack<int>st;
//     int arr[]={7,6,5,4,3,2,1};
//     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
//         st.push(arr[i]);
//     }
//     reverse(st);
//     while(!st.empty()){
//         cout<<st.top()<<" ";
//         st.pop();
//     }
//     return 0;
// }
//STACKING USING QUEUES
//Approach 1: push operation is costly
// class Stack{
//     public:
//     int N;
//     queue<int>q1;
//     queue<int>q2;
//     Stack(){
//         N=0;
//     }
//     void push(int val){
//         q2.push(val);
//         N++;
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         queue<int>temp=q1;
//         q1=q2;
//         q2=temp;
//     }
//     void pop(){
//         q1.pop();
//         N--;
//     }
//     int top(){
//         return q1.front();
//     }
//     int size(){
//         return N;
//     }
// };
// int main(){
//     Stack st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     cout<<"Stack's size is:";
//     cout<<st.size()<<endl;
//     for(int i=0;i<3;i++){
//         cout<<st.top()<<" ";
//         st.pop();
//     }
//     return 0;
// }
//Approach 2:pop operation is costly
// class Stack{
//     queue<int>q1;
//     queue<int>q2;
//     int N;
//     public:
//     Stack(){
//         N=0;
//     }
//     void push(int val){
//         q1.push(val);
//         N++;
//     }
//     void pop(){
//         if(q1.empty()){
//             return;
//         }
//         while(q1.size()!=1){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         q1.pop();
//         N--;
//         queue<int>temp=q1;
//         q1=q2;
//         q2=temp;
//     }
//     int top(){
//         if(q1.empty()){
//             return -1;
//         }
//         while(q1.size()!=1){
//             q2.push(q1.front());
//             q2.pop();
//         }
//         int ans=q1.front();
//         q2.push(q1.front()); 
//         q1.pop();
//         queue<int>temp=q1;
//         q1=q2;
//         q2=temp;
//         return ans;
//     }
//     int size(){
//         return N;
//     } 
// };
// int main(){
//     Stack st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     cout<<"Size of the stack is:";
//     cout<<st.size()<<endl;
//     for(int i=0;i<4;i++){
//         cout<<st.top()<<" ";
//         st.pop();
//     }
//     return 0;
// }

//INFIX NOTATION:<OPERAND><OPERATOR><OPERAND>,non-computer supported
//PREFIX NOTATION(polish notation):<OPERATOR><OPERAND><OPERAND>,computer supported
//POSTFIX NOTATION(reverse polish notation):<OPERATOR><OPERATOR><OPERAND>,computer supported
//Prefix evaluation is done from right to left
// int prefix_evaluation(string s){
//     stack<int>st;
//     for(int i=s.length()-1;i>=0;i--){
//         if(s[i]>='0' && s[i]<='9'){
//             st.push(s[i]-'0');
//         }
//         else{
//             int op1=st.top();
//             st.pop();
//             int op2=st.top();
//             st.pop();
//             switch (s[i])
//         {
//         case '+':
//            st.push(op1+op2);
//             break;
//         case '-':
//            st.push(op1-op2);
//             break;
//         case '*':
//            st.push(op1*op2);
//             break;
//         case '/':
//            st.push(op1/op2);
//             break;
//         case '^':
//            st.push(pow(op1,op2));
//             break;
//         default:
//             break;
//         }
//         }     
//     }
//     return st.top();
// }
// //Postfix evaluation is done from left to right
// int postfix_evaluation(string s){
//     stack<int>st;
//     for(int i=0;i<s.length();i++){
//         if(s[i]>='0' && s[i]<='9'){
//             st.push(s[i]-'0');
//         }
//         else{
//             int op2=st.top();
//             st.pop();
//             int op1=st.top();
//             st.pop();
//             switch (s[i])
//         {
//         case '+':
//            st.push(op1+op2);
//             break;
//         case '-':
//            st.push(op1-op2);
//             break;
//         case '*':
//            st.push(op1*op2);
//             break;
//         case '/':
//            st.push(op1/op2);
//             break;
//         case '^':
//            st.push(pow(op1,op2));
//             break;
//         default:
//             break;
//         }
//         }
//     }
//     return st.top();
// }
// int prec(char c){
//     if(c=='^'){
//         return 3;
//     }
//     else if(c=='*'||c=='/'){
//         return 2;
//     }
//     else if(c=='+'||c=='-'){
//         return 1;
//     }
//     else{
//         return -1;
//     }
// }    
// string infix_to_postfix(string s){
//     stack<char>st;
//     string res;
//     for(int i=0;i<s.length();i++){
//         if(s[i]>='a' && s[i]<='z'|| s[i]>='A' && s[i]<='Z'){
//             res+=s[i];
//         } 
//         else if(s[i]=='('){
//             st.push(s[i]);
//         }
//         else if(s[i]==')'){
//             while(!st.empty() && st.top()!='('){
//                 res+=st.top();
//                 st.pop();
//             }
//             if(!st.empty()){
//                 st.pop();
//             }
//         }
//         else{
//             while(!st.empty() && prec(st.top())>prec(s[i])){
//                 res+=st.top();
//                 st.pop();
//             }
//             st.push(s[i]);
//         }
//     }
//     while(!st.empty()){
//         res+=st.top();
//         st.pop();
//     }
//     return res;
// }
// string infix_to_prefix(string s){
//     reverse(s.begin(),s.end());
//     stack<char>st;
//     string res;
//     for(int i=0;i<s.length();i++){
//         if(s[i]>='a' && s[i]<='z'|| s[i]>='A' && s[i]<='Z'){
//             res+=s[i];
//         }
//         else if(s[i]==')'){
//             st.push(s[i]);
//         }
//         else if(s[i]=='('){
//             while(!st.empty() && st.top()!=')'){
//                 res+=st.top();
//                 st.pop();
//             }
//             if(!st.empty()){
//                 st.pop();
//             }
//         }
//         else{
//             while(!st.empty() && prec(st.top())>prec(s[i])){
//                 res+=st.top();
//                 st.pop();
//             }
//             st.push(s[i]);
//         }
//     }
//     while(!st.empty()){
//         res+=st.top();
//         st.pop();
//     }
//     reverse(res.begin(),res.end());
//     return res;
// }    
// int main(){
//     cout<<prefix_evaluation("-+7*45+20")<<endl;
//     cout<<postfix_evaluation("46+2/5*7+")<<endl;;
//     cout<<infix_to_postfix("(a-b/c)*(a-k/l)")<<endl;
//     cout<<infix_to_prefix("(a-b/c)*(a-k/l")<<endl;
//     return 0;
// }

//Balanced paranthesis:example of balanced paranthesis:([{}])
//unbalanced paranthesis:{([]})
// bool isvalid(string s){
//     int n=s.length();
//     stack<char>st;
//     bool ans=true;
//     for(int i=0;i<n;i++){
//         if(s[i]=='(' || s[i]=='{' || s[i]=='['){
//             st.push(s[i]);
//         }
//         else if(s[i]==')'){
//             if(!st.empty() && st.top()=='('){
//                 st.pop();
//             }
//             else{
//                 ans=false;
//                 break;
//             }
//         }
//         else if(s[i]=='}'){
//             if(!st.empty() && st.top()=='{'){
//                 st.pop();
//             }
//             else{
//                 ans=false;
//                 break;
//             }
//         }
//         else if(s[i]==']'){
//             if(!st.empty() && st.top()=='['){
//                 st.pop();
//             }
//             else{
//                 ans=false;
//                 break;
//             }
//         }
//     }
//     if(!st.empty()){
//         return false;
//     }
//     return ans;
// }
// int main(){
//     string s="([{}])";
//     if(isvalid(s)){
//         cout<<"Valid string\n";
//     }
//     else{
//         cout<<"Invalid string\n";
//     }
// }

//QUEUES:Stores a list of iTems in which an item can be inserted at one end and removed from the other end only
//Array implementation of queue
// #define n 20
// class queue{
//     int *arr;
//     int front;
//     int back;
//     public:
//     queue(){
//         arr=new int[n];
//         front=-1;
//         back=-1;
//     }
//     void push(int x){
//         if(back==n-1){
//             cout<<"Queue overflow\n";
//         }
//         back++;
//         arr[back]=x;
//         if(front==-1){
//             front++;
//         }
//     }
//     void pop(){
//         if(front==-1||front>back){
//             cout<<"No element present in queue\n";
//             return;
//         }
//         front++;
//     }
//     int peek(){
//         if(front==-1||front>back){
//             cout<<"No element present in queue\n";
//             return -1;
//         }
//         cout<<arr[front]<<endl;
//     }
//     bool empty(){
//         if(front==-1||front>back){
//             cout<<"No element present in queue\n";
//             return true;
//         }
//         return false;
//     }
// };
// int main(){
//     queue q;
//     int arr[]={1,2,3,4};
//     for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
//         q.push(arr[i]);
//     }
//     for(int i=0;i<4;i++){
//         q.peek();
//         q.pop();
//     }
//     q.empty();
//     return 0;
// }
//Linked list implemenetation
//while using array, left space gets wasted,limited memory,that's why linked list is prefered over array for queues
// class node{
//     public:
//     int data;
//     node*next;
//     node(int val){
//         data=val;
//         next=NULL;
//     }
// };
// class queue{
//     node*front;
//     node*back;
//     public:
//     queue(){
//         front=NULL;
//         back=NULL;
//     }
//     void push(int x){
//         node*n=new node(x);
//         if(front==NULL){
//             back=n;
//             front=n;
//             return;
//         }
//         back->next=n;
//         back=n;
//     }
//     void pop(){
//         if(front==NULL){
//             cout<<"Queue underflow\n";
//             return;
//         }
//         node*todelete=front;
//         front=front->next;
//         delete todelete;
//     }
//     int peek(){
//         if(front==NULL){
//             cout<<"No elements in queue\n";
//             return -1;
//         }
//         return front->data;
//     }
//     bool empty(){
//         if(front==NULL){
//             return true;
//         }
//         return false;
//     }
// };
// int main(){
//     queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     for(int i=0;i<4;i++){
//         cout<<q.peek()<<" ";
//         q.pop();
//     }
//     cout<<q.empty();
// }
//Queue implemetation using stack
//Approach 1:using 2 stacks in which dequeue is costly
// class queue{
//     stack<int>s1;
//     stack<int>s2;
//     public:
//     void push(int x){
//         s1.push(x);
//     }
//     int pop(){
//         if(s1.empty() && s2.empty()){
//             cout<<"Queue is empty\n";
//             return -1;
//         }
//         if(s2.empty()){
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         if (s2.empty()) {
//         cout << "Queue is still empty after pop operation\n";
//         return -1;
//         }
//         int topval=s2.top();
//         s2.pop();
//         return topval;
//         }
//     }
//     bool empty(){
//         if(s1.empty() && s2.empty()){
//             return true;
//         }
//         return false;
//     }
// };
// int main(){
//     queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     while (!q.empty()) {
//         int val = q.pop();
//         if (val != -1) {
//             cout << val << " ";
//         }
//     }
//     cout<<q.empty();
// }
//Approach-2:Using function call stack
// class Queue{
//     stack<int>s1;
//     public:
//     void push(int x){
//         s1.push(x);
//     }
//     int pop(){
//         if(s1.empty()){
//             cout<<"Queue is empty\n";
//             return -1;
//         }
//         int x=s1.top();
//         s1.pop();
//         if(s1.empty()){
//             return x;
//         }
//         int item=pop();
//         s1.push(x);
//         return item;
//     }
//     bool empty(){
//         if(s1.empty()){
//             return true;
//         }
//         return false;
//     }
// };
// int main(){
//     Queue q;
//     int arr[]={1,2,3,4,5};
//     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
//         q.push(arr[i]);
//     }
//     while(!q.empty()){
//         cout<<q.pop()<<" ";
//     }cout<<endl;
//     cout<<q.empty();
// }

//DEQUE:It is a structure in which elements can be added and deleted from the front as well as well as back.
// int main(){
// 	deque<int>dq;
// 	dq.push_back(1);
// 	dq.push_back(2);
// 	dq.push_front(3);
// 	dq.push_front(4);
// 	cout<<dq.size();
// 	dq.pop_back();
// 	dq.pop_front();
// 	for(auto i:dq){
// 		cout<<i<<" ";
// 	}cout<<endl;
// 	cout<<dq.size();
// 	return 0;
// }
//The sliding window is a data structure technique that transforms two nested loops into a single loop within an array or list.
// int main(){
// 	int n,k;cin>>n>>k;
// 	vector<int>a(n);
// 	for(auto &i:a){
// 		cin>>i;
// 	}
	//without using deque
	// multiset<int,greater<int>>s;
	// vector<int>ans;
	// for(int i=0;i<k;k++){
	// 	s.insert(a[i]);
	// }
	// ans.push_back(*s.begin());
	// for(int i=k;i<n;i++){
	// 	s.erase(s.lower_bound(a[i-x]));
	// 	s.insert(a[i]);
	// 	ans.push_back(*s.begin());
	// }
	// for(auto i:ans){
	// 	cout<<i<<" ";
	// }
	//with using deque
// 	deque<int>q;
// 	vector<int>ans;
// 	for(int i=0;i<k;i++)(
// 		while(!q.empty() and a[q.back()]<a[i]){
// 			q.pop_back();
// 		}
// 		q.push_back(i);
// 	)
// 	ans.push_back(a[q.front()]);
// 	for(int i=k;i<n;i++){
// 		if(q.front()==i-k){
// 			q.pop_front();
// 		}
// 		while(!q.empty() and a[q.back()]<a[i]){
// 			q.pop_back();
// 		}
// 		q.push_back(i);
// 		ans.push_back(a[q.front()]);
// 	}
// 	for(auto i:ans){
// 		cout<<i<<" ";
// 	}
// }

//given an array.Each elements represent the height to the histogram's bar and the width of the bar is 1, find the area of largest in the histogram
// int get_max_area(vector<int>a){
//     int n=a.size(),ans=0,i=0;
//     stack<int>st;
//     a.push_back(0);
//     while(i<n){
//         while(!st.empty() and a[st.top()]>a[i]){
//             int t=st.top();
//             int h=a[t];
//             st.pop();
//             if(st.empty()){
//                 ans=max(ans,h*i);
//             }
//             else{
//                 int len=i-st.top()-1;
//                 ans=max(ans,h*len);
//             }
//         }
//         st.push(i);
//         i++;
//     }
//     return ans;
// }
// int main(){
//     vector<int>a={2,1,5,6,2,3};
//     cout<<get_max_area(a);
//     return 0;
// }

//Trapping rainwater harvesting:Given non negative integers represting an elevation map where the width of each bar is 1,compute how much water it can trap after raining
// int rainwater(vector<int>a){
//     stack<int>st;
//     int n=a.size();int ans=0;
//     for(int i=0;i<n;i++){
//         while(!st.empty() and a[st.top()]<a[i]){
//             int cur=st.top();
//             st.pop();
//         if(st.empty()){
//             break;
//         }
//         int diff=i-st.top()-1;
//         ans+=(min(a[st.top()],a[i])-a[cur])*diff;
//         }
//         st.push(i);
//     }
//     return ans;    
// }
// int main(){
//     vector<int>a={0,1,0,2,1,0,1,3,2,1,2,1};
//     cout<<rainwater(a);
//     return 0;
// }

//Redunant paranthesis problem: Given a valid mathematical expression, find whether it has redundant paranthesis or not.
// int main(){
//     string s;
//     cin>>s;
//     bool ans=false;
//     stack<char> st;
//     for(int i=0;i<s.size();i++){
//         if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
//             st.push(s[i]);
//         }
//         else if(s[i]=='('){
//             st.push(s[i]);
//         }
//         else if(s[i]==')'){
//             if(st.top()=='('){
//                 ans=true;
//             }
//             while(st.top()=='+' or st.top()=='-' or st.top()=='*' or st.top()=='/'){
//                 st.pop();
//             }
//             st.pop();
//         }
//     }
//     cout<<ans;
//     return 0;
// }

//Stock span problem:the span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than or equal to today's price. Find the span of the stock for all the days
//Create a stack<pair<int,int>> representing {price,days}
// vector<int>stockspan(vector<int>prices){
//     vector<int>ans;
//     stack<pair<int,int>>s;
//     for(auto price:prices){
//         int days=1;
//         while(!s.empty() and s.top().first<=price){
//             days+=s.top().second;
//             s.pop();
//         }
//         s.push({price,days});
//         ans.push_back(days);
//     }
//     return ans;
// }
// int main(){
//     vector<int>a={100,80,60,70,60,75,85};
//     vector<int>res=stockspan(a);
//     for(auto i: res){
//         cout<<i<<" ";
//     }
// }

//3Sum problem: Given an array and a value, find if there exists three numbers whose sum is equal to the given value
// int main(){
//     int n;cout<<"Enter number of terms:";cin>>n;
//     int target;cout<<"Enter required target:";cin>>target;
//     vector<int>a(n);
//     for(auto &i:a){
//         cin>>i;
//     }
//     bool found=false;
//     sort(a.begin(),a.end());
//     for(int i=0;i<n;i++){
//         int lo=i+1;int hi=n-1;
//         while(lo<hi){
//             int curr=a[i]+a[lo]+a[hi];
//             if(curr == target){
//                 found =true;
//                 break;
//             }
//             else if(curr<target){
//                 lo++;
//             }
//             else{
//                 hi--;
//             }
//         }
//     }
//     if(found){
//         cout<<"True\n";
//     }
//     else{
//         cout<<"False\n";
//     }
//     return 0;
// } 

//Max consecutive ones problem: Given an array A of 1s and 0s, we can change upto K terms from 0 to 1. Return the length of the longest contigent subarray that contains only 1s.
// int main(){
//     int n;cin>>n;
//     int k;cin>>k;
//     vector<int>a(n);
//     for(auto &i:a){
//         cin>>i;
//     }
//     int zerocnt=0,i=0,ans=0;
//     for(int j=0;j<n;j++){
//         if(a[j]==0){
//             zerocnt++;
//         }
//         while(zerocnt>k){
//             if(a[i]==0){
//                 zerocnt--;
//             }
//             i++;
//         }
//         ans=max(ans,j-i+1);
//     }
//     cout<<ans;
// }

//Longest substring without repeating character
// int main(){
//     string s;cin>>s;
//     vector<int>dict(256,-1);
//     int maxlen=0,start=-1;
//     for(int i=0;i<s.size();i++){
//         if(dict[s[i]]>start){
//             start=dict[s[i]];
//         }
//         dict[s[i]]=i;
//         maxlen=max(maxlen,i-start);
//     }
//     cout<<maxlen;
// }