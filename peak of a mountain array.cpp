#include<bits/stdc++.h>

using namespace std;

int findIndexOfMaxInBitonicArray(vector < int > arr) {
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    if (n < 3) return -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < n - 1) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
            else if (arr[mid] > arr[mid + 1]) end = mid - 1;
            else start = mid + 1;
        }
        else if (mid == 0) {

            if (arr[mid] > arr[mid + 1]) return mid;
            else start = mid + 1;
        }

        else if (mid == n - 1) {
            if (arr[mid] > arr[mid - 1]) return mid;
            else end = mid - 1;
        }

    }

    return -1;

}

int main() {
    vector < int > arr = {
        0,
        1,
        2,3,2,
        0
    };
    cout << findIndexOfMaxInBitonicArray(arr);
    return 0;
}
