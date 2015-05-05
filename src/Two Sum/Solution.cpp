class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> available;
        vector<int> result;
        map<int, vector<int>> map;
        //找到最小
        int min = 0;
        for(int num:nums){
            if(num<min)
                min = num;
        }
        //更新数据
        if(min<0){
            for(int i = 0;i<nums.size();i++){
                nums[i] = nums[i] + (0-min);
            }
            target = target-(2*min);
        }
        
        for(int i = 0;i<nums.size();i++){
            int num = nums[i];
            if(num<=target){
                available.push_back(num);
                if(map.find(num)!=map.end())
                    map[num].push_back(i);
                else{
                    vector<int> temp;
                    temp.push_back(i);
                    map.insert(pair<int,vector<int>>(num,temp));
                }
            }
        }
        sort(available.begin(),available.end());
        int size = available.size();
        for(int i = 0;i<size;i++){
            for(int j = size-1;j>=0;j--){
                int front = available[i];
                int back = available[j];
                int sum = front+back;
                if(sum==target){
                    int result_1 = map[front][0]+1;
                    int result_2 = map[back].back()+1;
                    if(result_1<result_2){
                        result.push_back(result_1);
                        result.push_back(result_2);
                    }else{
                        result.push_back(result_2);
                        result.push_back(result_1);
                    }
                    return result;
                }else if(sum<target)
                    break;
            }
        }
        return result;
    }
};