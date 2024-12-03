from typing import List

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