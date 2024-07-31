#include<bits/stdc++.h>
using namespace std;

bool calculateSumAfterDivision(vector<int> arr, double divisor, int threshold){
	
	int n = arr.size();
	int eachRes = 0;
	int total = 0;
	for(int i = 0 ; i < n ; i++){
		eachRes = ceil(arr[i] / divisor);
		total += eachRes;
	}
	if(total <= threshold) return true;
	else return false;
	
}

int isThreashold(vector<int> arr, int threshold){
	
	int ans = -1;
	int maxi = 0 ; 
	int mini = 0;
	int n = arr.size();
	
	for(int i = 0 ; i < n ; i++){
		maxi = max(arr[i], maxi);
		mini = min(arr[i], mini);
	}
	
	int start = mini;
	int end = maxi;
	
	while(start <= end){
		int mid = start + (end - start) /2;
		
		if(calculateSumAfterDivision(arr, mid, threshold)) {
			ans = mid;
			end = mid - 1;
		}
		else start = mid+1;
	}
	return ans;
	
}

int main(){
	
	vector<int> arr = {1, 2, 5, 9};
	//	div = 4			1 1  2  3 = 7  // 7 > threshold
	// div = 5			1 1  1  2 = 5 // ans
	
	int threshold = 6 ;
	
	cout<< isThreashold(arr, threshold);
}
