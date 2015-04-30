class Solution {
public:
	int candy(vector<int>& ratings) {
		int size = ratings.size();
		int sum = 0;
		vector<int> result;
		bool done = false;

		//·ÖÀà£º×ó>ÓÒ> 1 ×ó<ÓÒ> 2 ×ó>ÓÒ< 3 ×ó<ÓÒ< 4
		vector<int> cate;
		if (ratings[0] > ratings[1])
			cate.push_back(2);
		else
			cate.push_back(4);
		if (cate.back() == 4)
			result.push_back(1);
		else
			result.push_back(ratings[0]);
		for (int i = 1; i<size - 1; i++){
			int rating = ratings[i];
			int preRating = ratings[i - 1];
			int nextRating = ratings[i + 1];
			if (rating>preRating){
				if (rating > nextRating){
					cate.push_back(1);
				}
				else{
					cate.push_back(3);
				}
			}
			else{
				if (rating > nextRating){
					cate.push_back(2);
				}
				else{
					cate.push_back(4);
				}
			}
			if (cate.back() == 4)
				result.push_back(1);
			else
				result.push_back(rating);
		}
		if (ratings[size - 1] > ratings[size - 2])
			cate.push_back(3);
		else
			cate.push_back(4);
		if (cate.back() == 4)
			result.push_back(1);
		else
			result.push_back(ratings.back());

		int resultTemp = 0;
		int preCandy = 0;
		int nextCandy = 0;
		while (!done){
			done = true;
			for (int i = 0; i<size; i++){
				switch (cate[i]){
				case 1:
					preCandy = result[i - 1];
					nextCandy = result[i + 1];
					resultTemp = preCandy>nextCandy ? (preCandy + 1) : (nextCandy + 1);
					if (result[i] != resultTemp){
						result[i] = resultTemp;
						done = false;
					}
					break;
				case 2:
					resultTemp = result[i + 1] + 1;
					if (result[i] != resultTemp){
						result[i] = resultTemp;
						done = false;
					}
					break;
				case 3:
					resultTemp = result[i - 1] + 1;
					if (result[i] != resultTemp){
						result[i] = resultTemp;
						done = false;
					}
					break;
				default:
					break;
				}
			}
		}
		for (int i = 0; i < size; i++){
			sum = sum + result[i];
		}
		return sum;
	}
};