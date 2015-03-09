class Solution {
public:
	double pow(double x, int n) {
		double result;
		if (n == 1)
			return x;
		else if (n == -1)
			return 1 / x;
		else if (n == 0)
		    return 1;
		else
			return n % 2 ? (result = pow(x, (n - 1) / 2))*result*x : (result = pow(x, n / 2))*result;
	}
};