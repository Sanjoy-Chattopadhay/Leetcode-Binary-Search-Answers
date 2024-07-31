#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> arr){
	int maxi = INT_MIN;
	for(int i = 0 ; i < arr.size() ; i++){
		maxi = max(maxi, arr[i]);
	}
	return maxi;
}

int calculateTotalTime(vector<int> arr, int k){
	
	int totalTime = 0;
	int n = arr.size();
	for(int i = 0 ; i < n ; i++){
		totalTime += ceil((double)arr[i] / (double)k);
	}
	return totalTime;
	
}



int binarySearchEatingBananas(vector<int> arr, int h){
	
	int n = arr.size();
	
	int start = 1;
	int end = findMax(arr);
	
	int ans = -1;
	
	while(start <= end){
		int midK = start + (end- start)/2;
		
		if(calculateTotalTime(arr, midK) <= h) {
			ans = midK;
			end = midK - 1;
			
		}
		else if(calculateTotalTime(arr, midK) > h){
			start = midK + 1;
		}
	}
	return ans;
	
}

int bruteForceEatingBananas(vector<int> arr, int h){
	
	int n = arr.size();
	int totalTime = 0;
	float k = 1;
	while(k<arr[n-1]){
	for(int i = 0 ; i < arr.size() ; i++){
		totalTime += ceil(arr[i] / k);
	
	}
		if(totalTime > h){
			k++;
			totalTime = 0;
		}
		else break;
	}
	
	return k;
	
}

int main(){
	
	vector<int> arr = {30,11,23,4,20};
	int h = 6 ;
	
	cout<< binarySearchEatingBananas(arr, h);
}
