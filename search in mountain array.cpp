#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int binarySearchOnDescending(vector<int> arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int searchInBitonicArray(vector<int> arr, int target) {
    int n = arr.size();
    if (n < 3) return -1;

    int start = 0;
    int end = n - 1;
    int peakIndex = -1;

    // Find the peak element index
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < n - 1) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                peakIndex = mid;
                break;
            }
            else if (arr[mid] > arr[mid + 1]) end = mid - 1;
            else start = mid + 1;
        }
        else if (mid == 0) {
            if (arr[mid] > arr[mid + 1]) {
                peakIndex = mid;
                break;
            }
            else {
                start = mid + 1;
            }
        }
        else if (mid == n - 1) {
            if (arr[mid] > arr[mid - 1]) {
                peakIndex = mid;
                break;
            }
            else {
                end = mid - 1;
            }
        }
    }

    if (peakIndex == -1) return -1; // Peak element not found

    // Search in the increasing part
    int ans1 = binarySearch(arr, 0, peakIndex, target);
    if (ans1 != -1) return ans1;

    // Search in the decreasing part
    int ans2 = binarySearchOnDescending(arr, peakIndex + 1, n - 1, target);
    return ans2;
}

int main() {
    vector<int> arr = {10, 23, 45, 67, 89, 45, 32, 12, 1};
    int target = 89;
    int result = searchInBitonicArray(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}

