class Solution {
public:
	int maxSubArray(int A[], int n) {
		int i = 1, largestSum, curSum;
		largestSum = A[0];
		curSum = largestSum;
		while(i<n){
			if (curSum<0){
				curSum = 0;
			}
			curSum = curSum + A[i];
			largestSum = (largestSum > curSum) ? largestSum : curSum;
			i++;
		}
		return largestSum;
	}
};