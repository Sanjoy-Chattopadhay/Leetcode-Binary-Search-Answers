#include <bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int> arr) {
    int n = arr.size();
    int start = 1;
    int end = n - 2;
    
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int prev = mid - 1;
        int next = mid + 1;
        
        if (arr[mid] != arr[prev] && arr[mid] != arr[next]) return arr[mid];
        
        // we are in the left half
        if ((mid % 2 == 0 && arr[mid] == arr[next]) || (mid % 2 == 1 && arr[mid] == arr[prev])) {
            start = mid + 1;
        } else { // right half
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7};
    cout << findSingleElement(arr);
}

