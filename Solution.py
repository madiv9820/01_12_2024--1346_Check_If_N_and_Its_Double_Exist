from typing import List
from collections import defaultdict

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