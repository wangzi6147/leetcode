class Solution {
public:
	int *** data;
	int numTrees(int n) {
		data = new int**[n + 1];
		for (int i = 0; i < n+1; i++){
			data[i] = new int *[n+1];
			for (int j = 0; j < n+1; j++){
				data[i][j] = new int[n + 1];
				for (int k = 0; k < n + 1; k++){
					data[i][j][k] = 0;
				}
			}
		}
		int result = 0;
		for (int i = 1; i <= n; i++){
			result = result + help(1, n, i);
		}

		for (int i = 0; i < n + 1; i++){
			for (int j = 0; j < n + 1; j++){
				delete[] data[i][j];
			}
			delete[] data[i];
		}
		delete[] data;

		return result;
	}

	int help(int min, int max, int val)
	{
		int left = 0, right = 0;
		if (val != min)
		{
			for (int i = min; i < val;i++){
				if (data[min][val-1][i]==0)
					data[min][val - 1][i] = help(min, val - 1, i);
				left = left + data[min][val - 1][i];
			}
		}
		else{
			left = 1;
		}
		if (val!=max)
		{
			for (int i = val + 1; i <= max;i++)
			{
				if (data[val+1][max][i]==0)
				{
					data[val + 1][max][i] = help(val + 1, max, i);
				}
				right = right + data[val + 1][max][i];
			}
		}
		else
		{
			right = 1;
		}
		return left*right;
	}
};