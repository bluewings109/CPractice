#include <cstdio>
#include <stack>

using namespace std;

bool arr[16][16] = { 0, };
bool issued[16][16] = { 0, };

int main(void) {
	FILE *fp = freopen("input.txt", "r", stdin);

	int N;
	int ans = 0;
	scanf("%d", &N);
	stack<pair<int, int>> s;

	for (int colOfFirstRow = 1; colOfFirstRow <= N; ++colOfFirstRow) {
		s.emplace(1, colOfFirstRow);
		arr[1][colOfFirstRow] = true;
		issued[1][colOfFirstRow] = true;
		while (s.empty() == false) {
			pair<int, int> top = s.top();
			int row = top.first;
			int col = top.second;
			bool flag = true;
			arr[row][col] = false;
			s.pop();
			issued[row][col] = true;

			// 1. 가로세로 검사
			for (int i = 1; i <= N; ++i) {
				if (arr[row][i] == true || arr[i][col] == true) {
					flag = false;
					break;
				}
			}

			// 2. left-upper 대각 검사
			if (flag == true) {
				int i = 0;
				while (1 <= row - i && 1 <= col - i ) {
					if (arr[row - i][col - i] == true) {
						flag = false;
						break;
					}
					++i;
				}
			}

			// 3. right-lower 대각 검사
			if (flag == true) {
				int i = 0;
				while (row + i <= N && col + i <= N) {
					if (arr[row + i][col + i] == true) {
						flag = false;
						break;
					}
					++i;
				}
			}

			// 4. right-upper 대각 검사
			if (flag == true) {
				int i = 0;
				while (1 <= row - i && col + i <= N) {
					if (arr[row - i][col + i] == true) {
						flag = false;
						break;
					}
					++i;
				}
			}

			// 5. left-lower 대각 검사
			if (flag == true) {
				int i = 0;
				while (row + i <= N && 1 <= col - i ) {
					if (arr[row + i][col - i] == true) {
						flag = false;
						break;
					}
					++i;
				}
			}


			// 못 넣으면 같은 row 중 시도 안한것 시도
			if (flag == false) {
				bool backFlag = true;
				for (int i = 1; i <= N; ++i) {
					if (issued[row][i] == false) {
						arr[row][i] = true;
						s.emplace(row, i);
						backFlag = false;
						break;
					}
				}

				if (backFlag == true) {
					for (int i = 1; i <= N; ++i) {
						issued[row][i] = false;
					}
					arr[s.top().first][s.top().second] = false;
					s.pop();
				}

			}
			// 넣을 수 있으면 
			else {
				// 마지막 row 인 경우
				if (row == N) {
					++ans;
					arr[row][(col%N) + 1] = true;
					s.emplace(row, (col%N) + 1);
				}
				else {
					// 검사한놈 넣고
					arr[row][col] = true;
					s.emplace(row, col);

				
					// 다음열거 후보군에 넣음
					arr[row + 1][(col%N) + 1] = true;
					s.emplace(row + 1, (col%N) + 1);
				}

			}
		}
	
	}

	printf("%d", ans);



	fclose(fp);
	return 0;

}