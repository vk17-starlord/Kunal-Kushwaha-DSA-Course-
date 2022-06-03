// if you are given a sorted array and a target element for e.g
// arr = [2,3,5,9,14,16,18] and target = 15 
// you have to return ceil and floor value of target
// ceil is a value >= target 
// floot is a value <= target 
// we will use binary search for this question ? why ?
/* 

1 WE WANT TO FIND THE NUMBER
2 IT IS A SORTED ARRAY
3 WE ALWAYS GET 2 VALUES HIGH AND LOW WHICH IS GREATER THAN OR LESS THAN ANSWER
*/

#include<iostream>
using namespace std;
void ceil(int len , int arr[] , int target){
int low = arr[0];
int high = arr[len-1];
while(low<=high){
int mid = (low+high)/2;
if(arr[mid]==target){
    cout<<"Ceil Value Is - "<<arr[mid]<<endl;
    break;
}if(arr[mid]<target){
    // go to the right side;
    low = mid+1;
}else{
    high = mid-1;
}
}

if(low>high){
    cout<<"ceil value is "<<arr[low]<<endl;
}
}
int floor(int len , int arr[] , int target){
int low = arr[0];
int high = arr[len-1];
while(low<=high){
int mid = (low+high)/2;
if(arr[mid]==target){
    cout<<"floor Value Is - "<<arr[mid]<<endl;
    break;
}if(arr[mid]<target){
    // go to the right side;
    low = mid+1;
}else{
    high = mid-1;
}
}

if(low>high){
    cout<<"floor value is "<<arr[high]<<endl;
}
}

int main(){
    int arr[7]={2,3,5,9,14,16,18};
    int target = 15;
    ceil(7,arr,target);
    floor(7,arr,target);

    return 0;
}