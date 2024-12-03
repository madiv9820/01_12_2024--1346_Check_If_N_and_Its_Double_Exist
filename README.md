- ## Approach 2:- Binary Search
    - ### Intuition
        The problem asks us to check if there exist two distinct indices `i` and `j` such that `arr[i] == 2 * arr[j]`. To solve this efficiently:

        - We can use binary search to check for the existence of the value `2 * arr[i]` in the sorted array for each element `arr[i]`.
        - Sorting the array ensures that we can efficiently search for values using binary search, reducing the time complexity compared to brute force methods.
        - The key observation is that sorting allows us to perform a binary search for the target `2 * arr[i]` while avoiding linear searches, which is computationally expensive.

    - ### Approach
        1. **Sort the Array**: First, we sort the array to leverage the efficiency of binary search.
        2. **Binary Search for Double**: For each element `arr[i]`, we use binary search to check if the value `2 * arr[i]` exists in the array. We ensure that we do not compare the element with itself by passing the index `i` to the binary search function.
        3. **Return Result**: If a match is found during the binary search, we return `true`. If no match is found for all elements, return `false`.

        Steps in the code:
            - Sort the array.
            - Iterate through each element of the sorted array.
            - For each element, use binary search to look for its double.
            - If the double is found, return `true`. If no valid pair is found after the loop, return `false`.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def checkIfExist(self, arr: List[int]) -> bool:
                    # Helper function to perform binary search
                    def binary_Search(start: int, end: int, x: int, i: int) -> bool:
                        # Perform binary search within the range [start, end]
                        while start <= end:
                            # Calculate the middle index
                            mid = (start + end) // 2
                            
                            # Check if the element at mid is equal to x and is not at index i
                            # (we want to avoid comparing the element with itself)
                            if mid != i and arr[mid] == x:
                                return True
                            # If the middle element is greater than x, narrow the search to the left half
                            elif arr[mid] > x:
                                end = mid - 1
                            # If the middle element is smaller than x, narrow the search to the right half
                            else:
                                start = mid + 1
                        
                        # Return False if no matching element is found
                        return False
                    
                    # Sort the array to make binary search possible
                    arr.sort()
                    
                    n = len(arr)  # Get the length of the array
                    
                    # Iterate through each element in the array
                    for i in range(n):
                        # For each element arr[i], check if its double (2 * arr[i]) exists in the sorted array
                        if binary_Search(0, n - 1, 2 * arr[i], i):
                            return True  # If found, return True
                    
                    # If no valid pair is found, return False
                    return False
            ```
        
        - **C++ Solution**
            ```cpp []
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
            ```
            
    - ### Time Complexity
        - **Sorting** the array takes `O(n log n)` time, where `n` is the length of the array.
        - **Binary Search** is performed for each element, which takes `O(log n)` time. Since we perform this search for all `n` elements, the total complexity for the search part is `O(n log n)`.
        - Therefore, the overall **time complexity** is `O(n log n)` due to the sorting step and the binary search.

    - ### Space Complexity
        - The space complexity is **O(1)**, as we are only using a constant amount of extra space for the binary search and the iteration over the array.
        - The space used for sorting is not counted in this complexity, assuming we are using an in-place sorting algorithm (like quicksort).

        Thus, the space complexity remains **O(1)**, aside from the space required for the input array.