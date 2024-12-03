- ## Approach 1:- Brute Force
    - ### Intuition
        The task is to check whether there exist two distinct indices `i` and `j` such that:

        - `i != j`
        - `arr[i] == 2 * arr[j]`

        To solve this, we can iterate through every pair of elements in the array and check whether one is twice the other. The brute force approach checks every possible pair, and once a match is found, we can return `True`. If no such pair exists after iterating through the entire array, we return `False`.

    - ### Approach
        1. We iterate through the array using two nested loops:
            - The outer loop iterates over each element `arr[i]`.
            - The inner loop checks every other element `arr[j]` in the array.
        
        2. For each pair `(i, j)` where `i != j`, we check if `arr[i] == 2 * arr[j]`.

        3. If a match is found, we set the flag `found` to `True` and break out of both loops.
        4. If no match is found by the end of the loops, we return `False`.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def checkIfExist(self, arr: List[int]) -> bool:
                    n = len(arr)  # Get the length of the input array
                    found = False  # Initialize a flag variable to track if a match is found
                        
                    # Iterate through each element 'i' of the array
                    for i in range(n):
                        # Compare arr[i] with every other element 'j' of the array
                        for j in range(n):
                            # Check if arr[i] is equal to twice the value of arr[j], 
                            # and ensure that i != j to avoid comparing an element with itself
                            if i != j and arr[i] == 2 * arr[j]:
                                found = True  # If condition is met, set found to True
                                break  # Exit the inner loop once a match is found

                        # If a match has been found, break the outer loop
                        if found:
                            break
                    
                    # Return True if a pair was found, else False
                    return found
            ```
        
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity
        - The solution uses two nested loops to check every pair of elements in the array.
        - The outer loop runs `n` times, where `n` is the length of the array, and the inner loop also runs `n` times for each iteration of the outer loop.
        - Therefore, the **time complexity** is **O(n<sup>2</sup>)**, where `n` is the length of the array.

    - ### Space Complexity
        - The solution uses only a few extra variables (`n` for the length and `found` for the flag).
        - The space used does not grow with the size of the input, so the **space complexity** is **O(1)**.