#include<bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int start, int end, int target){
	
	int n = arr.size();
	
	
	while(start <= end){
		int mid = start + (end - start)/2;
		if(target == arr[mid]) return mid;
		if(((mid-1) >= start) && (arr[mid-1] == target)) return mid-1;
		if(((mid+1) <= end) && (arr[mid+1] == target)) return mid+1;
		
		else if(target > arr[mid]) start = mid+2;
		else end = mid-1;

	}
	return -1;
} 

int main(){
	
	vector<int> arr = {5,10,30,20,40};
	int target;
	cout<<"Enter target : "<<endl;
	cin>>target;
	cout<<search(arr,0,5,target);
	
	return 0;
}
