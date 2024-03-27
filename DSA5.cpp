#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include <math.h>
#include <climits>
#include <string>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>

// Sets:Sets are a type of associative container in which each element has to be unique because the value of the element identifies it. The values are stored in a specific sorted order i.e. either ascending or descending
//Ordered sets: 1)contains unique elements
//2)Implemented using balanced BSTs
//3)Elements are in sorted order
//4)Random access is not possible,i.e. you cannot get i'th iteration element in O(1)/O(logn)
//5)Present in #include<set> header file

//Insertion code
set<int> insertion(){
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    return s;
}
//Print code
void print(set<int>&s){
    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }cout<<endl;
    //reverse print
    for(auto i=s.rbegin();i!=s.rend();i++){
        cout<<*i<<" ";
    }cout<<endl;
    cout<<s.size();
}
//custom comparator
void cust_comp(){
    set<int,greater<int>>s;
    s.insert(2);
    s.insert(4);
    s.insert(1);
    //expected entries: 2 4 1
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }cout<<endl;
    //order printed : 4 2 1
}

//Upper bound, Lower bound
void up_low(){
    set<int>s;
    s.insert(3);
    s.insert(5);
    s.insert(7);
    cout<<*s.lower_bound(2)<<" ";//3
    cout<<*s.upper_bound(2)<<" ";//3
    cout<<*s.lower_bound(10)<<" ";//3
    cout<<*s.upper_bound(5)<<" ";//7
}
//erase == delete the element
void Erase(set<int>&s){
    s.erase(s.begin());
    s.erase(3);
}

//Multisets : 1)Can contain duplicates as well
//2) Implemented using balanced BSTs
//3) Elements are in a sorted order
//4) Random access is not possible, i.e you cannot get i'th element in O(1)/O(logn)
//5) Present in #include<set> header file
void mul_operations(){
    multiset<int> m;
    m.insert(1);
    m.insert(1);
    m.insert(3);

    for(auto i:m){
        cout<<i<<" ";
    }
    //all operations of sets are applicable on multisets with one variatio in erased such that on deleting a specific element by its value it deletes all its instances
} 

//Unordered set:1)contains unique elements
//2)Implemented using hashing
//3)Elements are not in  sorted order
//4)Random access is not possible, i.e you cannot get i'th element in O(1)
//5) Present in #include<unordered_set> header file
// all operations are same as ordered sets, just it is unordered.
// its advantage is that it has better time complexity in its usage than ordered sets(O(1) rather than O(logn))
int main(){
    set<int>s=insertion();
    mul_operations();
    return 0;
}