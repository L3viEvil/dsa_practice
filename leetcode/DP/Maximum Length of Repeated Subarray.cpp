/*718. Maximum Length of Repeated Subarray*/
/*Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        /* 
        DP solution: table[i][j] la do dai cua dai con giua hai day bat dau tai i va j
        Bai nay duyet nguoc
        */
        int m = nums1.size();
        int n = nums2.size();
        int table[m][n];
        if (nums1[m-1] == nums2[n-1]) table[m-1][n-1] = 1;
        else table[m-1][n-1] = 0;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;
                if (nums1[i] == nums2[j]) {
                    if (i+1 > m-1 || j+1 > n-1) table[i][j] = 1;
                    else table[i][j] = table[i+1][j+1] + 1;
                }
                else table[i][j] = 0;
            }
        }
        // for (int  i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << table[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        int max = table[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (max < table[i][j]) max = table[i][j];
            }
        }
        
        return max;
        
    }
};

// class Solution {
// public:
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         /* 
//         DP solution: table[i][j] la do dai day con chung tai vi tri i va j
//         Duyet xuoi
//         */
//         int m = nums1.size();
//         int n = nums2.size();
//         int table[m][n];
//         if (nums1[0] == nums2[0]) table[0][0] = 1;
//         else table[0][0] = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == 0 && j == 0) continue;
//                 if (nums1[i] == nums2[j]) {
//                     if (i-1 < 0 || j-1 < 0) table[i][j] = 1;
//                     else table[i][j] = table[i-1][j-1] + 1;
//                 }
//                 else table[i][j] = 0;
//             }
//         }
        
//         // for (int  i = 0; i < m; i++) {
//         //     for (int j = 0; j < n; j++) {
//         //         cout << table[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
        
//         int max = table[0][0];
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (max < table[i][j]) max = table[i][j];
//             }
//         }
//         return max;
//     }
// };
