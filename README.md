# Check If N and Its Double Exist (All Approaches)

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