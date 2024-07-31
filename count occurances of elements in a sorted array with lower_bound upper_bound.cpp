#include<bits/stdc++.h>
using namespace std;

int findLowerBound(vector<int> nums, int target){
	int start = 0;
	int n = nums.size();
	int end = n - 1;
	int ans = -1;
	while(start <= end){
		int mid = (start + end)/2;
		if(nums[mid] == target){
			ans = mid;
			end = mid-1;
		}
		else if(nums[mid] > target){
			end = mid-1;
		}
		else start = mid+1;
		
	}
			return ans;

		
}

int findUpperBound(vector<int> nums, int target){
    
    int start = 0;
	int n = nums.size();
	int end = n - 1;
	int ans = -1;
	while(start <= end){
		int mid = (start + end)/2;
		if(nums[mid] == target){
			ans = mid;
			start = mid+1;
		}
		else if(nums[mid] > target){
			end = mid-1;
		}
		else start = mid+1;
		
	}
			return ans;

}

int countFrequency(vector<int> nums, int target){
	int lowerBound = findLowerBound(nums, target);
	int upperBound = findUpperBound(nums, target);
	return upperBound - lowerBound + 1;
}

int main(){

	vector<int> nums = {0,0,1,1,1,2,2,2,3,3,4,4,4,4,5};
	cout<<countFrequency(nums, 5);
	return 0;
}
