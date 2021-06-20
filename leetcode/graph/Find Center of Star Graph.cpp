/*
1791. Find Center of Star Graph
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

 

Example 1:


Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
 

Constraints:

3 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph.
*/

#include <vector>

using namespace std;


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
//         /*
//         Solution with O(V+E)
//         */
//         unordered_map<int, int> dict;
//         for (int i = 0; i < edges.size(); i++) {
//             dict[edges[i][0]] += 1;
//             dict[edges[i][1]] += 1;
//         }
//         int v = 1;
//         int m = dict[1];
//         int n = 1;
//         unordered_map<int, int>:: iterator p;
//         for (p = dict.begin(); p != dict.end(); p++) {
//             if (p->second > m) {
//                 m = p->second;
//                 v = p->first;
//             }
//             if (p->first > n) {
//                 n =p->first;
//             }
//         }
        
//         cout << n << " " << m << " " << v;
//         return v;
        
        /*
            Solution with O(1), dinh trung tam phai xuat hien o hai canh bat ky
        */
        
        int a = edges[0][0];
        for (int i = 0; i < 2; i++) {
            if (a == edges[1][i]) return a;
        }
        return edges[0][1];
        
    }
};
