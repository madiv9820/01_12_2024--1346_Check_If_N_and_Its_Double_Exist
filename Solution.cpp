#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Define a lambda function 'binary_Search' to perform binary search
        function<bool(int, int, int, int)> binary_Search = [&](int start, int end, int x, int i) -> bool {
            // Perform binary search within the range [start, end]
            while (start <= end) {
                // Calculate the mid index of the current search range
                int mid = (start + end) / 2;

                // Check if the element at mid equals x, and ensure it's not the same element as arr[i]
                if (mid != i and arr[mid] == x) return true;

                // If the element at mid is greater than x, narrow the search range to the left half
                else if (arr[mid] > x) end = mid - 1;

                // If the element at mid is smaller than x, narrow the search range to the right half
                else start = mid + 1;
            }

            // Return false if the element x is not found in the current range
            return false;
        };

        // Sort the array to prepare for binary search
        sort(arr.begin(), arr.end());
        
        int n = arr.size();  // Get the size of the array

        // Iterate through each element in the array
        for (int i = 0; i < n; ++i) {
            // For each element arr[i], check if its double (2 * arr[i]) exists in the array
            if (binary_Search(0, n - 1, 2 * arr[i], i)) {
                return true;  // If found, return true immediately
            }
        }

        // If no valid pair is found after checking all elements, return false
        return false;
    }
};

int main() {
    vector<int> arr = {10,2,5,3}; Solution sol;
    cout << (sol.checkIfExist(arr) ? "true":"false") << endl;
}