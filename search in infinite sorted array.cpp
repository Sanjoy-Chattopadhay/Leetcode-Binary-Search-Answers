#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int start, int end, int target){
	while(start<=end){
		int mid = start + (end-start)/2;
		if(arr[mid] == target) return mid;
		else if(arr[mid]<target) start = mid+1;
		else end = mid-1;
	}
	return -1;
}

int searchInInfiniteSortedArray(vector<int> arr, int target){
	int start = 0;
	int end = 1;
	while(target > arr[end]){
		start = end;
		end *= 2;
	}
	int ans = binarySearch(arr, start, end, target);
	return ans;
}

int main(){
	
	vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int target = 2;
	cout<<searchInInfiniteSortedArray(arr,target);
	return 0;
}
