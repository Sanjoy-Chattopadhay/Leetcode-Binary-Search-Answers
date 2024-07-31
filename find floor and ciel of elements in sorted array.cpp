#include <iostream>
#include <vector>
using namespace std;

int findFloorOfAnElement(const vector<int>& arr, int target) {
    int start = 0; 
    int end = arr.size() - 1;
    int ans = -1; // Initialize ans to -1 to handle cases where no floor is found

    // Special case: if target is smaller than the smallest element
    if (target < arr[start]) return ans; 

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) return arr[mid];
        else if (arr[mid] < target) {
            ans = arr[mid]; // Update ans to arr[mid] as it could be a potential floor
            start = mid + 1; // Move to the right to find a larger value
        } else {
            end = mid - 1; // Move to the left to find a smaller value
        }
    }

    return ans;
}

int findCeilOfAnElement(const vector<int>& arr, int target) {
    int start = 0; 
    int end = arr.size() - 1;
    int n = arr.size();
    int ans = -1; // Initialize ans to -1 to handle cases where no floor is found

    // Special case: if target is smaller than the smallest element
    if (target > arr[end]) return ans; 
    

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) return arr[mid];
        else if (arr[mid] < target) {
            end = mid - 1; // Move to the right to find a larger value
        } else {
        	ans = arr[mid]; // Update ans to arr[mid] as it could be a potential floor
            start = mid + 1; // Move to the left to find a smaller value
        }
    }

    return ans;
}


int main() {
    vector<int> arr = {1, 2, 6, 7, 8, 9, 12, 13, 14};
    int target = 3;
    cout << findFloorOfAnElement(arr, target) << endl;
    cout << findCeilOfAnElement(arr, target) << endl;

    return 0;
}

