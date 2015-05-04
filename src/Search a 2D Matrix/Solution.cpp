class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(vector<int> row:matrix){
            if(target>=row[0]&&target<=row.back())
                return binary_search(row.begin(),row.end(),target);
        }
        return false;
    }
};