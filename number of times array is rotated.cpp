#include<bits/stdc++.h>
using namespace std;

int countRotation(vector<int> arr){
	
	int n = arr.size();
	int start = 0;
	int end  = n - 1;
	
	int prev, next, mid;
	
	while(start <= end){
		mid =  (end + start)/2;
		
		prev = (mid + n -1 ) % n;
		next = (mid + 1) % n;
		if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) return mid;
		if(arr[start] <= arr[mid])	start = mid+1;
		else if(arr[mid] <= arr[end]) end = mid-1;
		
	}
	return mid;
	int index = (mid+n)%n;
	//
}

int main(){
	
	vector<int> arr = {4,5,6,7,0,1,2};
					//0  1 2 3 4 5 6
	cout<<countRotation(arr);
	
	return 0;
}
