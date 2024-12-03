- ## Approach 3:- Linear Search using Hashmap
    - ### Intuition
        The problem requires checking if there exist two distinct indices `i` and `j` such that a given condition holds, for example, `arr[i] == 2 * arr[j]`. A brute-force solution would check every pair of indices, which can be inefficient for larger inputs. A more efficient approach leverages a **hash map** (or dictionary in some languages) to store elements and their indices. This allows for constant-time lookups, improving efficiency.

    - ### Key Insights:
        - By storing each element and its index in a hash map, we can quickly check if a required element (such as double the current element) exists.
        - We ensure the indices are distinct by checking that the indices of the two elements are different.

    - ### Approach
        1. **Store Elements in a Hash Map**: Use a hash map to store each element and its corresponding index. This allows constant-time checks for the existence of related elements.
        2. **Iterate and Check**: For each element in the array, check if its corresponding value (e.g., double, half, or any other condition) exists in the hash map.
            - If the related value exists, ensure the indices are distinct to avoid comparing an element with itself.
        3. **Return the Result**: If a valid pair is found, return `true`. If no valid pair is found after iterating through the array, return `false`.
    
    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def checkIfExist(self, arr: List[int]) -> bool:
                    # Initialize a dictionary to store the elements and their indices
                    store_Index = defaultdict(int)
                    
                    n = len(arr)  # Get the length of the array

                    # Iterate through the array to populate the frequency dictionary with the indices of elements
                    for i in range(n):
                        store_Index[arr[i]] = i  # Store the index of each element

                    # Iterate through the array again to check if double of each element exists
                    for i in range(n):
                        # Check if 2 * arr[i] exists in the dictionary and the index is different from i
                        if 2 * arr[i] in store_Index.keys() and i != store_Index[2 * arr[i]]:
                            return True  # Return True if we find such a pair

                    # Return False if no valid pair is found
                    return False
            ```
        
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity
        - **Populating the hash map** takes `O(n)`, where `n` is the length of the array, because we iterate through the array once to store each element.
        - **Checking the related element for each element** also takes `O(1)` on average, since hash map lookups are constant time.
        - Thus, the overall **time complexity** is **O(n)**.

    - ### Space Complexity
        - The hash map stores each element and its index, so the space required is proportional to the size of the input.
        - The overall **space complexity** is **O(n)**, where `n` is the number of elements in the array.