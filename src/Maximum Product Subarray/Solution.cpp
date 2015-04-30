class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int max = nums[0];
        
        int* positive = NULL;
        int* negative = NULL;
        positive = new int[size+1];
        negative = new int[size+1];
        positive[0] = 1;
        negative[0] = 1;
        
        for(int i = 0; i<size;i++){
            int num = nums[i];
            if(num>0){
                positive[i+1] = positive[i]*num;
                max = max>positive[i+1]?max:positive[i+1];
                if(negative[i]>0)
                    negative[i+1] = 1;
                else
                    negative[i+1] = negative[i]*num;
            }else if(num<0){
                negative[i+1] = positive[i]*num;
                if(negative[i]>0)
                    positive[i+1] = 1;
                else{
                    positive[i+1] = negative[i]*num;
                    max = max>positive[i+1]?max:positive[i+1];
                }
            }else{
                if(max<0)
                    max = 0;
                positive[i+1] = 1;
                negative[i+1] = 1;
            }
        }
        
        delete[] positive;
        delete[] negative;
        return max;
    }
};