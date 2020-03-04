#include <cstdio>

using namespace std;

int arr[81][81];

bool dfs(int row, int col) {
	bool ret = true;
	// �� �ڸ��� ���
	if (arr[row][col] == 0) {
		// �ĺ��� Ž�� (1~9)
		for (int i = 1; i <= 9; ++i) {
			bool flag = true;
			// ����,���� �˻�
			for (int j = 0; j < 9; ++j) {
				if (arr[row][j] == i || arr[j][col] == i) {
					flag = false;
					break;
				}
			}
			// ���� �簢�� ���� �˻� 
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

			// ���� �� ������
			if (flag == true) {
				// �ְ�
				arr[row][col] = i;

				// ������ ĭ �ΰ�� �ְ� return true
				if (row ==8 && col == 8) {
					return true;
				}
				// ������ ĭ �ƴϸ� ������ ����
				if (col == 8) {
					ret = dfs(row + 1, 0);
				}
				else {
					ret = dfs(row, col + 1);
				}
				// ������ �ϴ� ������
				if (ret == false) {
					// ������ ���
					arr[row][col] = 0;
				}
			}
		}
		// �ĺ����� �� �������� ã�� �������� return false
		if (arr[row][col] == 0) {
			return false;
		}
		// ã������ return true
		else {
			return true;
		}
	}

	// ���ڸ��� �ƴ� ���
	else {
		// ������ ĭ �ΰ��
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