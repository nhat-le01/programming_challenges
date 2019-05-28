/**
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.
**/
class Solution {
public:
    //A function to check whether a sum of elements in a vector sum up to target
    bool sumToTarget(int target, vector<int>& v){
        int total = 0;
        for (int i = 0; i < v.size(); i++){
            total += v[i];
        }
        return total == target;
    }
    //A function to create subsets of a vector
    void createSubsets(vector<int>& v, vector<int>& soFar, vector<vector<int>>& result, int remain, int start){
        if (remain < 0) {
            return;
        }
        else if (remain == 0) {
            result.push_back(soFar);
        }
        else {
            for (int i = start; i < v.size(); i++) {
                soFar.push_back(v[i]);
                createSubsets(v, soFar, result, remain - v[i], i);
                soFar.erase(soFar.end() - 1);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> soFar;
        createSubsets(candidates, soFar, result, target, 0);
        return result;
    }
};
