#include<bits/stdc++.h>
using namespace std;

int power(int x, int y, int target){
	long long int ans = 1;
	for(int i = 1 ; i <= y ; i++){
		ans *= x;
		if(ans>target) return 2;
	}
	if(ans == target) return 1;
	else return 0;
	
	//returns 0 if power value < target
	//returns 1 if power value = target
	//return 2 if power value > target
}

float findNthRoot(int target, int n){
	
	if(target == 0) return 0;
	if (target < 0) return -1;
	int ans = -1;
	int start = 1;
	int end = target;
	while(start <= end){
		int mid = start + (end- start) /2;
		
		if(power(mid, n, target) == 1) return mid;
	
		else if(power(mid, n, target) == 0) {
			ans = mid;
			start = mid+1;
		}
		else end = mid-1;
	}
	return -1;
}

int main(){
	
	int target = 9;
	
	cout<<findNthRoot(64,3);
	return 0;
}
