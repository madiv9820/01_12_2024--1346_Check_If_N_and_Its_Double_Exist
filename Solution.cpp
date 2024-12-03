#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array
        
        // Initialize an unordered_map to store each element and its index
        unordered_map<int, int> store_Index;

        // Populate the unordered_map with the elements and their indices
        for (int i = 0; i < n; ++i)
            store_Index[arr[i]] = i;  // Map each element to its index

        // Iterate through the array to check if the double of each element exists
        for (int i = 0; i < n; ++i) {
            // Check if 2 * arr[i] exists in the map and is not the same element
            if (store_Index.find(2 * arr[i]) != store_Index.end() && store_Index[2 * arr[i]] != i)
                return true;  // Return true if a valid pair is found
        }

        // If no valid pair is found, return false
        return false;
    }
};

int main() {
    vector<int> arr = {10,2,5,3}; Solution sol;
    cout << ((sol.checkIfExist(arr)) ? "true":"false") << endl;
}