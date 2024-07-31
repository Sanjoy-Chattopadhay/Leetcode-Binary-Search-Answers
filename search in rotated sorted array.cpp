#include<bits/stdc++.h>
using namespace std;

    int binarySearch(vector<int> arr, int low, int high, int target){
        int n = arr.size();

        while(low<=high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) return mid;
            else if(target <= arr[mid]) high = mid-1;
            else low = mid+1;
        }
        return -1;

    }
    int main() {
    	vector<int> arr = {1,3};
		 int target = 0;
        int low=0, high=arr.size()-1;
    int mid;
    int prev, next, index;
    int n=arr.size();
    if(arr[0]<arr[n-1])
        return arr[0];

    while(low <= high){
        
        mid=low+(high-low)/2;

        prev=(mid-1+n)%n;
        next=(mid+1)%n;


        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next])
            index = mid;
        
        if(arr[0]<=arr[mid])
            low=mid+1;
        
        else if(arr[mid]<=arr[n-1])
                high=mid-1;
    }
        int ans=-1;
        ans = max(binarySearch(arr,0,index-1,target), binarySearch(arr,index,arr.size()-1,target));
        cout<< ans;

    }
    
   

