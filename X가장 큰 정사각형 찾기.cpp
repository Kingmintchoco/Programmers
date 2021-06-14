#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
	int area = 1;

	int cnt = 1;
	for (int i = 1; i < board.size(); ++i) {
		for (int j = 1; j < board[i].size(); ++j) {
			if (board[i][j] == 0) {
				continue;
			}
			else if (board[i][j - 1] >= 1 // ¿Ş
				|| board[i - 1][j] >= 1 // À§
				|| board[i - 1][j - 1] >= 1 // ¿ŞÂÊ ´ë°¢¼± À§
				) {
				board[i][j] = board[i - 1][j - 1] + 1;
				++cnt;
			}
		}
	}

	area = cnt;
	return area;
}