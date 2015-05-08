class Solution {
public:
    int climbStairs(int n) {
        int * data = new int[n+1];
        data[0] = 1;
        data[1] = 1;
        for(int i = 2;i<n+1;i++){
            data[i] = data[i-2]+data[i-1];
        }
        int result = data[n];
        delete[] data;
        return result;
    }
};