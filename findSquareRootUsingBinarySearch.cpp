#include<bits/stdc++.h>
using namespace std;

float findSquareRootUsingBinarySearch(int target){
	
	if(target == 0) return 0;
	if (target < 0) return -1;
	int ans = -1;
	int start = 1;
	int end = target;
	while(start <= end){
		int mid = start + (end- start) /2;
		
		if(mid * mid == target) return mid;
	
		else if(mid * mid < target) {
			ans = mid;
			start = mid+1;
		}
		else end = mid-1;
	}
	return ans;
}

int main(){
	
	int target = 9;
	cout<<findSquareRootUsingBinarySearch(1);
	return 0;
}
