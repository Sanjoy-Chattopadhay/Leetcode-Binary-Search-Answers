#include<bits/stdc++.h>
using namespace std;

int firstOccurenace(vector<int> arr,int start, int end, int target){
	int index = -1;
	int n = arr.size();
	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] == target) {
			index = mid;
			end = mid-1;
		}
		if(arr[mid] < target){
			start = mid+1;
		}
		else end = mid - 1;
	}
	return index;
}

int binarySearch(vector<int> arr, int start, int end, int target){
	int res = -1;
	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] == target) return mid;
		else if(arr[mid] > target) end = mid-1;
		else start = mid + 1;
		
	}
	return res;
}

int searchInInfiniteSortedArray(vector<int> arr, int target){
	int start = 0 ;
	int end = 1;
	while(target > arr[end]){
		start = end;
		end = end * 2;
	}
	
	return firstOccurenace(arr, start, end, target);
	}

int main(){
	vector<int> nums = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int target = 1;
	cout << searchInInfiniteSortedArray(nums, target);
	return 0;
}
