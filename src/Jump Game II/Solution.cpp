class Solution {
public:
	int jump(int A[], int n) {
		int *p = new int[n];
		int min;
		p[n - 1] = 0;
		for (int i = n - 2; i > -1; i--){
			if (A[i] == A[i+1]+1&&i!=n-2){
				p[i] = p[i+1];
				continue;
			}
			min = (1 << 16);
			for (int j = 1; j <= A[i] && i + j < n; j++){
				if (p[i + j] < min)
					min = p[i + j];
			}
			p[i] = min+1;
		}
		int result = p[0];
		delete[] p;
		return result;
	}
};