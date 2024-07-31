#include<bits/stdc++.h>
using namespace std;

int findMinimumDifferenceElement(vector<int> arr, int target)
{
	//1 3 6 7 9
	//key = 8
	int start = 0 ; 
	int n = arr.size();
	int end = n - 1;
	while(start <= end){
		int mid = start + (end - start)/2;
		int absEle = abs(arr[mid]);
		if(absEle == target) return arr[mid];
		else if(target < absEle) end = mid-1;
		else start = mid+1;
	}
	int a = abs(arr[end] - target);
	int b = abs(arr[start] - target);
	if(a<b) return arr[end];
	else return arr[start];
}


int main(){
	vector<int> nums = {-12,0,1,3,7,12,23,89};
	int target = 9;
	cout << findMinimumDifferenceElement(nums, target);
	return 0;
}
