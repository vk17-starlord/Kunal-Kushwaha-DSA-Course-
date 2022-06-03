/*
problem - Find First and Last Position of Element in Sorted Array

detail - Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

*/
#include<iostream>
#include<vector>

using namespace std;
int SearchIndex(vector<int>arr , int target , bool isFirstocc){
    // probable answer if element is not present 
    int ans = -1;
    int start = 0 ;
    int end  = arr.size() - 1;

    // perform normal binary search
    while(start <= end){
       int mid = start + (end - start ) / 2;
       if(target < arr[mid]){
           end=mid - 1;
       }
       if(target > arr[mid]){
           start = mid + 1;
       }
       if(target == arr[mid]){
           ans = mid;
           if(isFirstocc){
               end = mid - 1;
           }else{
               start = mid + 1;
           }
       }
    }
    return ans;
}



vector<int> SearchRange(vector<int>arr , int target){
    // finds first occurece
    int start = SearchIndex(arr , target , true);
    // finds last occurence 
    int end = SearchIndex(arr , target , false);

    vector<int> ans ;
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}

int main(){
    
    vector<int> arr = { 5,7,7,8,8,10 };
    int target = 8 ;

    vector<int> ans = SearchRange(arr , target );
    // simulation of output
    cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;



    return 0;
}