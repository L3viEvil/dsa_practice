/*
198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 
Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        DP solution: table la mang hai chieu, voi chieu 1 la max so tien cuop duoc tai nha i, chieu 2 la
        nha do co bi cuop hay khong. 0 la ko bi cuop, 1 la bi cuop
        ta thay table[i][0] = max(table[i-1][0], table[i-1][1])
                table[i][1] = max(table[i-2][0], table[i-2][1]) + nums[i]
        */
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int table[n][2];
        table[0][0] = 0;
        table[0][1] = nums[0];
        table[1][0] = table[0][1];
        table[1][1] = nums[1];
        for (int i = 2; i < n; i++) {
            table[i][0] = max(table[i-1][0], table[i-1][1]);
            table[i][1] = max(table[i-2][0] + nums[i], table[i-2][1]+nums[i]);
        }
        // for (int i = 0; i < n; i++) {
        //     cout << table[i][0] << " " << table[i][1] << " | ";
        // }
        // cout << endl;
        return max(table[n-1][0], table[n-1][1]);
    }
};