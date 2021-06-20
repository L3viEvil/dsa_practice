/*
152. Maximum Product Subarray   
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        DP solution: can them 1 chieu thu 2 de luu xem ket qua dang la am hay duong, max duong va min am
        so sanh voi nums[i], nums[i]*table[i-1][0] va nums[i]*table[i-1][1]
        */
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int table[n][2];
        table[0][0] = nums[0];
        table[0][1] = nums[0];
        int temps[3];
        for (int i = 1; i < n; i++) {
            temps[2] = nums[i];
            temps[0] = table[i-1][0] * nums[i];
            temps[1] = table[i-1][1] * nums[i];
            table[i][0] = temps[0];
            table[i][1] = temps[0];
            for (int j = 0; j < 3; j++) {
                if (table[i][0] > temps[j]) table[i][0] = temps[j];
                if (table[i][1] < temps[j]) table[i][1] = temps[j];
            }
        }
        for (int i = 0; i < n; i++) cout << table[i][0] << " " << table[i][1] << " | ";
        cout << endl;
        int max = table[0][0];
        for (int i = 0; i < n; i++) {
            if (table[i][0] > max) max = table[i][0];
            if (table[i][1] > max) max = table[i][1];
        }
        return max;
        
    }
};