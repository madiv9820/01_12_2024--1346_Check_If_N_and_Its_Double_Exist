# [1346. Check If N and Its Double Exist](https://leetcode.com/problems/check-if-n-and-its-double-exist?envType=daily-question&envId=2024-12-01)

__Type:__ Easy <br>
__Topics:__ Array, Hash Table, Two Pointers, Binary Search, Sorting <br>
__Companies:__  Google, Bloomberg, Amazon, Adobe 
<hr>

Given an array `arr` of integers, check if there exist two indices `i` and `j` such that :

- `i != j`
- `0 <= i, j < arr.length`
- `arr[i] == 2 * arr[j]`
<hr>

### Examples
- __Example 1:__ <br>
__Input:__ arr = [10,2,5,3] <br>
__Output:__ true <br>
__Explanation:__ For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

- __Example 2:__ <br>
__Input:__ arr = [3,1,7,11] <br>
__Output:__ false <br>
__Explanation:__ There is no i and j that satisfy the conditions.
<hr>

### Constraints:
- `2 <= arr.length <= 500`
- <code>-10<sup>3</sup> <= arr[i] <= 10<sup>3</sup></code>