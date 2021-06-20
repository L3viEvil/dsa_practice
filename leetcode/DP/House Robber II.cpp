/*
213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        DP solution navie la dung 2 bang table1 va table2 dai dien cho viec nha dau tien bi trom hay khong de handle truong hop vong tron.
        Con lai cong thuc tuong tu nhu bai house rober
        table[i][0] = max(table[i-1][0], table[i-1][1])
        table[i][1] = max(table[i-2][0], table[i-2][1]) + nums[i]
        
        Van can chu y cac truong hop bien
        */
        
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) { 
            return max(nums[0], nums[1]);
        }
        int table1[n][2], table2[n][2]; // table1 nha dau tien an trom, table2 nha dau tien khong an trom
        table1[0][0] = 0;
        table1[0][1] = nums[0];
        table1[1][0] = 0;
        table1[1][1] = table1[0][1];
        table2[0][0] = 0;
        table2[0][1] = 0;
        table2[1][0] = 0;
        table2[1][1] = nums[1];
        for (int i = 2; i < n-1 ;i ++) {
            table1[i][0] = max(table1[i-1][0], table1[i-1][1]);
            table1[i][1] = max(table1[i-2][0], table1[i-2][1]) + nums[i];
            table2[i][0] = max(table2[i-1][0], table2[i-1][1]);
            table2[i][1] = max(table2[i-2][0], table2[i-2][1]) + nums[i];
        }
        table1[n-1][0] = max(table1[n-2][0], table1[n-2][1]);
        table1[n-1][1] = max(table1[n-3][0], table1[n-3][1]);
        table2[n-1][0] = max(table2[n-2][0], table2[n-2][1]);
        table2[n-1][1] = max(table2[n-3][0], table2[n-3][1]) + nums[n-1];
        return max(max(table1[n-1][0], table1[n-1][1]), max(table2[n-1][0], table2[n-1][1]));
    }
};