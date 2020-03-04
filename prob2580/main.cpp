#include <cstdio>

using namespace std;

int arr[81][81];

bool dfs(int row, int col) {
	bool ret = true;
	// 빈 자리인 경우
	if (arr[row][col] == 0) {
		// 후보군 탐색 (1~9)
		for (int i = 1; i <= 9; ++i) {
			bool flag = true;
			// 가로,세로 검사
			for (int j = 0; j < 9; ++j) {
				if (arr[row][j] == i || arr[j][col] == i) {
					flag = false;
					break;
				}
			}
			// 작은 사각형 내부 검사 
			for (int j = (row / 3)*3; j < (row / 3)*3 + 3; ++j) {
				for (int k = (col / 3)*3; k < (col / 3)*3 + 3; ++k) {
					if (arr[j][k] == i) {
						flag = false;
						break;
					}
				}
				if (flag == false) {
					break;
				}
			}

			// 넣을 수 있으면
			if (flag == true) {
				// 넣고
				arr[row][col] = i;

				// 마지막 칸 인경우 넣고 return true
				if (row ==8 && col == 8) {
					return true;
				}
				// 마지막 칸 아니면 다음거 진행
				if (col == 8) {
					ret = dfs(row + 1, 0);
				}
				else {
					ret = dfs(row, col + 1);
				}
				// 다음거 하다 막히면
				if (ret == false) {
					// 넣은거 취소
					arr[row][col] = 0;
				}
			}
		}
		// 후보군을 다 돌았으나 찾지 못했으면 return false
		if (arr[row][col] == 0) {
			return false;
		}
		// 찾았으면 return true
		else {
			return true;
		}
	}

	// 빈자리가 아닌 경우
	else {
		// 마지막 칸 인경우
		if (row == 8 && col == 8) {
			return true;
		}
		if (col == 8) {
			return dfs(row + 1, 0);
		}
		else {
			return dfs(row, col + 1);
		}
	}
}
int main(void)
{
	FILE *fp = freopen("input.txt", "r", stdin);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%d", &(arr[i][j]));
		}
	}

	dfs(0, 0);


	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	fclose(fp);
	return 0;
}