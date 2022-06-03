// if u are given a infinite lenght array 
// i.e you are not given length of array
// i.e you can't use length function in this search
// how will you find element in o(logn) ?
// solution - reverse engineering the answer
// binary search works on divide and conquer approach
/*
e.g arr = [1,2,3,4,5] key = 4
iteration 1 arr=[3,4,5] 
iteration 2 arr=[4,5]
iteration 3 arr[4]
if you observe size is reduced by half

lets reverse engineer this solutio 
1st task is to find start and end
arr = [ 1,2,3,4,5,6,7,8,9,10 ..........11011]
target = 9 ;

we don't know end but we have start i.e arr[0]
initialy n = 2;
so start = arr [0]
and end = arr[n] ;

now we check if start < target and end > target 
1 < 9 && 3 > 9 -> false

now start = end + 1;
and end = n^n i.e 2^2=4
start = 4 
end = 4 
5 < 9 && 5 > 9 -> false


now start = end + 1 = 5;
and end =n^n i.e 4^4 = 16
start = 5;
end = 16

now start < target and end > target !! condition is true
// apply basic binary search !!;
*/


#include<iostream>
#include<vector>
using namespace std;
void BinarySearch(vector<int> arr , int target , int start , int end ){

while(start <= end ){
    int mid = start + (end - start ) / 2 ;
    if(target > arr[mid]){
        start = mid + 1;
    }else if ( target < arr[mid]){
        end = mid - 1;
    }else if(target == arr[mid]){
        cout<<"element found at index - "<<mid<<endl;
        break;
    }
}
if(start > end ){
    cout<<"no element found ";
}
}

int main(){
    // we can't take infinite array but we will not use len function to
    // calculate the length
    vector<int> arr =  {4 , 13 , 15 , 16 , 23 , 30};
     int target = 23;
    // lets first find start and end index ;
//    initially box size is 2 i.e start = 0 & end = 1 i.e 2 elements

   int start = 0 ;
   int end = 1 ;
   
    while(end < target ){

        if(arr[start] < target && arr[end] > target){
         BinarySearch(arr,target,start,end);
         break;
        }
        int  newstart = end + 1;
        // previous end + size of box * 2 
        end = end + ( end - start + 1 ) * 2;
        start = newstart;
        cout<<start<<"-"<<end<<endl;
    }
 
}