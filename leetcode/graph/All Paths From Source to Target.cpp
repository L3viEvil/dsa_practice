/*
797. All Paths From Source to Target

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        for(int i = 0; i < graph[0].size(); i++) {
            findPaths(graph, res, graph[0][i], path);
        }
        // for (int i = 0; i < res.size(); i++) {
        //     for (int j = 0; j < res[i].size(); j++) {
        //         cout << res[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return res;
    }
    
    void findPaths(vector<vector<int>> &graph, vector<vector<int>> &res, int i, vector<int> path) {
        cout << i << endl;
        if (i == graph.size()-1) {
            path.push_back(i);
            res.push_back(path);
        }
        if (graph[i].size() == 0) {
            return;
        }
        else {
            path.push_back(i);
            for (int j = 0; j < graph[i].size(); j++) {
                findPaths(graph, res, graph[i][j], path);
            }
        }
    }
};