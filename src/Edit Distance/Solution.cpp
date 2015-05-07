class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.length()+1;
        int size2 = word2.length()+1;
        int **data = new int*[size1];
        for(int i = 0;i<size1;i++){
            data[i] = new int[size2];
        }
        data[0][0] = 0;
        for(int i = 1;i<size1;i++){
            data[i][0] = i;
        }
        for(int i = 1;i<size2;i++){
            data[0][i] = i;
        }
        for(int i = 1;i<size1;i++){
            for(int j = 1;j<size2;j++){
                if(word1[i-1]==word2[j-1])
                    data[i][j] = data[i-1][j-1];
                else
                    data[i][j] = min(data[i-1][j-1], min(data[i-1][j], data[i][j-1]))+1;
            }
        }
        int result = data[size1-1][size2-1];
        for(int i = 0;i<size1;i++){
            delete[] data[i];
        }
        delete[] data;
        return result;
    }
};