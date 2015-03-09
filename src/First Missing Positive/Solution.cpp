class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		int max = getMax(A, n);
		//标记数组
		int * pInt = new int[max+1];
		//标记数组初始化为全0
		for (int i = 0; i < max + 1; i++){
			*(pInt + i) = 0;
		}
        //将A数组每一项数字对应的标记位表为1（标记数组将会剩余一项0就是要找的数字，或者没有0，那么要找的是max+1）
		for (int i = 0; i < n; i++){
			if (A[i]>0){
				*(pInt + A[i]) = 1;
			}
		}
        //找到这个0
		for (int i = 1; i < max + 1; i++){
			if (*(pInt + i) != 1){
				delete[] pInt;
				return i;
			}
		}
		delete[] pInt;
		return max + 1;
	}
private:
	int getMax(int A[], int n){
		int max = 0;
		for (int i = 0; i < n; i++){
			if (A[i]>max){
				max = A[i];
			}
		}
		return max;
	}
};