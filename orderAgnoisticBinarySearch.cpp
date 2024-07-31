#include<bits/stdc++.h>
using namespace std;

int orderAgnoisticBinarySearch(vector<int> arr, int start, int end, int target){
	
	bool isAsc = arr[start] < arr[end];
	//considering ascending sort
	while(start <= end){
		
		int mid = start + (end - start)/2;
		if(arr[mid] == target) return mid;

		if(isAsc){
		if(arr[mid] > target) end = mid-1;
		else start = mid+1;
		}
		else{

		if(arr[mid] > target) start = mid+1;
		else end = mid - 1;
	}
}
	return -1;
}

int main(){
	
	vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
	vector<int> arr2 = {9,8,7,6,5,4,3,2,1};
	int target = 99;
	
	cout << orderAgnoisticBinarySearch(arr1, 0, 8, target)<<endl;
	cout << orderAgnoisticBinarySearch(arr2, 0, 8, target);
	return 0;
}
