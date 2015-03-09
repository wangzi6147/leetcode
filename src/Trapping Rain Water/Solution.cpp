class Solution {
public:
	int trap(int A[], int n) {
		int sum = 0;
		int rightMaxPos = 1;
		int rightMax = 0;
		int increase;
		for (int i = 1; i < n - 1; i++){
			//找右边最高点
			if (rightMaxPos <= i){
				rightMax = A[i];
				for (int j = i + 1; j < n; j++){
					if (A[j] > rightMax){
						rightMax = A[j];
						rightMaxPos = j;
					}
				}
				if (rightMax<=A[i]){
					rightMaxPos = i;
				}
			}
			//注水
			if (A[i - 1] > A[i] && rightMaxPos != i){
				increase = (A[i - 1] < A[rightMaxPos]) ? (A[i - 1] - A[i]) : (A[rightMaxPos] - A[i]);
				sum = sum + increase;
				A[i] = A[i] + increase;
			}
		}
		return sum;
	}
};