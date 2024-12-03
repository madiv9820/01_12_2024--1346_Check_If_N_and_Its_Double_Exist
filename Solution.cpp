#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();  // Get the size of the input array
        bool found = false;   // Initialize a flag variable to track if a match is found

        // Iterate through each element 'i' of the array
        for(int i = 0; i < n; ++i) {
            // Compare arr[i] with every other element 'j' of the array
            for(int j = 0; j < n; ++j) {
                // Check if arr[i] is equal to twice the value of arr[j] and ensure i != j
                if(i != j && arr[i] == 2 * arr[j]) {
                    found = true;  // If the condition is met, set found to true
                    break;         // Exit the inner loop once a match is found
                }
            }

            // If a match has been found, break the outer loop
            if(found)
                break;
        }

        // Return true if a pair was found, otherwise return false
        return found;
    }
};

int main() {
    vector<int> arr = {-2,0,10,-19,4,6,-8}; Solution sol;
    cout << ((sol.checkIfExist(arr)) ? "true":"false") << endl;
}