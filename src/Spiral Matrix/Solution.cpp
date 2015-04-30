class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int i = 0;
        vector<int> result;
        while(matrix.size()!=0&&matrix[0].size()!=0){
            switch(i%4){
                case 0:
                    for(int j = 0; j<matrix[0].size(); j++){
                        result.push_back(matrix[0][j]);
                    }
                    matrix.erase(matrix.begin());
                    break;
                case 1:
                    for(int j = 0; j<matrix.size(); j++){
                        result.push_back(matrix[j].back());
                        matrix[j].pop_back();
                    }
                    break;
                case 2:
                    for(int j = matrix.back().size()-1; j>=0; j--){
                        result.push_back(matrix.back()[j]);
                    }
                    matrix.pop_back();
                    break;
                case 3:
                    for(int j = matrix.size()-1; j>=0; j--){
                        result.push_back(matrix[j][0]);
                        matrix[j].erase(matrix[j].begin());
                    }
                    break;
                defalt:
                    break;
            }
            i++;
        }
        return result;
    }
};