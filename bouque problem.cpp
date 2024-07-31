 #include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>& arr){
	int maxi = INT_MIN;
	for(int i = 0 ; i < arr.size() ; i++){
		maxi = max(maxi, arr[i]);
	}
	return maxi;
}

int findMin(vector<int>& arr){
	int mini = INT_MAX;
	for(int i = 0 ; i < arr.size() ; i++){
		mini = min(mini, arr[i]);
	}
	return mini;
}

bool isPossible(vector<int> arr, int days, int m, int k){
	int counter = 0;
	int noOfBouquets = 0;
	for(int i = 0 ; i < arr.size() ; i++){
		if(arr[i] <= days) counter++;
		else{
			noOfBouquets += counter / k;
			counter = 0;
		}
	} 
	noOfBouquets += counter / k;
	if(noOfBouquets >= m) return true;
	else return false;
}
 
 
 int minDays(vector<int>& arr, int m, int k) {
    
    	int start = findMin(arr);
    	int end = findMax(arr);
    	
    	int n = arr.size();
    	if(n < m*k) return -1;
    	
    	int ans;
    	
    	while(start <= end){
    		int mid = start + (end - start ) /2;
    		
    		if(isPossible(arr, mid, m, k)) {
    			ans = mid;
    			end = mid-1;
			}
			else start = mid + 1;
		}
    	
    	return ans;
    }

int main(){
	vector<int> arr = {7,7,7,7,13,11,12,7};
	int m = 2;
	int k = 3;
	cout << minDays(arr, m, k);
	return 0;
}

