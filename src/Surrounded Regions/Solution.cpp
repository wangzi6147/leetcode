class Solution {
public:
	vector<vector<int>> record;
	queue<pair<int, int>> q;
	int nCols, nRows;
	void solve(vector<vector<char>> &board) {
		nRows = board.size();
		if (nRows == 0)
			return;
		nCols = board[0].size();
		for (int i = 0; i < nRows; i++){
			vector<int> temp;
			record.push_back(temp);
			for (int j = 0; j < nCols; j++){
				record[i].push_back((board[i][j]=='O')?1:0);
			}
		}
		for (int i = 0; i < nCols;i++){
			if (record[0][i]){
				record[0][i] = 0;
				q.push(make_pair(0, i));
				process();
			}
		}
		for (int i = 1; i < nRows; i++){
			if (record[i][0]){
				record[i][0] = 0;
				q.push(make_pair(i, 0));
				process();
			}
		}
		for (int i = 1; i < nCols; i++){
			if (record[nRows - 1][i]){
				record[nRows - 1][i] = 0;
				q.push(make_pair(nRows - 1, i));
				process();
			}
		}
		for (int i = 1; i < nRows-1; i++){
			if (record[i][nCols - 1]){
				record[i][nCols - 1] = 0;
				q.push(make_pair(i, nCols - 1));
				process();
			}
		}
		for (int i = 1; i<nRows - 1; i++){
			for (int j = 1; j<nCols - 1; j++){
				if (record[i][j])
					board[i][j] = 'X';
			}
		}
	}
	void process(){
		int row, col;
		while (!q.empty()){
			row = q.front().first;
			col = q.front().second;
			q.pop();
			if (row > 0 && record[row - 1][col]){
				record[row - 1][col] = 0;
				q.push(make_pair(row - 1, col));
			}
			if (col > 0 && record[row][col - 1]){
				record[row][col - 1] = 0;
				q.push(make_pair(row, col - 1));
			}
			if (row < nRows - 1 && record[row + 1][col]){
				record[row + 1][col] = 0;
				q.push(make_pair(row + 1, col));
			}
			if (col < nCols - 1 && record[row][col + 1]){
				record[row][col + 1] = 0;
				q.push(make_pair(row, col + 1));
			}
		}
	}
};