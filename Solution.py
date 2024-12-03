from typing import List

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