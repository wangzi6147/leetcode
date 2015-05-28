class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        result.push_back({});
        backtrack(k-1, n, 0, 1, result);
        result.pop_back();
        return result;
    }
    bool backtrack(int k, int target, int count, int start, vector<vector<int>> &result){
        for(int i = start;i<10;i++){
            if(i>target)
                return false;
            if(count==k){
                if(i==target){
                    result.back().push_back(i);
                    result.push_back(result.back());
                    result.back().pop_back();
                    return true;
                }else{
                    continue;
                }
            }else{
                result.back().push_back(i);
                backtrack(k, target-i, count+1, i+1, result);
                result.back().pop_back();
            }
        }
        return false;
    }
};