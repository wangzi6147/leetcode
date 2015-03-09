class Solution {
public:
	int nRows;
	int nCols;
	int * record;
	vector<vector<char> > board;
	string word;
	bool exist(vector<vector<char> > &board, string word) {
		this->board = board;
		this->word = word;
		nRows = board.size();
		nCols = board[0].size();
		record = new int[nRows*nCols];
		for (int i = 0; i < nRows*nCols; i++)
			record[i] = 0;
		for (int i = 0; i < nRows; i++){
			for (int j = 0; j < nCols; j++){
				if (board[i][j] == word[0]){
					if (search(0, i, j)){
						delete[] record;
						return true;
					}
				}
			}
		}
		delete[] record;
		return false;
	}
	bool search(int iChar, int iRow, int iCol){
		if (iChar == word.length()-1)
			return true;
		record[iRow*nCols + iCol] = 1;
		int nextNum = iChar + 1;
		char nextChar = word[nextNum];
		if (iRow-1 >= 0 && record[(iRow - 1)*nCols + iCol] == 0 && board[iRow - 1][iCol] == nextChar){
			if (search(nextNum, iRow - 1, iCol))
				return true;
		}
		if ((iRow + 1) < nRows && record[(iRow + 1)*nCols + iCol] == 0 && board[iRow + 1][iCol] == nextChar){
			if (search(nextNum, iRow + 1, iCol))
				return true;
		}
		if ((iCol - 1) >= 0 && record[iRow*nCols + iCol - 1] == 0 && board[iRow][iCol - 1] == nextChar){
			if (search(nextNum, iRow, iCol - 1))
				return true;
		}
		if ((iCol + 1)<nCols&& record[iRow*nCols + iCol + 1] == 0 && board[iRow][iCol + 1] == nextChar){
			if (search(nextNum, iRow, iCol + 1))
				return true;
		}
		record[iRow*nCols + iCol] = 0;
		return false;
	}
};