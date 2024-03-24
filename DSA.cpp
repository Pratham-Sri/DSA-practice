#include <iostream>
using namespace std;
#include <math.h>
#include <climits>
#include <string>
#include<algorithm>
#include<vector>
// BINARY SEARCH PROGRAM
// int BinarySearch(int arr[],int n,int key){
//     int s=0;
//     int e=n;
//     int mid=s+e/2;
//     while(s<=e){
//         if(arr[mid]==key){
//             return mid;
//         }
//         else if(arr[mid]<key){
//             e=mid-1;
//         }
//         else{
//             s=mid+1;
//         }
//     } 
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int key;
//     cin>>key;
//     cout<<BinarySearch(arr,n,key)<<endl;
//     return 0;
// }

//SELECTION SORT
// int main(){
//         int n;
//         cout<<"Enter the size of array";
//         cin>>n;
//         int arr[n];
//         cout<<"Enter the elements of the array";     
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 if(arr[j]<arr[i]){
//                     int temp=arr[j];
//                     arr[j]=arr[i];
//                     arr[i]=temp;
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             cout<<arr[i]<<"";
//         }cout<<endl;
//         return 0;
// }

//BUBBLE SORT
// int main(){
//     int n;
//     cout<<"Enter size of the array:";
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the elements of the array:";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int counter=1;
//     while(counter<n){
//         for(int i=0;i<n-counter;i++){
//                 if(arr[i]>arr[i+1]){
//                     int temp=arr[i];
//                     arr[i]=arr[i+1];
//                     arr[i+1]=temp;   
//                 }
//         }
//     }
//     counter++;
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<"";
//     }cout<<endl;
//     return 0;
// }    

//INSERTION SORT
// int main(){
//     int n;
//     cout<<"Enter the size of array:";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Enter the elements of the list:";
//         cin>>arr[i];
//     }
//     for(int i=0;i<n;i++){
//         int current=arr[i];
//         int j=i-1;
//         while(arr[j]>current && j>=0){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=current;
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<endl;
//     }cout<<endl;
//     return 0;
// }

//Write a code to find the maximum digit till the ith iteration!!
// int main(){
//     int n;
//     cout<<"Enter the size of the array:";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Enter th elements of the array:";
//         cin>>arr[i];
//     }
//     int mx=-20000000;
//     for(int i=0;i<n;i++){
//         mx=max(mx,arr[i]);
//         cout<<"Max till"<<i<<"is"<<mx<<endl;
//     }
//     return 0;
// }

//SUBARRAYS: Continous part of the array, can be derived without taking any breaks in between the elements
//NO OF SUBBARRAYS:nC2+n=n(n+1)/2

//SUBSEQUENCES:A subsequence is a sequence that can be derived from an array, by selecting zero or more elements without changing the order of the remaining elements
//NO OF SUBSEQUENECES:2^n

//Every subarray is a sequence but every sequence is not a subarray

//Write a program to find the sum of all the subarrays made from an original array
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int curr=0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i;j<n;j++){
//             curr+=arr[j];
//             cout<<curr<<endl;
//         }
//     }
//     return 0;
// }

//Program to print all possible subarrays
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[n];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             for( int k=i;k<=j;k++){
//                 cout<<arr[k]<<"";
//             }cout<<endl;
//         }
//     }
//     return 0;
// }

//Write a program to find the subarray with maximum sum from all the possible subarrays

//1)Using BRUTE FORCE APPROACH
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int Maxsum=INT_MIN;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int k=i;k<=j;k++){
//                 sum+=arr[k];
//             }
//             Maxsum=max(Maxsum,sum);
//         }
//     }
//     cout<<Maxsum<<endl;
//     return 0;
// }

//2)Using CUMULATIVE SUM APPROACH (decreases time complexity from n^3 to n^2)
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i;i<n;i++){
//         cin>>arr[i];
//     }
//     int currsum[n+1];
//     currsum[0]=0;
//     for(int i=1;i<=n;i++){
//         currsum[i]=currsum[i-1]+arr[i-1];
//     }
//     int maxsum=INT_MIN;
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=0;j<=i;j++){
//             sum=currsum[i]-currsum[j];
//             maxsum=max(maxsum,sum);
//         }
//     }
//     cout<<maxsum<<endl;
//     return 0;
// }

//3)Using KADANE'S ALGORITHM(decreases the time complexity from n^2 to n)
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int maxsum=INT_MIN;
//     int currsum=0;
//     for(int i=0;i<n;i++){
//         currsum+=arr[i];
//         if(currsum<0){
//             currsum=0;
//         }
//         maxsum=max(maxsum,currsum);
//     } 
//     cout<<maxsum<<endl; 
//     return 0;
// }

//Write a program to find the maximum subarray sum where you consider subarray to be circular
// int kadane(int arr[],int n){
//     int currsum=0;
//     int maxsum=INT_MIN;
//     for(int i=0;i<n;i++){
//         currsum+=arr[i];
//         if(currsum<0){
//             currsum=0;
//         }
//         maxsum=max(maxsum,currsum);
//     }
//     return maxsum;
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int wrapsum,nonwrapsum;
//     nonwrapsum=kadane(arr,n);
//     int totalsum=0;
//     for(int i=0;i<n;i++){
//         totalsum+=i;
//         arr[i]=-arr[i];
//     }
//     wrapsum=totalsum+kadane(arr,n);
//     cout<<max(wrapsum,nonwrapsum)<<endl;
//     return 0;
// }

//Write a program to find the pair of numbers from a subarray which is equal to give input k;

//Method 1(Time complexity(n^2))
// bool pairsum(int arr[],int n,int k){
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]+arr[j]==k){
//                 cout<<i<<" "<<j<<endl;
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int k;
//     cout<<"Enter the desired number";
//     cin>>k;
//     cout<<pairsum(arr,n,k)<<endl;
//     return 0;
// }

//Method 2(time complexity(n))
// bool pairsum(int arr[],int n,int k){
//     int low=0;
//     int high=n-1;
//     for(int i=0;i<n;i++){
//         if(arr[high]+arr[low]==k){
//             return true;
//         }
//         else if(arr[high]+arr[low]>k){
//             high--;
//         }
//         else if(arr[high]+arr[low]<k){
//             low++;
//         }
//         return false;
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int k;
//     cout<<"Enter the desired number";
//     cin>>k;
//     cout<<pairsum(arr,n,k)<<endl;
//     return 0;
// 

//2-D ARRAYS

//Taking input and producing output
// int main(){
//     int n,m,arr[n][m];
//     cin>>n>>m;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j;j<m;j++){
//             cout<<arr[i][j];
//         }cout<<endl;
//     }
//     return 0;
// } 

//Searching for an element in a matrix
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int k;
//     cout<<"Enter the number you want to search:";
//     cin>>k;
//     bool flag=false;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==k){
//                 flag=true;
//             }
//         }
//     }
//     if(flag=true){
//         cout<<"Element found"<<endl;
//     }
//     else{
//         cout<<"Element not found!!";
//     }
//     return 0;
// }

//Spiral order matrix traversal
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int row_start=0,row_end=n-1,column_start=0,column_end=m-1;
//    while(row_start<=row_end && column_start<=column_end){
//         for(int col=column_start;col<=column_end;col++){
//             cout<<arr[row_start][col]<<" ";
//         }cout<<endl;
//         row_start++;
//         for(int row=row_start;row<=row_end;row++){
//             cout<<arr[row][column_end]<<" ";
//         }cout<<endl;
//         column_end--;
//         for(int col=column_end;col>=column_start;col--){
//             cout<<arr[row_end][col]<<" ";
//         }cout<<endl;
//         row_end++;
//         for(int row=row_end;row>=row_start;row--){
//             cout<<arr[row][column_start]<<" ";
//         }cout<<endl;
//         column_start++;
//     return 0;
//     }
// }    

//Matrix transpose
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=i;j<m;j++){
//             int temp=arr[i][j];
//             arr[i][j]=arr[j][i];
//             arr[j][i]=temp;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<' ';
//         }cout<<endl;
//     }
//     return 0;
// }

//Matrix multiplication
// int main(){
//     int n1,n2,n3;
//     cin>>n1>>n2>>n3;
//     //Order of matrix being multiplied is n1xn2 and n2xn3
//     int arr2[n2][n3],arr[n1][n2];
//     for(int i=0;i<n1;i++){
//         for(int j=0;j<n2;j++){
//             cin>>arr1[i][j];
//         }
//     }
//     for(int i=0;i<n2;i++){
//         for(int j=0;j<n3;j++){
//             cin>>arr2[i][j];
//         }
//     }
//     int ans[n1][n3];
//     for(int i=0;i<n1;i++){
//         for(int j=0;j<n3;j++){
//             ans[i][j]=0;
//         }
//     }
//     for(int i=0;i<n1;i++){
//         for(int j=0;j<n3;j++){
//             for(int k=0;k<n2;k++){
//                 ans[i][j]+=arr1[i][k]*arr2[k][j];
//             }
//         }
//     }
//     for(int i=0;i<n1;i++){
//         for(int j=0;j<n3;j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

//Matrix search when elements are sorted(asking for optimised solution)
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int target;
//     cout<<"Enter the required element:";
//     cin>>target;
//     int r=0,c=m-1;
//     bool flag=false;
//     while(r<n && c>=0){
//         if(arr[r][c]==target){
//             flag=true;
//         }
//         if(arr[r][c]>target){
//         c--;
//         }
//         else{
//             r++;
//         }
//     }
//     if(flag==true){
//         cout<<"Element found!!!";
//     }
//     else{
//         cout<<"Element not found!!";
//     }
//     return 0;
// }

//Character arrays:array made up of characters, declared with size[n+1] as 1 indicates the end of a word.

//Taking input and output
// int main(){
//     int n;
//     cin>>n;
//     char arr[n+1];
//     cin>>arr;
//     cout<<arr<<endl;
//     cout<<arr[3]<<endl;
//     for(int i=0;i<7;i++){
//         cout<<arr[i];
//     }cout<<endl;
//     return 0;
// }

//Program to check for palindrome
// int main(){
//     int n;
//     cin>>n;
//     char arr[n+1];
//     cin>>arr;
//     bool check=true;
//     for(int i=0;i<n;i++){
//         if(arr[i]!=arr[n-1-i])
//         check=false;
//         break;
//     }
//     if(check==true){
//         cout<<"palindrome!!"<<endl;
//     }
//     else{
//         cout<<"Not a palindrome!!"<<endl;
//     }
//     return 0;
// }

//Write a program to find the largest word in a sentence
// int main(){
//     int n;
//     cin>>n;
//     cin.ignore();
//     char arr[n+1];
//     cin.getline(arr,n);
//     cin.ignore();
//     int i=0;
//     int currlength=0,maxlength=0;
//     int st=0,maxst=0;
//     while(1){
//         if(arr[i]=' ' || arr[i]=='\0'){
//             if(currlength > maxlength){
//                 maxlength=currlength;
//                 maxst=st;
//             }
//             currlength=0;
//             st=i+1;
//         }
//         else
//         currlength++;
//         if(arr[i]=='\0'){
//             break;
//         }
//         i++;
//     }
//     cout<<maxlength<<endl;
//     for(int i=0;i<maxst;i++){
//         cout<<arr[i+maxst];
//     }
//     return 0;
// }

//POINTERS:These are variables which store the address of other variables

//Making a pointer
// int main(){
//     int a=10;
//     int*aptr;
//     aptr=&a;
//     cout<<&a<<endl;//output:0x28ff28
//     cout<<aptr<<endl;//output:0x28ff28
//     cout<<*aptr<<endl;//output:10
//     return 0;
// }

// Arrays can also be used for pointers as follows:
// int main(){
//     int arr[]={10,20,30,40};
//     cout<<*arr<<endl;
//     int *ptr=arr;//the pointer made is default at zero position of array
//     for(int i=0;i<4;i++){
//         cout<<*ptr<<" ";
//         ptr++;
//     }cout<<endl;
    //for using arr as a pointer, we cant use arr++ to increment as it is wrong.
    //to increment using arr, use arr+i
//     for(int i=0;i<4;i++){
//         cout<<*(arr+i)<<" ";
//     }
//     return 0;
// }

//Pointer to pointer
// int main(){
//     int a=20;
//     int*p=&a;
//     int**q=&p;
//         //here q acts as a pointer to ptr while ptr is a pointer to a as well.
//     return 0;
// }

//STACK AND HEAP:
//Stack memory is used to store local variables, function arguments, and return addresses. It is a limited resource, and the amount of memory that can be used on the stack is determined by the compiler. Stack memory is usually faster than heap memory because it is located on the CPU's registers.
//Heap memory is used to store dynamically allocated memory. This memory is not limited in size, and can be used to store any type of data. Heap memory is slower than stack memory because it is not located on the CPU's registers.

//STRINGS

//INPUT AND OUTPUT;
//int main(){
    // string str;
    // cin>>str;
    // cout<<str;
    //ways of declaration
    // string str1(5,'n');
    // cout<<str1<<endl;
    // string str2="Tis' is the second way to do it!!";
    // cout<<str2<<endl;
    //for input of string with spaces, use getline function to do it
    //only using cin will result in only the first syllable before space to get recognised.
//     string str3;
//     getline(cin,str3);
//     cout<<str3<<endl;
//     return 0;
// }

//STRING FUNCTIONS
//Concatenation
// int main(){
//     string str1;
//     string  str2;
//     getline(cin,str1);
//     getline(cin,str2);
//First method:
//     str1.append(" "+str2);
//Second method:
//     cout<<str1+" "+str2<<endl;
//     return 0;
// }
//Strings can also be iterated as an array
//to clear a string use the function clear
//syntax: str.clear();
//To compare strings compare function is used
//To check if a string is empty or not empty function is used
//To clear or empty a string clear function is used
//To delete characters from a string use erase function(Syntax:a.erase(starting index,no of characters to be removed))
//To find a substring from a given string use find function(Syntax:a.find("substr"),on printing returns the starting index of the found substring)
//To insert a substring inside a string use insert function(Syntax:a.insert("substr",index at which the substr is too be inserted))
//To find the size of the str,use length or size function(useful for iterating the string)
//To create a substring out of a given string,use substr function(Syntax:a.substr(starting index,no of characters))
//To convert a numeric string to integer use stoi function(Syntax:int x=stoi(a))
//To convert an integer to string use to_string function(Syntax:to_string(x))
//To sort a string use sort function under algorithm file(syntax:Sort(a.start,a.end))
// int main(){
//     string a,b;
//     cin>>a>>b;
//     if (!a.compare(b)){
//         cout<<"Strings are equal"<<endl;
//     }
//     if(a.empty()){
//         cout<<"string is empty"<<endl;
//     }
//     else{
//         cout<<"string is not empty"<<endl;
//     }
//     return 0;
// }

//Write a program to convert entire string to uppercase or lowercase

//Basic approach
// int main(){
//     string str;
//     cin>>str;
//     //to convert we use the diff between ascii values as the source::32
//     //Converting to uppercase
//     for(int i=0;i<str.size();i++){
//         if(str[i]>='a'&& str[i]<='z'){
//             str[i]-=32;
//         }
//     }
//     cout<<str<<endl;
//     //Converting to lowercase
//     for(int i=0;i<str.size();i++){
//         if(str[i]>='A' && str[i]<='Z'){
//             str[i]+=32;
//         }
//     }
//     cout<<str<<endl;
//     return 0;
// }

//Using transform function(Syntax:transform(starting index,last index,from which index function shoul be appied::function))
// int main(){
//     string str;
//     cin>>str;
//     //Converting to uppercase
//     transform(str.begin(),str.end(),str.begin(),::toupper);
//     cout<<str<<endl;
//     //Converting to lowercase
//     transform(str.begin(),str.end(),str.begin(),::tolower);
//     cout<<str<<endl;
//     return 0;
// }

//Given a numeric string,print the largest number possible
// int main(){
//     string num;
//     cout<<"Enter a numeric string:";
//     cin>>num;
//     sort(num.begin(),num.end(),greater<int>());//Here greater function allows sorting to be reversed
//     cout<<num<<endl;
//     return 0;
// }

//Given a string find the character with highest occurence
// int main(){
//     string s;
//     cin>>s;
//     int freq[26];
//     for(int i=0;i<26;i++){
//         freq[i]=0;
//     }
//     for(int i=0;i<s.size();i++){
//         freq[s[i]-'a']++;
//     }
//     char ans='a';
//     int maxf=0;
//     for(int i=0;i<26;i++){
//         if(freq[i]>maxf){
//             maxf=freq[i];
//             ans=i+'a';
//         }
//     }
//     cout<<maxf<<" "<<ans<<endl;
//     return 0;
// }

//BITWISE OPERATOR
//AND:&(multiplies the bits(0 and 1))
//OR:|(Adds the bits)
//NEGATION:~(Changes 0 to 1 and vice versa)
//XOR:^(gives 0 if both the operators are same and 1 if they are different)

//Getbit function:gives the bit at the specified function
// int Getbit(int n,int pos){
//     return((n & (1<<pos))!=0);
// }
// int main(){
//     cout<<Getbit(5,2)<<endl;
//     return 0;
// }

//Setbit function:Sets the bit at a specified position(Setting means turning 0 to 1 or if 1 is already there make no changes)
// int Setbit(int n,int pos){
//     return(n|(1<<pos));
// }
// int main(){
//     cout<<Setbit(5,1)<<endl;
//     return 0;
// }

//Clearbit function:clears the bit at the specified position
// int Clearbit(int n,int pos){
//     return(n & (~(1<<pos)));
// }
// int main(){
//     cout<<Clearbit(5,2)<<endl;
//     return 0;
// }

//Updatebit function:updates the bit to 0 or 1 at desired position
// int Setbit(int n,int pos,int value){
//     int mask=~(1<<pos);
//     n = n & mask;
//     return n|value<<pos;
// }
// int main(){
//     cout<<Setbit(5,1,1)<<endl;
// }

//Write a program to check if a number is power of 2 using bit manipulation
// bool ispowerof2(int n){
//     return (n && !(n & n-1));
// }
// int main(){
//     cout<<ispowerof2(16)<<endl;
//     cout<<ispowerof2(14)<<endl;
//     return 0;
// }

//Write a program to count the number of ones in a binary representation of the number
//n and n-1 has the same number of bits except the rightmost bit
//photo for explaination=C:\Users\user\Pictures
// int numberof1s(int n){
//     int count = 0;
//     while(n){
//         n=n & (n-1);
//         count++;
//     }
//     return count;
// }
// int main(){
//     cout<<numberof1s(19)<<endl;
//     cout<<numberof1s(18)<<endl;
//     return 0;
// }

//Write a program to find all subsets of the set {a,b,c}
//Explanation:file name:c2
// void subsets(int arr[],int n){
//     for(int i=0;i<(1<<n);i++){
//         for(int j=0;j<n;j++){
//             if(i & (1<<j)){
//                 cout<<arr[j]<<' ';
//             }
//         }cout<<endl;
//     }
// }
// int main(){
//     int arr[4]={1,2,3,4};
//     subsets(arr,4);
//     return 0;
// }

//Write a program to find the unique number in an array where all numbers except one are present twice
//This program uses the property of xor function that it only provides 1 when both inputs are different
// int unique(int arr[],int n){
//     int xorsum=0;
//     for(int i=0;i<n;i++){
//         xorsum=xorsum^arr[i];
//     }
//     return xorsum;
// }
// int main(){
//     int arr[]={1,2,3,4,1,2,3};
//     cout<<unique(arr,7)<<endl;
//     return 0;
// }

//Write a program to find two unique numbers in an array where all numbers except 2 are present twice
// int Setbit(int n,int pos){
//     return ((n & (1<<pos))!=0);
// }
// void unique(int arr[],int n){
//     int xorsum=0;
//     for(int i=0;i<n;i++){
//         xorsum=xorsum^arr[i];
//     }
//     int tempsum=xorsum;
//     int pos,setbit=0;
//     while(setbit!=1){
//         setbit= 1 & xorsum;
//         pos++;
//         xorsum=xorsum>>1;
//     }
//     int newxor=0;
//     for(int i=0;i<n;i++){
//         if(Setbit(arr[i],pos-1)){
//             newxor=newxor^arr[i];
//         }
//     }
//     cout<<newxor<<endl;
//     cout<<(tempsum^newxor)<<endl;
// }
// int main(){
//     int arr[]={1,2,3,1,2,3,5,7};
//     unique(arr,8);
// }

//Write a program to find a unique number from an array where all numbers except one are present thrice
// bool getbit(int n,int pos){
//     return ((n & (1<<pos))!=0);
// }
// int setbit(int n,int pos){
//     return (n |(1<<pos));
// }
// int result=0;
// int unique(int arr[],int n){
//     for(int i=0;i<64;i++){
//         int sum=0;
//         for(int j=0;j<n;j++){
//             if(getbit(arr[j],i)){
//                 sum++;
//             }
//         }
//         if(sum%3!=0){
//             result=setbit(result,i);
//         }
//     }
//     return result;
// }
// int main(){
//     int arr[]={1,2,3,1,2,3,1,2,3,4};
//     cout<<unique(arr,10)<<endl;
//     return 0;
// }

//SEIVE OF ERATOSTHENES:The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so

//Program to find prime numbers till the given number using seive algorithm
// void primeseive(int n){
//     int prime[100]={0};
//     for(int i=2;i<n;i++){
//         if(prime[i]==0){
//             for(int j=i*i;j<=n;j+=i){
//                 prime[j]=1;
//             }
//         }
//     }
//     for(int i=2;i<=n;i++){
//         if(prime[i]==0){
//             cout<<i<<' ';
//         } 
//     }cout<<endl;
// }
// int main(){
//     int n;
//     cin>>n;
//     primeseive(n);
//     return 0;
// }

//Program to find prime factors of a given number using seive algorithm
// void primefactor(int n){
//     int spf[100]={0};
//     for(int i=2;i<=n;i++){
//         spf[i]=i;
//     }
//     for(int i=2;i<=n;i++){
//         if(spf[i]==i){
//             for(int j=i*i;j<=n;j+=i){
//                 if(spf[j]==j){
//                     spf[j]=i;
//                 }
//             }
//         }
//     }
//     while(n!=1){
//         cout<<spf[n]<<" ";
//         n=n/spf[n];
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     primefactor(n);
//     return 0;
// }

//Write a program to find the numbers between 1 and 1000 divisible by 5 or 7
// int divisible(int n,int a,int b){
//     int c1=n/a;
//     int c2=n/b;
//     int c3=n/(a*b);
//     return(c1+c2-c3);
// }
// int main(){
//     int n,a,b;
//     cin>>n>>a>>b;
//     cout<<divisible(n,a,b)<<endl;
//     return 0;
// }

//Write a program to find gcd using euclidian algorithm
// int gcd(int a,int b){
//     while(b!=0){
//         int rem=a%b;
//         a=b;
//         b=rem;
//     }
//     return a;
// }
// int main(){
//     int a,b;
//     cin>>a>>b;
//     cout<<gcd(a,b)<<endl;
//     return 0;
//}

//RECURSION:Recursion performs a number of repetitive calls to the function from within the function. The recursive condition performs the repeating calls to the function until the base case is met. The base case is present inside the function, and once the condition of the base case is satisfied, it stops the execution.

//Write a program using recursion to find n**p
// int pow(int n,int p){
//     if(p==0){
//         return 1;
//     }
//     int prevmultiple=pow(n,p-1);
//     return(n*prevmultiple);
// }
// int main(){
//     int n,p;
//     cin>>n>>p;
//     cout<<pow(n,p)<<endl;
//     return 0;
// }

//Write a program to  find nth fibonacci number using recursion
// int fib(int n){
//     if(n==0){
//         return 0;
//     }
//     if(n==1){
//         return 1;
//     }
//     return(fib(n-1)+fib(n-2));
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<fib(n)<<endl;
//     return 0;
// }

//Using recursion,check if an array is sorted or not
// bool sorted(int arr[],int n){
//     if(n==1){
//         return true;
//     }
//     int restArray=sorted(arr+1,n-1);
//     return(arr[0]<arr[1] && restArray);
// }
// int main(){
//     int  arr[]={1,2,3,4,5};
//     int Arr[]={1,3,2,4,5};
//     cout<<sorted(arr,5)<<endl;
//     cout<<sorted(Arr,5)<<endl;
//     return 0;
// }

//Using recursion,print numbers till n in 1)increasing order 2)decreasing order
//In this ques, we have used the concept of stacking order and order of calling the function and printing the number
// void dec(int n){
//     if(n==0){
//         return;
//     }
//     cout<<n<<" ";
//     dec(n-1);
// }
// void inc(int n){
//     if(n==0){
//         return;
//     }
//     inc(n-1);
//     cout<<n<<" ";    
// }
// int main(){
//     int n;
//     cin>>n;
//     dec(n);
//     inc(n);
//     return 0;
// }

//Using recursion,in a array find the first and last occurence of a number
// int firstoccurence(int arr[],int n,int i,int key){
//     if(i==n){
//         return -1;
//     }
//     if(arr[i]==key){
//         return i;
//     }
//     firstoccurence(arr,n,i+1,key);
// }
// int lastoccurence(int arr[],int n,int i,int key){
//     if(i==n){
//         return -1;
//     }
//     int restArray=lastoccurence(arr,n,i+1,key);
//     if(restArray!=-1){
//         return restArray;
//     }
//     if(arr[i]==key){
//         return i;
//     }
//     return -1;
// }
// int main(){
//     int arr[]={1,2,3,2,4,5,2,6,7,2};
//     cout<<firstoccurence(arr,7,0,2)<<endl;
//     cout<<lastoccurence(arr,7,0,2)<<endl;
//     return 0;
// }

//Reverse a string using recursion 
// void reverse(string s){
//     if(s.length()==0){
//         return;
//     }
//     string ros=s.substr(1);
//     reverse(ros);
//     cout<<s[0];
// }
// int main(){
//     string s="discrepancy";
//     reverse(s);
//     return 0;
// }

//Using recursion, write a program to replace pi with 3.14 in string
// void replacepi(string s){
//     if(s.length()==0){
//         return;
//     }
//     if(s[0]=='p' && s[1]=='i'){
//         cout<<"3.14";
//         replacepi(s.substr(2));
//     }
//     else{
//         cout<<s[0];
//         replacepi(s.substr(1));
//     }
// }
// int main(){
//     string s;
//     cin>>s;
//     replacepi(s);
//     return 0;
// }

//Tower of Hanoi problem:Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. Initially, all the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of the puzzle is to move the entire stack to another rod (here considered C), obeying the following simple rules: 1)Only one disk can be moved at a time. 2)Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack. 3)No disk may be placed on top of a smaller disk.
// void towerofhanoi(int n,char src,char dest,char helper){
//     if(n==0){
//         return;
//     }
//     towerofhanoi(n-1,src,helper,dest);
//     cout<<"Moved from"<<src<<"to"<<dest<<endl;
//     towerofhanoi(n-1,helper,dest,src);
// }
// int main(){
//     towerofhanoi(4,'A','B','C');
//     return 0;
// }

//Using recursion, write a progarm to remove all the dupicate strings from a given string
// string duplicate(string s){
//     if(s.length()==0){
//         return " ";
//     }
//     char ch=s[0];
//     string ans=duplicate(s.substr(1));
//     if(ch==ans[0]){
//         return ans;
//     }
//     return (ch+ans);
// }
// int main(){
//     string s;
//     cin>>s;
//     cout<<duplicate(s);
//     return 0;
// }

//Write a program using recursion to move all x's in a string to the last
// string moveallx(string s){
//     if(s.length()==0){
//         return "";
//     }
//     char ch=s[0];
//     string ans=moveallx(s.substr(1));
//     if(ch=='x'){
//         return (ans+ch);
//     }
//     return ch+ans;
// }
// int main(){
//     string s;
//     cin>>s;
//     cout<<moveallx(s);
//     return 0;
// }

//Using recursion, print all substrings of a given string
// void substrings(string s,string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return;
//     }
//     char ch=s[0];
//     string ros=s.substr(1);
//     substrings(ros,ans);
//     substrings(ros,ans+ch);
// }
// int main(){
//     string s;
//     string ans="";
//     cin>>s;
//     substrings(s,ans);
//     return 0;
// }

//Keypad problem:write all the words that can be made from phone digits in a keypad phone
// string keypadarr[]={",","","abc","def","ghi","jkl","omn","pqrs","tuv","xyz"};
// void keypad(string s,string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return;
//     }
//     char ch=s[0];
//     string code=keypadarr[ch-'0'];
//     string ros=s.substr(1);
//     for(int i=0;i<code.length();i++){
//         keypad(ros,ans+code[i]);
//     }
// }
// int main(){
//     keypad("23","");
//     return 0;
// }

//Print all possible permutations of a string using recursion
// void permutation(string s,string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return;
//     }
//     for(int i=0;i<s.length();i++){
//         char ch =s[i];
//         string ros=s.substr(0,i)+s.substr(i+1);
//         permutation(ros,ans+ch);
//     }
// }
// int main(){
//     permutation("abc","");
//     return 0;
// }

//In a linear gameboard,find all possible ways to move from on block to another using a dice
// int countpath(int s,int e){
//     if(s==e){
//         return 1;
//     }
//     if(s>e){
//         return 0;
//     }
//     int count=0;
//     for(int i=0;i<=6;i++){
//         count+=countpath(s+i,e);
//     }
//     return count;
// }
// int main(){
//     int s,e;
//     cin>>s>>e;
//     cout<<countpath(s,e);
//     return 0;
// }

//In a maze a piece is allowed to move only in downward or forward direction,find the number of ways in which a piece can move from one block to the downright corner block 
// int countmaze(int n,int i,int j){
//     if(i==n-1 && j==n-1){
//         return 1;
//     }
//     if(i>n || j>n){
//         return 0;
//     }
//     return (countmaze(n,i+1,j)+countmaze(n,i,j+1));
// }
// int main(){
//     cout<<countmaze(5,0,0);
//     return 0; 
// }

//Given a "2 X n" board and tiles of size "2 X 1",count the number of ways to tile the given board
// int tilingways(int n){
//     if(n==0){
//         return 0;
//     }
//     if(n==1){
//         return 1;
//     }
//     return(tilingways(n-1)+tilingways(n-2));
// } 
// int main(){
//     int n;
//     cin>>n;
//     cout<<tilingways(n);
//     return 0;
// }

//BACKTRACKING:Backtracking can be defined as a general algorithmic technique that considers searching every possible combination in order to solve a computational problem.

//Rat maze problem:in this problem , a maze is given in the form of a 2D array, we have to answer the correct path for the rat to get out of the maze in the form of a 2D array itself
// bool isafe(int** arr,int x,int y,int n){
//     if(x<n && y<n && arr[x][y]==1){
//         return true;
//     }
//     return false;
// }
// bool rat_in_maze(int** arr,int x,int y,int n,int** solArr){
//     if(x==n-1 && y==n-1){
//         solArr[x][y]=1;
//         return true;
//     }
//     if(isafe(arr,x,y,n)){
//         solArr[x][y]==1;
//         if(rat_in_maze(arr,x+1,y,n,solArr)){
//             return true;
//         }
//         if(rat_in_maze(arr,x,y+1,n,solArr)){
//             return true;
//         }
//         solArr[x][y]==0; //Backtrack
//         return false;
//     }
//     return false;
// }
// int main(){
//     int n;
//     cin>>n;
//     int** arr=new int*[n];
//     for(int i=0;i<n;i++){
//         arr[i]=new int[n];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int** solArr=new int*[n];
//     for(int i=0;i<n;i++){
//         solArr[i]=new int[n];
//         for(int j=0;j<n;j++){
//             solArr[i][j]=0;
//         }
//     }
//     if(rat_in_maze(arr,0,0,n,solArr)){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//             cout<<solArr[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }
// }
// // 1 0 1 0 1
// // 1 1 1 1 1
// // 0 1 0 1 0
// // 1 0 0 1 1
// // 1 1 1 0 1

//MERGE SORT:Merge sort is defined as a sorting algorithm that works by dividing an array into smaller subarrays, sorting each subarray, and then merging the sorted subarrays back together to form the final sorted array.
//Time complexity:nlogn
// void merge(int arr[],int l,int mid,int r){
//     int n1=mid-l+1;
//     int n2=r-mid;
//     int a[n1];
//     int b[n2];
//     for(int i=0;i<n1;i++){
//         a[i]=arr[l+i];
//     }
//     for(int i=0;i<n2;i++){
//         b[i]=arr[mid+1+i];
//     }
//     int i=0;
//     int j=0;
//     int k=l;
//     while(i<n1 && j<n2){
//         if(a[i]<b[j]){
//             arr[k]=a[i];
//             k++;
//             i++;
//         }
//         else{
//             arr[k]=b[j];
//             k++;
//             j++;
//         }
//     }
//     while(i<n1){
//         arr[k]=a[i];
//         i++;
//         k++;
//     }
//     while(j<n2){
//         arr[k]=b[j];
//         j++;
//         k++;
//     }
// }
// void mergesort(int arr[],int l,int r){
//     if(l<r){
//         int mid=(l+r)/2;
//         mergesort(arr,l,mid);
//         mergesort(arr,mid+1,r);
//         merge(arr,l,mid,r);
//     }
// }
// int main(){
//    int arr[]={2,4,7,6,5,8,1};
//    mergesort(arr,0,8);
//    for(int i=0;i<7;i++){
//     cout<<arr[i]<<" ";
//    }
//    return 0;
// }

//QUICK SORT:The key process in quickSort is a partition(). The target of partitions is to place the pivot (any element can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the left of the pivot, and all greater elements to the right of the pivot.
//Time complexity:1)Best case:nlogn 2)Worst case:n^2
// void swap(int arr[],int i,int j){
//     int temp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;
// }
// int partition(int arr[],int l,int r){
//     int pivot=arr[r];
//     int i=l-1;
//     for(int j=l;j<r;j++){
//         if(arr[j]<pivot){
//             i++;
//             swap(arr,i,j);
//         }
//     }
//     swap(arr,i+1,r);
//     return i+1;
// }
// void quicksort(int arr[],int l,int r){
//     if(l<r){
//        int pi = partition(arr,l,r);
//        quicksort(arr,l,pi-1);
//        quicksort(arr,pi+1,r);
//     }
// }
// int main(){
//     int arr[]={2,4,5,6,7,3};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     quicksort(arr, 0, n - 1);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<' ';
//     }
//     return 0;
// }

//VECTORS:Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators
// int main(){
//     vector<int>v;
//     v.push_back(1);//command to enter elements in a vector
//     v.push_back(2);
//     v.push_back(3);
//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     }
//     vector<int>::iterator it;//making an iterator
//     for(it=v.begin();it!=v.end();it++){
//         cout<<*it<<" ";
//     }
//     for(auto element:v){
//         cout<<element<<" ";
//     }
//     v.pop_back();//command to remove element from the back
//     //1 2
//     vector<int> v2(3,50);
//     // 50 50 50
//     swap(v,v2);//swaps the values of v and v2
//     sort(v.begin(),v.end());//command to sort the function
//     return 0;
// }

//PAIRS:Pair is used to combine together two values that may be of different data types. Pair provides a way to store two heterogeneous objects as a single unit.
// bool mycompare(pair<int,int>p1,pair<int,int>p2){
//     return p1.first<p2.first;
// }
// int main(){
//     int arr[]={10,16,7,14,5,3,2,9};
//     vector<pair<int,int>> v;
//     for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
//         v.push_back(make_pair(arr[i],i));
//     }
//     sort(v.begin(),v.end(),mycompare);
//     for(int i=0;i<v.size();i++){
//         arr[v[i].second]=i;
//     }
//     for(int i=0;i<v.size();i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//COUNT SORT:The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions
//Time Complexity:max(A[i],N)
// void countsort(int arr[],int n){
//     int k=arr[0];
//     for(int i=0;i<n;i++){
//         k=max(k,arr[i]);
//     }
//     int count[10]={0};
//     for(int i=0;i<n;i++){
//         count[arr[i]]++;
//     }
//     for(int i=0;i<=k;i++){
//         count[i]+=count[i-1];    
//     }
//     int output[n];
//     for(int i=n-1;i>=0;--i){
//         output[--count[arr[i]]]=arr[i];
//     }
//     for(int i=0;i<n;i++){
//         count[i]=output[i];
//     }
// }
// int main(){
//     int arr[]={1,3,2,3,4,1,6,4,3};
//     countsort(arr,9);
//     for(int i=0;i<9;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//DNF(Dutch National Flag) Sort:Given an array A[] consisting of only 0s, 1s, and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.This problem is also the same as the famous “Dutch National Flag problem”.
//Time complexity:n
// void swap(int arr[],int a,int b){
//     int temp=arr[a];
//     arr[a]=arr[b];
//     arr[b]=temp;
// }
// int dnfsort(int arr[],int n){
//     int low=0;
//     int mid=0;
//     int high=n-1;
//     while(mid<=high){
//         if(arr[mid]==0){
//             swap(arr,low,mid);
//             low++; mid++;
//         }
//         else if(arr[mid]==1){
//             mid++;
//         }
//         else if(arr[mid]==2){
//             swap(arr,mid,high);
//             high--;
//         }
//     }
// }
// int main(){
//     int arr[]={1,0,2,1,0,1,2,1,2};
//     dnfsort(arr,9);
//     for(int i=0;i<9;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;    
// }

//WAVE SORT:Given an unsorted array of integers, sort the array into a wave array. An array arr[0..n-1] is sorted in wave form if:arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
//Time complexity:n
// void swap(int arr[],int i,int j){
//     int temp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;
// }
// void wavesort(int arr[],int n){
//     for(int i=1;i<n;i+=2){
//         if(arr[i]>arr[i-1]){
//             swap(arr,i,i-1);
//         }
//         if(arr[i]>arr[i+1] && i<=n-2){
//             swap(arr,i,i+1);
//         }
//     }
// }
// int main(){
//     int arr[]={1,3,4,7,5,6,2};
//     wavesort(arr,7);
//     for(int i=0;i<7;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }    

//Write a code to find the number of inversions in a given array
//An inversion is when a[i]>a[j] and i<j, for example, photo name:count inversion

//Brute force approach:Time Complexity:n^2
// int inversion(int arr[],int n){
//     int inv=0;
//     for(int  i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 inv++;
//             }
//         }
//     }
//     return inv;
// }
// int main(){
//     int a[]={3,5,6,9,1,2,7,8};
//     cout<<inversion(a,8)<<endl;
//     return 0;
// }

//Merge Sort Technique
// long long merge(int arr[],int l,int mid,int r){
//     long long inv;
//     int n1=mid-l+1;
//     int n2=r-mid;
//     int a[n1];
//     int b[n2];
//     for(int i=0;i<n1;i++){
//         a[i]=arr[l+i];
//     }
//     for(int i=0;i<n2;i++){
//        b[i]=arr[mid+i+1];
//     }
//     int i=0;int j=0;int k=l;
//     while(i<n1 && j<n2){
//         if(a[i]<b[j]){
//             arr[k]=a[i];
//             k++;i++;
//         }
//         else{
//             arr[k]=b[j];
//             inv+=n1-i;
//             k++;j++;
//         }
//     }
//     while(i<n1){
//         arr[k]=a[i];
//         i++;k++;
//     }
//     while(j<n2){
//         arr[k]=b[j];
//         k++;j++;
//     }
//     return inv;
// }
// long long mergesort(int arr[],int l,int r){
//     long long inv=0;
//     if(l<r){
//         int mid=(l+r)/2;
//         inv+=mergesort(arr,l,mid);
//         inv+=mergesort(arr,mid+1,r);
//         inv+=merge(arr,l,mid,r);
//     }
//     return inv;
// }
// int main(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<mergesort(arr,0,n-1);
//     return 0;
// }

//OOPS:Object-oriented programming – As the name suggests uses objects in programming. Object-oriented programming aims to implement real-world entities like inheritance, hiding, polymorphism, etc. in programming. The main aim of OOP is to bind together the data and the functions that operate on them so that no other part of the code can access this data except that function

//BASIC STUDY
// class student{
//     public:
//     string name;
//     int age;
//     bool gender;
//    student(){
//     cout<<"Default Constructor"<<endl;
//    }
//     student(string n,int a,bool g){
//         cout<<"Parameterised Constructor"<<endl;
//         name=n;
//         age=a;
//         gender=g;
//     }// paramaterised constructor
//     student(student &a){
//         cout<<"Copy Constructor"<<endl;
//         name=a.name;
//         age=a.age;
//         gender=a.gender;
//     }//Copy Constructor
//     ~student(){
//         cout<<"Destrcutor Called"<<endl;
//     }//on exiting the command, indicates the destruction of the objects created.
//     void PrintInfo(){
//         for(int i=0;i<3;i++){
//             cout<<"Name:";
//             cout<<name<<endl;
//             cout<<"Age:";
//             cout<<age<<endl;
//             cout<<"Gender:";
//             cout<<gender<<endl;
//         }
//     }
//     bool operator ==(student &a){
//         if(name==a.name && age==a.age && gender==a.gender){
//             return true;
//         }return false;
//     }//operator overloading
// };
// int main(){
//     // student a; 
//     // a.name='kim';
//     // a.age=30;
//     // a.gender=1;
//     // //Taking input inside an array
//     // student arr[3];
//     // for(int i=0;i<3;i++){
//     //     cout<<"Name:"<<endl;
//     //     cin>>arr[i].name;
//     //     cout<<"Age:"<<endl;
//     //     cin>>arr[i].age;
//     //     cout<<"Gender:"<<endl;
//     //     cin>>arr[i].gender;
//     // }
//     // int flag=0;
//     // cout<<"If you want to print the data enter any natural number:";
//     // cin>>flag;
//     // if(flag!=0){
//     //     for(int i=0;i<3;i++){
//     //         arr[i].PrintInfo();
//     //     }
//     // }
//     student a("pratham",18,0);
//     student b;
//     student c=a;
//     return 0;
//     if(c==a){
//         cout<<"Same"<<endl;
//     }
//     else{
//         cout<<"Not Same"<<endl;
//     }
// }

//INHERITANCE:inheritance is a feature or a process in which, new classes are created from the existing classes. The new class created is called “derived class” or “child class” and the existing class is known as the “base class” or “parent class”. The derived class now is said to be inherited from the base class
//Single inheritance
// class A{
//     public:
//     void func(){
//         cout<<"Inherited"<<endl;
//     }
// };
// class B:public A{};
// int main(){
//     B b;
//     b.func();
// }
//Multiple Inheritance
// class A{
//     public:
//     void funcA(){
//         cout<<"FuncA\n";
//     }
// };
// class B{
//     public:
//     void funcB(){
//         cout<<"FuncB\n";
//     }
// };
// class C:public A,public B{
//     public:
// };
// int main(){
//     C c;
//     c.funcA();
//     c.funcB();
// }
//Multilevel inheritance
// class A{
//     public:
//     void Afunc(){
//         cout<<"Afunc\n";
//     }
// };
// class B:public A{
//     public:
//     void Bfunc(){
//         cout<<"Bfunc\n";
//     }
// };
// class C:public B{
//     public:
// };
// int main(){
//     C c;
//     c.Afunc();
//     c.Bfunc();
// }
//Hybrid inheritance: it is a mix of multilevel and multiple inheritance
//Heirarchical inheritance:when multiple inheritance is used to make a binary tree form of a structure,this form of inheritance is used
//Private attributes can only be inherited directly and can not be accessed through multilevel inheritance

//POLYMORPHISM:The word “polymorphism” means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.
//Function overloading:
// class A{
//     public:
//     void afunc(){
//         cout<<"This is a function with no arguments given\n";
//     }
//     void afunc(int x){
//         cout<<"This is a function with integer argument given\n";
//     }
//     void afunc(bool x){
//         cout<<"This is a function with boolean argument given\n";
//     }
// };
// int main(){
//     A a;
//     a.afunc();
//     a.afunc(7);
//     a.afunc(true);
//     return 0;
// }
//Operator overloading
// class complex{
//     private:
//     int real;
//     int imag;
//     public:
//     complex(int r,int i){
//         real=r;
//         imag=i;
//     }
//     complex operator + (complex const &obj){
//         complex res(0,0);
//         res.imag=imag+obj.imag;
//         res.real=real+obj.real;
//         return res;
//     } 
//     void display(){
//         cout<<real<<"+"<<"i"<<imag<<endl;
//     }
// };
// int main(){
//     complex c1(12,7),c2(6,7);
//     complex c3=c1+c2;
//     c3.display();
//     return 0;
// }
//Runtime polymorphism
// class base{
//     public:
//     virtual void print(){
//         cout<<"This is base's class print function"<<endl;
//     }
//     void display(){
//         cout<<"This is base's class display function"<<endl;
//     }
// };
// class derived:public base{
//     public:
//     void print(){
//         cout<<"This is derived's class print function"<<endl;
//     }
//     void display(){
//         cout<<"This is derived's class display function"<<endl;
//     }
// };
// int main(){
//     base *baseptr;
//     derived d;
//     baseptr=&d;
//     baseptr->print();
//     baseptr->display();
//     return 0;
// }

